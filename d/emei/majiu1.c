// Code of ShenZhou
// Room: /city/majiu.c
// Cleansword 1996/12/01

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"���"NOR);
        set("long", @LONG
���ǲ���ߵ���ǣ����깩Ӧ���ʲ��ϡ���˵�˵���紾�ӣ�����ǻ��
��ǣ����Ǻ����տ���������ι�����㣬��ϴˢ�ø�Ǭ������һֱ�ź򵽿���
��·������жѷ������Ѳ��ϣ�������һ����ۡ�
LONG
        );

        set("objects", ([
		"/d/shaolin/npc/ma-fu" : 1,
		"/clone/horse/liuma" : 2,
		"/clone/horse/hongma" : 1,
		"/d/shaolin/obj/caoliao" : 2,
        ]));

        set("exits", ([
		"east" : __DIR__"shack",
        ]));

//	set("no_fight", 1);
        set("resource/water",1);
        set("cost",1);
	set("outdoors", "emei");

        setup();
        replace_program(ROOM);
}
