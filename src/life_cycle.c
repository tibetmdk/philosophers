/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:03:16 by tmidik            #+#    #+#             */
/*   Updated: 2025/05/04 15:55:13 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_action(philo,"has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print_action(philo,"has taken a fork");
	print_action(philo, "is eating");
	philo->last_meal_time = get_time();
	philo->meals_eaten++;
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}

int	philo_sleep(t_philo *philo)
{
	print_action(philo, "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
	return (0);
}

int	philo_think(t_philo *philo)
{
	print_action(philo, "is thinking");
	usleep(1000);
	return (0);
}

void	*life_cycle(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;

	if (philo->id % 2 == 0)
		usleep(1000);

	while (1)
	{
		pthread_mutex_lock(&philo->data->death_lock);
		if (philo->data->is_philo_died)
		{
			pthread_mutex_unlock(&philo->data->death_lock);
			break;
		}
		pthread_mutex_unlock(&philo->data->death_lock);

		philo_eat(philo);

		if (philo->data->each_philosophers_must_eat > 0 &&
			philo->meals_eaten >= philo->data->each_philosophers_must_eat)
			break;

		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

