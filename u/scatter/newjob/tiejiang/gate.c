//code by cheap
//11/10/01
#include <ansi.h>

inherit ROOM; 

void create()

{
        set("short",HIC"����"NOR);
        set("long",
"�����ǳ��еĴ��ţ�һ�顰���С��Ĵ��Ҹ߹��������ϡ�������ľ���Ŵ�\n"
"�����ڴ��ſڵ����Է�����ͷ�ſ��ں���ʯ���ʯʨ�ӡ�������˻������ˣ���\n" 
"�Ƕ�����������󳵣���ɽ�ڿ�ġ�\n " 
); 
        set("outdoors",
                     "city");
        set("exits", ([ 
                   "enter":"/newjob/tiejiang/dating",
                   "west":"/newjob/tiejiang/gate1",
                               ])); 
        set("objects", ([ "/newjob/tiejiang/npc/xiaosi.c" : 1,   ]) );
        set("no_clean_up",0);
       setup();
}
