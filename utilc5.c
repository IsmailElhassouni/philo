/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilc4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <ielhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:13:43 by ielhasso          #+#    #+#             */
/*   Updated: 2024/03/08 17:37:49 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
uint64_t	get_die_time(t_data *data)
{
    uint64_t	die_time;

    pthread_mutex_lock(&data->mut_die_t);
    die_time = data->die_time;
    pthread_mutex_unlock(&data->mut_die_t);
    return (die_time);
}