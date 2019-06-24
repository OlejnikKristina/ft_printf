
#include "includes/ft_printf.h"

int		main()
{
	int p;
//	printf("Return value origin pf:%d ", printf("Orgn pf:%p| ", &i));
//	printf("Return  value  mine pf:%d ", ft_printf("Mine pf:%p| ", &i));
	printf("orgn 0:{%-15p}\n", 0);
	ft_printf("mine 0:{%-15p}\n", 0);

	printf("orgn 0:{%-20p}\n", &p);
	ft_printf("mine 0:{%-20p}\n", &p);

	printf("orgn 0:{%015p}\n", 0);
	ft_printf("mine 0:{%015p}\n", 0);
/*
	printf("orgn 42:%10ld\n", 424242424242442424l);
	ft_printf("mine 42:%10ld\n\n", 424242424242442424l);

	printf("orgn 42:%10ld\n\n", -42l);
	ft_printf("mine 42:%10ld\n\n", -42l);

	printf("orgn 42:%20.0ld\n\n", 42l);
	ft_printf("mine 42:%20.0ld\n\n", 42l);*/
	return (0);
}
