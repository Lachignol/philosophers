/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:55:54 by ascordil          #+#    #+#             */
/*   Updated: 2025/03/31 11:58:59 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define NIMPORTE 50

enum e_actions
{
	EAT,
	THINK,
	FORK,
	SLEEP,
	DIE,
};

typedef struct s_global
{
	time_t								time_start_prog;
	int									nb_of_philo;
	time_t								time_to_die;
	time_t								time_to_eat;
	time_t								time_to_sleep;
	time_t								time_to_think;
	int									mute_print;
	int									one_philo_dead;
	int									start_dinner;
	int									stop_dinner;
	int									nb_eat_oblig;
	pthread_mutex_t						*mutex_forks;
	pthread_mutex_t						mutex_write;
	pthread_mutex_t						mutex_stop;
	pthread_mutex_t						mutex_data;
	struct s_philo						**philo;

}	t_global;

typedef struct s_philo
{
	int								id;
	int								nbr_of_eat;
	int								is_full;
	time_t							last_meal;
	pthread_t						thread_pid;
	pthread_mutex_t					*fork_l;
	pthread_mutex_t					*fork_r;
	t_global						*glob;
}	t_philo;

//check_and_init
int				control_input_and_init_global(char **args,
					t_global *global_info);
//function init - strucfunc
int				init_global_info(t_global *global);
int				init_philosophers(t_global *global_info, t_philo **philo);
int				join_philosophers(t_global *global_info, t_philo *philo);
int				init_mutex(t_global *global_info);
int				init_forks_mutex(t_global *global);
//function - life_of_philosophers 
int				start_dinner(t_philo *philo, t_global *glob, int nbr_philo);
int				one_philo_start(t_philo *philo, t_global *glob);
int				multiple_philos_start(t_philo *philo,
					t_global *glob, int nbr_philo);
int				choose_one_or_multiple_philo(t_philo *philo, t_global *glob);
void			*life_of_philosophers(void *philo_arg);
void			*life_of_one_philo(void *philo_arg);
//function -supervisor 
void			*my_cctv(t_philo *philo);
int				check_full_meal(t_philo *philo, t_global *glob,
					int nb_philo, int nb_meal_oblig);
int				check_dead(t_philo *philo, t_global *glob,
					int nb_philo, int time_die);
int				check_no_die_or_stop(t_philo *philo);
//function - actions 
void			to_sleep(t_philo *philo);
void			to_think(t_philo *philo);
void			to_eat(t_philo *philo);
void			eat_odd(t_philo *philo);
void			eat_even(t_philo *philo);
void			to_die(t_philo *philo);
//function - print
void			print_action(t_philo *philo, int action, int lock_after_print);
void			print_fork(t_philo *philo);
void			print_think(t_philo *philo);
void			print_sleep(t_philo *philo);
void			print_eat(t_philo *philo);
void			print_die(t_philo *philo);
//function - time
void			tic_tac(time_t time);
time_t			get_timestamp(t_philo philo);
time_t			get_time(void);
//function error
void			err_thread_create(void);
void			err_format_args(void);
void			err_thread_join(void);
void			err_parsing(void);
void			err_init(void);
//function helpers 
long			ft_atol_with_only_digit(char *nbr, int *error);
int				ft_strcmp(char *s1, char *s2);
// void			free_philo(t_philo **philo);
void			ft_free_tab(char **tab);
#endif
