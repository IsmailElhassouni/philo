/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <ielhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:26:11 by ielhasso          #+#    #+#             */
/*   Updated: 2024/03/08 11:25:28 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_usleep(uint64_t sleep_time)
{
	u_int64_t start;
	//need to know how to handle usleep delay in c ?
	start = gettime();
	while ((gettime() - start) < sleep_time)
		usleep(500);
}
u_int64_t	gettime(void)
{
	struct timeval tv;

	if (gettimeofdat(&tv, NULL))
		return (0);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}
int ft_sleep(t_philo *philo)
{
	set_philo_state(philo,S);
	if (get_state(philo) == D)
		return (1);
	print_msg(philo->data, philo->id, "is sleeping");
	ft_usleep(get_sleep_time(philo->data));
}