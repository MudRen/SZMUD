// Code of ShenZhou
// dxxiang.c ������
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
��������ͨͨ��һ��ʯ��С·���������棬Ҳ��������벻������ʩ�Ž�
������̨���Ϊ����ս��������ǳص���ʯ�˻��̳ɴ�·��
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"citong_s1",
		"east" : __DIR__"jiangfu",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
