// Code of ShenZhou
// chxiang.c ������
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
һ��������խ����ʯС·��������ľ�β����ɭ�䡣
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"southeast" : __DIR__"citong_n2",
		"northwest" : __DIR__"chmiao",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
