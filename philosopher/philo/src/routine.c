/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:55:46 by ciusca            #+#    #+#             */
/*   Updated: 2024/04/30 17:29:22 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	*ft_routine(void *args)
{
	t_philo	*philo;
	t_args	*arg;

	philo = (t_philo *)args;
	arg = philo->args;
	if (philo->id % 2 != 0)
		usleep(10000);
	while (1)
	{
		philo_eat(philo);
		// check n_of_meals
		print_philo(philo, SLEEP);
		ft_usleep(arg->time_to_sleep);
		print_philo(philo, THINK);
		check_death(philo);
	}
	exit(1);
	return (0);
}

int	starting_threads(t_args *args)
{
	int	i;

	i = -1;
	i = -1;
	args->initial_time = get_current_time();
	while (++i < args->n_philo)
	{
		//args->philo[i].thread_id = args->tid[i];`
		if (pthread_create(&args->tid[i], 0, &ft_routine, &args->philo[i]))
			return (ft_error("failed to create thread\n", 0));
	}
	i = -1;
	while (++i < args->n_philo)
		if (pthread_join(args->tid[i], 0))
			return (ft_error("pthread_join failed\n", 0));
	return (1);
}

int	init_mutex(t_args *args)
{
	int	i = -1;
	while (++i < args->n_philo)
	{
		if (pthread_mutex_init(&args->fork[i], 0))
			return (ft_error("failed to initialize mutex", 0));
	}
	if (pthread_mutex_init(&args->lock, 0))
		return (ft_error("failed to initialize mutex", 0));
	if (pthread_mutex_init(&args->print_lock, 0))
		return (ft_error("failed to initialize mutex", 0));
	return (1);
}

int	init_philo(t_args *args)
{
	int	i = args->n_philo;
	while (--i >= 0)
	{
		args->philo[i].id = i;
		args->philo[i].left_fork = i;
		args->philo[i].right_fork = (i + 1) % args->n_philo;
		args->philo[i].last_meal = 0;
		args->philo[i].args = args;
		args->philo[i].philo_ate = 0;
	}
	return (1);
}

int	ft_init(t_args *args)
{
	int	i;

	i = -1;
	args->is_dead = 0;
	args->n_philo = ft_atoi(args->argv[1]);
	args->time_to_death = ft_atoi(args->argv[2]);
	args->time_to_eat = ft_atoi(args->argv[3]);
	args->time_to_sleep = ft_atoi(args->argv[4]);
	args->fork = malloc(sizeof(pthread_mutex_t) * args->n_philo);
	if (!args->fork)
		return (ft_error("allocation fail\n", 0));
	args->tid = malloc(sizeof(pthread_t) * args->n_philo);
	if (!args->tid)
		return (ft_error("allocation fail\n", 0));	
	args->philo = malloc(sizeof(t_philo) * args->n_philo);
	if (!args->philo)
		return (ft_error("allocation fail\n", 0));
	if (!(init_philo(args)))
		return (ft_error("failed to initialize", 0));
	return (1);
}
