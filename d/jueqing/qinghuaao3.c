// Filename:   /d/jueqinggu/qinghuaao3.c
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
	  "north" : __DIR__"shulin",
	  "southeast" : __DIR__"qinghuaao2",
	  "southwest" : __DIR__"qinghuaao4"
	  		]));
	  
	  set("cost",1);
	  setup();	
}

