// sleeproom.c

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
        set ("short", HIC"˯��"NOR);
        set ("long", "������һ�������С����Ϣ�ң�����������Ų����ľ����˯һ����
���ѣ�����Լ��롰sleep��˯����ף����Ϣ�á�
");

        set("exits", ([ /* sizeof() == 2 */
                "east" : __DIR__"welcome5",
                ]));

        set("objects", ([
                "/d/welcome/npc/yahuan" : 1,
                ]));

        set("valid_startroom", "1");
        set("no_fight", 1);
        set("sleep_room", 1);
        setup();
}
