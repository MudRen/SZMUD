#define ID 1001
#include <ansi.h>
inherit ROOM;
void create()
{	set("short",HIW"�յ�"NOR);
	set("long",@LONG
����ӵ���ĳ������ѵ�һ���Ŀ����أ������������Ѿ�����ɨ�ɾ���
����ȥ����Ѱ������ء���������ӵ��һ���Լ��ķ���ɲ����ף�����Ҫ
����һ��ʵĹ��ؿ
LONG	);
	set("roomid",ID);
  if(ID%2) set("exits",(["east":__DIR__"street"+(string)(ID/100),]));
  else set("exits",(["west":__DIR__"street"+(string)(ID/100),]));
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}