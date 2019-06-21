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

	spec_res.str = NULL;
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

void	test_float_flags()
{
	ft_printf("Test  float flags\n");

	  printf("Origin 1:%+10.4f|\n", 42.42);
ft_printf("Mine pf1:%+10.4f|\n\n", 42.42);

      printf("Origin 5:% 10.4f|\n", 42.42);
 ft_printf("Mine pf5:% 10.4f|\n\n", 42.42);

     printf("Origin 2:%+10.4f|\n", -42.42);
ft_printf("Mine pf2:%+10.4f|\n\n", -42.42);

     printf("Origin 3:%+10.4f|\n", -42.42);
	ft_printf("Mine pf3:%+10.4f|\n\n", -42.42);

	 printf("Origin 4:% -010.4f|\n", 42.42);
ft_printf("Mine pf4:% -010.4f|\n\n", 42.42);
ft_printf("Mine pf4:% -10.4f|\n\n", 42.42);
}

void	test_float_high_precition()
{
	float	fnum = 3.14199265359;
	float	flnum = 3.99999999999;
	float	f42num = 4242.1231231234242424242424242424210101010;
	float	f32num = 4242.99999999999;

	printf("Number :4242.14199060359\n");
	printf("Origin :%010.30f|\n", f42num);
	ft_printf("Mine pf:%010.30f|\n\n", f42num);

	printf("Origin :%010.20f|\n", f42num);
	ft_printf("Mine pf:%010.20f|\n\n", f42num);

	printf("Number :4242.14199060359\n");
	printf("Origin :%010.18f|\n", f42num);
	ft_printf("Mine pf:%010.18f|\n\n", f42num);
}

void	test_float_mult_flags()
{
	ft_printf("Test multiple float flags\n\n");

		  printf("Origin 1:%+010.4f|\n", 42.42);
	ft_printf("Mine pf1:%+010.4f|\n\n|", 42.42);

	      printf("Origin 5:% 010.4f|\n", 42.42);
	 ft_printf("Mine pf5:% 010.4f|\n\n", 42.42);

	     printf("Origin 2:%+010.4f|\n", -42.42);
	ft_printf("Mine pf2:%+010.4f|\n\n", -42.42);

	     printf("Origin 3:%+010.4f|\n", -42.42);
	ft_printf("Mine pf3:%+010.4f|\n\n", -42.42);

		 printf("Origin 4:% -010.4f|\n", 42.42);
	ft_printf("Mine pf4:% -010.4f|\n\n", 42.42);
}

void	test_float()
{
	float	fnum = 3.14199265359;
	float	flnum = 3.99999999999;
	float	f42num = 4242.4242424242424242;
	float	f32num = 4242.99999999999;

	test_float_high_precition();

//	printf("Origin :%010.f|\n", f42num);
//	ft_printf("Mine pf:%010.f|\n\n", f42num);
	
//	printf("Origin :%+02.1f|\n", (float)4);
//	ft_printf("Mine pf:%+02.1f|\n\n", (float)4);

//	printf("Number :3.14199265359\n");
//	printf("Origin :%f|\n", fnum);
//	ft_printf("Mine pf:%f|\n\n", fnum);

//	printf("Number :3.99999999999\n");
//	printf("Origin :%.19f|\n", flnum);
//	ft_printf("Mine pf:%.19f|\n\n", flnum);
//	test_float_flags();
//	test_float_mult_flags();
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
	test_float();
//	printf("Number :4242.14199060359\n");
//	printf("Origin :%10f|\n", (float)-0.0/0.0);
//	printf("Origin :%-+10f|\n",  -0.0);
//	ft_printf("Mine pf:%-+10.4d|\n", );


/*	printf("Origin :%+-10.4f|\n", -42.42);
	ft_printf("Mine pf:%+-10.4f|\n", -42.42);


	printf("Origin :%-10.4f|\n", -42.42);
	ft_printf("Mine pf:%-10.4f|\n", -42.42);*/
//	test_float();
//	test_int();
	return (0);
}