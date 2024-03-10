/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilc5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <ielhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:13:43 by ielhasso          #+#    #+#             */
/*   Updated: 2024/03/10 12:18:17 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_died(t_philo *philo)
{
	int		res;
	t_data	*data;

	data = philo->data;
	res = 0;
	if (gettime() - get_last_eat_time(philo) > get_die_time(data)
		&& get_state(philo) != E)
	{
		set_philo_state(philo, D);
		res = 1;
	}
	return (res);
}

uint64_t	get_die_time(t_data *data)
{
	uint64_t	die_time;

	pthread_mutex_lock(&data->mut_die_t);
	die_time = data->die_time;
	pthread_mutex_unlock(&data->mut_die_t);
	return (die_time);
}

uint64_t	get_eat_time(t_data *data)
{
	uint64_t	eat_time;

	pthread_mutex_lock(&data->mut_eat_t);
	eat_time = data->eat_time;
	pthread_mutex_unlock(&data->mut_eat_t);
	return (eat_time);
}

void	sleep_for_eating(t_philo *philo)
{
	ft_usleep(get_eat_time(philo->data));
}

void	update_nb_meals_had(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut_nb_meals_had);
	philo->nb_meals_had++;
	pthread_mutex_unlock(&philo->mut_nb_meals_had);
}
