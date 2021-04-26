// Code of ShenZhou
// Room: /d/dali/garden4.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIB"�軨Ժ"NOR);
	set("long", @LONG
�������ر��ǲ軨��������ɫ��Ѥ�����ˡ�������ʱʱ���۷������䡣��
ʯ·��ȴ����һ����Ʒ���ֲ軨(flower)��
LONG);
	set("item_desc", ([
		"flower" : HIB"���ɹ���\n"
		"    ���ɹ������ǰ˶�軨����һ�꣬��ɫ������ͬ�����б��������Ϻ͵����\n"
		"��һ�䣬��������������ɹá�û���������ر���ɫ�ģ������ǰ˻���ɫҲ����\n"
		"���ǡ����ɹ������ˣ��������˱�ױ�����ʹ���һƷ��\n"NOR,]));
	set("exits", ([
		"northeast" : __DIR__"garden5",
		"southeast" : __DIR__"garden2",
		]));
 	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
