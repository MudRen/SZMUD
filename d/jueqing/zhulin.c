// Filename:   /d/jueqinggu/zhulin.c
// Program:    Jiuer
// Date:       Aug 15, 2001

inherit ROOM;

void create()
{
		  set("short","����");

		  set("long",@LONG
����ɽ���������г���������ӭ�������͵ĺô�һƬ���֡�����
���Ӽ��٣������һƬ���ָ��Ǻ��������������д����ŵ�һ����
�����㣬�Ǿ����׾�����
LONG);

	  set("exits",([ 
		"southdown" : __DIR__"shulin",
		"northeast" : __DIR__"shuitang",
			 ]));
	  	  
	  set("outdoors","jueqing");
	  set("cost",1);

	  setup();
	  replace_program(ROOM);
}

