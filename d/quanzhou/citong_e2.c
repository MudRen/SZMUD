// Code of ShenZhou
// citong_e2.c ��ͩ��·
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ͩ��·");
	set("long", @LONG
����Ȫ�ݵ���Ҫ�ɵ�����ֱ��㣬��ˮ���������ַǷ�����Թ�������ڱ�
�ߣ���ͨ����̨����̨������ǳ����һ��ʢ�¡�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"citong_e1", 
		"north" : __DIR__"enyuan",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
