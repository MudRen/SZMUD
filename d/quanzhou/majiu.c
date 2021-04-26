// Code of ShenZhou
// Room: /city/majiu.c
// Cleansword 1996/12/01

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"���"NOR);
        set("long", @LONG
���ǿ�ջ���ϵ���ǣ����깩Ӧ���ʲ��ϡ���˵�˵���紾�ӣ�����ֻҪ
  ס�꣬����Ǿͻ����ǣ����Ǻ����տ���������ι�����㣬��ϴˢ�øɸɾ���
����һֱ�ź򵽿��������·������жѷ������Ѳ��ϣ�������һ����ۡ�
LONG
        );

        set("objects", ([
		"/d/shaolin/npc/ma-fu" : 1,
//		"/clone/horse/gaoma" : 2,
		"/clone/obj/car" : 1,
		"/clone/horse/hongma" : 1,
		"/d/shaolin/obj/caoliao" : 2,
        ]));

        set("exits", ([
		"west" : __DIR__"qzkedian",
        ]));

        set("resource/water",1);
	set("outdoors", "quanzhou");
        set("cost",1);

        setup();
//	replace_program(ROOM);
}
