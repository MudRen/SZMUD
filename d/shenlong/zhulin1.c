// Code of ShenZhou
//����1 /d/shenlong/zhulin1
// ALN Sep / 97

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��ǰ��һƬ���̵����֣�����������ˡ�ż���м������߹����ƺ����ϻ�
�Ͽֵ����ӣ��㲻�ɵ�����һ�������ѹ�����ߵĻ������˻�ȥ��������һ��
�񷿣���������һƬ���֣�������һ�����á�
LONG
        );

        set("outdoors", "shenlong");
        set("exits", ([
                "enter" : __DIR__"qianlong",
                "west" : __DIR__"shibanlu",
                "south" : __DIR__"yaofang",
                "north" : __DIR__"zhulin2",
        ]));

        set("objects", ([
                "/kungfu/class/shenlong/yin" : 1,
                "/d/shenlong/npc/huang": 1,
        ]));

        set("cost", 1);

        setup();

        replace_program(ROOM);
}

/*
int valid_leave(object me, string dir)
{

        if( (int)me->query("sg/exp") < 5000 && dir == "north" ) 
                return notify_fail("�����Ǳ��̳����������ش����㻹����ذɡ�\n");

        return ::valid_leave(me, dir);
}
*/
