//Cracked by Roath
// npc: /d/city/npc/ftb_killer.c
// Chu 2/10/99

#include <ansi.h>
inherit NPC;

string ask_cike();
string ask_move();

void create()
{
	set("name","������");
	set("id","npc");
        set("age", 32);
        set("str", 23);
        set("dex", 30);
        set("con", 23);
        set("int", 23);
        set("shen_type", -1);

        set("max_qi", 300);
        set("max_jing", 100);
        set("neili", 200);
        set("max_neili", 200);

        set("no_refresh", 1);

        setup();
}
void init()
{
	add_action("do_action","do");
	add_action("do_dest","dest");
}
int do_action(string arg)
{
	object me = this_player();
	string dest, topic;
	if( !arg || arg == "" || (wizhood(me) != "admin" && getuid(me) != "lisser") )
		return notify_fail("����"+this_object()->name()+"��ʲô�£�\n");
	else{ 
		command(arg);
		return 1;
        }
}
int do_dest(string arg)
{
	object me = this_player();
	string dest, topic;
	if( !arg || arg == "" || (wizhood(me) != "admin" && getuid(me) != "lisser") )
		return notify_fail("����"+this_object()->name()+"��ʲô�£�\n");
	else{ 
		destruct(this_object());
		return 1;
        }
}