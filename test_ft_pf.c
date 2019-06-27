
#include "includes/ft_printf.h"

void	pf_test_colors()
{
	ft_printf("mine printf:\n\
%{RED}I am red str\n\
%{YELLOW}I am yellow str\n\
%{PINK}I am pink str\n\
%{GREEN}I am GREEN str\n\
%{DARKBLUE}I am DARKLUE str\n\
%{BLUE}I am BLUE str\n\
%{WHITE}I am WHITE str\n\
%{GRAY}I am GRAY str%{RESET}\n\
%{RESET}I am regular str\n\
%{PINK}I am PINK str\n\
\
%{RED_B}I am bold red str\n\
%{YELLOW_B}I am bold yellow str\n\
%{PINK_B}I am bold pink str\n\
%{GREEN_B}I am bold GREEN str\n\
%{RESET}I am regular str\n\
%{DARK_BLUE_B}I am bold DARK_BLUE str\n\
%{BLUE_B}I am bold BLUE str\n\
%{WHITE_B}I am bold WHITE str\n\
%{GRAY_B}I am bold GRAY str\n\
%{PINK_B}I am bold PINK str\n\
%{ORANGE_B}I am bold ORANGE str%{RESET}\n\
", 42);
}

int		main()
{
	int p;
//	printf("Return value origin pf:%d ", printf("Orgn pf:{%-15p}\n", 0));
//	printf("Return  value  mine pf:%d\n", ft_printf("Mine pf:{%-15p}\n", 0));

//	pf_test_colors();

	printf("orgn printf:{%c}\n", 42);
	ft_printf("mine printf:{%c}\n\n", 42);

//	printf("\033[0;31m orgn printf:{%.0s\033[0m}\n", "42");
//	ft_printf("mine printf:{%.0s}\n\n","42");

	return (0);
}
