// Code of ShenZhou
// mixiang.c �ײ���
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�ײ���");
	set("long", @LONG
����ͨ�����ֵ�С·���������˵��������ٹٸ����֣���������ŭ֮�£�
�ؿ���·�������йٱ���Ԯ���֡�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"dufu",
		"southwest" : __DIR__"liangcang",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
