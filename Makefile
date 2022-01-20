NAME	=	so_long

SRCS	=	src/1_main.c		src/2_read_map.c 	src/3_valid_map.c \
			src/4_run_game.c	src/5_open_img.c 	src/6_put_img.c \
			src/7_enemy.c		src/8_go_to.c 		src/error.c
			
HEADER	=	includes/so_long.h

OBJS	=	$(SRCS:%.c=%.o)

CC		=	gcc

LIBFT	=	-L lib -lft

INC		=	-I includes -I lib -I minilibx_opengl_20191021

CFLAGS	=	-Wall -Wextra -Werror -I $(HEADER) -Imlx

MLIBX	=	-Lmlx -lmlx -framework OpenGL -framework AppKit

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(HEADER)
	@$(CC) $(CFLAGS) $(INC) $(LIBFT) $(MLIBX) $(OBJS) -o $(NAME)
				@echo "-----Successful success!-----"
				@echo "───████────────██████████────"
				@echo "──█▒▒▒▒█─────███▒▒▒▒▒▒▒▒███──"
				@echo "───█▒▒▒▒█──██▒▒▒▒▒▒▒▒▒▒▒▒▒▒██"
				@echo "────█▒▒▒▒█─█▒▒▒▒██▒▒▒▒██▒▒▒▒█"
				@echo "─────█▒▒▒█─█▒▒▒▒██▒▒▒▒██▒▒▒▒█"
				@echo "──██████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█"
				@echo "─██▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█"
				@echo "██▒▒▒███████▒▒▒██▒▒▒▒▒▒██▒▒▒█"
				@echo "█▒▒▒▒▒▒▒▒▒▒█▒▒▒▒████████▒▒▒▒█"
				@echo "█▒▒▒▒▒▒▒▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒██"
				@echo "██▒▒▒███████─██▒▒▒▒▒▒▒▒▒▒██──"
				@echo "─██▒▒▒▒▒▒▒▒█───██████████────"
				@echo "──█████████▀─────────────────"

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJS)
	@echo "-------Clean completed-------"

fclean	:	clean
	@$(RM) $(NAME)
	@echo "------Fclean completed-------"

re		:	fclean all 
	@rm -f $(OBJS)