// Filename:   /d/jueqinggu/qinghuaao4.c
// Program:    Jiuer
// Date:       Aug 15, 2001

#include <ansi.h>
inherit ROOM;

void create()
{
		  set("short",HIM"�黨԰"NOR);

		  set("long",@LONG
����һƬ�������ɵ�԰�βݵأ�������ܲ���Χ�����黨������
���ĸ���λ���������а˾��ɵ��������黨��
LONG);

	  set("exits",([ 
	  "north" : __FILE__,
	  "west" : __FILE__,
	  "northeast" : __DIR__"qinghuaao3",
	  "southwest" : __DIR__"qinghuaao5",
          "southeast" : __DIR__"caodi",
		]));
	  
	  set("cost",1);
	  setup();	
}

