//indoor.c zip@hero 2000.1.27 �����ڲ�
#include <ansi.h>
#define ID 2601
inherit ROOM;
void create()
{	set("short","$GRE$����$[37;0m");
	set("long",@LONGLONGAGO
���籭�������������̣�����ŵ��͵����Է��ţ����������ˡ�ǿ׳�����塢��³�ľ�ֹ����ͨ����Ĵֿڡ�ɷ�н��µġ�������(��������)��ơ�ơ��������������еĴ��Դ�����������Ų���������kk�Ըе�ơ��Ů�ɡ����Ű���������ķ����Ľ���椡������Ŀ�ϯŮ������kk��͹���ⳡ���껪�������������λ��һ�аڲ����ţ����Ǵ��������߹۵������;����������һ�����Ա�����Ϊ���򰮺�����
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","xyab");
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
   call_other("/p/fystreet/board/xyab_board","???");
}
#include "indoor_func.c"
