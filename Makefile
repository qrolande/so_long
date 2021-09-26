NAME 		=	so_long

BONUSNAME	= 	so_long_bonus

SRCS  		=	main_part/start.c \
				main_part/steps.c \
				main_part/parser.c \
				main_part/endgame.c \
				main_part/errorout.c \
				main_part/checking_map.c \
				main_part/init_game_image.c \
				libft/get_next_line.c \
				libft/get_next_line_utils.c 

BONUS_SRCS	=	bonus/start_bonus.c \
				bonus/spray_fire.c \
				bonus/spray_exit.c \
				bonus/init_map.c \
				bonus/steps_bonus.c \
				bonus/parser_bonus.c \
				bonus/endgame_bonus.c \
				bonus/errorout_bonus.c \
				bonus/spray_animation.c \
				bonus/checking_map_bonus.c \
				bonus/init_game_image_bonus.c \
				libft_bonus/ft_itoa.c \
				libft_bonus/get_next_line.c \
				libft_bonus/get_next_line_utils.c 
						
OBJS		=	${SRCS:.c=.o}

BONUS_OBJS	=	${BONUS_SRCS:.c=.o}

CC			= 	gcc

RM			= 	rm -f

CFLAGS		= 	-Wall -Wextra -Werror

MLX			=	-lmlx -framework OpenGL -framework AppKit

INCLUDES	= 	includes/so_long.h

INC_BONUS	=	includes/so_long_bonus.h

%.o : %.c
			${CC} ${CFLAGS} -c $< -I ${INCLUDES} -o $@


all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDES)
			${CC} ${CFLAGS} ${MLX} ${OBJS} -o ${NAME}

bonus:		$(BONUS_OBJS) $(INC_BONUS)
			${CC} ${CFLAGS} ${MLX} ${BONUS_OBJS} -o ${BONUSNAME}

clean:		
			${RM} ${OBJS} ${BONUS_OBJS}

fclean:		clean
			${RM} ${NAME} ${BONUSNAME}

re:			fclean all

.PHONY:		all clean fclean re
