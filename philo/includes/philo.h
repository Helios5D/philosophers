/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 08:13:11 by hdaher            #+#    #+#             */
/*   Updated: 2024/08/26 12:23:53 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/// Includes ///

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

/// Defines ///

# define ARG_NB_ERR "Error\nWrong number of arguments."
# define ARG_ERR "Error\nInvalid argument(s) found."

/// Structures ///

typedef struct s_philo {
	pthread_t		philo_thread;
	int				id;
	int				meals_eaten;
	int				last_meal;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_eating;
	pthread_mutex_t	*message_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*dead_lock;
	int				*is_end;
	int				start_time;
}	t_philo;

typedef struct s_data {
	pthread_t		monitor;
	int				number_of_philosophers;
	int				is_end;
	pthread_mutex_t	*forks;
	pthread_mutex_t	message_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	t_philo			**philos;
}	t_data;

/// Prototypes ///

// init.c
int		create_forks(t_data *data, int philo_nb);
int		create_threads(t_data *data);
int		create_philos(t_data *data, char **av);

// main.c
char	*get_random_food(void);

// monitoring.c
void	*monitoring(void *data_ptr);
int		get_time(void);
void	write_message(t_philo *philo, char *str);

// parsing.c
int		get_data(t_data *data, char **av);

// philo.c
void	*philo_routine(void *philo_ptr);

// utils_1.c
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *nptr);
int		ft_isnumber(char *str);
int		ft_strlen(char *str);
void	ft_free_tab(void **tab);

#endif
