/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilc3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <ielhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:38:53 by ielhasso          #+#    #+#             */
/*   Updated: 2024/03/08 17:33:13 by ielhasso         ###   ########.fr       */
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
    philos[0].right_f = &data->forks[data->nb_philos-1];
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
t_state get_state(t_philo *philo)
{
    t_state state;
    pthread_mutex_lock(&philo->mut_state);
    state = philo->state;
    pthread_mutex_unlock(&philo->mut_state);
    return (state);
}
void *routine(void *philo_p)
{
    t_philo *philo;

    philo = (t_philo *)philo_p;
    update_last_meal_time(philo);
    if (philo->id % 2 == 0)
        ft_usleep(philo->data->eat_time - 10);
    while(get_state(philo) != D)
    {
        if (eat(philo) != 0)
            break;
        if (get_state(philo) == D)
            break;
        if (ft_sleep(philo) != 0)
            break;
        if (get_state(philo) == D)
            break;
        if (think(philo) != 0)
            break;
    }
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
   if (nb_meals_option(&data) == 1 
    && pthread_create(&data->monit_all_full, NULL, &all_full_routine, data))
        return (-86);
    return (0);
}