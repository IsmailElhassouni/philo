/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <ielhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:05:06 by ielhasso          #+#    #+#             */
/*   Updated: 2024/03/10 12:40:30 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

long	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
		if (str[i] != 0 && (str[i] < '0' || str[i] > '9'))
			return (0);
	}
	return (res * neg);
}

int	check_num(int ac, char **av)
{
	long(t), (i);
	i = 1;
	if (ac == 5)
	{
		while (i < 5)
		{
			t = ft_atoi(av[i]);
			if (t <= 0)
				return (0);
			else
				i++;
		}
	}
	else
	{
		while (i < 6)
		{
			t = ft_atoi(av[i]);
			if (t <= 0 || ft_atoi(av[5]) == 0)
				return (0);
			else
				i++;
		}
	}
	return (1);
}

int	check_arg(int ac, char **argv)
{
	if (ac < 5 || ac > 6)
		return (10);
	if (check_num(ac, argv) == 0)
		return (0);
	return (1);
}
void leaks()
{
	system("leaks a.out");
}
int	main(int ac, char **av)
{
	atexit(&leaks);
	if (check_arg(ac, av) == 0)
		return (printf("\terror\n"));
	if (philo(ac, av) != 0)
		return (0);
}