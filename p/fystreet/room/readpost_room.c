//indoor.c zip@hero 2000.1.27 �����ڲ�
#include <ansi.h>
#define ID 2100
inherit ROOM;
void create()
{	set("short","[1;36m̤[1;33m��[1;35mɨ[1;37mѩ[36m��[37;0m");
	set("long",@LONGLONGAGO
��ߵ�ǽ�Ϲ���һ������ӣ����Ƿ����˳����Ѿ��ܾ�û���ù��ˡ�͸�����ӣ����Կ�������������С�������߳��ź�һЩ���򻨣�����Ʈ�����ӣ�ʹ�����Ŀ��������ݶ���֪������ʲô���ģ����Կ�����ա��¹�͸���ݶ���������ʹ�˷·������ڿ�Ұ֮�С�
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","readpost");
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
   call_other("/p/fystreet/board/readpost_board","???");
}
#include "indoor_func.c"