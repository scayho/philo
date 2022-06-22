/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:39:49 by abelahce          #+#    #+#             */
/*   Updated: 2022/06/22 10:58:59 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*testing_thread(void *arg)
{
	(void)arg;
	printf("THE THREAD IS ON THE DUTY !\n");
	int i = 0;
	while (1)
	{
		printf("#%d#\n", i++ * 50);
		sleep(1);
	}
	return (NULL);
}

void	*routune(void	*arg)
{
	(void)arg;
	
	int i = 0;

	while (1)
	{
		sleep(1);
		printf("[%d]\n", i++);
	}
}

int	main(int arc, char **arv)
{
	t_data		*midgard;
	pthread_t	t1, t2;

	t1 = NULL;
	(void)arv;
	(void)arc;
	if (arc > 6 || arc < 5)
		ft_putstr(" my briend lemme thinking am i a philosopher \n");
	midgard = malloc(sizeof(t_data));
	if (midgard == NULL)
		return (-1);
	// parsing(arc, arv, midgard);
	pthread_create(&t1, NULL, testing_thread, NULL);
	pthread_create(&t2, NULL, routune, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return (0);
}
