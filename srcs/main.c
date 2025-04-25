/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:20:34 by ascordil          #+#    #+#             */
/*   Updated: 2025/03/31 11:56:02 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/philo.h>

void	*life_of_philosophers(void *philo_arg)
{
	t_philo	*philo;

	philo = (t_philo *)philo_arg;
	while (1)
	{
		pthread_mutex_lock(&philo->glob->mutex_data);
		if (philo->glob->start_dinner == 1)
		{
			pthread_mutex_unlock(&philo->glob->mutex_data);
			break ;
		}
		pthread_mutex_unlock(&philo->glob->mutex_data);
		usleep(10);
	}
	if (philo->id % 2 == 0)
		tic_tac(philo->glob->time_to_eat / 2);
	while (check_no_die_or_stop(philo))
	{
		to_eat(philo);
		if (!check_no_die_or_stop(philo))
			return (NULL);
		to_sleep(philo);
		to_think(philo);
	}
	return (NULL);
}

void	*life_of_one_philo(void *philo_arg)
{
	t_philo	*philo;

	philo = (t_philo *)philo_arg;
	printf("%ld %d has taken a fork\n", get_timestamp(*philo), philo->id);
	tic_tac(philo->glob->time_to_die);
	printf("%ld %d died\n", get_timestamp(*philo), philo->id);
	return (NULL);
}

int	main(int count, char **args)
{
	t_global				glob;
	t_philo					*philo;

	philo = NULL;
	if (count >= 5)
	{
		if (control_input_and_init_global(args, &glob))
		{
			if (!init_philosophers(&glob, &philo))
				return (err_init(), 1);
			if (!choose_one_or_multiple_philo(philo, &glob))
				return (err_thread_create(), 1);
			return (free(philo), 0);
		}
		else
			return (err_parsing(), free(philo), 1);
	}
	return (err_format_args(), 1);
}
