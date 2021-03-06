/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 12:33:37 by edescoin          #+#    #+#             */
/*   Updated: 2017/08/21 18:15:35 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

static double			sphere_intersect(t_ray *ray, t_sphere *s)
{
	t_dot		res;
	t_vector	*vd;
	t_vector	*vc;
	double		t;

	t = -1;
	vc = &ray->eq_obj.vconst;
	vd = &ray->eq_obj.vdir;
	if (get_quad_equation_sol(&res,
			pow(vd->x, 2) + pow(vd->y, 2) + pow(vd->z, 2),
			2 * (vd->x * vc->x + vd->y * vc->y + vd->z * vc->z),
			pow(vc->x, 2) + pow(vc->y, 2) + pow(vc->z, 2) - s->r2))
	{
		if ((long)(res.x * pow(10, 12)) > 0)
		{
			if ((long)(res.y * pow(10, 12)) > 0)
				t = (res.x < res.y ? res.x : res.y);
			else
				t = (res.x);
		}
		else if ((long)(res.y * pow(10, 12)) > 0)
			t = (res.y);
	}
	return (t);
}

static const t_vector	*get_sphere_normal(t_dot *d, t_sphere *s)
{
	(void)s;
	set_vector(&s->normal, 2 * d->x, 2 * d->y, 2 * d->z);
	return (&s->normal);
}

t_sphere				*new_sphere(t_dot center, double radius)
{
	t_sphere	*sphere;

	sphere = (t_sphere*)new_object(SPHERE, &sphere_intersect,
									&get_sphere_normal, sizeof(t_sphere));
	sphere->radius = radius;
	sphere->r2 = pow(radius, 2);
	sphere->center = center;
	translation(&sphere->trans, center.x, center.y, center.z);
	translation(&sphere->trans_inv, -center.x, -center.y, -center.z);
	return (sphere);
}
