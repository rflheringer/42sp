/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelheringer <rafaelheringer@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:21:57 by rafaelherin       #+#    #+#             */
/*   Updated: 2025/03/04 16:18:36 by rafaelherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo {
    int					id;
	int					fork_left;
	int					fork_rigth;
    size_t 				time_last_meal;
	size_t				meals_eaten;
	pthread_mutex_t		mutex_philo;
	pthread_t			thread;
    t_table				*table;
} t_philo;

typedef struct s_table {
    int					nbr_of_philos;
    size_t				time_to_die;
    size_t				time_to_eat;
    size_t				time_to_sleep;
    size_t				nbr_of_meals;
	size_t				start_time;
    pthread_mutex_t		*mutex_fork;
	pthread_mutex_t		mutex_full;
	pthread_mutex_t		mutex_dead;
	pthread_mutex_t		mutex_print;
	bool				is_dead;
	bool				are_full;
	pthread_t			thread;
} t_table;

//ultis_function
size_t  ft_atol(const char *str);

//inits_funcionts
void    init_philo_mutex(t_table *table, t_philo **philos);


#endif