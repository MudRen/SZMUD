// Code of ShenZhou
// hjting.c ����ͤ
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����ͤ");
	set("long", @LONG
����һ�����ڴ�·�����Сͤ�ӣ����������������ڴ���Ϣ����ȥ����˳
���ţ���ͨ���ۿڡ�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"jishi",
		"south" : __DIR__"sjqiao",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
