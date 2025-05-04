/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:53:42 by tmidik            #+#    #+#             */
/*   Updated: 2025/05/04 15:55:30 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	init_data(t_data *data, int ac, char **av)
{
	data->number_of_philo = ft_atoi(av[1]);
	data->time_to_eat = ft_atoi(av[2]);
	data->time_to_sleep = ft_atoi(av[3]);
	data->time_to_die = ft_atoi(av[4]);
	data->is_philo_died = 0;
	if (ac == 6)
		data->each_philosophers_must_eat = ft_atoi(av[5]);
	else
		data->each_philosophers_must_eat = 0;
}

int	init_philosophers(t_data *data)
{
	int	i;

	data->philosophers = malloc(sizeof(t_philo) * data->number_of_philo);
	if (!data->philosophers)
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philo);
	if (!data->forks)
		return (1);
	i = 0;
	while (i < data->number_of_philo)
		pthread_mutex_init(&data->forks[i++], NULL);
	i = 0;
	while (i < data->number_of_philo)
	{
		data->philosophers[i].id = i + 1;
		data->philosophers[i].data = data;
		data->philosophers[i].left_fork = &data->forks[i];
		data->philosophers[i].right_fork = &data->forks[(i + 1) % data->number_of_philo];
		data->philosophers[i].last_meal_time = 0;
		data->philosophers[i].meals_eaten = 0;
		i++;
	}
	pthread_mutex_init(&data->death_lock, NULL);
	return (0);
}
int	init_threads(t_data *data)
{
	int			i;
	pthread_t	*threads;
	pthread_t	control_thread;
	
	threads = malloc(sizeof(pthread_t) * data->number_of_philo);
	if (!threads)
		return (1);
	i = 0;
	while (i < data->number_of_philo)
	{
		if (pthread_create(&threads[i], NULL, life_cycle, &data->philosophers[i]))
			return (1);
		i++;
	}
	// ✅ Kontrol thread'i başlatılır (ölüm veya everyone_ate kontrolü)
	if (pthread_create(&control_thread, NULL, life_cycle_control, data))
		return (1);
	pthread_detach(control_thread); // join yerine detach kullanabilirsin
	i = 0;
	while (i < data->number_of_philo)
		pthread_join(threads[i++], NULL);
	free(threads);
	return (0);
}

