//indoor.c zip@hero 2000.1.27 �����ڲ�
#include <ansi.h>
#define ID 3901
inherit ROOM;
void create()
{	set("short","��Ե��[37;0m");
	set("long",@LONGLONGAGO

ͥԺ���Դ���е�,�����²�̦����,�м���һ��ʯ�������·.��������,����һ��ϸϸ����,����Ͽ�ʱ,��������"���Ĵ�˯ͼ",��������ѧʿ��̫��д��һ��������:�ۺ���������,����Ϯ���Ǿ���.
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","fxcl");
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
   call_other("/p/fystreet/board/fxcl_board","???");
}
#include "indoor_func.c"
