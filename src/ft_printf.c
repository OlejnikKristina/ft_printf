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
	if (ft_strchr("diouxX", specifier->type))
		integer(specifier, spec_res, arg_ptr);
	return (
		(specifier->type == 's' && type_s(specifier, spec_res, arg_ptr)) ||
		(specifier->type == 'p' && type_p(specifier, spec_res, arg_ptr)) ||
		(specifier->type == 'f' && type_f(specifier, spec_res, arg_ptr)) ||
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
	ft_putstr(out->str);
	if (spec_res.str)
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
//integer.c Norme
//type_s.c Norme

void	test_float()
{
	float	fnum = 3.14199265359;
	float	flnum = 3.99999999999;
	float	f42num = 4242.14199060359;
	float	f32num = 4242.99999999999;
//0/width/precidion
//0/width/prec=0
//
	printf("Number :4242.14199060359\n");
	printf("Origin :%010.3f|\n", f42num);
	ft_printf("Mine pf:%010.3f|\n\n", f42num);

	printf("Origin :%010.f|\n", f42num);
	ft_printf("Mine pf:%010.f|\n\n", f42num);

	
	printf("Origin :%010.0f|\n", f42num);
	ft_printf("Mine pf:%010.0f|\n\n", f42num);
	
	printf("Origin :%+02.1f|\n", 4);
	ft_printf("Mine pf:%+02.1f|\n\n", 4);

/*

	printf("Number :3.14199265359\n");
	printf("Origin :%f|\n", fnum);
	ft_printf("Mine pf:%f|\n\n", fnum);

		printf("Number :3.99999999999\n");
	printf("Origin :%.19f|\n", flnum);
	ft_printf("Mine pf:%.19f|\n\n", flnum);*/
}

void	test_int()
{
	printf("Orig pf:%015.1d|\n", -42);
	ft_printf("Mine pf:%015.1d|\n\n", -42);

	printf("Orig pf:%+015.1d|\n", 42);
	ft_printf("Mine pf:%+015.1d|\n\n", 42);

	printf("Orig pf:%+d|\n", 42);
	ft_printf("Mine pf:%+d|\n\n", 42);

	printf("Orig pf:%+15d|\n", -42);
	ft_printf("Mine pf:%+15d|\n", -42);

	printf("Orig pf:%+015d|\n", 42);
	ft_printf("Mine pf:%+015d|\n\n", 42);

	printf("Orig pf:%+015d|\n", -42);
	ft_printf("Mine pf:%+015d|\n\n", -42);

	printf("Orig pf:%015d|\n", 42);
	ft_printf("Mine pf:%015d|\n", 42);

	printf("Orig pf:%d|\n", 42);
	ft_printf("Mine pf:%d|\n", 42);

	printf("Orig pf:%d|\n", -42);
	ft_printf("Mine pf:%d|\n",-42);
}

int		main()
{
		printf("Origin :%010c|\n", 42);
	ft_printf("Mine pf:%010c|\n\n", 42);
//	test_int();
	return (0);
}