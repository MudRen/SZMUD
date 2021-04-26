//huohui.c
//  by Troy 2001.11
#include <ansi.h>

inherit ITEM;
void init()
{
	add_action("do_touch", "touch");
	add_action("do_touch", "mo");
}

void create()
{
        set_name(HIW"后悔石"NOR, ({"houhui stone","stone"}));
        
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一块平淡无奇的石头。\n");
                set("unit", "块");
                set("value", 5000);
	     set("material", "iron");
	        
        }
       setup();
}


int do_touch(string arg)
{
	object me = this_player();
	int karma;

	if ( !arg || arg == "" ) return 0;

	if ( arg == "stone" || arg == "houhui shi" ) {
		karma = me->query("combat_exp");
		if ( karma < 100 )
		message_vision("$N抱着后悔石，笑嘻嘻的摸了摸，什么都没有发生。\n", me);
		else 
		{message_vision("$N抱着后悔石，笑嘻嘻的摸了摸，好像失去点什么。\n", me);
		message_vision(HIY"$N失去了100点经验。\n"NOR, me);
		me->set("combat_exp", karma-100);}
		return 1;
	}

	return 0;
}
