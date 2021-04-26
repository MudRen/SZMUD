// Code of ShenZhou
// /d/wanshou/bedroom.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��������ɽׯ������Ϣ�ĵط������Ϲ��ź��صĴ��������ڵ�
���߻谵���������ΰ���������齣�����ͬ�����������Ϣ��
LONG
        );

        set("no_fight", "1");
        set("no_steal", "1");
        set("sleep_room",1);
        set("exits", ([
                "west" : __DIR__"houting",
        ]));

	    set("cost", 0);
        setup();
        replace_program(ROOM);

}
void init()
{
add_action("do_get", "get");
}
int do_get(string arg)  
{
        object obj;

        if( arg
        && objectp(obj = present(arg, environment(this_player())))
        && obj->is_character() ) {
                write("�㲻�ܰᶯ��ҵ����塣\n");
                return 1;
        }
        else
                return 0;
} 

