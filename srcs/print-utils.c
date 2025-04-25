/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:20:34 by ascordil          #+#    #+#             */
/*   Updated: 2025/03/27 03:36:20 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/philo.h>

void	print_fork(t_philo *philo)
{
	printf("%ld %d has taken a fork\n", get_timestamp(*philo), philo->id);
}

void	print_eat(t_philo *philo)
{
	printf("%ld %d is eating\n", get_timestamp(*philo), philo->id);
}

void	print_sleep(t_philo *philo)
{
	printf("%ld %d is sleeping\n", get_timestamp(*philo), philo->id);
}

void	print_think(t_philo *philo)
{
	printf("%ld %d is thinking\n", get_timestamp(*philo), philo->id);
}

void	print_die(t_philo *philo)
{
	printf("%ld %d died\n", get_timestamp(*philo), philo->id);
}
