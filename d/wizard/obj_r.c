// Room: /d/wizard/wizard_room.c
// huaishi Aug 14, 2001
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"��Ʒ���߻�����"+NOR);
        set("long", @LONG
��������ϯ��Ʒ����������������ֵĻ����ң����ߵ�ǽ�Ƿ���������ľ
�����һ�ų����������ϰڷ���ʮ�����ɵ�ľ���ӡ��ı�ǽ��������ߡ�����
��״�Ź����Ǳ���һ��Ķ��������ӵ��м����һ�Ż����������ϻ����ż���
��ߺ�һ�������¼��(board)��
LONG
        );
        set("exits", ([ 
                  "out" : "/d/wizard/meeting_room",

]));
        
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("cost", 0);
        setup();
        call_other("/clone/board/obj_b", "???");
        call_other("/clone/board/obj_pro", "???");
}

void init()
{
        object me = this_player();

        if (wizhood(me) == "(player)")
                me->move("/d/death/death.c");
}
