// Code of ShenZhou
// mituo.c ������
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
�����ľ���죬��ʯ����������ʱ�ڣ��з��������������ϴ�����������
��ǧ��ϸĭ��ʫ�ƣ�����ǧ�㴵���ϣ���������ӿ���ࡣ�ٱ������ʯ���ţ�
�ұ�С���������������ϸ��һ�ߣ���Ϊ��һ���졹֮���ڡ�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"northwest" : __DIR__"qianshou",
		"southeast" : __DIR__"liandan",
	]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 3);
        set("fjing", 1);
        setup();
	replace_program(ROOM);
}
