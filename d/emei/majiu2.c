// Code of ShenZhou
// Room: /city/majiu.c
// Cleansword 1996/12/01

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"���"NOR);
        set("long", @LONG
����һ����ǣ����깩Ӧ���ʲ��ϡ��˵���紾�ӣ�����ǰ���ǣ�����
�����տ���������ι�����㣬��ϴˢ�ø�Ǭ������һֱ�ź򵽿��������·��
����жѷ������Ѳ��ϣ�������һ����ۡ�
LONG
        );

        set("objects", ([
		"/d/shaolin/npc/ma-fu" : 1,
		"/clone/horse/baima" : 2,
		"/clone/horse/heima" : 1,
		"/d/shaolin/obj/caoliao" : 2,
        ]));

        set("exits", ([
		"south" : __DIR__"huayanding",
        ]));

        set("resource/water",1);
        set("cost",1);
	set("outdoors", "emei");

        setup();
        replace_program(ROOM);
}
