/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <ielhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 21:13:43 by ielhasso          #+#    #+#             */
/*   Updated: 2024/03/09 18:33:48 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_keep(t_data *data, int keep)
{
	pthread_mutex_lock(&data->mut_keep_iter);
	data->keep_iterating = keep;
	pthread_mutex_unlock(&data->mut_keep_iter);
}

int	nb_meals_option(t_data *data)
{
	if (data->nb_meals > 0)
		return (1);
	return (0);
}

void	notify(t_data *data)
{
	t_philo	*philo;
	int		i;
	int		nb;

	nb = get_nb_philos(data);
	philo = data->philos;
	i = -1;
	while (++i < nb)
		set_philo_state(&philo[i], D);
}

int	is_philo_full(t_data *data, t_philo *philo)
{
	int	res;

	res = 0;
	if (get_nb_meals_philo_had(philo) >= data->nb_meals)
		res = 1;
	return (res);
}

void	*all_full_routine(void *data_p)
{
	t_data *data;
	int i;
	int nb;

	data = (t_data *)data_p;
	nb = get_nb_philos(data);
	i = -1;
	while (++i < nb && keep(data))
	{
		// why usleep in some placeses
		usleep(1000);
		if (is_philo_full(data, &data->philos[i]) == 0)
			i = -1;
	}
	if (keep(data) == 1)
	{
		set_keep(data, 0);
		notify(data);
	}
	return (NULL);
}