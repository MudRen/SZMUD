// Room��/u/athena/dating.c

#include <room.h>
#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", YEL"����"NOR);
        set("long", @LONG
�ͱ���������Ե��е�յ����ģ�ֻ��һЩ�ɹ�������Ϣ������ɢ���ڴ���
�Ľ��䡣ǽ���Ϲ��Ÿ������ɵĶ����������е��⼣�߰ߣ��еĻ���������Ѫ�⡣
ż�����˴�չ�����߳�����ȴ��ʮ�ְ��������Ƿ·�Ҳ��˼����ʲô���е���Ǵ�
��Ц�ݣ��е�ȴ����̾Ϣ��
LONG
        );
        set("no_fight",1);
        set("exits", ([
                "east" : __DIR__"jubian",
                "west" : __DIR__"renwu",
                "north" : __DIR__"cangsang",
                "out" : __DIR__"damen",
        ]));
        create_door("out", "����", "enter", DOOR_CLOSED);
        set("cost", 1);
        setup();
}
