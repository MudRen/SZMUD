//Modified by Zyu on k1-8-6

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "武馆大门");
	set("long", @LONG
一所气派辉煌的武馆。朱漆大门旁边摆镇了两头高大威猛，栩栩如生
的石狮子。门上挂着一块黑底大匾额，四个刷金的大字－「扬威武馆」闪
闪生光。左边插着一根两丈多高的旗杆，绣着“武”字的红旗随风飘扬。
这便是江湖上招牌最老，威信最著的武馆，好多城中的子弟都在此学些拳
脚兵器功夫。馆主马五德豪富好客，颇有孟尝之风。所聘教头都是一等一
的具真功夫的好手。
LONG
	);

	set("exits", ([
		"west" : __DIR__"gardeno",
		"east" : "/d/quanzhou/minzai2",
	]));

	set("objects", ([
//		__DIR__"npc/dadizi" : 1,
		__DIR__"npc/xuetu1" : 3,
	]));

	set("cost", 1);
        set("outdoors", "wuguan" );

	setup();
}

void init()
{
	object me = this_player();

	add_action("do_kill", "kill");
	add_action("do_kill", "fight");
	add_action("do_kill", "steal");
	add_action("do_sleep", "sleep");
}

int do_kill(string arg)
{
	object me = this_player();

	tell_object(me,"你在大弟子面前也想打这种注意？\n");
	return 1;
}

int do_sleep(string arg)
{
	object me = this_player();

	tell_object(me,"在武馆可不能随地睡觉的哦！\n");
	return 1;
}

