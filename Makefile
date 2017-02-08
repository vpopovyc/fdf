# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/11 16:18:35 by vpopovyc          #+#    #+#              #
#    Updated: 2017/02/08 17:39:41 by vpopovyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c ft_parse.c ft_s_fdf.c

OBJ = $(SRC:.c=.o)

LIBOBJ = libft/*.o

INC = -I ft_fdf.h

CFLAGS = -c -Wall -Wextra #-Werror

LIBCR = make -C libft/

LIBINC = -I libft/includes/libft.h -L./libft -lft

all: $(NAME)

$(NAME): liball $(OBJ)
	gcc $(LIBINC) $(OBJ) -o $(NAME)
	
%.o: %.c
	gcc $(INC) $(CFLAGS) -o $@ $<

clean: libclean
	rm -f $(OBJ)

fclean: clean
	rm -f libft/libft.a
	rm -f $(NAME)

re: fclean all

liball:
	$(LIBCR) all

libclean:
	$(LIBCR) clean

libre:
	$(LIBCR) re 
