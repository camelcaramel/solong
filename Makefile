# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 15:26:48 by donghwik          #+#    #+#              #
#    Updated: 2021/11/01 15:38:14 by donghwik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = solong
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBRARY_FLAG = -L mlx -l mlx
MLX_FLAGS = -framework OpenGL -framework Appkit
HEADER = -I includes -I mlx
SRCS = ./srcs/enemy.c \
		./srcs/init.c \
		./srcs/main.c \
		./srcs/monitor.c \
		./srcs/parse.c \
		./srcs/parse2.c \
		./srcs/render.c \
		./srcs/render_component.c \
		./srcs/render_player.c \
		./srcs/status.c \
		./srcs/utils.c \
		./srcs/utils2.c \
		./srcs/utils3.c
BONUS_SRCS = ./srcs_bonus/enemy_bonus.c \
			./srcs_bonus/init_bonus.c \
			./srcs_bonus/main_bonus.c \
			./srcs_bonus/monitor_bonus.c \
			./srcs_bonus/parse2_bonus.c \
			./srcs_bonus/parse_bonus.c \
			./srcs_bonus/render_bonus.c \
			./srcs_bonus/render_component_bonus.c \
			./srcs_bonus/render_player_bonus.c \
			./srcs_bonus/status_bonus.c \
			./srcs_bonus/utils2_bonus.c \
			./srcs_bonus/utils3_bonus.c \
			./srcs_bonus/utils_bonus.c
OBJS = ${SRCS:.c =.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

.c.o :
	${CC} ${FLAGS} ${HEADER} -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	make -C mlx
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LIBRARY_FLAG) $(MLX_FLAGS)

bonus : $(BONUS_OBJS)
	make -C mlx
	$(CC) $(FLAGS) $(BONUS_OBJS) -o $(NAME) $(LIBRARY_FLAG) $(MLX_FLAGS)

all : $(NAME)

clean : 
	make clean -C mlx
	rm $(OBJS) $(BONUS_OBJS)

fclean : clean
	make fclean -C mlx
	rm $(NAME)

re : fclean all

.PHONY	:	all clean fclean re