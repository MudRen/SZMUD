// /d/kaifeng/ximen.c
//by bravo
#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
        set("short", "����");
        set("long", @LONG
���ǿ����ϳ��ţ��������Ϸ����š����š�����������֣���ǽ
�����ż��Źٸ���ʾ(gaoshi)��һ����ֱ����ʯ�����������졣��
���ǽ��⣬������˽�����ˡ������ǳ��
LONG
        );

        set("item_desc", ([
                "gaoshi" : (:look_gaoshi:),
        ]));
        set("exits", ([
                  "north" : __DIR__"sroad2",
                  "south" : __DIR__"tiandi1",
        ]));
        set("objects", ([
           __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
        ]));
        set("outdoors", "kaifeng");
        setup();
}

string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n���⸮\n����\n";
}
