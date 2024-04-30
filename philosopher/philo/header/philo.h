/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:12:05 by ciusca            #+#    #+#             */
/*   Updated: 2024/04/30 17:29:38 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

/* --actions-- */
# define TAKEN_FORK "has taken a fork\n"
# define THINK "is thinking\n"
# define SLEEP "is sleeping\n"
# define EAT "is eating\n"
# define DIE "died\n"

/* --colors-- */
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define WHITE "\033[1;37m"
# define NONE "\033[0m"

/* philosophers informations */
typedef struct s_philo
{
	int					id;
	int					left_fork;
	int					right_fork;
	long long			last_meal;
	int					philo_ate;
	pthread_t			thread_id;
	struct s_args			*args;
}				t_philo;

/* general information */
typedef struct s_args
{
	int				argc;
	char			**argv;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_death;
	int				meals_limit;
	int				is_dead;
	int				n_philo;
	long long		initial_time;
	pthread_t		*tid;
	pthread_mutex_t	*fork;
	pthread_mutex_t	lock;
	pthread_mutex_t	print_lock;
	t_philo			*philo;
}				t_args;

/* writes a message and return and integer passed as the second argument */
int	ft_error(char *str, int quit);

/* init struct && routine */
int	ft_init(t_args *args);
int	starting_threads(t_args *args);
int	init_mutex(t_args *args);

/* checking for valid input */
int	check_args(char **argv);

/* utils */
long long	get_current_time(void);

/* philo actions */
void	philo_eat(t_philo *philo);
int		ft_usleep(size_t milliseconds);
void	print_philo(t_philo *philo, char *action);
int		check_death(t_philo *philo);

/* lib functions */
char	*ft_itoa(int n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_strlen(char *str);

#endif