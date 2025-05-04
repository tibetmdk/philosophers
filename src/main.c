/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:03:27 by tmidik            #+#    #+#             */
/*   Updated: 2025/05/04 15:03:30 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
		return (printf("Usage: ./philo number time_to_die time_to_eat time_to_sleep [meals]\n"), 1);
	init_data(&data, ac, av);
	if (init_philosophers(&data))
		return (1);
	if (init_threads(&data))
		return (1);
	return (0);
}

