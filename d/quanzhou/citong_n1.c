// Code of ShenZhou
// citong_n1.c ��ͩ��·
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ͩ��·");
	set("long", @LONG
����Ȫ�ݵ���Ҫ�ɵ�����ֱ��㣬��ˮ���������ַǷ��������Ƕ����
��ͨ����������һ�Ӷӵ�ʿ��������ȥ������ɭ�ϡ�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"duxiang",
		"north" : __DIR__"weiyuan",
		"south" : __DIR__"citong_n2",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
