# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/19 10:05:01 by ttas              #+#    #+#              #
#    Updated: 2025/10/09 14:29:49 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
EXE = cub3d

# Files
SRC =				./srcs/main.c
					
SRC_PARSER =		./srcs/parse/args.c \
					./srcs/parse/texture.c \
					./srcs/parse/texture2.c \
					./srcs/parse/color.c \
					./srcs/parse/map.c \
					./srcs/parse/floodfill.c \

SRC_SETUP =			./srcs/setup/init.c \
					./srcs/setup/free_parse.c \

SRC_ERROR =			./srcs/error/error_msg.c \

SRC_UTILS =			./srcs/utils/utils.c \
					./srcs/utils/list.c \


SOURCES =		${SRC} ${SRC_PARSER} ${SRC_SETUP} ${SRC_ERROR} ${SRC_UTILS}
LIBFT = ./includes/libft

OBJDIR = obj

# Map .c files to obj/ structure
OBJECTS = $(patsubst ./srcs/%, $(OBJDIR)/srcs/%, $(SOURCES:.c=.o))

# Variables
CC = cc
#
CFLAGS = -Wall -Werror -Wextra -Includes -fsanitize=address,leak -g
RM = rm -f

# Pattern rule for object files in obj/ directory
$(OBJDIR)/%.o: ./%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

all:		${EXE}

${EXE}:		${OBJECTS} 
		@${MAKE} --silent -C ${LIBFT}
		@${CC} ${CFLAGS} ${OBJECTS} ${LIBFT}/libft.a -o ${EXE}
		@${MAKE} --silent -C ${LIBFT} clean
	
ac: all clean

clean:
		@${MAKE} --silent -C ${LIBFT} clean
		@${RM} ${OBJECTS}

fclean:		clean
		@${MAKE} --silent -C ${LIBFT} fclean
		@${RM} ${EXE}

re:			fclean all

.PHONY: all clean fclean re ac