// Code of ShenZhou
// Room: /d/dali/garden7.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIG"�軨Ժ"NOR);
	set("long", @LONG
�������ر��ǲ軨��������ɫ��Ѥ�����ˡ�������ʱʱ���۷������䡣��
ʯ·��ȴ����һ����Ʒ���ֲ軨(flower)��
LONG);
	set("item_desc", ([
		"flower" : HIG"����\n"
		"    ���£���һ����׻���΢�������ĺڰߵģ���׻�����һ�����£���Щ�ڰߣ�n"
		"�������еĹ�֦�ˡ�\n"NOR,]));
	set("exits", ([
		"northwest" : __DIR__"garden9",
		"west" : __DIR__"garden6",
		]));
 	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
