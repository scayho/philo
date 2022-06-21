/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:40:37 by abelahce          #+#    #+#             */
/*   Updated: 2022/06/21 14:11:59 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include "philo.h"

typedef struct s_data{
	int	nb_philo;
	int	tdie;
	int	teat;
	int	tsleep;
	int	nbeat;
}		t_data;

int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(char *str);
int		ft_strlen(const char	*str);
int		ft_atoi(const char *str);
int		ft_isdigit(char	*str);
void	parsing(int arc, char	**arv);

#endif