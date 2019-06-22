/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_pf.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 14:31:26 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/21 20:25:55 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

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


void		test_hexadecimal()
{
//		printf("%hx\n", (unsigned short)4294967296);
//	ft_printf("%hx\n\n", (unsigned short)4294967296);

		printf("%hx\n", (unsigned short)4295967295);
	ft_printf("%hx\n\n", (unsigned short)4295967295);

		printf("%hx\n", (unsigned short)4294967294);
	ft_printf("%hx\n\n", (unsigned short)4294967294);

	printf("%hx\n", (unsigned short)42);
	ft_printf("%hx\n\n", (unsigned short)42);

	printf("%hx\n", (unsigned short)0);
	ft_printf("%hx\n\n", (unsigned short)0);
}
//73832
//65535
int		main()
{
//	test_float();
//	printf("Number :4242.14199060359\n");
//	printf("Origin :%10f|\n", (float)-0.0/0.0);
//	printf("Origin :%-+10f|\n",  -0.0);
//	ft_printf("Mine pf:%-+10.4d|\n", );
		test_hexadecimal();

//	printf("res: %d\n", 	printf("%%\n"));
//	printf("res: %d\n", 	ft_printf("%%\n"));

/*	printf("Origin :%+-10.40f|\n", -42.42);
	ft_printf("Mine pf:%+-10.4f|\n", -42.42);


	printf("Origin :%-10.4f|\n", -42.42);
	ft_printf("Mine pf:%-10.4f|\n", -42.42);*/
//	test_float();
//	test_int();
	return (0);
}