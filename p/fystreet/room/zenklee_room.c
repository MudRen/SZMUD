//indoor.c zip@hero 2000.1.27 �����ڲ�
#include <ansi.h>
#define ID 2400
inherit ROOM;
void create()
{	set("short","[1;33m���[37;0m");
	set("long",@LONGLONGAGO
����С�ǵļ��,������Ѱ�ֵĺõط�.һ����,�����˾���һ��.
��������,�����Ǻܴ�Ĵ���.���漫֮����,����Ư�����ö�����
��.�������벻������,ʲô���ҵ����ö���.����,��,��,��,��,
��Ĵ�32A��38F,���Ŵ�ѧУ��,���ȼ���,����û������.С�ǵ�
�����ѵ���������,���᲻����,˵δ�湻.
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","zenklee");
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
   call_other("/p/fystreet/board/zenklee_board","???");
}
#include "indoor_func.c"
