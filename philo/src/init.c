/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:05:20 by hdaher            #+#    #+#             */
/*   Updated: 2024/08/26 15:18:36 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philo(t_philo *philo, t_data *data, int i, char **av)
{
	philo->id = i + 1;
	philo->is_end = &data->is_end;
	philo->message_lock = &data->message_lock;
	philo->dead_lock = &data->dead_lock;
	philo->meal_lock = &data->meal_lock;
	philo->meals_eaten = 0;
	philo->last_meal = 0;
	philo->number_of_philosophers = data->number_of_philosophers;
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->max_eating = ft_atoi(av[5]);
	else
		philo->max_eating = -1;
	philo->start_time = get_time();
	philo->fork_l = &data->forks[i];
	philo->fork_r = &data->forks[(i + 1) % ft_atoi(av[1])];
}

int	create_philos(t_data *data, char **av)
{
	t_philo	**philos;
	int		i;

	i = 0;
	philos = malloc((ft_atoi(av[1]) + 1) * sizeof(t_philo *));
	if (!philos)
		return (0);
	while (i < ft_atoi(av[1]))
	{
		philos[i] = malloc(sizeof(t_philo));
		if (!philos[i])
			return (ft_free_tab((void **)philos), 0);
		init_philo(philos[i], data, i, av);
		i++;
	}
	philos[i] = NULL;
	data->philos = philos;
	return (1);
}

int	create_forks(t_data *data, int philo_nb)
{
	int				i;
	pthread_mutex_t	*forks;

	i = 0;
	forks = malloc(philo_nb * sizeof(pthread_mutex_t));
	if (!forks)
		return (0);
	while (i < philo_nb)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	data->forks = forks;
	return (1);
}

int	create_threads(t_data *data)
{
	int		i;

	i = 0;
	if (pthread_create(&data->monitor,
			NULL, monitoring, (void *) data) != 0)
		return (0);
	while (i < data->number_of_philosophers)
	{
		if (pthread_create(&data->philos[i]->philo_thread,
				NULL, philo_routine, (void *) data->philos[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}
