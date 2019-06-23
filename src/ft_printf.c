/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 14:31:26 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/23 16:42:12 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	init_specifier(char **input, s_format_spec *specifier, s_output *out)
{
	bool	feature;

	feature = 0;
	check_flags(input, specifier);
	check_width_filed(input, specifier);
	feature = check_precision(input, specifier);
	check_length_filed(input, specifier);
	return (check_type(input, specifier, feature));
}
/*
return (
		(specifier->type == 's' && type_s(specifier, spec_res, arg_ptr)) ||
		(specifier->type == 'p' && type_p(specifier, spec_res, arg_ptr)) ||
		(specifier->type == 'f' && type_f(specifier, spec_res, arg_ptr)) ||
		(specifier->type == '%' && type_percent(specifier, spec_res, arg_ptr)) ||
		(specifier->type == 'c' && type_c(specifier, spec_res, arg_ptr)));*/

bool		proccesing_specifier(s_format_spec *specifier, s_placeholder *spec_res,
va_list arg_ptr)
{
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
		if (type_c(specifier, spec_res, arg_ptr) == 0)
			return (0);
	return (1);
}

int		huj(s_format_spec *s)
{
	char	fill_chr;

	(s->flag_zero) ?
	(fill_chr = '0') :
	(fill_chr = ' ');
	while (1 < s->width && !s->flag_minus)
	{
		write(1, &fill_chr, 1);
		s->width -= 1;
	}
	write(1, "", 1);
	while (1 < s->width && s->flag_minus)
	{
		write(1, &fill_chr, 1);
		s->width -= 1;
	}
	return (0);
}

bool	read_input(char *input, va_list arg_ptr, s_output *out)
{
	s_format_spec	specifier;
	s_placeholder	result;
	char			*holder;
	int				i;

	result.str = NULL;
	specifier.usage = 0;
	while (copy_until(input, out, '%') != FINISHED)
	{
		input = ft_strchr(input, '%') + 1;
		holder = input;
		if (init_specifier(&input, &specifier, out) == false)
		{
			out->str = ft_superjoin(&out->str, "%");
			input = holder;
		}
		else
		{
			if (proccesing_specifier(&specifier, &result, arg_ptr) == false)
			{
				ft_putstr(out->str);
				ft_strdel(&out->str);
				huj(&specifier);
				out->str = ft_strnew(0);
			}
			else
				out->str = ft_superjoin(&out->str, result.str);
		}
		
	}
	if (out->str)
		ft_putstr(out->str);
	if (out->str)
		out->usage = ft_strlen(out->str) + specifier.usage;
	if (result.str)
		ft_strdel(&result.str);
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
			ft_strdel(&out.str);
	ft_strdel(&input);
	return (out.usage);
}
/*
	result.str = NULL;
	ft_bzero((void *)&specifier, sizeof(specifier));
	while (copy_until(input, out, '%') != FINISHED)
	{
		specifier.usage = 0;
		input = ft_strchr(input, '%') + 1;
		holder = input;
		if (init_specifier(&input, &specifier, out) == false)
		{
			out->str = ft_superjoin(&out->str, "%");
			out->usage += ft_strlen(out->str);
			input = holder;
		}
		else
		{
			proccesing_specifier(&specifier, &result, arg_ptr);
			out->usage += ft_strlen(out->str);
			temp = out->str;
			out->str = ft_strnew(out->usage + specifier.usage);
			ft_memcpy((void *)out->str, temp, out->usage);
			//ft_memcpy((void *)&out->str[out->usage], &result.str[0], specifier.usage);

			ft_memcpy((void *)&out->str[out->usage], (void *)"\0\0", 1);
			out->str[out->usage + 1] = '\0';
			ft_strdel(&temp);
			//out->str = ft_superjoin(&out->str, result.str);
		}
	}
*/