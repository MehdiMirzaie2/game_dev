/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdimirzaie <mehdimirzaie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:40:29 by clovell           #+#    #+#             */
/*   Updated: 2023/12/18 11:58:56 by mehdimirzai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "game.h"
#include "utils_mlx.h"

void	put_color_to_pixel(t_mlx *mlx, int x, int y, int color)
{
	int	*buffer;

	buffer = mlx->pointer_to_image;
	buffer[(y * mlx->size_line / 4) + x] = color;
}

int worldMap[mapWidth][mapHeight]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

float posX = 22, posY = 12;  //x and y start position
float dirX = -1, dirY = 0; //initial direction vector
float planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

// float time = 0; //time of current frame
// float oldTime = 0; //time of previous frame

void verLine(t_mlx *mlx, int x, int yStart, int yEnd, rgbColor color)
{
	// printf("%x\n", color);
	// printf("%d\t %d\n", yStart, yEnd);
	// put_color_to_pixel(mlx, x, yStart, color);
	while (yStart < yEnd)
	{
		put_color_to_pixel(mlx, x, yStart, color);
		yStart++;
	}	
}

 #include <time.h>
//  #include <math.h>
//  #include <stdlib.h> 
//  #include <conio.h>

void	clearScreen(t_mlx *mlx)
{
	int x = 0;
	int y = 0;
	while (x < screenWidth)
	{
		while (y < screenHeight)
		{
			put_color_to_pixel(mlx, x, y, 0x000000);
			y++;
		}
		x++;
		y = 0;
	}
}

#include <math.h>

void	render(t_mlx *mlx)
{
	clearScreen(mlx);
	for (int x = 0; x < screenWidth; x++)
	{
		//calculate ray position and direction
		float cameraX = 2 * x / (float)screenWidth - 1; //x-coordinate in camera space
		float rayDirX = dirX + planeX * cameraX;
		float rayDirY = dirY + planeY * cameraX;


		//which box of the map we're in
		int mapX = (int)posX;
		int mapY = (int)posY;

		//length of ray from current position to next x or y-side
		float sideDistX;
		float sideDistY;

		//length of ray from one x or y-side to next x or y-side
		float deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		float deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
		float perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?


		//calculate step and initial sideDist
		if (rayDirX < 0)
		{
		stepX = -1;
		sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
		stepX = 1;
		sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
		stepY = -1;
		sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
		stepY = 1;
		sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}

		//perform DDA
		while (hit == 0)
		{
		//jump to next map square, either in x-direction, or in y-direction
		if (sideDistX < sideDistY)
		{
			sideDistX += deltaDistX;
			mapX += stepX;
			side = 0;
		}
		else
		{
			sideDistY += deltaDistY;
			mapY += stepY;
			side = 1;
		}
		//Check if ray has hit a wall
		if (worldMap[mapX][mapY] > 0) hit = 1;
		} 
		
		//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
		if(side == 0) perpWallDist = (sideDistX - deltaDistX);
		else          perpWallDist = (sideDistY - deltaDistY);

		 //Calculate height of line to draw on screen
		int lineHeight = (int)(screenHeight / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + screenHeight / 2;
		if(drawStart < 0)drawStart = 0;
		int drawEnd = lineHeight / 2 + screenHeight / 2;
		if(drawEnd >= screenHeight)drawEnd = screenHeight - 1;

		//choose wall color
		rgbColor color;
		switch(worldMap[mapX][mapY])
		{
		case 1:  color = 0xff0000;  break; //red
		case 2:  color = 0x00ff00;  break; //green
		case 3:  color = 0x0000ff;   break; //blue
		case 4:  color = 0xffffff;  break; //white
		default: color = 0xf0f0f0; break; //yellow
		}

		//give x and y sides different brightness
		if (side == 1) {color = color / 2;}

		//draw the pixels of the stripe as a vertical line
		verLine(mlx, x, drawStart, drawEnd, color);
	}
	mlx_put_image_to_window(mlx, mlx->window, mlx->image, 0, 0);
	// timing for input and FPS counter
    // oldTime = time;
    // time = GetTickCount()/1000.0 - time;
    // float frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
    // print(1.0 / frameTime); //FPS counter
    // redraw();
    // cls();

    // speed modifiers
    // float moveSpeed = frameTime * 5.0; //the constant value is in squares/second
    // float rotSpeed = frameTime * 3.0; //the constant value is in radians/second
}

int readKey(int key, t_mlx *mlx)
{
	// printf("key = %d\n", key);
	//move forward if no wall in front of you
    if (key == 126)
    {
      if(worldMap[(int)(posX + dirX)][(int)posY] == false) posX += dirX * 0.34;
      if(worldMap[(int)posX][(int)(posY + dirY)] == false) posY += dirY * 0.34;
    }
    //move backwards if no wall behind you
    if (key == 125)
    {
      if(worldMap[(int)(posX - dirX)][(int)(posY)] == false) posX -= dirX  * 0.34;
      if(worldMap[(int)(posX)][(int)(posY - dirY)] == false) posY -= dirY * 0.34;
    }
//     //rotate to the right
	float rotSpeed = 0.08;
    if (key == 124)
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = dirX;
      dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
      dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
      planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
    }
//     //rotate to the left
    if (key == 123)
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = dirX;
      dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
      dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
      planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
    }
	return (0);
//   }
}

int	main(void)
{
	// creating screen
	t_mlx	*mlx = malloc(sizeof(t_mlx));
	init_mlx(mlx);



	// looping through the game
	mlx_loop_hook(mlx->mlx, (void *)render, mlx);
	// mlx_key_hook(mlx->window, readKey, mlx);
	mlx_hook(mlx->window, 2, 0, readKey, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
