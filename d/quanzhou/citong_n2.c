// Code of ShenZhou
// citong_b1.c ��ͩ��·
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ͩ��·");
	set("long", @LONG
����Ȫ�ݵ���Ҫ�ɵ�����ֱ��㣬��ˮ���������ַǷ�������������һ��
���ӣ���ͨ��������
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"citong_n1",
		"south" : __DIR__"citong_n3",
		"northwest" : __DIR__"chxiang",
	]));

	set("objects", ([ 
                __DIR__"npc/liumang" : 2,
	]));

        set("no_clean_up", 0);
        set("fanhua", 2);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
