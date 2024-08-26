/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 08:59:28 by hdaher            #+#    #+#             */
/*   Updated: 2024/08/26 15:23:42 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_usleep(int time, t_philo *philo)
{
	int	start;

	start = get_time();
	while ((get_time() - start) < time)
	{
		pthread_mutex_lock(philo->dead_lock);
		if (*(philo->is_end))
			return (pthread_mutex_unlock(philo->dead_lock), 0);
		pthread_mutex_unlock(philo->dead_lock);
		usleep(500);
	}
	return (1);
}

static void	eating(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->fork_l);
		write_message(philo, "has taken a fork 🍴\n");
		pthread_mutex_lock(philo->fork_r);
		write_message(philo, "has taken a fork 🍴\n");
	}
	else
	{
		pthread_mutex_lock(philo->fork_r);
		write_message(philo, "has taken a fork 🍴\n");
		pthread_mutex_lock(philo->fork_l);
		write_message(philo, "has taken a fork 🍴\n");
	}
	write_message(philo, get_random_food());
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_time() - philo->start_time;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat, philo);
	pthread_mutex_lock(philo->meal_lock);
	philo->meals_eaten += 1;
	pthread_mutex_unlock(philo->meal_lock);
	pthread_mutex_unlock(philo->fork_r);
	pthread_mutex_unlock(philo->fork_l);
}

static void	sleeping(t_philo *philo)
{
	write_message(philo, "is sleeping 🛏️\n");
	ft_usleep(philo->time_to_sleep, philo);
}

static void	thinking(t_philo *philo)
{
	int	thinking_time;

	thinking_time = philo->time_to_die - philo->time_to_eat
		- philo->time_to_sleep - 5;
	if (thinking_time < 0)
		thinking_time = 0;
	write_message(philo, "is thinking 🧠\n");
	ft_usleep(thinking_time, philo);
}

void	*philo_routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = philo_ptr;
	if (philo->number_of_philosophers == 1)
	{
		pthread_mutex_lock(philo->fork_r);
		write_message(philo, "has taken a fork 🍴\n");
		ft_usleep(philo->time_to_die, philo);
		pthread_mutex_unlock(philo->fork_r);
		return (philo_ptr);
	}
	while (1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
		pthread_mutex_lock(philo->dead_lock);
		if (*(philo->is_end))
			break ;
		pthread_mutex_unlock(philo->dead_lock);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (philo_ptr);
}
