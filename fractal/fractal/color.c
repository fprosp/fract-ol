/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:28:47 by fprosper          #+#    #+#             */
/*   Updated: 2023/02/21 16:13:21 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color2(int inter, t_data *data)
{
	if (inter == ((int)data->mm_inter - 9))
		return (0x00b8b2);
	else if (inter == ((int)data->mm_inter - 8))
		return (0x00b89e);
	else if (inter == ((int)data->mm_inter - 7))
		return (0x76b874);
	else if (inter == ((int)data->mm_inter - 6))
		return (0xa0b85e);
	else if (inter == ((int)data->mm_inter - 5))
		return (0xc6b644);
	else if (inter == ((int)data->mm_inter - 4))
		return (0xfeb500);
	else if (inter == ((int)data->mm_inter - 3))
		return (0xff8c00);
	else if (inter == ((int)data->mm_inter - 2))
		return (0xfb7700);
	else if (inter == ((int)data->mm_inter - 4))
		return (0xec4e02);
	else if (inter == ((int)data->mm_inter - 0))
		return (0xFC0909);
	return (0x03006A);
}

int	color1(int inter, t_data *data)
{
	if (inter == ((int)data->mm_inter - 20))
		return (0x00b8b2);
	else if (inter == ((int)data->mm_inter - 19))
		return (0x00b89e);
	else if (inter == ((int)data->mm_inter - 18))
		return (0x76b874);
	else if (inter == ((int)data->mm_inter - 17))
		return (0xa0b85e);
	else if (inter == ((int)data->mm_inter - 16))
		return (0xc6b644);
	else if (inter == ((int)data->mm_inter - 15))
		return (0xfeb500);
	else if (inter == ((int)data->mm_inter - 14))
		return (0xff8c00);
	else if (inter == ((int)data->mm_inter - 13))
		return (0xfb7700);
	else if (inter == ((int)data->mm_inter - 12))
		return (0xec4e02);
	else if (inter == ((int)data->mm_inter - 11))
		return (0xFC0909);
	else if (inter == ((int)data->mm_inter - 10))
		return (0xdf210b);
	return (color2(inter, data));
}

int	color(int inter, t_data *data)
{
	if (inter == ((int)data->mm_inter - 30))
		return (0x03006A);
	else if (inter == ((int)data->mm_inter - 29))
		return (0x2a0062);
	else if (inter == ((int)data->mm_inter - 28))
		return (0x300071);
	else if (inter == ((int)data->mm_inter - 27))
		return (0x35008a);
	else if (inter == ((int)data->mm_inter - 26))
		return (0x3b0097);
	else if (inter == ((int)data->mm_inter - 25))
		return (0x4300b1);
	else if (inter == ((int)data->mm_inter - 24))
		return (0x3a00b4);
	else if (inter == ((int)data->mm_inter - 23))
		return (0x2440ba);
	else if (inter == ((int)data->mm_inter - 22))
		return (0x0071c0);
	else if (inter == ((int)data->mm_inter - 21))
		return (0x00a0c4);
	return (color1(inter, data));
}
