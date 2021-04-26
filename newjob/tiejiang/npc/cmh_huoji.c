//cmh_huoji. 车马行伙计
// snowlf by 2001/11/13
//Troy By 2001/12/18
#include <ansi.h>

inherit NPC;
int do_buy();
int do_zu(string arg);

void create()
{
	set_name("车马行伙计", ({ "chemahang huoji", "huoji" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 18);
	set("long", "他是车马行老板从乡下招来帮忙的。\n");
	set("combat_exp", 250);
	set("attitude", "peaceful");
		setup();
}

void init()
{
	add_action("do_buy","buy");
	add_action ("do_zu","zu");
}

int do_buy()
{
	message_vision( HIG"$n对着$N说道：客官如果要买马，请入内挑选。\n"NOR,this_player(),this_object());
	return 1;
		}

int do_zu(string arg)
{
	object me=this_player();
	object luoche2;
	if (!arg)
	return notify_fail("你要租什么？！\n");
	if (!(arg=="luoche"))
		return notify_fail("这里只有骡车（luoche)可以租。\n");
	luoche2 = new("/newjob/tiejiang/obj/luoche2");
          luoche2->move("/d/city/kedian");
  	luoche2->set_owner(me);
	message_vision( HIG"$N对着$n说道：你要租的骡车已经停在外面了，每天租金二两银子。\n"NOR,this_object(),this_player());
	return 1;
	}
