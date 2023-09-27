
#include "../inc/fractol.h"

int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}
double	ft_atof(const char *str)
{
	double	int_part;
	double	dec_part;
	double	sign;
	int		i;

	int_part = 0.0;
	dec_part = 0.0;
	sign = 1.0;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1.0;
	while (ft_isdigit(*str))
		int_part = int_part * 10 + (*str++ - '0');
	i = -1;
	if (*str == '.' && *str++)
	{
		while (ft_isdigit(*str))
			dec_part += (pow(10, i--) * (*str++ - '0'));
	}
	return (sign * (int_part + dec_part));
}
/*
int main(int ac, char **av)
{
    if (ac == 2)
    {
        printf("%f", ft_atof(av[1]));
    }
    return (0);
} 
*/  