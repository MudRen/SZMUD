// Code of ShenZhou
// ����ͨ��
// qfy 16/10/1996

#include <room.h>
#include <ansi.h>

inherit ROOM;
int do_strike();

void create()
{
        set("short", "��");
	set("long", @LONG
�������󷽡�������Զ�������ƻ�Ȼ����������һ����Ѩ��������
��ʯ�ҡ�
LONG
        );

	set("exits", ([ /* sizeof() == 1 */
		"enter" :  __DIR__"jinshedong",
		"left" : __DIR__"yongdao3",
	]));
	   
	set("cost", 1);
                setup();
}
