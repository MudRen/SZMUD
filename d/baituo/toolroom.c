//���չ��߷� toolroom.c
//by spark 5/24/2002

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","���߷�");
	set("long",@LONG
����һ���������ķ��䣬�ڷ���һ����ľ��(jia)��һЩ�����С��
Ʒ��ľ���ϳ����źܶ����ι�״�Ĺ��ߡ�
LONG
	);
	set("exits",([
		"northwest": __DIR__"kongdi2",
		]));

	set("cost",1);
	setup();
   	replace_program(ROOM);
}
