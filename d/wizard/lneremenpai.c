// Room: /d/wizard/wizard_room.c
// huaishi Aug 14, 2001
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", CYN"���ɹ�����"+NOR);
        set("long", @LONG
�������������ϯ�������ɵ����ֵĻ����ң��컨��������һյ����ƣ�
��ҫ�����������������һ��Բ�͵Ļ�������������ż����ʻ�����ɢ������
���㣬���ϻ��ż�̨�ʼǱ����Ժ�һ�������¼��(board)����˵�����ݡ�
���ش����������������ġ�
LONG
        );
        set("exits", ([ 
             "east" : "/d/wizard/general_r",

]));
        
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("cost", 0);
        setup();
          call_other("/clone/board/lneremp_b", "???");
}

void init()
{
        object me = this_player();

        if (wizhood(me) == "(player)")
                me->move("/d/death/death.c");
}
