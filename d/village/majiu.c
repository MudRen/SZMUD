// Code of ShenZhou
// Room: /city/majiu.c
// Cleansword 1996/12/01

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"���"NOR);
        set("long", @LONG
�����ӻ�����ϵ���ǣ��ҳ��깩Ӧ���ʲ��ϡ���˵�˵���紾�ӣ�����ֻҪ
ס�꣬����Ǿͻ����ǣ����Ǻ����տ���������ι�����㣬��ϴˢ�ø�Ǭ������
һֱ�ź򵽿��������·������жѷ������Ѳ��ϣ�������һ����ۡ�
LONG
        );

        set("objects", ([
                "/d/shaolin/npc/ma-fu" : 1,
                "/clone/horse/aijiaoma" : 2,
                "/clone/obj/car" : 1,
                "/clone/horse/hongma" : 1,
                "/d/shaolin/obj/caoliao" : 2,
        ]));

        set("exits", ([
                "east" : __DIR__"shop",
                "southwest" : __DIR__"square",
        ]));

        set("resource/water",1);
        set("outdoors", "village");
        set("cost",1);

        setup();
//      replace_program(ROOM);
}

void init()
{
        object me = this_player();

        if ( interactive(me) && me->query("huashan/job_pending") ) {
                me->set_temp("hz_job/majiu", 1);
        }
}
