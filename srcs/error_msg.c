/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:20:34 by ascordil          #+#    #+#             */
/*   Updated: 2025/03/31 12:07:20 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/philo.h>

void	err_thread_create(void)
{
	write(2, "Error during the creation of thread\n", 36);
}

void	err_thread_join(void)
{
	write(2, "Error during the join of thread\n", 32);
}

void	err_format_args(void)
{
	write(2, "format :", 8);
	write(2, "[nb_philos] [time_2_die] [time_2_eat]", 37);
	write(2, "[time_2_sleep] optional (max_meal)\n", 35);
}

void	err_parsing(void)
{
	write(2, "wrong argument ", 15);
	write(2, "nb_philos must be greater than 0 ", 33);
	write(2, "and others equal or highter than 0\n", 35);
}

void	err_init(void)
{
	write(2, "Error initialization of philo\n", 15);
}
