/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:16:59 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/26 22:06:46 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	clean_scene(t_scene *scene)
{
	t_list	*tmp;

	if (!scene)
		return ;
	if (scene->ambient)
		free(scene->ambient);
	if (scene->camera)
		free(scene->camera);
	if (scene->light)
		free(scene->light);
	while (scene->list)
	{
		tmp = scene->list->next;
		if (scene->list->obj)
			free(scene->list->obj);
		free(scene->list);
		scene->list = tmp;
	}
	scene->n_objects = 0;
}
