#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "minilibx-linux/mlx.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define MAP_WIDTH 8
#define MAP_HEIGHT 8
#define TILE_SIZE 64
#define FOV (60 * M_PI / 180.0)

#define MOVE_SPEED 5
#define ROT_SPEED 0.05

#define KEY_ESC 65307
#define KEY_W 119
#define KEY_S 115
#define KEY_A 97
#define KEY_D 100




typedef struct s_player {
    double x, y;
    double angle;
} t_player;

typedef struct s_game {
    void *mlx;
    void *win;
    t_player player;
    int map[MAP_HEIGHT][MAP_WIDTH];
} t_game;

int world_map[MAP_HEIGHT][MAP_WIDTH] = {
    {1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,1},
    {1,0,1,0,1,0,0,1},
    {1,0,0,0,0,0,0,1},
    {1,0,1,0,1,0,0,1},
    {1,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1}
};

int is_wall(t_game *g, double x, double y)
{
    int mapX = (int)(x / TILE_SIZE);
    int mapY = (int)(y / TILE_SIZE);
    if (mapX < 0 || mapY < 0 || mapX >= MAP_WIDTH || mapY >= MAP_HEIGHT)
        return (1);
    return g->map[mapY][mapX];
}

void my_pixel_put(void *img, int line_len, int bpp, char *addr, int x, int y, int color)
{
    if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
        return;
    char *dst = addr + (y * line_len + x * (bpp / 8));
    *(unsigned int *)dst = color;
}

int render(t_game *g)
{
    void *img = mlx_new_image(g->mlx, WIN_WIDTH, WIN_HEIGHT);
    char *addr;
    int bpp, line_len, endian;
    addr = mlx_get_data_addr(img, &bpp, &line_len, &endian);

    for (int y = 0; y < WIN_HEIGHT; y++)
    {
        int color = (y < WIN_HEIGHT / 2) ? 0x87CEEB : 0x222222;
        for (int x = 0; x < WIN_WIDTH; x++)
            my_pixel_put(img, line_len, bpp, addr, x, y, color);
    }

    for (int x = 0; x < WIN_WIDTH; x++)
    {
        double cameraX = 2 * x / (double)WIN_WIDTH - 1;
        double rayDirX = cos(g->player.angle) + cameraX * cos(g->player.angle + M_PI_2);
        double rayDirY = sin(g->player.angle) + cameraX * sin(g->player.angle + M_PI_2);

        int mapX = (int)(g->player.x / TILE_SIZE);
        int mapY = (int)(g->player.y / TILE_SIZE);

        double deltaDistX = fabs(1 / rayDirX);
        double deltaDistY = fabs(1 / rayDirY);
        double sideDistX, sideDistY;
        int stepX, stepY;

        if (rayDirX < 0) {
            stepX = -1;
            sideDistX = (g->player.x / TILE_SIZE - mapX) * deltaDistX;
        } else {
            stepX = 1;
            sideDistX = (mapX + 1.0 - g->player.x / TILE_SIZE) * deltaDistX;
        }
        if (rayDirY < 0) {
            stepY = -1;
            sideDistY = (g->player.y / TILE_SIZE - mapY) * deltaDistY;
        } else {
            stepY = 1;
            sideDistY = (mapY + 1.0 - g->player.y / TILE_SIZE) * deltaDistY;
        }

        int hit = 0;
        int side = 0;
        while (!hit)
        {
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            if (g->map[mapY][mapX] > 0)
                hit = 1;
        }

        double perpWallDist;
        if (side == 0)
            perpWallDist = (sideDistX - deltaDistX);
        else
            perpWallDist = (sideDistY - deltaDistY);

        int lineHeight = (int)(WIN_HEIGHT / perpWallDist * TILE_SIZE / 64);
        int drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
        if (drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
        if (drawEnd >= WIN_HEIGHT) drawEnd = WIN_HEIGHT - 1;

        int color = (side == 1) ? 0xAAAAAA : 0xFFFFFF;

        for (int y = drawStart; y < drawEnd; y++)
            my_pixel_put(img, line_len, bpp, addr, x, y, color);
    }

    mlx_put_image_to_window(g->mlx, g->win, img, 0, 0);
    mlx_destroy_image(g->mlx, img);
    return (0);
}

int handle_key(int key, t_game *g)
{
    if (key == KEY_ESC)
        exit(0);
    if (key == KEY_W) {
        double nx = g->player.x + cos(g->player.angle) * MOVE_SPEED;
        double ny = g->player.y + sin(g->player.angle) * MOVE_SPEED;
        if (!is_wall(g, nx, ny)) {
            g->player.x = nx;
            g->player.y = ny;
        }
    }
    if (key == KEY_S) {
        printf("sss : %d", KEY_S);
        double nx = g->player.x + cos(g->player.angle) * MOVE_SPEED;
        double ny = g->player.y - sin(g->player.angle) * MOVE_SPEED;
        if (!is_wall(g, nx, ny)) {
            g->player.x = nx;
            g->player.y = ny;
        }
    }
    if (key == KEY_A)
        g->player.angle -= ROT_SPEED;
    if (key == KEY_D)
        g->player.angle += ROT_SPEED;

    if (g->player.angle < 0)
        g->player.angle += 2 * M_PI;
    if (g->player.angle > 2 * M_PI)
        g->player.angle -= 2 * M_PI;
    return (0);
}

int main(void)
{
    t_game g;
    g.mlx = mlx_init();
    g.win = mlx_new_window(g.mlx, WIN_WIDTH, WIN_HEIGHT, "Raycaster DDA");

    for (int y = 0; y < MAP_HEIGHT; y++)
        for (int x = 0; x < MAP_WIDTH; x++)
            g.map[y][x] = world_map[y][x];

    g.player.x = 150;
    g.player.y = 150;
    g.player.angle = 0;

    mlx_hook(g.win, 2, 1L << 0, handle_key, &g);
    mlx_loop_hook(g.mlx, render, &g);
    mlx_loop(g.mlx);
    return (0);
}