/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 12:21:27 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/20 13:53:35 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	new_event(t_event **head, SDL_EventType type, void *data, int (*fct)())
{
	t_event	*event;

	if (!(event = malloc(sizeof(t_event))))
		exit_error("rtv1", "malloc");
	*event = (t_event){type, data, fct, *head};
	*head = event;
}

void	delete_event(t_event **head)
{
	free((*head)->data);
	*head = (*head)->next;
}

void	clear_events(t_event **head)
{
	while (*head)
		delete_event(head);
}

void	wait_events(t_event *list_evts)
{
	SDL_Event	evt;
	t_event		*tmp;
	int			flag;

	flag = 1;
	while (flag)
	{
		tmp = list_evts;
		SDL_WaitEvent(&evt);
		while (tmp && tmp->type != evt.type)
			tmp = tmp->next;
		if (tmp)
			flag = tmp->fct(&evt, tmp);
	}
}
