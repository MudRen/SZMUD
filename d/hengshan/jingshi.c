//Cracked by Roath
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", 
"���Ǻ�ɽ���Ӵ�������������ϰ֮��������Ů������������
���ϱ�Ŀ���С�\n"
        );
        set("exits", ([
                "east"  : __DIR__"square",
                "west"  : __DIR__"sleeproom"
]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

