//indoor.c zip@hero 2000.1.27 �����ڲ�
#include <ansi.h>
#define ID 701
inherit ROOM;
void create()
{	set("short","[35m����С��[37;0m");
	set("long",@LONGLONGAGO
����һ���䲻������ȴ��ʰ�ú�����Ŀ�����
  ���аڷ���һ��������������ɫ����İ�������
  �������������ż������Ρ�
  ������һ��ʢ���ŵ�ˮ�ɣ�
  ������Լ�ɼ�һ�������СϪ���������ʡ�
  ΢�紵��������������������㣬���˾���Ϊ֮��ˬ�����ࡣ
  ���������������Լ���д��һ�����ӣ�
      һ �� Я �֣��� ¥ �� �� ��
      һ �� �� �飬�� �� �� �� ·
LONGLONGAGO	);
	set("exits",([
//         "up":"/u/snowyu/yangtai1",
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","qingl");
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
   call_other("/p/fystreet/board/qingl_board","???");
}
#include "indoor_func.c"