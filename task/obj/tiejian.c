#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("С����",({"tie jian","jian"}));
	set_weight(40);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("task_owner","yuzhen zi");
		set("task_owner_cname","������");
		set("reward_point",7);
		set("unit","��");
		set("no_sell",1);
                set("no_beg",1);
		set("value",1000);
		
	}
	setup();
	
}
