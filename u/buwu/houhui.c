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
        set_name(HIW"���ʯ"NOR, ({"houhui stone","stone"}));
        
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��ƽ�������ʯͷ��\n");
                set("unit", "��");
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
		message_vision("$N���ź��ʯ��Ц��������������ʲô��û�з�����\n", me);
		else 
		{message_vision("$N���ź��ʯ��Ц������������������ʧȥ��ʲô��\n", me);
		message_vision(HIY"$Nʧȥ��100�㾭�顣\n"NOR, me);
		me->set("combat_exp", karma-100);}
		return 1;
	}

	return 0;
}
