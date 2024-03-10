/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilc2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <ielhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:29:55 by ielhasso          #+#    #+#             */
/*   Updated: 2024/03/10 12:18:43 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut_last_eat_time);
	philo->last_eat_time = gettime();
	pthread_mutex_unlock(&philo->mut_last_eat_time);
}

uint64_t	get_sleep_time(t_data *data)
{
	uint64_t	sleep_time;

	pthread_mutex_lock(&data->mut_sleep_t);
	sleep_time = data->sleep_time;
	pthread_mutex_unlock(&data->mut_sleep_t);
	return (sleep_time);
}

int	think(t_philo *philo)
{
	set_philo_state(philo, T);
	if (get_state(philo) == D)
		return (1);
	print_msg(philo->data, philo->id, "is thinking");
	return (0);
}

int	keep(t_data *data)
{
	int	keep;

	pthread_mutex_lock(&data->mut_keep_iter);
	keep = data->keep_iterating;
	pthread_mutex_unlock(&data->mut_keep_iter);
	return (keep);
}

void	*all_alive_routine(void *d)
{
	int i;
	int nb_philos;
	t_data *data;
	t_philo *philos;

	data = (t_data *)d;
	philos = data->philos;
	nb_philos = get_nb_philos(data);
	i = 0;
	while (i < nb_philos && keep(data))
	{
		if (philo_died(&philos[i]) && keep(data))
		{
			print_msg(data, philos[i].id, "died");
			set_philo_state(&philos[i], D);
			set_keep(data, 0);
			notify(data);
			break ;
		}
		i++;
		if (i == nb_philos)
			i = 0;
		usleep(1000);
	}
	return (NULL);
}