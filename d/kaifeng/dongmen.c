// d/kaifeng/dongmen.c
//by bravo
#include <room.h>
inherit ROOM;
string look_gaoshi();
void create()
{
        set("short", "����");
        set("long", @LONG
���������������⣬ֻ���ߴ�ĳ�ǽ��ʵ���أ�������ϸ���̲�
�Ź������ˣ�һ�ж��Եþ�����������ǽ�����ż��Ÿ�ʾ(gaoshi)��
����ԶԶ���Կ����������Ϫ��ˮ�������ǳ��
LONG
        );

        set("item_desc", ([
                "gaoshi" : (:look_gaoshi:),
        ]));
        set("exits", ([
                  "west" : __DIR__"eroad2",
                  "east" : "/d/shaolin/yidao3",
                  
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
