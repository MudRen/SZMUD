// Code of ShenZhou
// gtxiang.c ��̳��

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "��̳��");
        set("long", @LONG
��̳��˳��ʩ����ǽ���Ѷ�����һ����������ˮ�Ĺ������İ���������̳
����������ǳ����¡�
LONG
        );

        set("exits", ([ /* sizeof() == 3 */
		"southwest" : __DIR__"chengtian",
		"north" : __DIR__"jiangfu",
		"west" : __DIR__"xuetang",
	]));

	set("no_clean_up", 0);
	set("outdoors", "quanzhou");
	set("cost", 1);
        setup();
}

int valid_leave(object me, string dir)
{
        me->set_temp("mark/��", 0);
        return 1;
}
