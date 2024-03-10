/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilc8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <ielhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:28:52 by ielhasso          #+#    #+#             */
/*   Updated: 2024/03/10 12:29:12 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void drop_forks(t_philo *philo)
{
    pthread_mutex_unlock(philo->left_f);
    pthread_mutex_unlock(philo->right_f);
}