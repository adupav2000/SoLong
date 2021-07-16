SRCS	= main.c srcs/parsing.c\
			srcs/parsing2.c\
			srcs/clear.c\
			srcs/map_info.c\
			srcs/move.c\
			srcs/img_handle.c\
			srcs/handle_view.c\
			srcs/init_game.c




INCLUDES	= includes/
OBJS		= ${SRCS:.c=.o}

CC			= clang -Wall -Werror -Wextra

NAME		= solong

.c.o:
		${CC} -c $< -o ${<:.c=.o}

all:	${OBJS}	
	$(CC) $(OBJS) -lm libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:	
		rm -rf ${OBJS}

fclean: clean
		rm -rf ${NAME}
		rm -rf ${OBJS}

re: fclean all	

.PHONY : all clean fclean re
