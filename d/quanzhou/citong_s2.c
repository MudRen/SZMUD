// Code of ShenZhou
// citong_s1.c ��ͩ��·
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ͩ��·");
	set("long", @LONG
����Ȫ�ݵ���Ҫ�ɵ�����ֱ��㣬��ˮ���������ַǷ����ɴ˶��б㵽��
���£���������լ����������һ��������լ����Ȫ�ݳ�����Դ���ñ������ߡ�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"chengtian",
		"west" : __DIR__"minzai3",
		"north" : __DIR__"citong_s1",
		"southeast" : __DIR__"alabo",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        set("fanhua", 2);
        setup();
	replace_program(ROOM);
}
