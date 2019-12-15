# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azineddi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/08 11:13:05 by azineddi          #+#    #+#              #
#    Updated: 2019/10/26 21:05:18 by azineddi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

srcs_files = ft_print.c ft_print_capx.c ft_print_float.c ft_print_o.c ft_print_six.c ft_print_u.c ft_print_x_norme.c ft_print_2d.c ft_print_capx_norme.c ft_print_float_norme.c ft_print_o_norme.c ft_print_three.c ft_print_u_norme.c ft_print_2d_norme.c ft_print_five.c ft_print_four.c ft_print_one.c ft_print_two.c ft_print_x.c ../libft/ft_atoi.c ../libft/ft_isalpha.c ../libft/ft_isdigit.c ../libft/ft_putchar.c ../libft/ft_putnbr.c ../libft/ft_putstr.c ../libft/ft_strchr.c ../libft/ft_strdup.c ../libft/ft_strlen.c ../libft/ft_strnew.c ../libft/ft_strstr.c ../libft/ft_toupper.c

srcs_dir=srcs

headers = includes/ft_printf_header.h

objs_dir = objs


objs = $(addprefix $(objs_dir)/,$(srcs_files:.c=.o))

all : $(NAME)

$(NAME) : $(objs)
	make -C libft/
	ar rc $(NAME) $(objs)

$(objs): $(objs_dir)/%.o : $(srcs_dir)/%.c $(headers) | $(objs_dir)
		gcc -Wall -Wextra -Werror -c $< -o $@ -I includes/

$(objs_dir):
	mkdir $(objs_dir)

clean:
	make -C libft clean
	rm -rf $(objs)

fclean:clean
	make -C libft fclean
	rm -rf $(NAME)

re : fclean all
	make -C libft re
