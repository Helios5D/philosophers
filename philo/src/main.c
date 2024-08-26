/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 08:11:29 by hdaher            #+#    #+#             */
/*   Updated: 2024/08/26 15:23:26 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*get_random_food(void)
{
	int					a;
	unsigned long long	rand;

	a = 0;
	rand = ((unsigned long long)&a) % 10;
	if (rand == 0)
		return ("is eating 🍔\n");
	else if (rand == 2)
		return ("is eating 🥗\n");
	else if (rand == 4)
		return ("is eating 🍕\n");
	else if (rand == 6)
		return ("is eating 🍗\n");
	else
		return ("is eating 🥐\n");
}

static void	free_all(t_data *data)
{
	int	i;

	i = 0;
	while (data->philos[i])
	{
		pthread_mutex_destroy(&data->forks[i]);
		free(data->philos[i]);
		i++;
	}
	pthread_mutex_destroy(&data->dead_lock);
	pthread_mutex_destroy(&data->meal_lock);
	pthread_mutex_destroy(&data->message_lock);
	free(data->philos);
	free(data->forks);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	i = 0;
	if (ac != 5 && ac != 6)
		return (ft_putstr_fd(ARG_NB_ERR, 2), 1);
	if (!get_data(&data, av))
		return (1);
	if (!create_threads(&data))
		return (free_all(&data), 1);
	pthread_join(data.monitor, NULL);
	while (i < data.number_of_philosophers)
	{
		pthread_join(data.philos[i]->philo_thread, NULL);
		i++;
	}
	free_all(&data);
}
