//code by cheap
//11/10/01
#include <ansi.h>

inherit ROOM; 

void create()

{
        set("short",HIC"����"NOR);
        set("long",
"�����ǳ��д��������϶����������ס������һ����������ǽ������һ����\n"
"�ң�������д��������ʤ�⡱�ĸ����֡��ϰ����ں͹˿��ּۻ����ء�\n"
); 
        set("exits", ([ 
               "out":"/newjob/tiejiang/gate", 
                      ])); 
        set("objects", ([ 
                "/newjob/tiejiang/npc/feng.c" : 1, 
                        ]) );
        set("day_shop",1);
        setup();
}
