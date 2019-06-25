
#include "includes/ft_printf.h"

int		main()
{
	int p;
//	printf("Return value origin pf:%d ", printf("Orgn pf:{%-15p}\n", 0));
//	printf("Return  value  mine pf:%d\n", ft_printf("Mine pf:{%-15p}\n", 0));

	printf("orgn 0:{% 03d}\n", 1);
	ft_printf("mine 0:{% 03d}\n", 1);

	// printf("orgn 0:{%-15p}\n", 0);
	// ft_printf("mine 0:{%-15p}\n", 0);

	// printf("orgn 0:{%020p}\n", 0);
	// ft_printf("mine 0:{%020p}\n", 0);

	// printf("orgn 0:{%20p}\n", &p);
	// ft_printf("mine 0:{%20p}\n", &p);
/*
	printf("orgn 42:%10ld\n", 424242424242442424l);
	ft_printf("mine 42:%10ld\n\n", 424242424242442424l);

	printf("orgn 42:%10ld\n\n", -42l);
	ft_printf("mine 42:%10ld\n\n", -42l);

	printf("orgn 42:%20.0ld\n\n", 42l);
	ft_printf("mine 42:%20.0ld\n\n", 42l);*/
	return (0);
}
