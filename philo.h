/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <ielhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:03:38 by ielhasso          #+#    #+#             */
/*   Updated: 2024/03/09 19:05:24 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

typedef enum e_philo_state
{
	E = 0,
	S = 1,
	T = 2,
	D = 3,
	F = 4,
	I = 5
}					t_state;

struct	s_data;

typedef unsigned long long u_int64_t;
typedef unsigned long long uint64_t;
typedef struct s_philo
{
	int				id;
	int				nb_meals_had;
	struct s_data	*data;
	t_state			state;
	pthread_mutex_t	*left_f;
	pthread_mutex_t	*right_f;
	pthread_mutex_t	mut_state;
	pthread_mutex_t	mut_nb_meals_had;
	pthread_mutex_t	mut_last_eat_time;
	u_int64_t		last_eat_time;
}					t_philo;

typedef struct s_data
{
	int				nb_philos;
	int				nb_meals;
	int				nb_full_p;
	int				keep_iterating;
	u_int64_t		eat_time;
	u_int64_t		die_time;
	u_int64_t		sleep_time;
	u_int64_t		start_time;
	pthread_mutex_t	mut_eat_t;
	pthread_mutex_t	mut_die_t;
	pthread_mutex_t	mut_sleep_t;
	pthread_mutex_t	mut_print;
	pthread_mutex_t	mut_nb_philos;
	pthread_mutex_t	mut_keep_iter;
	pthread_mutex_t	mut_start_time;
	pthread_t		monit_all_alive;
	pthread_t		monit_all_full;
	pthread_t		*philo_ths;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}					t_data;
long				ft_atoi(const char *str);
u_int64_t			gettime(void);
void				update_meal_time(t_philo *philo);
int					fork_int(t_data *data);
int					thread_runs(t_data *data);
int					get_nb_philos(t_data *data);
uint64_t			get_die_time(t_data *data);
void				set_philo_state(t_philo *philo, t_state state);
void 				ft_usleep(uint64_t sleep_time);
void				update_nb_meals_had(t_philo *philo);
uint64_t			get_sleep_time(t_data *data);
t_state 			get_state(t_philo *philo);
void				*all_alive_routine(void *data_p);
void 				set_keep(t_data *data, int set_to);
void 				notify(t_data *data);
int					nb_meals_option(t_data *data);
int 				keep(t_data *data);
void				*all_full_routine(void *data_p);
int 				threads_join(t_data *data);
void 				free_memory(t_data *data);