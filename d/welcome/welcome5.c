// welcome.c
// modified by lisser, 10/4/2001


#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", HIC"书馆"NOR);
        set ("long", "这里是一间书馆，屋内一排排都是书架，架上摆满了书，屋子正中摆
放着一张紫檀木的书桌，桌上摆着一本摊开的线装书籍，书桌右首是一只
青铜古鼎，烧着檀香，鼎盖的兽头口中袅袅吐出一缕缕青烟，一位老者正
在书架边随意翻阅。你可以在这里向老者学("HIG"xue"NOR")知识和读书("HIG"du book"NOR")。
");

	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"welcome2",
                "west" : __DIR__"sleeproom",
		]));
	set("objects", ([
		__DIR__"npc/xueshi" : 1,
		__DIR__"obj/force-book" : 1,
		]));
        // set("no_fight", "1");
	set("valid_startroom", "1");

	setup();
}

int valid_leave(object me, string dir)
{
	object *inv;
        int i;
	me = this_player();
        inv = all_inventory(me);

	if( dir=="south" )
	{
		if( present("book", me) )
			return notify_fail("你不能把东西带走，请用drop <物品名>命令放下东西再离开。\n");
                // can not got to any where if they take players
                for (i=0; i<sizeof(inv); i++) {
                        if ( userp(inv[i]) )
                        return notify_fail("你不能带着其他玩家离开这里。\n");
                         }
        }
        return ::valid_leave(me, dir);
}            
