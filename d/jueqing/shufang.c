// Filename:   /d/jueqinggu/shufang.c
// Program:    Jiuer
// Date:       Aug 15, 2001

#include <ansi.h>
inherit ROOM;

void create()
{
		set("short","�鷿");
		set("long",@LONG
�����ˮ��ׯׯ�����鷿������ż���һ�������ղص��鼮�;��ᣬ
ֻ����ǽ��һ����ܣ������˵��̵ĵ伮��������һ�������εĴ����ӣ�
��������������顣һ���Ҷ����ڴ�ɨ�鷿��
LONG);

	  set("exits",([ 
		"south" : __DIR__"changlang4",
		]));
	  
	  create_door("south", "ľ��", "north");

	  set("objects",([ 
		  "/d/zhongnan/obj/daodejing" : 1,
		  "/d/zhongnan/obj/daodejing-i" : 1,
		  __DIR__"npc/jiading" : 1,
		  ]));

	  set("cost",1);
	  setup();
	  replace_program(ROOM);
}

