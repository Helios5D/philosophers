/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaher <hdaher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:58:33 by hdaher            #+#    #+#             */
/*   Updated: 2024/08/26 15:23:38 by hdaher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi_check(char *nptr)
{
	int		i;
	long	number;

	i = 0;
	number = 0;
	while (nptr[i] && nptr[i] == 0)
		i++;
	if (!nptr[i] || ft_strlen(nptr) > 10)
		return (0);
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		number = number * 10 + (nptr[i] - 48);
		i++;
	}
	if (number > 2147483647)
		return (0);
	return ((int)number);
}

static int	arg_checker(char *arg)
{
	int	nb;

	if (!ft_isnumber(arg))
		return (0);
	nb = ft_atoi_check(arg);
	if (nb == 0)
		return (0);
	return (1);
}

int	get_data(t_data *data, char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!arg_checker(av[i]))
			return (ft_putstr_fd(ARG_ERR, 2), 0);
		i++;
	}
	pthread_mutex_init(&data->message_lock, NULL);
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	data->number_of_philosophers = ft_atoi(av[1]);
	data->is_end = 0;
	if (!create_forks(data, ft_atoi(av[1])))
		return (0);
	if (!create_philos(data, av))
		return (free(data->forks), 0);
	return (1);
}
