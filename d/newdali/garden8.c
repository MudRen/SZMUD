// Code of ShenZhou
// Room: /d/dali/garden8.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIR"�軨Ժ"NOR);
	set("long", @LONG
�������ر��ǲ軨��������ɫ��Ѥ�����ˡ�������ʱʱ���۷������䡣��
ʯ·��ȴ����һ����Ʒ���ֲ軨(flower)��
LONG);
	set("item_desc", ([
		"flower" : HIR"�۶���\n"
		"    һ���׻������������������魺˶�״�ڰߵģ��������۶��ġ�����������\n"
		"�ߣ���������˶������ۡ�\n"NOR,]));
	set("exits", ([
		"northeast" : __DIR__"garden9",
		"east" : __DIR__"garden6",
		]));
 	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
