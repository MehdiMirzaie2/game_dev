/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:00:07 by mmirzaie          #+#    #+#             */
/*   Updated: 2023/12/13 10:12:17 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// std
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <time.h>
# include <unistd.h>
# include <stdbool.h>

// ours
# include "get_next_line.h"
# include "libft.h"
# include "rt.h"

// Srceen dimensions
# define SIZE 700

void	init_mlx(t_mlx *mlx);

#endif
