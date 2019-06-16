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

bool	type_p(s_format_spec *specifier, s_placeholder *result, va_list arg_ptr);

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

bool	proccesing_specifier(s_format_spec *specifier, s_placeholder *spec_res,
 va_list arg_ptr)
{
	return (
		(specifier->type == 'd' && integer(specifier, spec_res, arg_ptr)) ||
		(specifier->type == 'i' && integer(specifier, spec_res, arg_ptr)) ||
		(specifier->type == 'u' && integer(specifier, spec_res, arg_ptr)) ||
		(specifier->type == 'o' && integer(specifier, spec_res, arg_ptr)) ||
		(specifier->type == 'x' && integer(specifier, spec_res, arg_ptr)) ||
		(specifier->type == 'X' && integer(specifier, spec_res, arg_ptr)) ||
		(specifier->type == 's' && type_s(specifier, spec_res, arg_ptr)) ||
		(specifier->type == 'p' && type_p(specifier, spec_res, arg_ptr)) ||
		(specifier->type == 'c' && type_c(specifier, spec_res, arg_ptr))
	);
}

bool	read_input(char *input, va_list arg_ptr, s_output *out)
{
	s_format_spec	specifier;
	s_placeholder	spec_res;
	char			*holder;

	ft_bzero((void *)&specifier, sizeof(specifier));
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
			proccesing_specifier(&specifier, &spec_res, arg_ptr);
			out->str = ft_superjoin(&out->str, spec_res.str);
		}
	}
	printf("%s", out->str);
	ft_strdel(&spec_res.str);
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
		ft_strdel(&output.str);
	}
	ft_strdel(&input);
	return (0);
}

bool	type_p(s_format_spec *specifier, s_placeholder *result, va_list arg_ptr)
{
	int64_t	address;

	address = va_arg(arg_ptr, long long);
	result->str = ft_strdup("0x");
	result->str = ft_superjoin(&result->str, itoa_base64(address, 16, 0));
	return (true);
}

int		main()
{
	char	**pp;
	char	*p = "hello";
	int		*pi;
	int		num = 31;

	pi = &num;
	printf("%10p\n", p);
	ft_printf("%10p\n", p);
//	printf("%p\n", pi);
//	printf("address(?): %s\n", itoa_base64((int64_t)p, 16, 0));
	printf(" \n");
	return (0);
}