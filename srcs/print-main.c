/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:55:41 by ascordil          #+#    #+#             */
/*   Updated: 2025/03/31 11:35:23 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/philo.h>

void	print_action(t_philo *philo, int action, int lock_print_after)
{
	(void)lock_print_after;
	pthread_mutex_lock(&philo->glob->mutex_stop);
	if (philo->glob->mute_print == 1)
	{
		pthread_mutex_unlock(&philo->glob->mutex_stop);
		return ;
	}
	pthread_mutex_unlock(&philo->glob->mutex_stop);
	pthread_mutex_lock(&philo->glob->mutex_write);
	if (action == EAT)
		print_eat(philo);
	else if (action == THINK)
		print_think(philo);
	else if (action == FORK)
		print_fork(philo);
	else if (action == SLEEP)
		print_sleep(philo);
	else if (action == DIE)
		print_die(philo);
	pthread_mutex_unlock(&philo->glob->mutex_write);
	return ;
}

void	to_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
		eat_even(philo);
	else
		eat_odd(philo);
}

void	to_sleep(t_philo *philo)
{
	print_action(philo, SLEEP, 0);
	tic_tac(philo->glob->time_to_sleep);
}

void	to_think(t_philo *philo)
{
	print_action(philo, THINK, 0);
}

void	to_die(t_philo *philo)
{
	print_die(philo);
}
