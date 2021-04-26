// 小雪茄烟，拿来给赢了钱的大款们摆阔的，哈哈哈    ★/npc/obj/smsegar.c
// by naihe  2002-04-29
// 哈哈哈 OK 了。

inherit ITEM;
#include <ansi.h>

int remaining=(5+random(5));

void create()
{
	set_name(YEL"小雪茄"NOR, ({"smsegar","yan","xiao xuejia"}));
	set_weight(30);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一根看起来略小的西洋卷烟，感觉上斯斯文文的。\n(吸烟用指令：xiyan)\n");
		set("unit", "根");
                set("value", 5000);
	}
	setup();
}

void init()
{
	add_action("do_xiyan", "xiyan");
}

int do_xiyan(string arg)
{
	object me=this_player();

	if (!arg)
	{

		if (me->is_busy())
		return notify_fail("吸那么快，小心呛死~~\n");

		set("value", 0);

		if(me->is_fighting())
		me->start_busy(3);

		me->start_busy(3);
		remaining-=1;

		if (remaining>0)
		{
// 。ο。○ο●¤°○●◎０ΟО·о
		switch(random(3))
			{
			case 0 :
			message_vision("
$N拿起"YEL"小雪茄"NOR"吸了一口，喷出了几个烟圈："WHT"。ο。¤ο○о°°"NOR"\n",me);
			break;

			case 1 :
			message_vision("
$N拿起"YEL"小雪茄"NOR"吸了一口，随便地就把烟喷了出来："WHT"~~~~~~~~~"NOR"\n",me);
			break;

			case 2 :
			message_vision("
$N拿起"YEL"小雪茄"NOR"吸了一口，差点给呛得喘不过气来。\n",me);
			if(me->query("qi") > 22) me->add("qi",-random(5));
			return 1;
			break;
			}
			if(me->query("jing") < me->query("max_jing"))
			me->add("jing",random(5));
		}

		else
		{
			message_vision(""HIC"$N吸完了最后一口烟，似乎仍在陶醉着。"NOR"\n",me);
			destruct(this_object());
		}
		return 1;
	}
	return 0;
}
