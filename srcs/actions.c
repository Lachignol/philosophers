/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:55:41 by ascordil          #+#    #+#             */
/*   Updated: 2025/04/03 14:56:41 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/philo.h>

void	eat_even(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_r);
	print_action(philo, FORK, 0);
	pthread_mutex_lock(philo->fork_l);
	print_action(philo, FORK, 0);
	pthread_mutex_lock(&philo->glob->mutex_data);
	print_action(philo, EAT, 0);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->glob->mutex_data);
	tic_tac(philo->glob->time_to_eat);
	pthread_mutex_lock(&philo->glob->mutex_data);
	philo->nbr_of_eat++;
	pthread_mutex_unlock(&philo->glob->mutex_data);
	pthread_mutex_unlock(philo->fork_r);
	pthread_mutex_unlock(philo->fork_l);
}

void	eat_odd(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_l);
	print_action(philo, FORK, 0);
	pthread_mutex_lock(philo->fork_r);
	print_action(philo, FORK, 0);
	pthread_mutex_lock(&philo->glob->mutex_data);
	print_action(philo, EAT, 0);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->glob->mutex_data);
	tic_tac(philo->glob->time_to_eat);
	pthread_mutex_lock(&philo->glob->mutex_data);
	philo->nbr_of_eat++;
	pthread_mutex_unlock(&philo->glob->mutex_data);
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
}
