// Room: /d/wizard/wizard_room.c
// huaishi Aug 14, 2001
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIY"�ƽ���"+NOR);
        set("long", @LONG
������һ���ƽ�ĵ��ã�ʮ����ΰ������������˸��⡣ǰ�����߳����
�������ܡ��ʻ�г����ĸ�һ�˱���ס���������ӡ��������м���ž޴�ĺ�ľ
Բ�����������ҵط���һ���������ͼֽ���ĸ壬����������עĿ����һ������
���С���ӣ�������д���������塸��ѫ�᡹(ce)��
LONG
        );
        set("exits", ([ 
                  "job" : "/d/wizard/job_room",
                  "up"  : "/d/wizard/meeting_room",
                  "gm"  : "/d/gumu/dating",
                  "mp"  : "/d/wizard/smiling_room",                  
                  "wg"  : "/u/zyu/workroom",                  
                  "cl"  : "/d/forest/clxiaoting",                  
                  "test"  : "/d/wizard/testroom",                  
                  "down"  : "/d/wizard/guest_room",                  

]));
        
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("cost", 0);
        setup();
        call_other("/clone/board/wiz_b", "???");
}

void init()
{
        object me = this_player();

        if (wizhood(me) == "(player)")
                me->move("/d/death/death.c");
}
