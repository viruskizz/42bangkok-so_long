#include "so_long.h"


t_vtr	set_vtr(int x, int y)
{
	t_vtr	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_vtr	add_vtr(t_vtr v1, t_vtr v2)
{
	t_vtr	v3;

	v3.x = v1.x + v2.x;
	v3.y = v1.y + v2.y;
	return (v3);
}
