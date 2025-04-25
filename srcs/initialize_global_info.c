/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:20:34 by ascordil          #+#    #+#             */
/*   Updated: 2025/03/31 12:04:24 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/philo.h>

int	control_input_and_init_global(char **args, t_global *global_info)
{
	int	error;

	error = 0;
	global_info->nb_of_philo = ft_atol_with_only_digit(args[1], &error);
	if (global_info->nb_of_philo <= 0)
		return (0);
	global_info->time_to_die = ft_atol_with_only_digit(args[2], &error);
	global_info->time_to_eat = ft_atol_with_only_digit(args[3], &error);
	global_info->time_to_sleep = ft_atol_with_only_digit(args[4], &error);
	global_info->mute_print = -1;
	global_info->one_philo_dead = 0;
	global_info->stop_dinner = 0;
	global_info->start_dinner = 0;
	global_info->nb_eat_oblig = -1;
	global_info->time_to_think = (global_info->time_to_die
			- (global_info->time_to_eat + global_info->time_to_sleep)) / 2 ;
	if (args[5])
	{
		global_info->nb_eat_oblig = ft_atol_with_only_digit(args[5], &error);
		if (global_info->nb_eat_oblig == 0)
			return (0);
	}
	if (error || !(init_mutex(global_info)))
		return (0);
	return (1);
}

int	init_mutex(t_global *global_info)
{
	if (pthread_mutex_init(&global_info->mutex_stop, NULL) < 0)
		return (0);
	if (pthread_mutex_init(&global_info->mutex_data, NULL) < 0)
		return (0);
	if (pthread_mutex_init(&global_info->mutex_write, NULL) < 0)
		return (0);
	if (!init_forks_mutex(global_info))
		return (0);
	return (1);
}

int	init_forks_mutex(t_global *global)
{
	int	i;

	i = 0 ;
	if (!global->nb_of_philo)
		return (0);
	global->mutex_forks = malloc(sizeof(pthread_mutex_t)
			* global->nb_of_philo);
	if (!global->mutex_forks)
		return (0);
	while (i < global->nb_of_philo)
	{
		if (pthread_mutex_init(&global->mutex_forks[i], NULL) < 0)
			return (0);
		i++;
	}
	return (1);
}
