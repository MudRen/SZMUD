// Code of ShenZhou
// citong_x1.c ��ͩ��·
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ͩ��·");
	set("long", @LONG
����Ȫ�ݵ���Ҫ�ɵ�����ֱ��㣬��ˮ���������ַǷ��������ǿ�Ԫ�£�
�ϱ��Ǽ������ϵ꣬�����������ŵ��š�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"kaiyuan",
		"west" : __DIR__"xiqiao",
		"east" : __DIR__"citong_w1",
		"south" : __DIR__"yaopu",
	]));

        set("fanhua", 2);
        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
