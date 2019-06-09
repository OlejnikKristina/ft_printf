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

bool	init_specifier(char **input, s_format_spec *specifier, s_output *out)
{
	check_flags(input, specifier);
	check_width_filed(input, specifier);
	check_precision(input, specifier);
	check_length_filed(input, specifier);
	return (check_type(input, specifier));
}

bool	proccesing_specifier(s_format_spec *specifier, s_placeholder *spec_res,
 va_list arg_ptr)
{
	return (
		(specifier->type == 'd' && integer(specifier, spec_res, arg_ptr)) ||
		(specifier->type == 'u' && integer(specifier, spec_res, arg_ptr))
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
/*
void	pf_test_u()
{
	unsigned long		REG_UL = 10446744073709551610;
	unsigned long long	MAX_UNSLL = 18446744073709551610;

	printf("   printf:%8.4hhu type\n", 65535);
	ft_printf("ft_printf:%8.4hhu type\n\n", 65535);

		printf("   printf:%8.4hu type\n", 6553);
	ft_printf("ft_printf:%8.4hu type\n\n", 6553);

	printf("   printf:%u type\n", 4294967299);	
	ft_printf("ft_printf:%u type\n\n", 4294967299);

	printf("   printf:%8.4lu type\n", REG_UL);
	ft_printf("ft_printf:%8.4lu type\n\n", REG_UL);

	printf("   printf:%8.4llu type\n", MAX_UNSLL);		
	ft_printf("ft_printf:%8.4llu type\n\n", MAX_UNSLL);
}*/

int		main()
{
	long				REG_L =  -4200083648;
	long long 			REG_LL = -9223372036854775800;
	long long 			MINIM_LL = -9223372036854775800;
	long long 			MAX_LL = 9223372036854775807;

//	pf_test_u();

	printf("   printf:%42.20ld type\n", REG_L);
	ft_printf("ft_printf:%42.20d type\n", REG_L);

	printf("   printf:%+20.12lld type\n", REG_LL);
	ft_printf("ft_printf:%+20.12lld type\n", REG_LL);

	printf("   printf:%4.8d type\n", -42);
	ft_printf("ft_printf:%4.8d type\n", -42);
	return (0);
}