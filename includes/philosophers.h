/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 01:17:22 by tmidik            #+#    #+#             */
/*   Updated: 2025/05/01 01:20:55 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSPHERS_H

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>

typedef struct s_data
{
	int			number_of_philo;
	int			time_to_eat;
	int			time_to_sleep;
	int			time_to_die;
	int			each_philosophers_must_eat;
}				t_data;
#endif