# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/19 10:05:01 by ttas              #+#    #+#              #
#    Updated: 2025/09/08 14:16:25 by marvin           ###   ########.fr        #
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

SRC_SETUP =			./srcs/setup/init.c \
					./srcs/setup/free_parse.c \

SRC_ERROR =			./srcs/error/error_msg.c \

SRC_UTILS =			./srcs/utils/utils.c \


SOURCES =		${SRC} ${SRC_PARSER} ${SRC_SETUP} ${SRC_ERROR} ${SRC_UTILS}
OBJECTS =		${SOURCES:.c=.o}
LIBFT = ./includes/libft

# Variables
CC = cc
#
CFLAGS = -Wall -Werror -Wextra -Includes -fsanitize=address,leak -g
RM = rm -f

# Makefile
%.o:		%.c
		${CC} ${CFLAGS} -c $? -o $@

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