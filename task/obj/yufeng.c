
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("????",({"yu feng","feng"}));
	set_weight(40);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("task_owner","yuan ziyi");
		set("task_owner_cname","Ԭ????");
		set("reward_point",6);
		set("unit","??");
		set("no_sell",1);
                set("no_beg",1);
		set("value",1000);
		
	}
	setup();
	
}
