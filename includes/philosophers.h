/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 01:17:22 by tmidik            #+#    #+#             */
/*   Updated: 2025/05/01 14:54:57 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
#include <pthread.h>

typedef	struct s_philo t_philo;

typedef struct s_data
{
	int				number_of_philo;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				each_philosophers_must_eat;
	t_philo			*philosopher;
	pthread_mutex_t	*forks;
}				t_data;

struct s_philo
{
	int				id;
	int				last_meal_time;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
};



int		ft_atoi(const char *str);


int		init_philosophers(t_data *data);
int		init_threads(t_data *data);
int		life_cyle(t_data *data);
void	init_data(t_data *data, int ac, char **av);


#endif