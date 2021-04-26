// Code of ShenZhou
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"���"NOR);
        set("long", @LONG
���Ǿ�Ӫ���ϵ���ǣ����깩Ӧ���ʲ��ϡ���˵�˵���紾�ӣ�
����ֻҪ������������Ǿͻ����ǣ����Ǻ����տ���������ι����
�㣬��ϴˢ�ø�Ǭ������һֱ�ź򵽿��������·������жѷ�����
�Ѳ��ϣ�������һ����ۡ�
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
                "east" : __DIR__"bingying",
                
        ]));

        set("outdoors", "dali");
        set("resource/water",1);
        set("cost",1);

        setup();
        replace_program(ROOM);
}

