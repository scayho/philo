/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:39:49 by abelahce          #+#    #+#             */
/*   Updated: 2022/06/23 20:03:28 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int arc, char **arv)
{
	t_data		*midgard;

	if (arc > 6 || arc < 5)
		ft_putstr(" my briend lemme thinking am i a philosopher \n");
	midgard = malloc(sizeof(t_data));
	if (midgard == NULL)
		return (-1);
	if (!parsing(arc, arv, midgard))
		return (0);
	if (!start_philo(midgard))
		return (0);
	return (0);
}
