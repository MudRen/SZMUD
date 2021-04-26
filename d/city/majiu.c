// Code of ShenZhou
// Room: /city/majiu.c
// Cleansword 1996/12/01

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"����"NOR);
        set("long", @LONG
���ǿ�ջ���ϵ����ǣ����깩Ӧ���ʲ��ϡ���˵�˵���紾�ӣ�����ֻҪס
�꣬�����Ǿͻ����ǣ�����Ǻ����տ���������ι�����㣬��ϴˢ�ø�Ǭ������
һֱ�ź򵽿��������·�������жѷ������Ѳ��ϣ�������һ����ۡ�����һ��
�������ӭ��������������ڵ�Ц����
LONG
        );

        set("objects", ([
                "/clone/obj/car" : 10,
		"/d/shaolin/npc/ma-fu" : 1,
		"/clone/horse/xiaoma" : 2,
		"/clone/horse/huangma" : 1,
		"/clone/horse/qingma" : 1,
		"/d/shaolin/obj/caoliao" : 2,
        ]));

        set("exits", ([
		"south" : __DIR__"kedian",
		"southeast" : __DIR__"beidajie1",
        ]));

        set("outdoors", "city");
        set("resource/water",1);
        set("cost",1);

        setup();
        replace_program(ROOM);
}