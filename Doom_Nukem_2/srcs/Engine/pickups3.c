#include "doom.h"

void chckdoorcolli(int way, t_object *obj, t_input *data)
{
	while (obj)
	{
		if (obj->type == DOOR && obj->exist == 1)
		{
			if (check_colli(obj->poly))
			{
				rev_moove(data, way);
				return ;
			}
		}
		obj = obj->next;
	}
}

void coll2(t_object *obj, t_input *data)
{
	if (obj->type == END)
		win_anim(data->data_hud);
	else if (obj->type == DOOR)
	{

		if (data->data_hud->keys[KEY_E] == 1 && data->data_hud->inventory.slot_three >= 1)
		{
			obj->exist = 0;
			data->data_hud->inventory.slot_three--;
		}
	}
}