/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_pf.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 14:31:26 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/24 12:54:21 by krioliin      ########   odam.nl         */
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

		printf("Orig pf:% 10.5d|\n", 4242);
	ft_printf("Mine pf:% 10.5d|\n\n", 4242);

		printf("Orig pf:% 10.5o|\n", 42);
	ft_printf("Mine pf:% 10.5o|\n\n", 42);

		printf("Orig pf: %d %d|\n", 0, 0);
	ft_printf("Mine pf: %d %d|\n\n", 0, 0);

//	test_float();
//	test_int();
	return (0);
}

/*

SUCCESS TESTS:

   1.      ft_printf("");                                -> ""
   2.      ft_printf("\n");                              -> "$\n"
   3.      ft_printf("test");                            -> "test"
   4.      ft_printf("test\n");                          -> "test$\n"
   5.      ft_printf("1234");                            -> "1234"
   6.      ft_printf("%%");                              -> "%"
   7.      ft_printf("%5%");                             -> "    %"
   8.      ft_printf("%-5%");                            -> "%    "
   9.      ft_printf("%.0%");                            -> "%"
  10.      ft_printf("%%", "test");                      -> "%"
  11.      ft_printf("%   %", "test");                   -> "%"
  12.      ft_printf("%x", 42);                          -> "2a"
  13.      ft_printf("%X", 42);                          -> "2A"
  14.      ft_printf("%x", 0);                           -> "0"
  15.      ft_printf("%X", 0);                           -> "0"
  16.      ft_printf("%x", -42);                         -> "ffffffd6"
  17.      ft_printf("%X", -42);                         -> "FFFFFFD6"
  18.      ft_printf("%x", 4294967296);                  -> "0"
  19.      ft_printf("%X", 4294967296);                  -> "0"
  20.      ft_printf("%x", test);                        -> "0"
  21.      ft_printf("%10x", 42);                        -> "        2a"
  22.      ft_printf("%-10x", 42);                       -> "2a        "
  23.      ft_printf("%lx", 4294967296);                 -> "100000000"
  24.      ft_printf("%llX", 4294967296);                -> "100000000"
  25. FAIL ft_printf("%hx", 4294967296);                 -> "0"
  26. FAIL ft_printf("%hhX", 4294967296);                -> "0"
  27. FAIL ft_printf("%jx", 4294967295);                 -> "ffffffff"
  28. FAIL ft_printf("%jx", 4294967296);                 -> "100000000"
  29. FAIL ft_printf("%jx", -4294967296);                -> "ffffffff00000000"
  30. FAIL ft_printf("%jx", -4294967297);                -> "fffffffeffffffff"
  31.      ft_printf("%llx", 9223372036854775807);       -> "7fffffffffffffff"
  32.      ft_printf("%llx", 9223372036854775808);       -> "7fffffffffffffff"
  33.      ft_printf("%010x", 542);                      -> "000000021e"
  34.      ft_printf("%-15x", 542);                      -> "21e            "
  35.      ft_printf("%2x", 542);                        -> "21e"
  36.      ft_printf("%.2x", 5427);                      -> "1533"
  37.      ft_printf("%5.2x", 5427);                     -> " 1533"
  38.      ft_printf("%#x", 42);                         -> "0x2a"
  39.      ft_printf("%#llx", 9223372036854775807);      -> "0x7fffffffffffffff"
  40.      ft_printf("%#x", 0);                          -> "0"
  41.      ft_printf("%#x", 42);                         -> "0x2a"
  42.      ft_printf("%#X", 42);                         -> "0X2A"
  43.      ft_printf("%#8x", 42);                        -> "    0x2a"
  44.      ft_printf("%#08x", 42);                       -> "0x00002a"
  45.      ft_printf("%#-08x", 42);                      -> "0x2a    "
  46.      ft_printf("@moulitest: %#.x %#.0x", 0, 0);    -> "@moulitest:  "
  47.      ft_printf("@moulitest: %.x %.0x", 0, 0);      -> "@moulitest:  "
  48.      ft_printf("@moulitest: %5.x %5.0x", 0, 0);    -> "@moulitest:            "
  49.      ft_printf("%s", "abc");                       -> "abc"
  50.      ft_printf("%s", "this is a string");          -> "this is a string"
  51.      ft_printf("%s ", "this is a string");         -> "this is a string "
  52.      ft_printf("%s  ", "this is a string");        -> "this is a string  "
  53.      ft_printf("this is a %s", "string");          -> "this is a string"
  54.      ft_printf("%s is a string", "this");          -> "this is a string"
  55.      ft_printf("Line Feed %s", "\n");              -> "Line Feed $\n"
  56.      ft_printf("%10s is a string", "this");        -> "      this is a string"
  57.      ft_printf("%.2s is a string", "this");        -> "th is a string"
  58.      ft_printf("%5.2s is a string", "this");       -> "   th is a string"
  59.      ft_printf("%10s is a string", "");            -> "           is a string"
  60.      ft_printf("%.2s is a string", "");            -> " is a string"
  61.      ft_printf("%5.2s is a string", "");           -> "      is a string"
  62.      ft_printf("%-10s is a string", "this");       -> "this       is a string"
  63.      ft_printf("%-.2s is a string", "this");       -> "th is a string"
  64.      ft_printf("%-5.2s is a string", "this");      -> "th    is a string"
  65.      ft_printf("%-10s is a string", "");           -> "           is a string"
  66.      ft_printf("%-.2s is a string", "");           -> " is a string"
  67.      ft_printf("%-5.2s is a string", "");          -> "      is a string"
  68.      ft_printf("%s %s", "this", "is");             -> "this is"
  69.      ft_printf("%s %s %s", "this", "is", "a");     -> "this is a"
  70.      ft_printf("%s %s %s %s", "this", "is", "a", "multi"); -> "this is a multi"
  71.      ft_printf("%s %s %s %s string. gg!", "this", "is", "a", "multi", "string"); -> "this is a multi string. gg!"
  72.      ft_printf("%s%s%s%s%s", "this", "is", "a", "multi", "string"); -> "thisisamultistring"
  73.      ft_printf("@moulitest: %s", NULL);            -> "@moulitest: (null)"
  74.      ft_printf("%.2c", NULL);                      -> "^@"
  75.      ft_printf("%s %s", NULL, string);             -> "(null) string"
  76.      ft_printf("%c", 42);                          -> "*"
  77.      ft_printf("%5c", 42);                         -> "    *"
  78. FAIL ft_printf("%-5c", 42);                        -> "*    "
  79.      ft_printf("@moulitest: %c", 0);               -> "@moulitest: ^@"
  80.      ft_printf("%2c", 0);                          -> " ^@"
  81.      ft_printf("null %c and text", 0);             -> "null ^@ and text"
  82.      ft_printf("% c", 0);                          -> "^@"
  83.      ft_printf("%o", 40);                          -> "50"
  84.      ft_printf("%5o", 41);                         -> "   51"
  85.      ft_printf("%05o", 42);                        -> "00052"
  86.      ft_printf("%-5o", 2500);                      -> "4704 "
  87.      ft_printf("%#6o", 2500);                      -> " 04704"
  88.      ft_printf("%-#6o", 2500);                     -> "04704 "
  89.      ft_printf("%-05o", 2500);                     -> "4704 "
  90.      ft_printf("%-5.10o", 2500);                   -> "0000004704"
  91.      ft_printf("%-10.5o", 2500);                   -> "04704     "
  92.      ft_printf("@moulitest: %o", 0);               -> "@moulitest: 0"
  93.      ft_printf("@moulitest: %.o %.0o", 0, 0);      -> "@moulitest:  "
  94.      ft_printf("@moulitest: %5.o %5.0o", 0, 0);    -> "@moulitest:            "
  95.      ft_printf("@moulitest: %#.o %#.0o", 0, 0);    -> "@moulitest: 0 0"
  96.      ft_printf("@moulitest: %.10o", 42);           -> "@moulitest: 0000000052"
  97.      ft_printf("%d", 1);                           -> "1"
  98.      ft_printf("the %d", 1);                       -> "the 1"
  99.      ft_printf("%d is one", 1);                    -> "1 is one"
 100.      ft_printf("%d", -1);                          -> "-1"
 101.      ft_printf("%d", 4242);                        -> "4242"
 102.      ft_printf("%d", -4242);                       -> "-4242"
 103.      ft_printf("%d", 2147483647);                  -> "2147483647"
 104.      ft_printf("%d", 2147483648);                  -> "-2147483648"
 105.      ft_printf("%d", -2147483648);                 -> "-2147483648"
 106.      ft_printf("%d", -2147483649);                 -> "2147483647"
 107.      ft_printf("% d", 42);                         -> " 42"
 108.      ft_printf("% d", -42);                        -> "-42"
 109.      ft_printf("%+d", 42);                         -> "+42"
 110.      ft_printf("%+d", -42);                        -> "-42"
 111.      ft_printf("%+d", 0);                          -> "+0"
 112.      ft_printf("%+d", 4242424242424242424242);     -> "-1"
 113.      ft_printf("% +d", 42);                        -> "+42"
 114.      ft_printf("% +d", -42);                       -> "-42"
 115.      ft_printf("%+ d", 42);                        -> "+42"
 116.      ft_printf("%+ d", -42);                       -> "-42"
 117.      ft_printf("%  +d", 42);                       -> "+42"
 118.      ft_printf("%  +d", -42);                      -> "-42"
 119.      ft_printf("%+  d", 42);                       -> "+42"
 120.      ft_printf("%+  d", -42);                      -> "-42"
 121.      ft_printf("% ++d", 42);                       -> "+42"
 122.      ft_printf("% ++d", -42);                      -> "-42"
 123.      ft_printf("%++ d", 42);                       -> "+42"
 124.      ft_printf("%++ d", -42);                      -> "-42"
 125.      ft_printf("%0d", -42);                        -> "-42"
 126.      ft_printf("%00d", -42);                       -> "-42"
 127.      ft_printf("%5d", 42);                         -> "   42"
 128.      ft_printf("%05d", 42);                        -> "00042"
 129.      ft_printf("%0+5d", 42);                       -> "+0042"
 130.      ft_printf("%5d", -42);                        -> "  -42"
 131.      ft_printf("%05d", -42);                       -> "-0042"
 132.      ft_printf("%0+5d", -42);                      -> "-0042"
 133.      ft_printf("%-5d", 42);                        -> "42   "
 134.      ft_printf("%-05d", 42);                       -> "42   "
 135.      ft_printf("%-5d", -42);                       -> "-42  "
 136.      ft_printf("%-05d", -42);                      -> "-42  "
 137.      ft_printf("%hd", 32767);                      -> "32767"
 138. FAIL ft_printf("%hd", −32768);                   -> "0"
 139.      ft_printf("%hd", 32768);                      -> "-32768"
 140. FAIL ft_printf("%hd", −32769);                   -> "0"
 141.      ft_printf("%hhd", 127);                       -> "127"
 142.      ft_printf("%hhd", 128);                       -> "-128"
 143.      ft_printf("%hhd", -128);                      -> "-128"
 144.      ft_printf("%hhd", -129);                      -> "127"
 145.      ft_printf("%ld", 2147483647);                 -> "2147483647"
 146.      ft_printf("%ld", -2147483648);                -> "-2147483648"
 147.      ft_printf("%ld", 2147483648);                 -> "2147483648"
 148.      ft_printf("%ld", -2147483649);                -> "-2147483649"
 149.      ft_printf("%lld", 9223372036854775807);       -> "9223372036854775807"
 150.      ft_printf("%lld", -9223372036854775808);      -> "-9223372036854775808"
 151. FAIL ft_printf("%jd", 9223372036854775807);        -> "9223372036854775807"
 152. FAIL ft_printf("%jd", -9223372036854775808);       -> "-9223372036854775808"
 153. FAIL ft_printf("%zd", 4294967295);                 -> "4294967295"
 154. FAIL ft_printf("%zd", 4294967296);                 -> "4294967296"
 155. FAIL ft_printf("%zd", -0);                         -> "0"
 156. FAIL ft_printf("%zd", -1);                         -> "-1"
 157.      ft_printf("%d", 1);                           -> "1"
 158.      ft_printf("%d %d", 1, -2);                    -> "1 -2"
 159.      ft_printf("%d %d %d", 1, -2, 33);             -> "1 -2 33"
 160.      ft_printf("%d %d %d %d", 1, -2, 33, 42);      -> "1 -2 33 42"
 161.      ft_printf("%d %d %d %d gg!", 1, -2, 33, 42, 0); -> "1 -2 33 42 gg!"
 162.      ft_printf("%4.15d", 42);                      -> "000000000000042"
 163.      ft_printf("%.2d", 4242);                      -> "4242"
 164.      ft_printf("%.10d", 4242);                     -> "0000004242"
 165.      ft_printf("%10.5d", 4242);                    -> "     04242"
 166.      ft_printf("%-10.5d", 4242);                   -> "04242     "
 167.      ft_printf("% 10.5d", 4242);                   -> "     04242"
 168.      ft_printf("%+10.5d", 4242);                   -> "    +04242"
 169.      ft_printf("%-+10.5d", 4242);                  -> "+04242    "
 170.      ft_printf("%03.2d", 0);                       -> " 00"
 171.      ft_printf("%03.2d", 1);                       -> " 01"
 172. FAIL ft_printf("%03.2d", -1);                      -> "-01"
 173.      ft_printf("@moulitest: %.10d", -42);          -> "@moulitest: -0000000042"
 174.      ft_printf("@moulitest: %.d %.0d", 42, 43);    -> "@moulitest: 42 43"
 175.      ft_printf("@moulitest: %.d %.0d", 0, 0);      -> "@moulitest:  "
 176.      ft_printf("@moulitest: %5.d %5.0d", 0, 0);    -> "@moulitest:            "
 177.      ft_printf("%u", 0);                           -> "0"
 178.      ft_printf("%u", 1);                           -> "1"
 179.      ft_printf("%u", -1);                          -> "4294967295"
 180.      ft_printf("%u", 4294967295);                  -> "4294967295"
 181.      ft_printf("%u", 4294967296);                  -> "0"
 182.      ft_printf("%5u", 4294967295);                 -> "4294967295"
 183.      ft_printf("%15u", 4294967295);                -> "     4294967295"
 184.      ft_printf("%-15u", 4294967295);               -> "4294967295     "
 185.      ft_printf("%015u", 4294967295);               -> "000004294967295"
 186. FAIL ft_printf("% u", 4294967295);                 -> "4294967295"
 187. FAIL ft_printf("%+u", 4294967295);                 -> "4294967295"
 188.      ft_printf("%lu", 4294967295);                 -> "4294967295"
 189.      ft_printf("%lu", 4294967296);                 -> "4294967296"
 190.      ft_printf("%lu", -42);                        -> "18446744073709551574"
 191.      ft_printf("%llu", 4999999999);                -> "4999999999"
 192. FAIL ft_printf("%ju", 4999999999);                 -> "4999999999"
 193. FAIL ft_printf("%ju", 4294967296);                 -> "4294967296"
 194. FAIL ft_printf("%U", 4294967295);                  -> "4294967295"
 195. FAIL ft_printf("%hU", 4294967296);                 -> "4294967296"
 196. FAIL ft_printf("%U", 4294967296);                  -> "4294967296"
 197.      ft_printf("@moulitest: %.5u", 42);            -> "@moulitest: 00042"
 */