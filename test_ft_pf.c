
#include "includes/ft_printf.h"

int		main()
{
	int p;
//	printf("Return value origin pf:%d ", printf("Orgn pf:{%-15p}\n", 0));
//	printf("Return  value  mine pf:%d\n", ft_printf("Mine pf:{%-15p}\n", 0));

	printf("orgn printf:{%*3d}\n", -5, 42);
	ft_printf("mine printf:{%*3d}\n\n", -5, 42);

	printf("orgn printf:{%.*s}\n", 0, "42");
	ft_printf("mine printf:{%.*s}\n\n", 0, "42");

	printf("orgn printf:{%.0s}\n", "42");
	ft_printf("mine printf:{%.0s}\n\n","42");
/*
	printf("orgn printf:{%f}{%lf}\n", 1.42, (double)1.42);
	ft_printf("mine printf:{%f}{%lf}\n\n", 1.42, (double)1.42);

	printf("orgn printf:{%f}{%lf}\n", 3.72, (double)3.123);
	ft_printf("mine printf:{%f}{%lf}\n\n", 3.72, (double)3.123);


	printf("orgn printf:{%f}{%lf}\n", 2.32, (double)2.3l);
	ft_printf("mine printf:{%f}{%lf}\n", 2.32, (double)2.3l);
*/


	return (0);
}
