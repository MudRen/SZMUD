// Code of ShenZhou
// citong_e1.c ��ͩ��·
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ͩ��·");
	set("long", @LONG
����Ȫ�ݵ���Ҫ�ɵ�����ֱ��㣬��ˮ���������ַǷ������ߵ���������
ʿ�����أ��Է�����ϴ�١�����������Թ��ٵ���̨��
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"liangcang",
		"west" : __DIR__"zhongxin",
		"east" : __DIR__"citong_e2",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
