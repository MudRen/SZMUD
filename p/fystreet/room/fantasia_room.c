//indoor.c zip@hero 2000.1.27 �����ڲ�
#include <ansi.h>
#define ID 801
inherit ROOM;
void create()
{	set("short","[1;36m���ǻ�԰��MeteorGarden)[37;0m");
	set("long",@LONGLONGAGO
������ǿա�Ӧ������ж������������ԡ�Ϊ�㲼��һƬ��� 
��׼���ѹ��������ƽ��į�������������ȫ����������
ǣ���֡��������ߡ����ٴ����������������ҡ���Ҳ������·���� 
�˸���̫�ࡡ�Ķ����ұ�����ƣ����̻��Ҷ����������
���õ����ֻ�ܵ�׺��С�����ҳ�Ĭ����Ϊ����İ��� 
ǣ���֡��������ߡ����ٴ����������������ҡ���Ҳ������·����
����ƽ���ɢ��������һƬ��ů����Ҫ���������е���� 
����ȥ�� ������ ����������ϡ�������������Ҽ��
Ҫ�������ҵİ�ֻ��Ϊ���¸ҡ���ῴ���Ҹ�������
P.S. This House is For the Specialest Woman in My Heart
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","fantasia");
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
   call_other("/p/fystreet/board/fantasia_board","???");
}
#include "indoor_func.c"
