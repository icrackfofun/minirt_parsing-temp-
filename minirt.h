/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:46:49 by psantos-          #+#    #+#             */
/*   Updated: 2025/10/27 12:11:43 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

//formatting check
typedef struct s_counts
{
	int	count_a;
	int	count_c;
	int	count_l;
	int	count_shape;
}	t_counts;

//helper structs
typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}	t_vec;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

//scene elements
typedef struct s_ambient
{
	float	ratio;
	t_color	color;
}	t_ambient;

typedef struct s_camera
{
	t_vec	pos;
	t_vec	dir;
	float	fov;
}	t_camera;

typedef struct s_light
{
	t_vec	pos;
	float	brightness;
	t_color	color;
}	t_light;

//shape structs
typedef enum s_material
{
	DEFAULT,
	GLASS,
	MIRROR
}	t_material;

typedef struct s_sphere
{
	t_vec		center;
	float		radius;
	t_color		color;
	t_material	material;
}	t_sphere;

typedef struct s_plane
{
	t_vec		point;
	t_vec		normal;
	t_color		color;
	t_material	material;
}	t_plane;

typedef struct s_cylinder
{
	t_vec		center;
	t_vec		axis;
	float		radius;
	float		height;
	t_color		color;
	t_material	material;
}	t_cylinder;

//shapes list
typedef enum s_obj_type
{
	SPHERE,
	CYLINDER,
	PLANE
}	t_obj_type;

typedef struct s_list
{
	t_obj_type		type;
	void			*obj;
	struct s_list	*next;
}	t_list;

//main scene struct
typedef struct s_scene
{
	t_ambient	*ambient;
	t_camera	*camera;
	t_light		*light;
	t_list		*list;
	int			n_objects;
}	t_scene;

//precheck
int		precheck(int argc, char *filename);

//clean
void	clean_scene(t_scene *scene);

//main parsing
void	parse(char *filename, t_scene *scene);

//utils
int		ft_isspace(int c);
int		ft_issign(int c);
int		isshape(char *sub);
int		ft_is_zerovec(t_vec *v);
int		count_attributes(char *line);

//attribute check
int		is_valid_float(char *s, float min, float max);
int		is_valid_int(char *s, int min, int max);
int		is_valid_vec(char *s);
int		is_valid_rgb(char *s);

//attribute parsing
float	parse_float(char *line, int *i);
int		parse_int(char *line, int *i);
void	parse_vec(char *line, int *i, t_vec *vec);
void	parse_color(char *line, int *i, t_color *color);

//element parsing
int		parse_ambient(char *line, t_scene *scene);
int		parse_camera(char *line, t_scene *scene);
int		parse_light(char *line, t_scene *scene);
int		parse_sphere(char *line, t_scene *scene);
int		parse_plane(char *line, t_scene *scene);
int		parse_cylinder(char *line, t_scene *scene);