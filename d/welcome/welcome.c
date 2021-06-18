// welcome.c
// modified by lisser, 10/4/2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", HIC"新手的殿堂"NOR);
	set ("long", "欢迎来到【神州】，如果你是一个对侠客行很熟的人请键入"HIR"down"NOR"，到
【神州】的世界去闯荡冒险吧！如果你是新手，请使用"HIY"help"NOR"指令熟悉这里的
新环境。在里面还有很多的基本知识让你学习，快去(enter)学习吧。

        输入"HIY" help newbie "NOR"，立刻回答你满脑子的疑问！


");

	set("exits", ([ /* sizeof() == 2 */
		"enter" : __DIR__"welcome2",
		"down" :"/d/city/kedian",
		"xkd" : "/d/xiakedao/shatan",
		]));

	set("valid_startroom", "1");
	set("no_fight", 1);

setup();
}

int valid_leave(object me, string dir)
{
	me = this_player();

	if( dir=="enter" ) return 1;

	if( dir=="down" ) {
		me->delete("newbie", "yes");
	}
	return ::valid_leave(me, dir);
}
