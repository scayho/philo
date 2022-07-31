/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:40:37 by abelahce          #+#    #+#             */
/*   Updated: 2022/07/04 22:26:29 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include "philo.h"

typedef struct philo
{
	int				index;
	int				eated;
	int				maxeated;
	int				nbeat;
	int				death;
	long long			start;
	int				teat;
	int				total;
	pthread_mutex_t			*shopsticks;
	pthread_mutex_t 		*rshopsticks;
	pthread_mutex_t			*call;
}	t_philo;

typedef struct s_data{
	char				*smito;
	int				nb_philo;
	int				tdie;
	int				teat;
	int				tsleep;
	int				nbeat;
	pthread_mutex_t			*forks;
	int				maxeat;
	int				reste;
	int				death;
	int				start;
	pthread_t			*th;
	int				close;
	t_philo				*philo;
	pthread_mutex_t			ccall;
}		t_data;

// typedef struct s_philo
// {

// }	t_philo;

int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(char *str);
int		ft_strlen(const char	*str);
int		ft_atoi(const char *str);
int		ft_isdigit(char	*str);
int		parsing(int arc, char	**arv, t_data *midgard);
int		start_philo(t_data *midgard);
long long	wakt(void);

#endif
