#include "doom.h"

void coll2(t_object *obj, t_input *data)
{
	if (obj->type == END)
		win_anim(data->data_hud);
}