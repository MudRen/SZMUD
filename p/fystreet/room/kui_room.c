//indoor.c zip@hero 2000.1.27 �����ڲ�
#include <ansi.h>
#define ID 2200
inherit ROOM;
void create()
{	set("short","[1;37m��[1;37m[1;33m��[1;33m[1;37m����[1;37m[37;0m");
	set("long",@LONGLONGAGO
Ӣ���ʼҹ���ۼ���Ӣ����������������������Ӷ����ı��
���з����й���������Σ������һ�����������Ȼ����ʯ�����ɵ�������ɣ��ԡ�أ�
�ұ���һ�����������Ļƽ��Ƶ����磮
���������һ����������������Ǻ�������ԼԼ�и���ȶ��˵���Ӱ��������ֱ����Ѫ����
�ڷ�����������һֻ�������ĺ�ľ�����ӣ�
��������������������ص���ζ��Ҫ������playboy �ķ���Ů�����Ա���ʱ׼��������happy.....(�ǳԷ����������룡��
ͻȻ�㷢��kui ���������ϰ�Ū�������Ƶ��ԣ�һ���˶���mudϲϲɵЦ��
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","kui");
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
   call_other("/p/fystreet/board/kui_board","???");
}
#include "indoor_func.c"
