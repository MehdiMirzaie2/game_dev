#include "game.h"

void	error(char *comment)
{
	ft_putstr_fd(comment, 2);
	exit(2);
}