/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 14:31:26 by krioliin       #+#    #+#                */
/*   Updated: 2019/05/28 14:31:26 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

bool	check_flags(char **input, s_format_spec *format_specifier)
{
	if (**input == '-')
		format_specifier->flag_minus = true;
	else if (**input == '+')
		format_specifier->flag_plus = true;
	else if (**input == ' ')
		format_specifier->flag_space = true;
	else if (**input == '0')
		format_specifier->flag_zero = true;
	else if (**input == '#')
		format_specifier->flag_hash = true;
	else
		return (false);
	(*input)++;
	return (true);
}

bool	check_precision(char **input, s_format_spec *format_specifier)
{
	format_specifier->precision = 0;
	if ((*input)[0] == '.')
		(*input)++;
	else
		return (false);
	if (**input == '*')
	{
		format_specifier->precision = -1;
		(*input)++;
	}
	else if (ft_isdigit(**input))
	{
		format_specifier->precision = ft_atoi(*input);
		(*input) += ft_count_digit(format_specifier->precision);
	}
	return (format_specifier->precision);
}

bool	check_width_filed(char **input, s_format_spec *format_specifier)
{
	format_specifier->width = 0;
	if (**input == '*')
	{
		format_specifier->width = -1;
		(*input)++;
	}
	else if (ft_isdigit(**input))
	{
		format_specifier->width = ft_atoi(*input);
		(*input) += ft_count_digit(format_specifier->width);
	}
	return (format_specifier->width);
}

bool	check_length_filed(char **input, s_format_spec *format_specifier)
{
	if (**input == 'h' && (*input)[1] == 'h')
		format_specifier->len_hh = true;
	else if (**input == 'h')
		format_specifier->len_h = true;
	else if (**input == 'l' && (*input)[1] == 'l')
		format_specifier->len_ll = true;
	else if (**input == 'l')
		format_specifier->len_l = true;
	else if (**input == 'L')
		format_specifier->len_L = true;
	else
		return (false);
	if (format_specifier->len_hh || format_specifier->len_ll)
		(*input)++;
	(*input)++;
	return (true);
}

bool	check_type(char **input, s_format_spec *format_specifier)
{
	if (ft_strchr("cspdiouxX", **input))
		format_specifier->type = **input;
	else
		return (false);
	return (true);
}

bool	init_specifier(char **input, s_format_spec *specifier, s_output *out)
{
	check_flags(input, specifier);
	check_width_filed(input, specifier);
	check_precision(input, specifier);
	check_length_filed(input, specifier);
	return (check_type(input, specifier));
}

bool	read_input(char *input, va_list arg_ptr, s_output *out)
{
	s_format_spec	specifier;
	s_placeholder	result;
	int				percent_pos;
	char			*temp;

	while (copy_until(input, &out->str, '%', out) == COMPLITED)
	{
		percent_pos = findchr(input, '%') + 1;
		input += percent_pos;
		if (init_specifier(&input, &specifier, out) == false)
		{
			input -= percent_pos - 1;
			temp = out->str;
			out->str = ft_strjoin(out->str, "%");
			ft_strdel(&temp);
		}
		printf("input 1: %s\n", input);
		printf("str->out 1: %s\n", out->str);
	}
	printf("type: %c\n", specifier.type);
	printf("flag_space: %c\n", specifier.flag_space);
	printf("width: %zd\n", specifier.width);
	printf("precision: %zu\n", specifier.precision);
	printf("len_h: %zu\n", specifier.len_h);
	return (FINISHED);
}

int		ft_printf(const char *format, ...)
{
	va_list		arg_ptr;
	s_output	output;
	char		*input;

	va_start(arg_ptr, format);
	input = ft_strdup(format);
	output.size = 0;
	output.str = ft_strnew(0);
	if (read_input(input, arg_ptr, &output) == FINISHED)
	{
		printf("out->str: %s\n", output.str);
		ft_strdel(&output.str);
	}
	ft_strdel(&input);
	return (0);
}

int		main()
{
	int num_fife;

	num_fife = 5;
	printf("|%d|\n", num_fife);
	ft_printf("Hello %010.10 i am persent");
/*	printf("%.5s = %0*.*f\n", "value trash", 10, 5, 3.1415926535);
	printf("%.5s = %010.*f\n", "value trash", 5, 3.1415926535);
	printf("%.5c = %010.*f\n", 'V', 5, 3.1415926535);
	printf("|%d| = %010.*f\n", num_fife, 5, 3.1415926535);
	printf("|%d|\n", num_fife);*/
	return (0);
}