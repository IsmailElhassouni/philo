/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilc4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <ielhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:33:43 by ielhasso          #+#    #+#             */
/*   Updated: 2024/03/10 12:28:35 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_l_fork(t_philo *philo)
{
	if (philo_died(philo) || get_state(philo) == D)
		return (1);
	pthread_mutex_lock(philo->left_f);
	print_msg(philo->data, philo->id, "has taken a fork");
	return (0);
}

void	set_philo_state(t_philo *philo, t_state state)
{
	pthread_mutex_lock(&philo->mut_state);
	if (philo->state != D)
		philo->state = state;
	pthread_mutex_unlock(&philo->mut_state);
}

int	one_philo(t_philo *philo)
{
	take_l_fork(philo);
	ft_usleep(get_die_time(philo->data));
	set_philo_state(philo, D);
	return (1);
}

int	take_r_fork(t_philo *philo)
{
	if (philo_died(philo) || get_state(philo) == D)
		return (1);
	pthread_mutex_lock(philo->right_f);
	print_msg(philo->data, philo->id, "has taken a fork");
	return (0);
}

int	takeforks(t_philo *philo)
{
	if (get_nb_philos(philo->data) == 1)
		return (one_philo(philo));
	if (take_r_fork(philo) != 0)
		return (1);
	if (take_l_fork(philo) != 0)
	{
		drop_right_fork(philo);
		return (1);
	}
	return (0);
}

int	eat(t_philo *philo)
{
	if (takeforks(philo) != 0)
		return (1);
	set_philo_state(philo, E);
	print_msg(philo->data, philo->id, "is eating");
	update_meal_time(philo);
	sleep_for_eating(philo);
	update_nb_meals_had(philo);
	drop_forks(philo);
	return (0);
}