//indoor.c zip@hero 2000.1.27 �����ڲ�
#include <ansi.h>
#define ID 500
inherit ROOM;
void create()
{	set("short","[1;33m��ó���Ĵ���[37;0m");
	set("long",@LONGLONGAGO
��ó���Ĵ������ϱ�����˫��¥���ɣ�¥��411�ף�110�㡣
��������ߵĽ�������107���ǲt��������ĿԶ��������������
���۵ס� ��¥������ó�ס��������ҵ��һ�����ݸ�����
��������ҵ������ҵ��ITҵ�Ⱦ�Ӣ�������ڴˡ� ���»������
Ϊ���ͳ��м�ͣ������ ����ǰ�Ĺ㳡���е���վ���ڣ���ͨ��
�㡣��ŦԼ��ó���ı��ֲ����Ӵݻٺ�Ϊ�������б�.���ǵ�
׷���ߣ���¥��ǿ�˰����ʩ����¥�Ͽ�5���ﷶΧ����Ϊ����
�����������δ����������������ߵ�������ܡ�
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","lock");
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
   call_other("/p/fystreet/board/lock_board","???");
}
#include "indoor_func.c"
