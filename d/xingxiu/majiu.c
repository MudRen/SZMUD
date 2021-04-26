// Code of ShenZhou
// Room: /city/majiu.c
// Cleansword 1996/12/01

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"���"NOR);
        set("long", @LONG
���ǿ�ջ���ϵ���ǣ����깩Ӧ���ʲ��ϡ���˵�˵���紾�ӣ�
����ֻҪס�꣬����Ǿͻ����ǣ����Ǻ����տ���������ι������
����ϴˢ�ø�Ǭ������һֱ�ź򵽿��������·������жѷ�������
���ϣ�������һ����ۡ�
LONG
        );

        set("objects", ([
		"/d/shaolin/npc/ma-fu" : 1,
		"/clone/horse/donkey" : 1,
		"/clone/horse/sanhema" : 1,
		"/clone/horse/qingma" : 1,
		"/clone/horse/camel" : 2,
                "/clone/obj/car" : 3,
		"/d/shaolin/obj/caoliao" : 2,
        ]));

        set("exits", ([
		"east" : __DIR__"yili",
        ]));

        set("outdoors", "shaolin");
        set("resource/water",1);
        set("cost",1);

        setup();
        replace_program(ROOM);
}
