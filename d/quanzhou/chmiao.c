// Code of ShenZhou
// chmiao.c ������
// qfy Nov 3, 1996

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
����һ�������Զ��С�����湩���Ź�������������ү����Ȫ�������
�����Եĳ�������˵�����ǩ�����顣�Ա�����С�š�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"southwest" : __DIR__"houshan",
		"southeast" : __DIR__"chxiang",
	]));

        set("objects", ([ 
		__DIR__"npc/miaozhu" : 1,
        ]));

	create_door("southwest", "С��", "northeast", DOOR_CLOSED);

        set("no_clean_up", 0);

	set("cost", 0);
        setup();
}
