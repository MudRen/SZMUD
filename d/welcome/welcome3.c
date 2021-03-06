// welcome.c
// modified by lisser, 10/4/2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", HIC"武器库"NOR);
        set ("long", "这里是一间武器库，四周的兵器架上摆满了造形各异的长短兵刃，地
上还散落着几件器械。在这里你可以试试武器和防具的使用方法：先使用
"HIG"get <物品名>"NOR"命令，从地上捡起武器或者防具，再用"HIY"wield <武器物品名>
"NOR"命令装备武器，用"HIY"wear <防具物品名>"NOR"命令装备防具。
");

	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"welcome2",
		]));
	set("objects", ([
		"/d/city/obj/gangjian" : 1,
		"/clone/armor/beixin" : 1,
		]));

	set("valid_startroom", "1");
        // set("no_fight", "1");

	setup();
}

int valid_leave(object me, string dir)
{
	me = this_player();

	if( dir=="west" && present("gangjian", me) || present("beixin", me))
		return notify_fail("你不能把东西带走，请用drop <物品名>命令放下东西再离开。\n");
			
	return ::valid_leave(me, dir);

}
