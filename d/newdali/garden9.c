// Code of ShenZhou
// Room: /d/dali/garden9.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", RED"�軨Ժ"NOR);
	set("long", @LONG
�������ر��ǲ軨��������ɫ��Ѥ�����ˡ�������ʱʱ���۷������䡣��
ʯ·��ȴ����һ����Ʒ���ֲ軨(flower)��
LONG);
	set("item_desc", ([
		"flower" : RED"ץ��������\n"
		"    �װ������ߵģ���������ױ�ع������ٰ����һĨ���Σ�һ˿�����Ľ���\n"
		"��ץ����������������˿���ˣ����ǡ���魽����ˡ�\n"NOR,]));
	set("exits", ([
		"southwest" : __DIR__"garden8",
		"southeast" : __DIR__"garden7",
		"south" : __DIR__"garden6",
		]));
 	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
