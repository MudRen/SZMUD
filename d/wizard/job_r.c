// Room: /d/wizard/wizard_room.c
// huaishi Aug 14, 2001
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"����ϵͳ������"+NOR);
        set("long",
 "��������ϯ����ϵͳ������������ֵĻ����ң�������ڴ���ǽ���Ϲ���һ\n"
+"����д��ľ���ϣ�"+HIW+"�����˵��٣�ĺ�˹�ɪ�����������������������"+NOR+"����Ʈ�ݳ�\n"
+"�����Ծ��������������а���Բ�����Σ�����յ�Ҵ������Ĺ���ӳ���£�������\n"
+"��ֻ�м��м�����ļҾ㣬��Ϊ��֦ľ���ƣ����ɹ��Ÿ߹�\n");
        set("exits", ([ 
                  "out" : "/d/wizard/meeting_room",

]));
        
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("cost", 0);
        setup();
        call_other("/clone/board/job_board", "???");
        call_other("/clone/board/job_pro", "???");
}

void init()
{
        object me = this_player();

        if (wizhood(me) == "(player)")
                me->move("/d/death/death.c");
}
