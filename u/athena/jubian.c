// Room��/u/athena/renwu.c

#include <room.h> 
inherit ROOM;

void create()
{
        set("short", "���ݾޱ�");
        set("long", @LONG
�����¼����ٵ��������ݵ��ش�ı䡣���ڵƹ�������һ����Ⱦ��һ����˿
��С��������ط��������ϣ�����ȡ�ġ�
LONG
        );
        set("no_fight",1);
        set("exits", ([
                "west" : __DIR__"dating",
        ]));
        setup();
}
