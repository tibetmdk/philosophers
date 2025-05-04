/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:03:11 by tmidik            #+#    #+#             */
/*   Updated: 2025/05/04 15:39:48 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*life_cycle_control(void *arg)
{
	t_data *data = (t_data *)arg;
	int i;
	int full_philo_count;

	while (1)
	{
		full_philo_count = 0;
		i = 0;
		while (i < data->number_of_philo)
		{
			if (data->each_philosophers_must_eat > 0 &&
				data->philosophers[i].meals_eaten >= data->each_philosophers_must_eat)
				full_philo_count++;
			i++;
		}
		if (data->each_philosophers_must_eat > 0 &&
			full_philo_count == data->number_of_philo)
		{
			pthread_mutex_lock(&data->death_lock);
			data->is_philo_died = 1;
			pthread_mutex_unlock(&data->death_lock);
			return (NULL);
		}
		usleep(1000);
	}
}
