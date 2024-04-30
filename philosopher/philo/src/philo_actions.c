/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:38:16 by ciusca            #+#    #+#             */
/*   Updated: 2024/04/30 17:31:57 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	print_philo(t_philo *philo, char *action)
{
	t_args *args;

	args = philo->args;
	pthread_mutex_lock(&args->print_lock);
	if (!args->is_dead)
	{	
		printf("[");
		printf(MAGENTA);
		printf("%lli", get_current_time() - args->initial_time);
		printf(NONE);
		printf("] \033[1;32m%i ", philo->id + 1);
		printf(WHITE);
		printf("%s\n", action);
		printf(NONE);
	}
	pthread_mutex_unlock(&args->print_lock);
}

void	philo_eat(t_philo *philo)
{
	t_args *args = (t_args*)philo->args;
	
	pthread_mutex_lock(&args->fork[philo->right_fork]);
	print_philo(philo, TAKEN_FORK);
	pthread_mutex_lock(&args->fork[philo->left_fork]);
	print_philo(philo, TAKEN_FORK);
	print_philo(philo, EAT);
	philo->last_meal = get_current_time();
	ft_usleep(args->time_to_eat);
	philo->philo_ate = 1;
	pthread_mutex_unlock(&args->fork[philo->left_fork]);
	pthread_mutex_unlock(&args->fork[philo->right_fork]);
}

int	check_death(t_philo *philo)
{
	long long	time;
	t_args	*args;

	args = philo->args;	
	time = get_current_time();
	if (time - philo->last_meal > args->time_to_death && philo->philo_ate == 1)
	{
		pthread_mutex_lock(&args->lock);
		print_philo(philo, DIE);
		//printf("hello\n\n\n\n\n\n");
		args->is_dead = 1;
		pthread_mutex_unlock(&args->lock);
		exit(1);
	}
	philo->philo_ate = 0;
	//pthread_mutex_unlock(&args->lock);
	return (1);
}