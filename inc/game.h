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
#include "render.h"

# include "utils.h"

# define SWIDTH  960
# define SHEIGHT 960

typedef struct s_mlx				t_mlx;



// float fPlayerX = 14.7f;			// Player Start Position
// float fPlayerY = 5.09f;
// float fPlayerA = 0.0f;			// Player Start Rotation
// float fFOV = 3.14159f / 4.0f;	// Field of View
// float fDepth = 16.0f;			// Maximum rendering distance
// float fSpeed = 5.0f;			// Walking Speed

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
