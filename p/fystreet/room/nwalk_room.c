//indoor.c zip@hero 2000.1.27 �����ڲ�
#include <ansi.h>
#define ID 3600
inherit ROOM;
void create()
{	set("short","[1;32m����ի[37;0m");
	set("long",@LONGLONGAGO
���һ���ţ��ͱ��������ӵ�������ס�ˣ����������ܹ���ǰ԰��԰��
��ͥ�������֣�ǰ԰��ʯ������Ա��ȳ�����൭������ӡ�������������
�书��񣬺�԰��ɽˮ�أ�һƬ���ⰻȻ���㲻����֣����׺η���ʿ�д�
�������¡��ս���ͥ���߳�һλ������Ů���㶨��һ�����Թ����ض�����Ů
ò�����ɣ����˱����߻����������㣬ܽ�����ޣ����Ļش����㲻������һ
��,���˹�ȥ��
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","nwalk");
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
   call_other("/p/fystreet/board/nwalk_board","???");
}
#include "indoor_func.c"
