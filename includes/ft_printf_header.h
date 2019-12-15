/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_header.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azineddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 20:59:44 by azineddi          #+#    #+#             */
/*   Updated: 2019/10/26 21:25:52 by azineddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_HEADER_H
# define FT_PRINTF_HEADER_H
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include "../libft/libft.h"

typedef	struct		s_format
{
	char			*flags;
	int				field_width;
	int				precision;
	char			*conversion_flags;
	char			conversion;
	int				i;
	int				len_read;
}					t_format;

typedef	struct		s_var
{
	int				len;
	int				read_len;
	int				zeros_to_print;
	int				sign_char;
	int				spaces_to_print;
	int				print_minus_check;
	int				print_plus_check;
	int				print_espace_check;
}					t_var;

char				*grep_flags(char **format);
int					grep_field_width(char **format);
int					grep_precision(char **format);
char				*grep_conversion_flags(char **format);
char				grep_conversion(char **format);
void				grep_information(char *format, t_format *strc);
void				init_structure_each_percent(char *format, t_format *strc);
char				*check_str(char *str);
void				ft_printubase(uintmax_t num
					, unsigned int base, int is_lower);
int					print_decimal_to_hex(uintmax_t n);
int					printing_maestro(va_list ap, t_format *strc);
int					ft_printf(const char *restrict format, ...);
int					ft_printf_d(intmax_t n, t_format *strc);
int					ft_printf_o(uintmax_t n, t_format *strc);
int					ft_printf_u(uintmax_t n, t_format *strc);
int					ft_printf_x(uintmax_t n, t_format *strc);
int					print_decimal_to_octal(uintmax_t n);
int					ft_printf_capx(uintmax_t n, t_format *strc);
void				ft_initialize_to_zero_capx(t_var *var_d);
void				count_len_capx(uintmax_t n, t_var *var_d, t_format *strc);
void				check_flags_one_char_capx(uintmax_t n, t_format *strc
					, t_var *var_d);
void				calculate_zeros_to_print_capx(t_format *strc, t_var *var_d);
void				calculate_spaces_to_print_capx(t_format *strc
					, t_var *var_d);
void				ft_print_without_minus_capx(uintmax_t n, t_format *strc
					, t_var *var_d);
void				ft_print_result_w_minus_capx(uintmax_t n, t_format *strc
					, t_var *var_d);
int					ft_countnumber_d(uintmax_t n);
void				ft_initialize_to_zero_d(t_var *var_d);
void				count_len_d(intmax_t n, t_var *var_d, t_format *strc);
void				check_flags_one_charachter_d(intmax_t n, t_format *strc
					, t_var *var_d);
void				calculate_zeros_to_print_d(t_format *strc, t_var *var_d);
void				calculate_spaces_to_print_d(t_format *strc, t_var *var_d);
void				ft_print_without_minus_d(intmax_t n, t_format *strc
					, t_var *var_d);
void				ft_print_result_with_minus_d(intmax_t n, t_format *strc
					, t_var *var_d);
void				ft_initialize_to_zero_x(t_var *var_d);
void				count_len_x(uintmax_t n, t_var *var_d, t_format *strc);
void				check_flags_one_charachter_x(uintmax_t n, t_format *strc
					, t_var *var_d);
void				calculate_zeros_to_print_x(t_format *strc, t_var *var_d);
void				calculate_spaces_to_print_x(t_format *strc, t_var *var_d);
void				ft_print_without_minus_x(uintmax_t n, t_format *strc
					, t_var *var_d);
void				ft_print_result_with_minus_x(uintmax_t n, t_format *strc
					, t_var *var_d);
void				ft_initialize_to_zero_o(t_var *var_d);
void				count_len_o(uintmax_t n, t_var *var_d, t_format *strc);
void				check_flags_one_charachter_o(uintmax_t n, t_format *strc
					, t_var *var_d);
void				calculate_zeros_to_print_o(t_format *strc, t_var *var_d);
void				calculate_spaces_to_print_o(t_format *strc, t_var *var_d);
void				ft_print_without_minus_o(uintmax_t n, t_format *strc
					, t_var *var_d);
void				ft_print_result_with_minus_o(uintmax_t n
					, t_format *strc, t_var *var_d);
int					ft_countnumber_u(uintmax_t n);
void				ft_initialize_to_zero_u(t_var *var_d);
void				count_len_u(uintmax_t n, t_var *var_d, t_format *strc);
void				check_flags_one_charachter_u(t_format *strc);
void				calculate_zeros_to_print_u(t_format *strc, t_var *var_d);
void				calculate_spaces_to_print_u(t_format *strc, t_var *var_d);
void				ft_print_without_minus_u(uintmax_t n, t_format *strc
					, t_var *var_d);
void				ft_print_result_with_minus_u(uintmax_t n, t_format *strc
					, t_var *var_d);
int					ft_countnumber_f(double n);
void				ft_initialize_to_zero_f(t_var *var_d);
void				count_len_f(double n, t_var *var_d, t_format *strc);
void				check_flags_one_charachter_f(double n, t_format *strc
					, t_var *var_d);
void				calculate_zeros_to_print_f(t_format *strc, t_var *var_d);
void				calculate_spaces_to_print_f(t_format *strc, t_var *var_d);
void				ft_print_without_minus_f(double n, t_format *strc);
void				ft_print_result_with_minus_f(double n, t_format *strc);
int					ft_printf_float(double n, t_format *strc);
int					ft_printf_core_norme3(t_format *st);
void				ft_initialise_to_zero(t_format *st);
void				ft_printf_free(t_format *st);
void				ft_printf_core_norme4(const char *restrict format
					, t_format *st);
void				calculate_norme(t_format *strc, t_var *var_d);
int					ft_printf_string(char *str_s, t_format *strc);
int					ft_printf_pointer(long ptr, t_format *strc);
int					ft_printf_core_norme(t_format *st);
int					print_maestro_s(t_format *strc, char *str_s, va_list ap);
int					print_maestro_p(t_format *strc, long ptr, va_list ap);
int					print_maestro_d(t_format *strc, uintmax_t num, va_list ap);
int					print_maestro_o(t_format *strc, uintmax_t num, va_list ap);
int					print_maestro_u(t_format *strc, uintmax_t num, va_list ap);
int					print_maestro_c(t_format *strc, char arg, va_list ap);
#endif
