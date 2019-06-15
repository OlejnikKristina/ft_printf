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
		(specifier->type == 'i' && integer(specifier, spec_res, arg_ptr)) ||
		(specifier->type == 'u' && integer(specifier, spec_res, arg_ptr))
	//	(specifier->type == 'o' && type_oxX(specifier, spec_res, arg_ptr)) ||
	//	(specifier->type == 'x' && type_oxX(specifier, spec_res, arg_ptr)) ||
	//	(specifier->type == 'X' && type_oxX(specifier, spec_res, arg_ptr))
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

char *ft_strrev(char str_rev[])
{
	unsigned	i;
	unsigned	end_str;
	char		temp;

	i = 0;
	end_str = ft_strlen(str_rev);
	end_str--;
	while (i <= (end_str + 1) / 2)
	{
		temp = str_rev[i];
		str_rev[i] = str_rev[end_str];
		str_rev[end_str] = temp;
		end_str--;
		i++;
	}
	str_rev[ft_strlen(str_rev)] = '\0';
	return (NULL);
}

char	*change_base(long value, unsigned short base)
{
	unsigned	i;
	unsigned	mod;
	char		num[21];
	char		*result;
	char		*letters;
	
	i = 0;
	letters = (1) ? ft_strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ") :
	ft_strdup("abcdefghijklmnopqrstuvwxyz");
	ft_memset((void *)num, '\0', 21);
	while(i < 20)
	{
		if (value <= 1)
		{
			mod = value % base;
			if (0 < mod)
				num[i] = '1';
			break ;
		}
		else
		{
			mod = value % base;
			if (9 < mod)
				num[i] = letters[mod - 10];
			else
				num[i] = mod + '0';
		}
		value /= base;
		i++;
	}
	ft_strrev(num);
	result = ft_strdup(num);
	
	return (result);
}

char	*ft_itoa_base(long value, unsigned short base, bool uppercase)
{
	char		*letters;
	char		*result;

	if (value == 0)
		return (ft_strdup("0"));
	result = change_base(value, base);
	return (change_base(value, base));
}

int		main()
{
	long				REG_L =  -4200083648;
	long long			REG_LL = -9223372036854775800;
	long long			MINIM_LL = -9223372036854775800;
	long long			MAX_LL = 9223372036854775807;
	char				*str;
	char				*str1;
	char				*str2;

//	test_u();
/*
	printf("   printf:%42.20ld type\n", REG_L);
	ft_printf("ft_printf:%42.20ld type\n", REG_L);

	printf("   printf:%+20.12lld type\n", REG_LL);
	ft_printf("ft_printf:%+20.12lld type\n\n", REG_LL);

	printf("   printf:%+20.20lld type\n", MINIM_LL);
	ft_printf("ft_printf:%+20.20lld type\n\n", MINIM_LL);*/

//	printf("   printf:%20.20lld type\n", MAX_LL);
//	ft_printf("ft_printf:%20.20lld type\n\n", MAX_LL);

/*	printf("   printf:%#10.o type\n", 9);
	printf("   printf:%#10.o type\n", 9);
	printf("   printf:%#10.5X type\n", 42);
	ft_printf("ft_printf:%#10.5i type\n", -42);*/

	str =  ft_itoa_base(42, 2, 1);
	printf("fr: %s\n", str);
	ft_strdel(&str);

	str =  ft_itoa_base(1, 11, 1);
	printf("fr: %s\n", str);
	ft_strdel(&str);

	str =  ft_itoa_base(142, 11, 1);
	printf("fr: %s\n", str);
	ft_strdel(&str);

	str =  ft_itoa_base(1, 2, 1);
	printf("fr: %s\n", str);
	ft_strdel(&str);

	str = ft_itoa_base(142, 13, 1);
	printf("fr: %s\n", str);
	ft_strdel(&str);

	str1 = ft_itoa_base(142, 14, 1);
	printf("fr: %s\n", str);
	ft_strdel(&str1);

	str2 = ft_itoa_base(142, 15, 1);
	printf("fr: %s\n", str);
	ft_strdel(&str2);

	return (0);
}