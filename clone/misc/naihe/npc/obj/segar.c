// 雪茄烟，拿来给赢了钱的大款们摆阔的，哈哈哈    ★/npc/obj/segar.c
// by naihe  2002-04-29
// 哈哈哈 OK 了。

inherit ITEM;
#include <ansi.h>

int remaining=(10+random(6));


void create()
{
        set_name(YEL"雪茄烟"NOR, ({"segar","xuejia","yan","xuejia yan"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "这是一根西洋的卷烟，粗粗的模样甚为气派。\n(吸烟用指令：xiyan)\n");
		set("unit", "根");
                set("value", 10000);
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

// 。ο。○ο●¤°○●◎０ΟО·о

		if (remaining>0)
		{
		switch(random(7))
			{
			case 0 :
			message_vision("
$N拿起"YEL"雪茄烟"NOR"吸了一口，差点给呛得喘不过气来。\n",me);
			if(me->query("qi") > 22) me->add("qi",-random(10));
			return 1;
			break;

			case 1 :
			message_vision("
$N拿起"YEL"雪茄烟"NOR"吸了一口，漂亮地喷出了几个烟圈："WHT"。ο ○ ○ ο °"NOR"\n",me);
			break;

			case 2 :
			message_vision("
$N拿起"YEL"雪茄烟"NOR"吸了一口，喷出了几个双重的烟圈："WHT"◎◎◎◎◎◎"NOR"\n",me);
			break;

			case 3 :
			message_vision("
$N拿起"YEL"雪茄烟"NOR"吸了一口，想喷个烟圈结果不知道喷出了些什么："WHT"~~~~~~~~~~~~~"NOR"\n",me);
			break;

			case 4 :
			message_vision("
$N拿起"YEL"雪茄烟"NOR"吸了一口，胡乱地喷出了几个烟圈："WHT"。ο。¤ο○о°°"NOR"\n",me);
			break;

			case 5 :
			message_vision("
$N拿起"YEL"雪茄烟"NOR"吸了一口，徐徐地喷出了几个烟圈："WHT"。 о ０ Ο ○ ¤"NOR"\n",me);
			break;

			case 6 :
			message_vision("
$N拿起"YEL"雪茄烟"NOR"深深地吸了一口，嘴巴一嘟一嘟地喷出好几个烟圈："WHT" 。оΟ００００"NOR"\n",me);
			break;
			}
			if(me->query("jing") < me->query("max_jing"))
				me->add("jing",10+random(6));
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
