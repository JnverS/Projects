NAME = so_long

INC = include/so_long.h

INC_B = include/so_long_bonus.h

SRC = main.c solong_utils.c solong_utils2.c \
		solong_utils3.c init.c \
		validation.c rendering.c

SRC_B = main_bonus.c solong_utils_bonus.c solong_utils2_bonus.c \
		solong_utils3_bonus.c init_bonus.c solong_utils4_bonus.c \
		validation_bonus.c rendering_bonus.c init2_bonus.c

SRCS = $(addprefix ./src/, $(SRC))

SRCS_B = $(addprefix ./src/bonus/, $(SRC_B))

OBJ = ${SRCS:.c=.o}

OBJ_B = $(SRCS_B:.c=.o)

FLAGS = -Wall -Wextra -Werror
LFLAGS = -L minilibx_opengl_20191021/ -lmlx -framework OpenGL -framework AppKit

LDIR = minilibx_opengl_20191021/

all : $(NAME)

$(NAME) : $(OBJ) $(INC)
	@make -C $(LDIR)
	gcc -o $(NAME) $(OBJ) $(FLAGS) $(LFLAGS) -I $(INC)

clean :
	@make clean -C $(LDIR)
	@rm -f $(OBJ) $(OBJ_B)

fclean : clean
	@rm -f $(NAME)

bonus : $(OBJ_B) $(INC_B)
	@make -C $(LDIR)
	gcc $(OBJ_B) $(LFLAGS) $(FLAGS) -I $(INC_B) -o $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
