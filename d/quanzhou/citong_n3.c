// Code of ShenZhou
// citong_b1.c ��ͩ��·
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ͩ��·");
	set("long", @LONG
����Ȫ�ݵ���Ҫ�ɵ�����ֱ��������ˮ���������ַǷ�����������������
�����Ĺ㳡�����ӵ�����ԶԶ���������������мҺ踣¥��
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"citong_n2",
		"south" : __DIR__"zhongxin",
		"east" : __DIR__"qzkedian",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
