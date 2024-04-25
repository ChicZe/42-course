/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:38:16 by ciusca            #+#    #+#             */
/*   Updated: 2024/04/25 18:07:49 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	print_philo(t_philo *philo, char *action)
{
	t_args *args;

	args = philo->args;
	pthread_mutex_lock(&args->print_lock);
	printf("[");
	printf(MAGENTA);
	printf("%zu", get_current_time());
	printf(NONE);
	printf("] \033[1;32m%i ", philo->id + 1);
	printf(WHITE);
	printf("%s\n", action);
	printf(NONE);
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
	pthread_mutex_unlock(&args->fork[philo->left_fork]);
	pthread_mutex_unlock(&args->fork[philo->right_fork]);
}

int	check_death(t_philo *philo)
{
	size_t	time;
	t_args	*args;
	
	args = philo->args;
	time = get_current_time();
	if ((int)time - philo->last_meal > args->time_to_death)
	{
		print_philo(philo, DIE);
		exit(1);
	}
	return (1);
}