// Code of ShenZhou
// Room: /d/dali/wuhua10.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"Сͤ"NOR);
	set("long", @LONG
����һ���߽�Сͤ��ͤ��ǰ������ٷ��ء��ٷ��ط�Բʮ�����ʯ���ɣ�
ˮ�������ĳߣ����Ϥ�У��Ǹ��廪¥��Ĺ���Ǵ����������ޡ�
LONG);
	set("exits", ([
		"south" : __DIR__"wuhua1.c",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
