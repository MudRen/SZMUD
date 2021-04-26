
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("¹ø×Ó",({"guo","guozi"}));
	set_weight(40);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("task_owner","hu laoye");
		set("task_owner_cname","ºúÀÏÒ¯");
		set("reward_point",2);
		set("unit","Ö»");
		set("no_sell",1);
                set("no_beg",1);
		set("value",1000);
		
	}
	setup();
	
}
