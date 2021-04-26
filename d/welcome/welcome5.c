// welcome.c
// modified by lisser, 10/4/2001


#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", HIC"���"NOR);
        set ("long", "������һ����ݣ�����һ���Ŷ�����ܣ����ϰ������飬�������а�
����һ����̴ľ�����������ϰ���һ��̯������װ�鼮������������һֻ
��ͭ�Ŷ�������̴�㣬���ǵ���ͷ���������³�һ�������̣�һλ������
����ܱ����ⷭ�ġ������������������ѧ("HIG"xue"NOR")֪ʶ�Ͷ���("HIG"du book"NOR")��
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
			return notify_fail("�㲻�ܰѶ������ߣ�����drop <��Ʒ��>������¶������뿪��\n");
                // can not got to any where if they take players
                for (i=0; i<sizeof(inv); i++) {
                        if ( userp(inv[i]) )
                        return notify_fail("�㲻�ܴ�����������뿪���\n");
                         }
        }
        return ::valid_leave(me, dir);
}            
