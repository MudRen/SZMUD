// Code of ShenZhou
// citong_s1.c ��ͩ��·
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ͩ��·");
	set("long", @LONG
����Ȫ�ݵ���Ҫ�ɵ�����ֱ��㣬��ˮ���������ַǷ�����ͩ��·�Ķ���
�Ǵ����������һ��Ƭ��լ����ͨ�˴������ݺ�ϷԺ�����߱������ֵ�
���Ĺ㳡��
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"zhongxin",
		"south" : __DIR__"citong_s2",
		"east" : __DIR__"dxxiang",
		"west" : __DIR__"minzai1",
		"southwest" : __DIR__"minzai2",
	]));

        set("no_clean_up", 0);
        set("fanhua", 1);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
