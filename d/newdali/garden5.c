// Code of ShenZhou
// Room: /d/dali/garden5.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", MAG"�軨Ժ"NOR);
	set("long", @LONG
�������ر��ǲ軨��������ɫ��Ѥ�����ˡ�������ʱʱ���۷������䡣��
ʯ·��ȴ����һ����Ʒ���ֲ軨(flower)��
LONG);
	set("item_desc", ([
		"flower" : MAG"�糾����\n"
		"    �糾����������Ʒ�͸�Ʒ֮�֣�������Ʒ�����仨�б�����ɫ���������\n"
		"��׿ɣ���ɫ�ߴ�֮�����������ɫ����С����ޣ����Ǻ��Ů������컨\n"
		"������ϻ��׻����Ǳ��Ǹ�Ʒ�ˣ���ݾͲ�ö��ˡ�\n"NOR,]));
	set("exits", ([
		"southwest" : __DIR__"garden4",
		"southeast" : __DIR__"garden3",
		"north" : __DIR__"garden6",
		]));
 	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
