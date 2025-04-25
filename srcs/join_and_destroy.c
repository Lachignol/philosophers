/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:20:34 by ascordil          #+#    #+#             */
/*   Updated: 2025/03/25 19:00:42 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/philo.h>

int	join_philosophers(t_global *global_info, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < global_info->nb_of_philo)
	{
		if (pthread_join(philo[i].thread_pid, NULL) != 0)
			return (err_thread_join(), 0);
	}
	i = -1;
	while (++i < global_info->nb_of_philo)
	{
		pthread_mutex_destroy(&global_info->mutex_forks[i]);
	}
	free(global_info->mutex_forks);
	return (1);
}
