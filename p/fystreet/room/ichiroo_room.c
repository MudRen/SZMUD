//indoor.c zip@hero 2000.1.27 �����ڲ�
#include <ansi.h>
#define ID 2201
inherit ROOM;
void create()
{       set("short",HIW"#51 ICHIROO ������ϰ��"NOR);
	set("long",@LONGLONGAGO
��������ϰ���Ĺ����...���������ڴ�СЪƬ�� 
��͸���Ĳ�������ȥ,��������������ͼˮ�ֶ�����ʱ��һ��һ��       
��...���������ݵľ�����ľһ��
�����ó���һ֧����
�������Էɿ�Ľų�����ݵ�ȥ
��һ�ε��ݳɹ� 
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","ichiroo");
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
   call_other("/p/fystreet/board/ichiroo_board","???");
}
#include "indoor_func.c"
