// Filename:   /d/jueqinggu/dating.c ����
// Program:    Jiuer
// Date:       Aug 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
�߽�ʯ�ݵĴ��������ＫΪ��������������һ�ѿ��Ρ�һ�Ų�����
���κ�����һ�����磬����һ�����Σ�������һ�г��������ɫ��
�����ڴ����ĸ���ʯ�����������ĸ�������ӡ�
LONG);
	
	set("objects", ([
		CLASS_D("jueqing") + "/gongsun" : 1,
               __DIR__"npc/zhang" : 1,
		]));

	set("exits",([ 
		"east" : __DIR__"shishi2",
		"west" : __DIR__"changlang2",
		"south" : __DIR__"changlang1",
		"north" : __DIR__"houtang",
		]));

	set("cost",1);
	setup();
	replace_program(ROOM);
}
