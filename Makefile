# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/11 16:18:35 by vpopovyc          #+#    #+#              #
#    Updated: 2017/02/21 20:58:07 by vpopovyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c ft_parse.c ft_s_fdf.c ft_gradient.c ft_init_image.c \
		ft_draw_aa_line.c ft_drawpixel.c ft_keycodes.c ft_modify_xyz.c 

OBJ = $(SRC:.c=.o)

LIBOBJ = libft/*.o

INC = -I ft_fdf.h

CFLAGS = -c -Wall -Wextra -Werror

LIBCR = make -C libft/

LIBINC = -I libft/includes/libft.h -L./libft -lft

all: $(NAME)

$(NAME): liball $(OBJ)
	gcc $(LIBINC) $(OBJ) -lmlx -framework AppKit -framework OpenGL -o $(NAME)
	
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
