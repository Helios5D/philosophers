/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:42:22 by hdaher            #+#    #+#             */
/*   Updated: 2024/08/26 15:23:35 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_philo_death(t_data *data, int i)
{
	if (data->philos[i]->time_to_die + data->philos[i]->last_meal
		< get_time() - data->philos[i]->start_time)
	{
		write_message(data->philos[i], "died 🪦\n");
		pthread_mutex_lock(&data->dead_lock);
		data->is_end = 1;
		pthread_mutex_unlock(&data->dead_lock);
		return (1);
	}
	return (0);
}

static int	is_end(t_data *data)
{
	int	i;
	int	full_philos;

	i = 0;
	full_philos = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_lock(data->philos[i]->meal_lock);
		if (data->philos[i]->meals_eaten >= data->philos[i]->max_eating
			&& data->philos[i]->max_eating >= 0)
			full_philos++;
		if (check_philo_death(data, i))
			return (pthread_mutex_unlock(data->philos[i]->meal_lock), 1);
		pthread_mutex_unlock(data->philos[i]->meal_lock);
		i++;
	}
	if (full_philos == data->number_of_philosophers)
	{
		pthread_mutex_lock(&data->dead_lock);
		data->is_end = 1;
		pthread_mutex_unlock(&data->dead_lock);
		return (1);
	}
	return (0);
}

void	*monitoring(void *data_ptr)
{
	t_data	*data;

	data = data_ptr;
	while (1)
	{
		if (is_end(data))
			return (NULL);
		usleep(50);
	}
	return (data_ptr);
}

int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((int)(time.tv_sec * 1000 + time.tv_usec / 1000));
}

void	write_message(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*(philo->is_end) == 0)
	{
		pthread_mutex_unlock(philo->dead_lock);
		pthread_mutex_lock(philo->message_lock);
		printf("%d %d %s", get_time() - philo->start_time, philo->id, str);
		pthread_mutex_unlock(philo->message_lock);
	}
	else
		pthread_mutex_unlock(philo->dead_lock);
}
