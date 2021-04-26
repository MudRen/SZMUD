// Code of ShenZhou
// Room: /city/majiu.c
// Cleansword 1996/12/01

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"���"NOR);
        set("long", @LONG
��������Զ·������������ĵط����������ƥ�ϵȣ�Զ��������һλ��
���ڸ���ƥ��ι�ϣ��Ա��м�λ�������������ʿ��������
LONG
        );

        set("objects", ([
		"/clone/obj/car" : 2,
		"/d/shaolin/npc/ma-fu" : 1,
		"/clone/horse/xiaoma" : 2,
		"/clone/horse/huangma" : 1,
		"/clone/horse/qingma" : 1,
		"/d/shaolin/obj/caoliao" : 2,
        ]));

        set("exits", ([
     "east" : __DIR__"kezhan",
     "west" : __DIR__"xfroad5",
		        ]));

        set("outdoors", "changan");
        set("resource/water",1);
        set("cost",1);

        setup();
        replace_program(ROOM);
}
