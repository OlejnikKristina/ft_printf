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
//	if (ft_strchr("diouxX", specifier->type))
//		integer(specifier, spec_res, arg_ptr);
	return (
		(specifier->type == 'd' && integer(specifier, spec_res, arg_ptr)) ||
		(specifier->type == 'i' && integer(specifier, spec_res, arg_ptr)) ||
		(specifier->type == 'u' && integer(specifier, spec_res, arg_ptr)) ||
		(specifier->type == 'o' && integer(specifier, spec_res, arg_ptr)) ||
		(specifier->type == 'x' && integer(specifier, spec_res, arg_ptr)) ||
		(specifier->type == 'X' && integer(specifier, spec_res, arg_ptr)) ||
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

void	test_float()
{
	float	fnum = 3.14199265359;
	float	flnum = 3.99999999999;
	float	f42num = 4242.14199060359;
	float	f32num = 4242.99999999999;

	printf("Number :4242.14199060359\n");
	printf("Origin :%.30f|\n", f42num);
	ft_printf("Mine pf:%.30f|\n\n", f42num);

	printf("Origin :%.25f|\n", f42num);
	ft_printf("Mine pf:%.25f|\n\n", f42num);

	
	printf("Origin :%.20f|\n", f42num);
	ft_printf("Mine pf:%.20f|\n\n", f42num);
	
	printf("Origin :%.19f|\n", f42num);
	ft_printf("Mine pf:%.19f|\n\n", f42num);

/*

	printf("Number :3.14199265359\n");
	printf("Origin :%f|\n", fnum);
	ft_printf("Mine pf:%f|\n\n", fnum);

		printf("Number :3.99999999999\n");
	printf("Origin :%.19f|\n", flnum);
	ft_printf("Mine pf:%.19f|\n\n", flnum);*/
}

int		main()
{
	char	**pp;
	char	*p = "hello";
	int		*pi;
	int		num = 31;
	float	nbr = 3.14199265359;
	float	flnum = 3.99999999999;
	float	f42num = -4242.14199060359;
	float	f32num = 4242.99999999999;

/*	printf("Org1:%014f|\n", f42num);
	printf("Org2:%-14f|\n", f42num);
	printf("Org3:% 12f|\n", f42num);
	printf("Org4:%12f|\n", f42num);
	printf("Number :3.99999999999\n");
	printf("Origin :%.19f|\n", flnum);
	ft_printf("Mine pf:%.19f|\n\n", flnum);*/

	printf("Number :4242.14199060359\n");
	printf("Origin :%+15.1f|\n", f42num);
	printf("Origin :%-15.1f|\n", f42num);
	ft_printf("Mine pf:%-15.1f|\n\n", f42num);
/*
	printf("Origin :%020.3f|\n", f42num);
	ft_printf("Mine pf:%020.3f|\n\n", f42num);

	printf("Origin :%-10.1f|\n", f42num);
	ft_printf("Mine pf:%-10.1f|\n\n", f42num);*/

//	printf("Origin :%.2f|\n", f42num);
//	ft_printf("Mine pf:%.2f|\n\n", f42num);
	
//	printf("Origin :%.1f|\n", f42num);
//	ft_printf("Mine pf:%.1f|\n\n", f42num);
/*
	printf("Number :3.14199265359\n");
	printf("Origin :%f|\n", fnum);
	ft_printf("Mine pf:%f|\n\n", fnum);*/

	return (0);
}