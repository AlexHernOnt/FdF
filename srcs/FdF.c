/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:39:32 by ahernand          #+#    #+#             */
/*   Updated: 2022/08/17 20:30:58 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int main(int argc, char **argv)
{
	t_dt		sc;

	if (argc == 2)
	{
		if (ft_read(&sc, argv[1]) == 0)
		{
			ft_exec(&sc);
			mlx_hook(sc.win, 2, 1L << 0, ft_close, &sc);
			mlx_loop(sc.mlx);
		}
	}
	return (ft_error(1));
}