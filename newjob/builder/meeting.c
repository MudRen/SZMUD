//Room:/newjob/builder/meeting.c
//Lara 2001/11/09
inherit ROOM;
#include "teamlist.h"
void create()
{
        set("short", "���������ܻ�����");
        set("long", @LONG
��ϲ��Ϊ������ĳ�Ա�����ǵ�Ŀ���ǽ�����õĽ���ְҵϵͳ��Ϊ
�����Ŀ���ܹ�����ʵ�֣����Ǳ�������ϸ����ķֹ���Ŀǰ�ķֹ���
ʱ��ο�teamlist���������(teamlist)���쿴������Ա��
LONG );
        set("exits", ([
                "wiz" : "/d/wizard/wizard_room",
                "sys" : "/d/wizard/sys_r",
                "jiuer" : "/u/jiuer/workroom",
              "hongyan" : "/u/hongyan/workroom",
                "mariner" : "/u/mariner/workroom",
                "piao" : "/u/piao/workroom",
                "fywen" : "/u/fywen/workroom",
                "lara" : "/u/lara/workroom"               
                 ]));
        set("valid_startroom", 1);
        set("no_fight", "1");
        set("no_clean_up", 0);
        set("cost", 0);
        setup();
        "/clone/board/builder_b.c"->foo();
}
void init()
{       object me = this_player();

        if (wizhood(me) == "(player)") me->move("/d/death/death.c");
        else if ( !is_member(me) ) me->move("/d/wizard/wizard_room.c");
        
        add_action("teamlist","teamlist");
}
int teamlist()
{       int i;
        for(i=0; i<sizeof(member); i++) write(member[i]+"\n");
        return 1;
}

