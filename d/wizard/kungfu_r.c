// Room: /d/wizard/wizard_room.c
// huaishi Aug 14, 2001
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"�����ܻ�����"+NOR);
        set("long", @LONG
��������ϯ������������������ֵĻ����ң����ܶ��Ǵ�ĥ�⻬�Ĵ�ʯ
�ڣ����Ͽ̵���ͼ���֣���ϸһ�����ƺ����Ǹ����ɵ��书��ʽ�������ǽ��
����һ���ľ�����������һ�������¼��(board)����˵���������������
���񻰶��������ﴴ������ġ�
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
        call_other("/clone/board/kungfu_b", "???");
        call_other("/clone/board/kf_Pro", "???");
}

void init()
{
        object me = this_player();

        if (wizhood(me) == "(player)")
                me->move("/d/death/death.c");
}
