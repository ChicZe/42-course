/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:38:16 by ciusca            #+#    #+#             */
/*   Updated: 2024/07/09 17:06:12 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	print_philo(t_philo *philo, char *action)
{
	t_args *args;

	args = philo->args;
	pthread_mutex_lock(&args->print_lock);
	if (!death_status(args))
	{	
		/*printf("[");
		printf(MAGENTA);
		printf("%lli", get_current_time() - args->initial_time);
		printf(NONE);
		printf("] \033[1;32m%i ", philo->id + 1);
		printf(WHITE);
		printf("%s\n", action);
		printf(NONE);*/
		printf("%lli ", get_current_time() - args->initial_time);
		printf("%d ", philo->id + 1);
		printf("%s\n", action);
		pthread_mutex_unlock(&args->print_lock);
		return (1);
	}
	pthread_mutex_unlock(&args->print_lock);
	return (0);
}

int	philo_eat(t_philo *philo)
{
	t_args *args = (t_args*)philo->args;
	int first_fork = philo->right_fork;
	int second_fork = philo->left_fork;

	if (first_fork > second_fork)
	{
    	first_fork = philo->left_fork;
   	 	second_fork = philo->right_fork;
	}
	pthread_mutex_lock(&args->fork[first_fork]);
	print_philo(philo, TAKEN_FORK);
	if (args->n_philo == 1)
	{
		pthread_mutex_unlock(&args->fork[first_fork]);
		return (0);
	}
	pthread_mutex_lock(&args->fork[second_fork]);
	print_philo(philo, TAKEN_FORK);
	philo->is_eating = 1;
	if (!print_philo(philo, EAT))
	{
		pthread_mutex_unlock(&args->fork[first_fork]);
		pthread_mutex_unlock(&args->fork[second_fork]);
		return (0);
	}
	ft_usleep(args->time_to_eat);
	philo->is_eating = 0;
	pthread_mutex_lock(&args->eat_lock);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&args->eat_lock);
	pthread_mutex_unlock(&args->fork[second_fork]);
	pthread_mutex_unlock(&args->fork[first_fork]);
	return (1);
}

int	check_death(t_philo *philo)
{
	long long	time;
	t_args		*args;
	int			i;

	args = philo->args;
	while (1)
	{
		i = -1;	
		while (++i < args->n_philo && !args->is_dead)
		{
			pthread_mutex_lock(&args->print_lock);
			time = get_current_time();
			pthread_mutex_unlock(&args->print_lock);
			if ((time - philo[i].last_meal) > args->time_to_death) //&& !philo[i].is_eating)
			{
				print_philo(&philo[i], DIE);
				pthread_mutex_lock(&args->lock);
				args->is_dead = 1;
				pthread_mutex_unlock(&args->lock);
			}
		}
		usleep(100);
		if (args->is_dead)
			return (1);
	}
	return (1);
}
