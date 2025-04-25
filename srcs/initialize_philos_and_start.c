/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:20:34 by ascordil          #+#    #+#             */
/*   Updated: 2025/03/29 00:04:22 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/philo.h>

int	init_philosophers(t_global *global_info, t_philo **philo)
{
	int	i;

	i = -1;
	*philo = malloc(sizeof(t_philo) * global_info->nb_of_philo);
	if (!*philo)
		return (0);
	while (++i < global_info->nb_of_philo)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].nbr_of_eat = 0;
		(*philo)[i].is_full = 0;
		(*philo)[i].last_meal = global_info->time_start_prog;
		(*philo)[i].fork_l = &global_info->mutex_forks[i];
		(*philo)[i].fork_r = &global_info->mutex_forks[((i + 1)
				% global_info->nb_of_philo)];
		(*philo)[i].glob = global_info;
	}
	return (1);
}

int	choose_one_or_multiple_philo(t_philo *philo, t_global *glob)
{
	int					nbr_philo;

	nbr_philo = glob->nb_of_philo;
	if (nbr_philo == 1)
	{
		if (!one_philo_start(philo, glob))
			return (0);
		free(glob->mutex_forks);
	}
	else
	{
		if (!multiple_philos_start(philo, glob, nbr_philo))
			return (0);
		my_cctv(philo);
		if (!join_philosophers(glob, philo))
			return (err_thread_join(), 0);
	}
	return (1);
}

int	one_philo_start(t_philo *philo, t_global *glob)
{
	struct timeval		prog_start_time;

	if (gettimeofday(&prog_start_time, NULL) != 0)
		return (0);
	glob->time_start_prog = (prog_start_time.tv_sec * 1000)
		+ (prog_start_time.tv_usec / 1000);
	philo[0].last_meal = get_time();
	life_of_one_philo(&philo[0]);
	return (1);
}

int	multiple_philos_start(t_philo *philo, t_global *glob, int nbr_philo)
{
	int					i;

	i = -1;
	while (++i < nbr_philo)
	{
		if (pthread_create(&philo[i].thread_pid, NULL,
				&life_of_philosophers, (void *)&philo[i]) != 0)
			return (err_thread_create(), 0);
	}
	if (!start_dinner(philo, glob, nbr_philo))
		return (0);
	return (1);
}

int	start_dinner(t_philo *philo, t_global *glob, int nbr_philo)
{
	struct timeval		prog_start_time;
	int					i;

	i = -1;
	if (gettimeofday(&prog_start_time, NULL) != 0)
		return (0);
	glob->time_start_prog = (prog_start_time.tv_sec * 1000)
		+ (prog_start_time.tv_usec / 1000);
	pthread_mutex_lock(&glob->mutex_data);
	while (++i < nbr_philo)
		philo[i].last_meal = glob->time_start_prog;
	glob->start_dinner = 1;
	pthread_mutex_unlock(&glob->mutex_data);
	return (1);
}
