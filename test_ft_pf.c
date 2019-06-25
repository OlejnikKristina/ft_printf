
#include "includes/ft_printf.h"

int		main()
{
	int p;
//	printf("Return value origin pf:%d ", printf("Orgn pf:{%-15p}\n", 0));
//	printf("Return  value  mine pf:%d\n", ft_printf("Mine pf:{%-15p}\n", 0));
// 10.5d%.4d", 42
//	printf("orgn 0:{%15.5p}\n", 0);
//	ft_printf("mine 0:{%15.5p}\n", 0);

	printf("orgn 0:{%35.20p}\n", &p);
	ft_printf("mine 0:{%35.20p}\n", &p);

	printf("orgn 0:{%-15.5p}\n", &p);
//	ft_printf("mine 0:{%-15.5p}\n", 4);


	return (0);
}
