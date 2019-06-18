#include "ft_printf.h"

/*
void	test_u()
{
//	unsigned long		REG_UL = 10446744073709551610;
//	unsigned long long	MAX_UNSLL = 18446744073709551610;
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
/*	printf("%25p\n", pi);
	ft_printf("%25p\n", pi);

	printf("%010.6d  || %d ||%s\n", 42, -42, "You can make it!");
	ft_printf("%010.6d  || %d ||%s\n", 42, -42, "You can make it!");

	printf("%010.6s\n", "I belive everuthing gonna be fine\n");
	ft_printf("%010.6s\n", "I belive everuthing gonna be fine\n");*/

int		pf_test()
{
	long				REG_L =  -4200083648;
	long long			REG_LL = -9223372036854775800;
	long long			MINIM_LL = -9223372036854775800;
	long long			MAX_LL = 9223372036854775807;
	char				*str;

/*
	printf("   printf:%42.20ld type\n", REG_L);
	ft_printf("ft_printf:%42.20ld type\n", REG_L);

	printf("   printf:%+20.12lld type\n", REG_LL);
	ft_printf("ft_printf:%+20.12lld type\n\n", REG_LL);

	printf("   printf:%+20.20lld type\n", MINIM_LL);
	ft_printf("ft_printf:%+20.20lld type\n\n", MINIM_LL);

	printf("   printf:%20.20lld type\n", MAX_LL);
	ft_printf("ft_printf:%20.20lld type\n\n", MAX_LL);

	printf("   printf:%+10.5i type\n", 42);
	ft_printf("ft_printf:%+10.5i type\n\n", 42);

	printf("   printf:%-10.5i type\n", -42);
	ft_printf("ft_printf:%-10.5i type\n\n", -42);*/
	//test_o();

	return (0);
}