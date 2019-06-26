
#include "includes/ft_printf.h"

int		main()
{
	int p;
//	printf("Return value origin pf:%d ", printf("Orgn pf:{%-15p}\n", 0));
//	printf("Return  value  mine pf:%d\n", ft_printf("Mine pf:{%-15p}\n", 0));
// 10.5d%.4d", 42
//	printf("orgn 0:{%15.5p}\n", 0);
//	ft_printf("mine 0:{%15.5p}\n", 0);

	printf("orgn 0:{%05p}\n", 4);
	ft_printf("mine 0:{%05p}\n", 4);

	printf("orgn 0:{%05p}\n", 0);
	ft_printf("mine 0:{%05p}\n", 0);

	printf("orgn 0:{%5p}\n", 0);
	ft_printf("mine 0:{%5p}\n", 0);


	return (0);
}
