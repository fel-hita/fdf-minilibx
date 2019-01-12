# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/02 18:52:24 by fel-hita          #+#    #+#              #
#    Updated: 2019/01/05 00:55:48 by fel-hita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

SRCDIR=srcs
LIBDIR=libs
HEADDIR=includes

CFLAGS=-I$(HEADDIR) -Wall -Wextra -Werror
LDFLAGS=-I$(HEADDIR) -L$(LIBDIR) -lft -lmlx -framework OpenGL -framework AppKit

SRC=$(SRCDIR)/fdf_main.c\
	$(SRCDIR)/fdf_tools.c\
	$(SRCDIR)/fdf_draw.c\
	$(SRCDIR)/fdf_input_handler.c\
	$(SRCDIR)/input.c\
	$(SRCDIR)/utils.c\
	$(SRCDIR)/fdf_color.c\
	$(SRCDIR)/keycodes.c

OBJ=$(SRCDIR)/fdf_main.o\
	$(SRCDIR)/fdf_tools.o\
	$(SRCDIR)/fdf_draw.o\
	$(SRCDIR)/fdf_input_handler.o\
	$(SRCDIR)/input.o\
	$(SRCDIR)/utils.o\
	$(SRCDIR)/fdf_color.o\
	$(SRCDIR)/keycodes.o

NAME=fdf

all: $(NAME)

$(NAME): $(OBJ)
	make re -C $(LIBDIR)/libft
	cp $(LIBDIR)/libft/libft.a $(LIBDIR)/
	$(CC) $(LDFLAGS) -o $@ $^

$(LIBDIR)/%.o:$(HEADDIR)/%.h

$(LIBDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean fclean

clean :
	rm -rf $(LIBDIR)/*.o
	rm -rf $(SRCDIR)/*.o
	make clean -C $(LIBDIR)/libft

fclean : clean
	rm -rf $(NAME)
	make fclean -C $(LIBDIR)/libft

re: fclean all
