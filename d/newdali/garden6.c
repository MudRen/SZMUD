// Code of ShenZhou
// Room: /d/dali/garden6.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", GRN"�軨Ժ"NOR);
	set("long", @LONG
�������ر��ǲ軨��������ɫ��Ѥ�����ˡ�������ʱʱ���۷������䡣��
ʯ·��ȴ����һ����Ʒ���ֲ軨(flower)��
LONG);
	set("item_desc", ([
		"flower" : GRN"������\n"
		"    �����ţ�����ʮ�߶䲻ͬɫ�Ĳ軨����һ�꣬������ɫ����ʮ��ѧʿ����\n"
		"һɫ��ƫ���ǲ�����������������ٻ��磬�����д���С��������ʩЧ򭣬ѧ��\n"
		"ʮ��ѧʿȴ��ѧ�������Ǿͱ������ˡ������š���\n"NOR,]));
	set("exits", ([
		"north" : __DIR__"garden9",
		"south" : __DIR__"garden5",
		"west" : __DIR__"garden8",
		"east" : __DIR__"garden7",
		]));
 	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
