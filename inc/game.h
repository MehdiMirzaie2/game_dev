#ifndef GAME_H
# define GAME_H
# include <inttypes.h>

# include "libft.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <errno.h>

# define SWIDTH  960
# define SHEIGHT 960

typedef struct s_mlx				t_mlx;

struct s_mlx
{
	void			*mlx;
	void			*window;
	void			*image;
	void			*pointer_to_image;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
};

#endif
