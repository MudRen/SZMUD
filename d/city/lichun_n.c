// Code of ShenZhou
// Room: /city/lichunyuan.c
// YZC 1995/12/04 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"��÷Է"NOR);
	set("long", @LONG
����һ��ط���Ϊ�����᷿�����ڲ��õù��ⰻȻ��һֻ�ż�������һ
�٣�����һֻ��ͭ�Ŷ����������̴Ӷ����������ϣ�����������ϯ���ε�֮��
�������磬���˶ٷ�˼��֮���顣�ı�ֻ��׺��֦��÷���������㡣
LONG
	);

/*
	set("objects", ([
	]));

	set("item_desc", ([
		"tu" :
	"\n"
	]));
*/
	set("exits", ([
		"south" : __DIR__"lichun2",
	]));

	set("cost", 0);
	setup();
//	replace_program(ROOM);
}
 

