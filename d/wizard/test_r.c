// Room: /d/wizard/wizard_room.c
// huaishi Aug 14, 2001
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"���Ե��������"+NOR);
        set("long", @LONG
�����ǲ��Ե���ͳ�����������ֵĻ����ң�ǽ�����ܰڷ��ż������ӣ���
�ϵĵ�������֨֨����ع����ţ������ƺ��е㲻ʤ���ɣ�ǽ�ڵ�����ɢ����
���Ԫ�صĵ�ƿ�ӣ���˵����ͨ���ﵩ�Ŀ��ᡢ���Գ�����������������ġ�
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
        "/clone/board/test_pro"->foo();
        call_other("/clone/board/test_b", "???");
}

void init()
{
        object me = this_player();

        if (wizhood(me) == "(player)")
                me->move("/d/death/death.c");
}
