/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:34:59 by dicarval          #+#    #+#             */
/*   Updated: 2024/08/05 17:33:34 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_cross_press(t_data *data)
{
        mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        data->win_ptr = NULL;
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(0);
}

int	handle_esc_press(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
    {
        mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        data->win_ptr = NULL;
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(0);
	}
	return (0);
}
void	img_pix_put(t_img *img, int x, int y, int color)
{
    char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

int render_rect(t_img *img, t_rect rect)
{
	int	i;
	int j;

	if (img->mlx_img == NULL)
		return (1);
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}
int	change_color(t_data *data)
{
	static t_rect	rect1 = {WINDOW_WIDTH - ((WINDOW_WIDTH/2)+50), WINDOW_HEIGHT - ((WINDOW_HEIGHT/2)+50), 100, 100, GREEN_PIXEL};

	if (rect1.color == GREEN_PIXEL)
		rect1.color = BLUE_PIXEL;
	else if (rect1.color == RED_PIXEL)
		rect1.color = GREEN_PIXEL;
	else
		rect1.color = RED_PIXEL;
	render_rect(&data->img, rect1);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

/* void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	if (img->mlx_img == NULL)
		return ;
	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			 img_pix_put(img, j++, i, color);
		++i;
	}
} */

/* int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, WHITE_PIXEL);
    render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100,
            100, 100, GREEN_PIXEL});
    render_rect(&data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
} */

int	main(void)
{
    t_data	data;

    data.mlx_ptr = mlx_init();
    if (data.mlx_ptr == NULL)
        return (MLX_ERROR);
    data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
                                "my window");
    if (data.win_ptr == NULL)
    {
        free(data.win_ptr);
        return (MLX_ERROR);
    }
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len,
								&data.img.endian);
	/* Setup hooks */
	/* mlx_loop_hook(data.mlx_ptr, &render, &data); */
	mlx_loop_hook(data.mlx_ptr, &change_color, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_esc_press, &data);
	mlx_hook(data.win_ptr, DestroyNotify, NoEventMask, &handle_cross_press, &data);
    mlx_loop(data.mlx_ptr);
    /* we will exit the loop if there's no window left, and execute this code */
}
