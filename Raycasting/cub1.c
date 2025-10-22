#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "minilibx-linux/mlx.h"

void my_pixel_put(void *img, int line_len, int bpp, char *addr, int x, int y, int color)
{
    if (x < 0 || x >= 800 || y < 0 || y >= 600)
        return;
    char *dst = addr + (y * line_len + x * (bpp / 8));
    *(unsigned int *)dst = color;
}

#define PI 3.14159265

int main(void)
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 800, 600, "Cub3d");
    void *img = mlx_new_image(mlx, 800, 600);

    char *addr;
    int bpp, line_len, endian;
    addr = mlx_get_data_addr(img, &bpp, &line_len, &endian);

    int position_joueur_x = 350;
    int position_joueur_y = 350;

    double angle_central_deg = 60;
    double champ_vue_deg = 60;
    double angle_depart = angle_central_deg - champ_vue_deg / 2;
    double angle_fin = angle_central_deg + champ_vue_deg / 2;

    for (double angle_deg = angle_depart; angle_deg <= angle_fin; angle_deg += 0.5) // pas d’angle 0.5°
    {
        double angle_rad = angle_deg * PI / 180.0;

        // Parcours le rayon sur une distance (ex: 200 pixels)
        for (int dist = 0; dist < 200; dist++)
        {
            int x = position_joueur_x + dist * cos(angle_rad);
            int y = position_joueur_y + dist * sin(angle_rad);
            
            my_pixel_put(img, line_len, bpp, addr, x, y, 0xF0340E);
        }
    }

    mlx_put_image_to_window(mlx, win, img, 0, 0);

    mlx_loop(mlx);
}

/*

int main(void)
{
    void *mlx;
    void *win;
    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "Cub3d");
    void *img;
    void *adr;
    img = mlx_new_image(mlx, 800, 600);

    char *addr;
    int bpp, line_len, endian;
    addr = mlx_get_data_addr(img, &bpp, &line_len, &endian);
    int position_joueur_x = 350;
    int position_joueur_y = 350;
    int angle = 60;

    
    for(int x = 0; x <= 400; x++)
    {   
        for(int y = 0; y <= (1/tan(10))*x; y++)
            my_pixel_put(img, line_len, bpp, addr, x, y, 0xF0340E);
    }
    mlx_put_image_to_window(mlx, win, img, 0, 0);

   

    //mlx_hook(g.win, 2, 1L << 0, handle_key, &g);
    //mlx_loop_hook(g.mlx, render, &g);
    mlx_loop(mlx);
    return (0);
}*/