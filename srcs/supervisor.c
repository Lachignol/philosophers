/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:20:34 by ascordil          #+#    #+#             */
/*   Updated: 2025/03/31 11:55:29 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/philo.h>

int	check_no_die_or_stop(t_philo *philo)
{
	pthread_mutex_lock(&philo->glob->mutex_stop);
	if (philo->glob->stop_dinner)
	{
		pthread_mutex_unlock(&philo->glob->mutex_stop);
		return (0);
	}
	pthread_mutex_unlock(&philo->glob->mutex_stop);
	return (1);
}

int	check_dead(t_philo *philo, t_global *glob, int nb_philo, int time_die)
{
	int	i;

	i = -1;
	while (++i < nb_philo)
	{
		pthread_mutex_lock(&glob->mutex_data);
		if ((get_time() - philo[i].last_meal) > time_die)
		{
			to_die(&philo[i]);
			pthread_mutex_unlock(&glob->mutex_data);
			pthread_mutex_lock(&glob->mutex_stop);
			glob->stop_dinner = 1;
			glob->mute_print = 1;
			pthread_mutex_unlock(&glob->mutex_stop);
			return (1);
		}
		pthread_mutex_unlock(&glob->mutex_data);
		usleep(10);
	}
	return (0);
}

int	check_full_meal(t_philo *philo, t_global *glob, int nb_p, int nb_m)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&glob->mutex_data);
	while ((i < nb_p) && (philo[i].nbr_of_eat >= nb_m))
		i++;
	pthread_mutex_unlock(&glob->mutex_data);
	if (i == nb_p)
	{
		pthread_mutex_lock(&glob->mutex_stop);
		glob->stop_dinner = 1;
		glob->mute_print = 1;
		pthread_mutex_unlock(&glob->mutex_stop);
		return (1);
	}
	return (0);
}

void	*my_cctv(t_philo *philo)
{
	int				nb_philo;
	int				nb_meal_oblig;
	time_t			time_die;
	t_global		*glob;

	glob = philo[0].glob;
	time_die = glob->time_to_die;
	nb_philo = glob->nb_of_philo;
	nb_meal_oblig = glob->nb_eat_oblig;
	while (1)
	{
		if (check_dead(philo, glob, nb_philo, time_die))
			return (NULL);
		if (nb_meal_oblig != -1)
		{
			if (check_full_meal(philo, glob, nb_philo, nb_meal_oblig))
				return (NULL);
		}
	}
	return (NULL);
}
