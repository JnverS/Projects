# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 13:25:42 by kdominic          #+#    #+#              #
#    Updated: 2022/02/10 15:58:36 by kdominic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

INC = philo.h

SRCS = philo.c philo_utils.c init.c monitoring.c

OBJ = ${SRCS:.c=.o}

FLAGS = -Wall -Wextra -Werror -g -fsanitize=thread

all : $(NAME)

$(NAME) : $(OBJ) $(INC)
	gcc $(FLAGS) -o $(NAME) $(OBJ) -I $(INC)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
