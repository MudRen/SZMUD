// Code of ShenZhou
// wglou1.c �������¥
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�������¥");
	set("long", @LONG
���˵���˼�飬�������ߡ���������������Ȥ��Ȼ���������¥�����
¥��ʵ��Զ��������һ����¥�����㣬һ�����ţ����ɼ�԰����̨ͤ¥鿣���
ɽ��ˮ��һ�ر�ˮ����źӳ�졣�����������ͷ����ӡ�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"up" : __DIR__"wglou2.c",
		"west" : __DIR__"jiedao2.c",
	]));

        set("objects", ([ 
		__DIR__"npc/qzxiaoer" : 1,
        ]));

        set("no_clean_up", 0);

	set("cost", 1);
        setup();
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if( present("xiao er", me) && dir="west" )
                return notify_fail("�ö˶˵��������С��������ȥ����\n");

        return ::valid_leave(me, dir);
}
