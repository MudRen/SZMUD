//Cracked by Roath
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�Է�");
        set("long", 
"���ھ����ĵģ��������ţ����߻谵�������һ���ſ�����
��������齣�������ɽ����������Ϣ��\n"
        );
        set("exits", ([
                "east"  : __DIR__"jingshi",
]));
        set("no_clean_up", 0);
        set("sleep_room", "1");
        set("no_fight", "1");
        setup();
        replace_program(ROOM);
}

