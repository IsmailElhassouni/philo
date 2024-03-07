/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilc3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <ielhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:38:53 by ielhasso          #+#    #+#             */
/*   Updated: 2024/03/07 12:28:14 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int fork_int(t_data *data)
{
    int     i;
    t_philo *philos;

    philos = data->philos;
    i =-1;
    while (i++ < data->nb_philos)
        pthread_mutex_init(&data->forks[i], NULL);
    i = 0;
    philos[0].left_f= &data->forks[0];
    philos[0].right_f = &data->forks[&data->nb_philos-1];
    while (++i < data->nb_philos)
    {
        philos[i].left_f = &data->forks[i];
        philos[i].right_f = &data->forks[i-1];
    }
    return (0);
}

int get_nb_philos(t_data *data)
{
    int nb;
    pthread_mutex_lock(&data->mut_keep_iter);
    keep = data->keep_iterating;
    pthread_mutex_unlock(&data->mut_keep_iter);
    return (keep);
}

int thread_runs(t_data *data)
{
    int i;
    int nb_of_philos;

    nb_of_philos = get_nb_philos(data);
}