
// Filename:   /d/jueqinggu/shiwu1.c
// Program:    Jiuer
// Date:       Aug 15, 2001


inherit ROOM;

void create()
{
	set("short","Сʯ��");

	set("long",@LONG
������һ��Сʯͷ���ӣ��Ǹ��ɻѰɽ�ļҶ��͹����Ŀ�����Ъ
��ҹ�޶���ġ�
LONG);

	  set("exits",([ 
		  "west" : __DIR__"shulin",
		  ]));

	  set("cost",1);
	  set("outdoors","jueqing");
	  setup();	
	  replace_program(ROOM);
}

