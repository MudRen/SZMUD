// Code of ShenZhou
// Room: /city/lichunyuan.c
// YZC 1995/12/04 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"���Ҹ�"NOR);
	set("long", @LONG
����һ��ط������С�᷿�����г�����Ϊ���£�����װ���������滨Ϊ
����֦�ɺ�б����Ҷ�������£�������Ȼ������һ������ˮīɽˮһ�㡣�ݽ�
һ��С����һ����������ᡵʹ�����������һ�󵭵����㡣
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
		"west" : __DIR__"lichun2",
	]));

	set("cost", 0);
	setup();
//	replace_program(ROOM);
}
 

