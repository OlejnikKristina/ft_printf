/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_pf.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 14:31:26 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/23 21:45:10 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

/*

int_width(specifier, result);
	if (specifier->precision)
		result->str = ft_strsub((char const *)line, 0, specifier->precision);
	 else
		result->str = ft_strdup(line);
	// result->str = ft_superjoin(&result->str, line);
	// if (specifier->precision)
	// 	result->str[specifier->precision] = '\0';
	// int_flag_minus(specifier, result);*/


static void	test_o()
{/*
	printf("%10s Test width, presition\n", "=D");

		printf("%10o\n", 0);
	ft_printf("%10o\n\n", 0);

		printf("%10o\n", -42);
	ft_printf("%10o\n\n", -42);

		printf("%.10o\n", 4242);
	ft_printf("%.10o\n\n", 4242);

		printf("%7.7o\n", 3101);
	ft_printf("%7.7o\n\n", 3101);

	printf("%10s Test flags\n", "=D");

	printf("%-10o|\n", 0);
	ft_printf("%-10o|\n\n", 0);

	printf("%10o\n", -42);
	ft_printf("%10o\n\n", -42);

	printf("%0.10o\n", 4242);
	ft_printf("%0.10o\n\n", 4242);

	printf("%07.7o\n", 42);
	ft_printf("%07.7o\n\n", 42);
		printf("%llx|\n", LLONG_MAX);
	ft_printf("%llx|\n\n", LLONG_MAX);

	printf("%-10.10lx|\n", LONG_MIN);
	ft_printf("%-10.10lx|\n\n", LONG_MIN);

	printf("%-10.10lx|\n", -2147483647);
	ft_printf("%-10.10lx|\n\n", -2147483647);

	printf("%hx|\n", USHRT_MAX);
	ft_printf("%hx|\n\n", USHRT_MAX);

	printf("%-12.6hx|\n", UCHAR_MAX);
	ft_printf("%-12.6hx|\n\n", UCHAR_MAX);*/

}

/*
void	test_u()
{
	unsigned long		REG_UL = 10446744073709551610;
	unsigned long long	MAX_UNSLL = 18446744073709551610;
	unsigned char		value = 42;
	unsigned short		short_value = 42;

	printf("   printf:%8.42hhu type\n", value);
	ft_printf("ft_printf:%8.42hhu type\n\n", value);

		printf("   printf:%12.4hu type\n", short_value);
	ft_printf("ft_printf:%12.4hu type\n\n", short_value);

	printf("   printf:%-12d type\n", -42949672);	
	ft_printf("ft_printf:%-12d type\n\n", -42949672);

	printf("   printf:%8.4lu type\n", REG_UL);
	ft_printf("ft_printf:%8.4lu type\n\n", REG_UL);

	printf("   printf:%8.4llu type\n", MAX_UNSLL);		
	ft_printf("ft_printf:%8.4llu type\n\n", MAX_UNSLL);
	
}*/

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

	 printf("Origin 4:% -10.4f|\n", 42.42);
	ft_printf("Mine pf4:% -10.4f|\n\n", 42.42);
}

void	test_float_high_precition()
{
	float	f32num = 4242.99999999999;
	float	f42num = 4242.123;
	float	flnum = 3.99999999999;
	float	fnum = 3.14199265359;

	printf("Number :4242424242.123\n");
	printf("Origin :%10.40f|\n", fnum);
	ft_printf("Mine pf:%10.40f|\n\n", fnum);

	printf("Origin :%20.10f|\n", f42num);
	ft_printf("Mine pf:%20.10f|\n\n", f42num);

	printf("Number :4242424242.10424\n");
	printf("Origin :%10.16f|\n", f42num);
	ft_printf("Mine pf:%10.16f|\n\n", f42num);
}

void	test_float_mult_flags()
{
	ft_printf("Test multiple float flags\n\n");

		  printf("Origin 1:%+010.40f|\n", 42.42);
	ft_printf("Mine pf1:%+010.40f|\n\n", 42.42);

	      printf("Origin 5:% 010.4f|\n", 42.42);
	 ft_printf("Mine pf5:% 010.4f|\n\n", 42.42);

	     printf("Origin 2:%+010.4f|\n", -42.42);
	ft_printf("Mine pf2:%+010.4f|\n\n", -42.42);

	     printf("Origin 3:%+010.4f|\n", -42.42);
	ft_printf("Mine pf3:%+010.4f|\n\n", -42.42);

		 printf("Origin 4:% 010.4f|\n", 42.42);
	ft_printf("Mine pf4:% 010.4f|\n\n", 42.42);
}

void	test_float()
{
	float	fnum = 3.14199265359;
	float	flnum = 3.99999999999;
	float	f42num = 4242.4242424242424242;
	float	f32num = 4242.99999999999;

//	test_float_flags();
//	test_float_mult_flags();
	test_float_high_precition();

	printf("Origin :%15f.1|\n", -0.0);
	ft_printf("Mine pf:%15f.1|\n\n", -0.0);

//	printf("Origin :%15f.1|\n", 1.0);
//	ft_printf("Mine pf:%15f.1|\n\n", 0.0);
	
//	printf("Origin :%+02.1f|\n", (float)4);
//	ft_printf("Mine pf:%+02.1f|\n\n", (float)4);

//	printf("Number :3.14199265359\n");
//	printf("Origin :%f|\n", fnum);
//	ft_printf("Mine pf:%f|\n\n", fnum);

//	printf("Number :3.99999999999\n");
//	printf("Origin :%.19f|\n", flnum);
//	ft_printf("Mine pf:%.19f|\n\n", flnum);
}
// if + -> ignore space
// if + -> ignore multiple space (???)
// if ++ -> possibility to handle multiple plus flags
// if negative && flag zero mine ignore sign (-) 

void		test_int_multiple_flags()
{/*
	ft_printf("% +d|\n", 42);  
  ft_printf("% +d|\n", -42); 
  ft_printf("%+ d|\n", 42);  
  ft_printf("%+ d|\n", -42); 
  ft_printf("%  +d|\n", 42); 
  ft_printf("%  +d|\n", -42);
  ft_printf("%+  d|\n", 42); 
  ft_printf("%+  d|\n", -42);
  ft_printf("% ++d|\n", 42); 
  ft_printf("% ++d|\n", -42);
  ft_printf("%++ d|\n", 42); 
  ft_printf("%++ d|\n", -42);
  ft_printf("%0d|\n", -42);  
  ft_printf("%00d|\n", -42);

	printf("% +d|\n", 42);  
  printf("% +d|\n", -42); 
  printf("%+ d|\n", 42);  
  printf("%+ d|\n", -42); 
  printf("%  +d|\n", 42); 
  printf("%  +d|\n", -42);
  printf("%+  d|\n", 42); 
  printf("%+  d|\n", -42);
  printf("% ++d|\n", 42); 
  printf("% ++d|\n", -42);
  printf("%++ d|\n", 42); 
  printf("%++ d|\n", -42);
  printf("%0d|\n", -42);  
  printf("%00d|\n", -42);*/
}

void	test_int()
{
	test_int_multiple_flags();
/*	printf("Orig pf:%015.1d|\n", -42);
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
	ft_printf("Mine pf:%d|\n",-42);*/
}

void	test_str()
{/*
	printf("%.2c\n", NULL);
	ft_printf("%.2c\n", NULL);
	printf("Orig pf:@moulitest: %s|\n", NULL);
	ft_printf("Orig pf:@moulitest: %s|\n", NULL);

	printf("Orig pf:%.2c||\n", NULL);
	ft_printf("Mine pf:%.2c||\n", NULL);

	ft_printf("Orig pf:%s %s|\n", NULL, "string");
	ft_printf("Mine pf:%s %s|\n", NULL, "string");*/

	printf("Orig pf:@moulitest: %c|\n", 0);
	ft_printf("Mine pf:@moulitest: %c|\n", 0);

	printf("Orig pf:%2c|\n", 0);
	ft_printf("Mine pf:%2c|\n", 0);

  printf("Orig pf:null %c and text|\n", 0);
	ft_printf("Mine pf:null %c and text", 0);
}

void		test_hexadecimal()
{/*
		printf("%hx\n", (unsigned short)4294967296);
	ft_printf("%hx\n\n", (unsigned short)4294967296);

		printf("%hx\n", (unsigned short)4295967295);
	ft_printf("%hx\n\n", (unsigned short)4295967295);

		printf("%hx\n", (unsigned short)4294967294);
	ft_printf("%hx\n\n", (unsigned short)4294967294);


	printf("Orig pf:%20.1s|\n", "Exetion");
	ft_printf("Mine pf:%20.1s|\n\n", "Exetion");

	printf("Orig pf:%-20.s|\n", "Exetion");
	ft_printf("Mine pf:%-20.s|\n\n", "Exetion");

	printf("Orig pf:%20.0s|\n", "Exetion");
	ft_printf("Mine pf:%20.0s|\n\n", "Exetion");

	printf("Orig pf:%020.2s\n", "Exetion");
	ft_printf("Mine pf:%020.2s\n\n", "Exetion");

	printf("Orig pf:%-20.5s|\n", "Exetion");
	ft_printf("Mine pf:%-20.5s|\n", "Exetion");
*/
}

















int		main()
{

		printf("Orig pf: %.d %.0d|\n", 42, 43);
	ft_printf("Mine pf: %.d %.0d|\n\n", 42, 43);

		printf("Orig pf: %.d %.0d|\n", 0, 0);
	ft_printf("Mine pf: %.d %.0d|\n\n", 0, 0);
//	test_float();
//	test_int();
	return (0);
}