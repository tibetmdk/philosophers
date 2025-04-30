/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 01:12:45 by tmidik            #+#    #+#             */
/*   Updated: 2025/05/01 01:21:32 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
int main() //  ./philosophers number_of_philo | time_to_eat | time_to_sleep | time_to_die | each_philosophers_must_eat
{
	t_data	*data;
	
	data = (t_data *)malloc(sizeof(t_data));
	init_all();
}
