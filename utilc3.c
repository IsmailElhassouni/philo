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
    pthread_mutex_lock(&data->mut_nb_philos);
   nb = data->nb_philos;
    pthread_mutex_unlock(&data->mut_nb_philos);
    return (nb);
}
void *routine(void *philo_p)
{
    t_philo *philo;

    philo = (t_philo)
}
int thread_runs(t_data *data)
{
    int i;
    int nb_of_philos;

    nb_of_philos = get_nb_philos(data);
    i =-1;
    data->start_time = gettime();
    while(++i < nb_of_philos)
    {
        if (pthread_create(&data->philo_ths[i],NULL,&routine,&data->philos[i]))
            return (-84);
    }
    if (pthread_create(&data->monit_all_alive, NULL , &all_alive_routine, data))
        return (-85);
   // if (nb_meals_option(&data) == true && pthread_create)
}