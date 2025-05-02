/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:54:06 by tmidik            #+#    #+#             */
/*   Updated: 2025/05/02 17:18:18 by tmidik           ###   ########.fr       */
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
	philo->last_meal_time = //get_time();
	usleep(philo->data->time_to_eat);
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
	usleep(100);
	return (0);
}

void	*life_cycle(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}	
}
