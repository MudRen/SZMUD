//indoor.c zip@hero 2000.1.27 �����ڲ�
#include <ansi.h>
#define ID 300
inherit ROOM;
void create()
{	set("short","[35m����ȶϳ���[37;0m");
	set("long",@LONGLONGAGO
 ��������Ů��С��

���ٻ�ͷ�����ǹ��ϵĳ���
Ҳ��ֻ����Щ��ҹ�����Ⱥ������
����ÿ���峿��Ȼ�Ὺ��̽�� 
ÿ���ļ���Ȼ�������������

LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","longnv");
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
	set("objects", ([__DIR__"obj/cabinet" : 1,]),);
	setup();
   call_other("/p/fystreet/board/longnv_board","???");
}
#include "indoor_func.c"
