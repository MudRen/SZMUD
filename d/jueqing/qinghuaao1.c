// Filename:   /d/jueqinggu/qinghuaao1.c
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
		"north" : __DIR__"qinghuaao2",
		"eastdown" : __DIR__"path",
		"southwest" : __DIR__"qinghuaao6",
	    "west" : __DIR__"caodi",
		]));
	  
	  set("cost",1);
	  setup();	
}

