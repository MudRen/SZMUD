// Code of ShenZhou
// Room: /city/lichunyuan.c
// YZC 1995/12/04 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"���ի"NOR);
	set("long", @LONG
����һ��ط���Ϊ�����᷿������һ�ɺ����������ɣ���价�ƣ�����
Ŀ��Ͼ�ӡ�������þ�ΪѰ�����������ޣ�����֮���ݿɼ�һ�ߡ�����������
�ǣ����������ı�װ���Ծջ�ͼ��Ϊ�������в���Ũ���޸���
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
		"north" : __DIR__"lichun2",
	]));

	set("cost", 0);
	setup();
//	replace_program(ROOM);
}
 

