/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilc4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <ielhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:33:43 by ielhasso          #+#    #+#             */
/*   Updated: 2024/03/08 17:37:49 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int takeforks(t_philo *philo)
{
   if (get_nb_philos(philo->data) == 1)
        return (handle_1_philo(philo));
    if (take_right_fork(philo) != 0)
        return (1);
    if (take_left_fork(philo) != 0)
    {
        drop_right_fork(philo);
        return (1);
    }
    return (0);
}

int eat(t_philo *philo)
{
    if (takeforks(philo) != 0)
        return (1);
}