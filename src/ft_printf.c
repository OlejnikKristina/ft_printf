/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 14:31:26 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/26 20:40:21 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	init_specifier(char **input, s_format_spec *specifier, s_output *out,
va_list arg_ptr)
{
	bool	dot_zero;

	check_flags(input, specifier);
	check_width_filed(input, specifier, arg_ptr);
	dot_zero = check_precision(input, specifier, arg_ptr);
	check_length_filed(input, specifier);
	return (check_type(input, specifier, dot_zero));
}

int		proccesing_specifier(s_format_spec *specifier, s_placeholder *spec_res,
va_list arg_ptr)
{
	if (specifier->precision == STAR)
	{
		specifier->precision = (int)va_arg(arg_ptr, int);
		if (specifier->precision == 0 && specifier->type == 's')
			specifier->precision = DOT_ZERO;
		else if (specifier->precision < 0)
			specifier->precision = 0;
	}
	if (ft_strchr("diouxX", specifier->type))
		integer(specifier, spec_res, arg_ptr);
	if (specifier->type == 's')
		type_s(specifier, spec_res, arg_ptr);
	if (specifier->type == 'p')
		type_p(specifier, spec_res, arg_ptr);
	if (specifier->type == 'f')
		type_f(specifier, spec_res, arg_ptr);
	if (specifier->type == '%')
		type_percent(specifier, spec_res, arg_ptr);
	if (specifier->type == 'c')
		if (type_c(specifier, spec_res, arg_ptr) == UNPR_NULL)
			return (UNPR_NULL);
	return (1);
}

int		unprintable_chr(s_format_spec *s, s_placeholder *result, s_output *out)
{
	char	fill_chr;

	fill_chr = s->flag_zero ? '0' : ' ';
	out->usage += ft_strlen(out->str);
	out->usage += 1;
	ft_putstr(out->str);
	ft_strdel(&out->str);
	out->str = ft_strnew(0);
	while (1 < s->width && !s->flag_minus)
	{
		write(1, &fill_chr, 1);
		s->width -= 1;
		out->usage += 1;
	}
	write(1, "", 1);
	while (1 < s->width && s->flag_minus)
	{
		write(1, &fill_chr, 1);
		s->width -= 1;
		out->usage += 1;
	}
	return (0);
}

bool	read_input(char *input, va_list arg_ptr, s_output *out)
{
	s_format_spec	specifier;
	s_placeholder	result;
	char			*holder;

	result.str = NULL;
	while (copy_until(input, out, '%') != FINISHED)
	{
		ft_bzero((void *)&specifier, sizeof(specifier));
		input = ft_strchr(input, '%') + 1;
		holder = input;
		if (init_specifier(&input, &specifier, out, arg_ptr) == false)
			input = holder;
		else
		{
			if (proccesing_specifier(&specifier, &result, arg_ptr) == UNPR_NULL)
				unprintable_chr(&specifier, &result, out);
			else
			{
				out->str = ft_superjoin(&out->str, result.str);
				ft_strdel(&result.str);
			}
		}
	}
	(result.str) ? ft_strdel(&result.str) : 1;
	return (FINISHED);
}

int		ft_printf(const char *format, ...)
{
	va_list		arg_ptr;
	s_output	out;
	char		*input;

	va_start(arg_ptr, format);
	input = ft_strdup(format);
	out.usage = 0;
	out.str = ft_strnew(0);
	if (read_input(input, arg_ptr, &out) == FINISHED)
		if (out.str)
		{
			ft_putstr(out.str);
			out.usage += ft_strlen(out.str);
			ft_strdel(&out.str);
		}
	ft_strdel(&input);
	return (out.usage);
}
