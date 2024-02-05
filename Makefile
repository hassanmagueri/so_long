# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 19:17:50 by emagueri          #+#    #+#              #
#    Updated: 2024/01/17 23:14:55 by emagueri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = 	./mandatory/get_next_line_utils.c \
	 	./mandatory/get_next_line.c \
	 	./mandatory/ft_strlen.c \
	 	./mandatory/ft_strdup.c \
	 	./mandatory/ft_itoa.c \
	 	./mandatory/ft_putendl_fd.c \
	 	./mandatory/ft_split.c \
	 	./mandatory/ft_strjoin.c \
	 	./mandatory/ft_putchar_fd.c \
	 	./mandatory/ft_putstr_fd.c \
	 	./mandatory/ft_calloc.c \
	 	./mandatory/ft_bzero.c \
	 	./mandatory/ft_strncmp.c \
		./mandatory/checkmap.c \
		./mandatory/checkmap_utils1.c \
		./mandatory/checkmap_utils2.c \
		./mandatory/frame.c \
		./mandatory/frame_utils.c \
		./mandatory/initialize_objects.c \
		./mandatory/so_long.c

SRCB = 	./bonus/get_next_line_utils_bonus.c \
	 	./bonus/get_next_line_bonus.c \
	 	./bonus/ft_strlen_bonus.c \
	 	./bonus/ft_strdup_bonus.c \
	 	./bonus/ft_itoa_bonus.c \
	 	./bonus/ft_putendl_fd_bonus.c \
	 	./bonus/ft_split_bonus.c \
	 	./bonus/ft_strjoin_bonus.c \
	 	./bonus/ft_putchar_fd_bonus.c \
	 	./bonus/ft_putstr_fd_bonus.c \
	 	./bonus/ft_calloc_bonus.c \
	 	./bonus/ft_bzero_bonus.c \
	 	./bonus/ft_strncmp_bonus.c \
		./bonus/checkmap_bonus.c \
		./bonus/checkmap_utils1_bonus.c \
		./bonus/checkmap_utils2_bonus.c \
		./bonus/frame_bonus.c \
		./bonus/frame_utils_bonus.c \
		./bonus/initialize_objects_bonus.c \
		./bonus/draw_frame_bonus.c \
		./bonus/so_long_bonus.c

OBJ		= $(SRC:.c=.o)
OBJB	= $(SRCB:.c=.o)

NAME	= so_long
NAME_B	= so_long_bonus
CC 		= cc
CFLAGS 	= -Wall -Werror -Wextra
RM 		= rm -rf
LIBX 	= -lmlx -framework OpenGL -framework AppKit

all:$(NAME)

bonus:$(NAME_B)

$(NAME):$(OBJ)
	$(CC) $(LIBX) $^ -o $@

$(NAME_B):$(OBJB)
	$(CC) $(LIBX) $^ -o $@

%.o:%.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJB)

fclean: clean
	$(RM) $(NAME) $(NAME_B)

re: fclean all

.PHONY: clean