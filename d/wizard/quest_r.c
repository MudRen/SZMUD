// Room: /d/wizard/wizard_room.c
// huaishi Aug 14, 2001
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", HIW"������������"+NOR);
        set("long",
 "��������ϯ���ⴴ�����������ֵĻ����ң���һ���ţ�ֻ��������������\n"
+"���г��̹���������������з����ݽǼ���̴��¯���������㣬�ϳ�һ�ֳ�ӯ\n"
+"����ڵĹ�ζ�������м�Ļ������Ϸ���һ�����ӣ������̳�"+BLU+"������ѧ��"+NOR+"��\n"
+"�����֡���˵�������й������ǧ�����������ܡ�\n");
        set("exits", ([ 
                  "out" : "/d/wizard/meeting_room",

]));
        
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("cost", 0);
        setup();
        call_other("/clone/board/quest_b", "???");
        call_other("/clone/board/qst_pro", "???");
}

void init()
{
        object me = this_player();

        if (wizhood(me) == "(player)")
                me->move("/d/death/death.c");
}
