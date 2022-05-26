#include "so_long.h"

int		get_direction(int cur_x, int cur_y, int nxt_x, int nxt_y)
{
	int		df_x;
	int		df_y;

	df_x = nxt_x - cur_x;
	df_y = nxt_y - cur_y;
	if (df_x > 0)
		return (DIRCT_RIGHT);
	if (df_x < 0)
		return (DIRCT_LEFT);
	if (df_y > 0)
		return (DIRCT_DOWN);
	if (df_y < 0)
		return (DIRCT_UP);
	return (0);
}
