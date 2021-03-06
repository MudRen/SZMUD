//                标准描述长度示例                                   |
// 赌场茶座！！！  ★dc_chazuo.c
// by naihe  2002-04-29  于茂名
// 请勿擅自更改本文件源码，谢谢！

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"茶座"NOR);
	set("long", "这是一个不大的房间，井然有序地排放着一些有分隔板的厢座；墙壁上都帖
着漂亮的纸张，靠楼梯的地方有个小窗子可以看到下面大街的景色。你从楼下走
上来，发现楼下的吵闹声完全听不到了，在这里休息一会真是赏心悦事。楼梯正
对着的前面就是柜台，有个漂亮的女侍应(waitress)正向你迎了过来。\n");
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("invalid_startroom",1);

	set("objects", ([
	    __DIR__"npc/dc_waiter" : 1,
	    ]));

	set("exits", ([
	    "down": __DIR__"dc_dating",
	    ]));

	setup();
}

void init()
{
	add_action("do_skills",  "exercise");
	add_action("do_skills",  "dazuo");
	add_action("do_skills",  "respirate");
	add_action("do_skills",  "tuna");
	add_action("do_skills",  "practice");
	add_action("do_skills",  "lian");
	add_action("do_skills",  "study");
	add_action("do_skills",  "du");
	add_action("do_drop", "drop");
}

int do_skills(string arg)
{
	tell_object(this_player(), "这里好安静呢，别吵呀 :P\n");
	return 1;
}

int do_drop(string arg)
{
	if(arg=="gold") return 0;
	tell_object(this_player(), "不许乱扔垃圾~~\n");
	return 1;
}
