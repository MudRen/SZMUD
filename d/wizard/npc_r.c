// Room: /d/wizard/wizard_room.c
// huaishi Aug 14, 2001
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"��������������"+NOR);
        set("long", @LONG
�����Ƿ��������������������ֵĻ����ң���װ�޹�������ǽ���Ϲ��ż�
յ�ڵƣ��������������һ�Ż����������ϳ��������������Ʒ�����������
����ȫ���ڶ����˵���ʽ�������ƺ�����ĳλ�������˵���ƣ����������ѹ�
�����������չ�������˵�ǧ�˰�̬�С�
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
        call_other("/clone/board/npc_b", "???");
        call_other("/clone/board/npc_pro", "???");
}

void init()
{
        object me = this_player();

        if (wizhood(me) == "(player)")
                me->move("/d/death/death.c");
}
