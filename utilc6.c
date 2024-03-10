#include "philo.h"

int	get_nb_meals_philo_had(t_philo *philo)
{
	int	nb_meals_had;

	pthread_mutex_lock(&philo->mut_nb_meals_had);
	nb_meals_had = philo->nb_meals_had;
	pthread_mutex_unlock(&philo->mut_nb_meals_had);
	return (nb_meals_had);
}

int	thread_join(t_data *data)
{
	int	i;
	int	nb;

	nb = get_nb_philos(data);
	i = -1;
	if (pthread_join(data->monit_all_alive, NULL))
		return (1);
	if (nb_meals_option(data) == 1 && pthread_join(data->monit_all_full, NULL))
		return (1);
	while (++i < nb)
	{
		if (pthread_join(data->philo_ths[i], NULL))
			return (1);
	}
	return (0);
}
// all of free need a revice
void	free_memory(t_data *data)
{
	int	i;
	int	nb;

	nb = get_nb_philos(data);
	i = -1;
	while (++i < nb)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].mut_state);
		pthread_mutex_destroy(&data->philos[i].mut_nb_meals_had);
		pthread_mutex_destroy(&data->philos[i].mut_last_eat_time);
	}
	pthread_mutex_destroy(&data->mut_die_t);
	pthread_mutex_destroy(&data->mut_eat_t);
	pthread_mutex_destroy(&data->mut_sleep_t);
	pthread_mutex_destroy(&data->mut_nb_philos);
	pthread_mutex_destroy(&data->mut_print);
	pthread_mutex_destroy(&data->mut_keep_iter);
	pthread_mutex_destroy(&data->mut_start_time);
	free(data->philo_ths);
	free(data->philos);
	free(data->forks);
}
u_int64_t	get_start_time(t_data *data)
{
	u_int64_t	start_time;

	pthread_mutex_lock(&data->mut_start_time);
	start_time = data->start_time;
	pthread_mutex_unlock(&data->mut_start_time);
	return (start_time);
}

void	print_msg(t_data *data, int id, char *msg)
{
	uint64_t time;
	time = gettime() - get_start_time(data);
	pthread_mutex_lock(&data->mut_print);
	if (keep(data))
		printf("%llu %d %s\n", time, id, msg);
	pthread_mutex_unlock(&data->mut_print);
}
