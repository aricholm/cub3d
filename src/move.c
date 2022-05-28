/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 18:39:19 by aricholm          #+#    #+#             */
/*   Updated: 2022/05/28 19:20:26 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void move_up(t_cub3d *c)
{
	// printf("upup\n%c\n",c->map.map[(int)(c->player.pos.x )][(int)c->player.pos.y]);
	if (c->map.map[(int)(c->player.pos.x + c->player.dir.x * MOV_SPEED)][(int)c->player.pos.y] != '1')
		c->player.pos.x += c->player.dir.x * MOV_SPEED;
	if (c->map.map[(int)c->player.pos.x][(int)(c->player.pos.y + c->player.dir.y * MOV_SPEED)] != '1')
		c->player.pos.y += c->player.dir.y * MOV_SPEED;
}

void move_down(t_cub3d *c)
{
	if (c->map.map[(int)(c->player.pos.x - c->player.dir.x * MOV_SPEED)][(int)c->player.pos.y] != '1')
		c->player.pos.x -= c->player.dir.x * MOV_SPEED;
	if (c->map.map[(int)c->player.pos.x][(int)(c->player.pos.y - c->player.dir.y * MOV_SPEED)] != '1')
		c->player.pos.y -= c->player.dir.y * MOV_SPEED;
}

void move_left(t_cub3d *c)
{
	if (c->map.map[(int)(c->player.pos.x - c->player.plane.x * MOV_SPEED)][(int)c->player.pos.y] != '1')
		c->player.pos.x -= c->player.plane.x * MOV_SPEED;
	if (c->map.map[(int)c->player.pos.x][(int)(c->player.pos.y - c->player.plane.y * MOV_SPEED)] != '1')
		c->player.pos.y -= c->player.plane.y * MOV_SPEED;
}

void move_right(t_cub3d *c)
{
	if (c->map.map[(int)(c->player.pos.x + c->player.plane.x * MOV_SPEED)][(int)c->player.pos.y] != '1')
		c->player.pos.x += c->player.plane.x * MOV_SPEED;
	if (c->map.map[(int)c->player.pos.x][(int)(c->player.pos.y + c->player.plane.y * MOV_SPEED)] != '1')
		c->player.pos.y += c->player.plane.y * MOV_SPEED;
}

void rotate_left(t_cub3d *c)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = c->player.dir.x;
	c->player.dir.x = c->player.dir.x * cos(-ROT_SPEED) - c->player.dir.y * sin(-ROT_SPEED);
	c->player.dir.y = old_dir_x * sin(-ROT_SPEED) + c->player.dir.y * cos(-ROT_SPEED);
	old_plane_x = c->player.plane.x;
	c->player.plane.x = c->player.plane.x * cos(-ROT_SPEED) - c->player.plane.y * sin(-ROT_SPEED);
	c->player.plane.y = old_plane_x * sin(-ROT_SPEED) + c->player.plane.y * cos(-ROT_SPEED);
}
void rotate_right(t_cub3d *c)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = c->player.dir.x;
	c->player.dir.x = c->player.dir.x * cos(ROT_SPEED) - c->player.dir.y * sin(ROT_SPEED);
	c->player.dir.y = old_dir_x * sin(ROT_SPEED) + c->player.dir.y * cos(ROT_SPEED);
	old_plane_x = c->player.plane.x;
	c->player.plane.x = c->player.plane.x * cos(ROT_SPEED) - c->player.plane.y * sin(ROT_SPEED);
	c->player.plane.y = old_plane_x * sin(ROT_SPEED) + c->player.plane.y * cos(ROT_SPEED);
}

int move(int key, t_cub3d *cub)
{
	if (key == KEY_W || key == KEY_UP)
		move_up(cub);
	else if (key == KEY_S || key == KEY_DOWN)
		move_down(cub);
	else if (key == KEY_A)
		move_left(cub);
	else if (key == KEY_D)
		move_right(cub);
	else if (key == KEY_LEFT)
		rotate_left(cub);
	else if (key == KEY_RIGHT)
		rotate_right(cub);
	else
		printf("in move %d\n", key);
	return (0);
}


int handle_key(int key, t_cub3d *c)
{
	printf("in key handler -	> > %d\n",key);
	if (key == 53)
		mlx_destroy_window(c->mlx, c->win);
	else
		move(key, c);
	return (0);
}
