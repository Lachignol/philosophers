/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:20:34 by ascordil          #+#    #+#             */
/*   Updated: 2025/03/31 11:58:57 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/philo.h>

long	ft_atol_with_only_digit(char *nbr, int *error)
{
	long		result;
	int			signe;

	result = 0;
	signe = 1;
	if (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
		{
			*error = 1;
			signe *= -1;
		}
		nbr++;
	}
	while (*nbr <= '9' && *nbr >= '0')
	{
		result *= 10;
		result += *nbr - 48;
		nbr++;
	}
	if (*nbr && !(*nbr <= '9' && *nbr >= '0'))
	{
		return (*error = 1, -1);
	}
	return (result * signe);
}

void	tic_tac(time_t time)
{
	time_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(10);
}

time_t	get_timestamp(t_philo philo)
{
	struct timeval		current_time;
	time_t				time_stamp;
	time_t				time;
	time_t				start_prog;

	start_prog = philo.glob->time_start_prog;
	if (gettimeofday(&current_time, NULL) != 0)
		return (0);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	time_stamp = (time - start_prog);
	return (time_stamp);
}

time_t	get_time(void)
{
	struct timeval		current_time;
	long				time;

	if (gettimeofday(&current_time, NULL) != 0)
		return (0);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
