//indoor.c zip@hero 2000.1.27 �����ڲ�
#include <ansi.h>
#define ID 1401
inherit ROOM;
void create()
{	set("short","[35mС����[1;32m��[37;0m");
	set("long",@LONGLONGAGO
һ�������Ĵ��Ϸ���һ��snoopy�����ֽа��������ܹԵ����ڴ��ϡ�
��������һ�������輸���������ӡ��輸�ϰ���һ�����򻨣��������������㡣


����ʱ��
�ð�����
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","piggy");
       set("no_fight",1);
       set("no_magic",1);
       set("sleep_room",1);
       set("if_bed",1);
       set("NONPC",1);
       set("no_dazuo",1);
       set("no_study",1);
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
   call_other("/p/fystreet/board/piggy_board","???");
}
#include "indoor_func.c"