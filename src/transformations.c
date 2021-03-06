/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 21:19:18 by edescoin          #+#    #+#             */
/*   Updated: 2017/07/05 17:18:03 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <math.h>

void	translation(t_matrix **mtx, double x, double y, double z)
{
	t_matrix	*tmp;
	t_matrix	*res;

	tmp = create_identity(4);
	tmp->mat[0][3] = x;
	tmp->mat[1][3] = y;
	tmp->mat[2][3] = z;
	res = mult_matrix(*mtx, tmp);
	delete_matrix(*mtx);
	delete_matrix(tmp);
	*mtx = res;
}

void	scale(t_matrix **mtx, double x, double y, double z)
{
	t_matrix	*tmp;
	t_matrix	*res;

	tmp = create_identity(4);
	tmp->mat[0][0] = x;
	tmp->mat[1][1] = y;
	tmp->mat[2][2] = z;
	res = mult_matrix(*mtx, tmp);
	delete_matrix(*mtx);
	delete_matrix(tmp);
	*mtx = res;
}

void	x_rotation(t_matrix **mtx, double theta)
{
	t_matrix	*tmp;
	t_matrix	*res;

	tmp = create_identity(4);
	theta = ft_to_rad(theta);
	tmp->mat[1][1] = cos(theta);
	tmp->mat[1][2] = -sin(theta);
	tmp->mat[2][1] = sin(theta);
	tmp->mat[2][2] = cos(theta);
	res = mult_matrix(*mtx, tmp);
	delete_matrix(*mtx);
	delete_matrix(tmp);
	*mtx = res;
}

void	y_rotation(t_matrix **mtx, double theta)
{
	t_matrix	*tmp;
	t_matrix	*res;

	tmp = create_identity(4);
	theta = ft_to_rad(theta);
	tmp->mat[0][0] = cos(theta);
	tmp->mat[0][2] = sin(theta);
	tmp->mat[2][0] = -sin(theta);
	tmp->mat[2][2] = cos(theta);
	res = mult_matrix(*mtx, tmp);
	delete_matrix(*mtx);
	delete_matrix(tmp);
	*mtx = res;
}

void	z_rotation(t_matrix **mtx, double theta)
{
	t_matrix	*tmp;
	t_matrix	*res;

	tmp = create_identity(4);
	theta = ft_to_rad(theta);
	tmp->mat[0][0] = cos(theta);
	tmp->mat[0][1] = -sin(theta);
	tmp->mat[1][0] = sin(theta);
	tmp->mat[1][1] = cos(theta);
	res = mult_matrix(*mtx, tmp);
	delete_matrix(*mtx);
	delete_matrix(tmp);
	*mtx = res;
}
