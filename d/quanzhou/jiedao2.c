// Code of ShenZhou
// jiedao1.c �ֵ�
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�ֵ�");
	set("long", @LONG
����Ȫ�ݵ�һ���ɵ�����ȥ�ɴﺣ�⽻ͨʹ�ڸ����������������¥��
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"wglou1",
		"south" : __DIR__"shijiefu",
		"north" : __DIR__"jiedao1",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
