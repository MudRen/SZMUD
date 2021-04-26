inherit ROOM;
#include "list.h"

void create()
{
        set("short", "ҽʦϵͳ�Ļ�����");
        set("long", @LONG
�����Ƕ�ϵͳ�ڶ��ӵĻ����ң����е���ƶ�������ƻ�������
����ʵ�
LONG );

        set("exits", ([
                "down" : "/d/wizard/wizard_room" ]));

        set("valid_startroom", 1);
        set("no_fight", "1");
        set("no_clean_up", 0);
        set("cost", 0);
        setup();

        "/clone/board/doctor_b.c"->foo();

}

void init()
{
        object me = this_player();

        if (wizhood(me) == "(player)") me->move("/d/death/death.c");
        else if ( !is_member(me) ) me->move("/d/wizard/wizard_room.c");
        
        add_action("list","list");
        add_action("list","more");
}

int list()
{
        int i;

        for(i=0; i<sizeof(member); i++) write(member[i]+"\n");

        return 1;
}
