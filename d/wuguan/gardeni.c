//Creatied by sleep on k1-08-11
//Modified by Zyu on k1-08-11
// road : /d/wuguan/gardeni.c

inherit ROOM;

void create()
{
        set("short", "花园深处");
        set("long", @LONG
不知不觉中，你已经走到了花园深处了。这儿到处都是花，连空气中
都飘荡着鲜花的清香。不远处是一座半圆形的透明房子，想必也就是武馆
众人口中所说的培养名贵花草的温室吧。
LONG
        );

        set("objects", ([
                 __DIR__"obj/shizi" : 1,
                 __DIR__"obj/flower1" : 1,
                 __DIR__"obj/flower2" : 1,
	]));
        set("exits", ([
                "southwest" : __DIR__"wenshi",
                "west" : __DIR__"garden",
        ]));

        set("cost", 1);
        set("outdoors", "wuguan");

        setup();
}

void init()
{
	object me = this_player();

	add_action("go_sw", "southwest");
	add_action("do_go", "go");
}

int go_sw(string arg)
{
	object me = this_player();

	if ( arg ) return 0;

        if ( me->query("combat_exp") <= 4000 )
	{
		tell_object(me,"你的经验不足，恐怕无法完成花匠给予你的任务。\n");
		return 1;
	}

	return 0;
}

int do_go(string arg)
{
	object me = this_player();

	if ( !arg || arg=="" ) return 0;

	if ( arg != "southwest" ) return 0;

        if ( me->query("combat_exp") <= 4000 )
	{
		tell_object(me,"你的经验不足，恐怕无法完成花匠给予你的任务。\n");
		return 1;
	}

	return 0;
}