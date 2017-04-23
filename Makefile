#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tprysiaz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/17 18:06:03 by tprysiaz          #+#    #+#              #
#    Updated: 2016/12/17 18:06:07 by tprysiaz         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

C = main.c ft_array.c ft_list.c ft_next.c ft_valid_file.c

O = main.o ft_array.o ft_list.o ft_next.o ft_valid_file.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(C)
	gcc -Wall -Wextra -Werror -o $(NAME) $(O)

clean:
	rm -f $(O)

fclean: clean
	rm -f $(NAME)

re: fclean all