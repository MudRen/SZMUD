
// Filename:   /d/jueqinggu/qinghuaao.c
// Program:    Jiuer
// Date:       Aug 15, 2001

#include <ansi.h>
inherit ROOM;

void create()
{
		  set("short",HIM"�黨԰"NOR);

		  set("long",@LONG
����һƬ�������ɵ�԰�βݵأ�������ܲ���Χ�����黨������
���Ǹ���λ���������а˾��ɵ��������黨��
LONG);

	  set("exits",([ 
		"northwest" : __DIR__"zhulin",
		"east" : __DIR__"caodi",
		"eastdown" : __FILE__,
		"north" : __FILE__,
		"southwest" : __DIR__"shiwu1",
	    "west" : __DIR__"shulin",
		]));
	  
	  set("cost",1);
	  setup();	
}

