
// Filename:   /d/jueqinggu/caodi.c
// Jiuer 08/15/2001


#include <ansi.h>
inherit ROOM;

void create()
{
		  set("short","�ݵ�");

                  set("long",
"������һƬ������Ĳݵأ��ݾ������ɶ࣬�ݴ����ܵ�׺��"+HIY"���ɫ"NOR+"
�ģ�"+RED"�ٺ�ɫ"NOR+"�ģ�"+MAG"����ɫ"NOR+"��Ұ����������ɢ���������Ļ�������ĵ����
��Ϣ��\n"
);

	  set("exits",([ 
		"east" : __DIR__"qinghuaao1",
        "south" : __DIR__"qinghuaao6",
		"northeast" : __DIR__"qinghuaao2",
		"northwest" : __DIR__"qinghuaao4",
		]));

	  set("outdoors","jueqing");
	  set("resource/grass", 1);
	  set("cost",1);
	  setup();	
	  replace_program(ROOM);
}

