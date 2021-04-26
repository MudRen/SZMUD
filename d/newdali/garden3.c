// Code of ShenZhou
// Room: /d/dali/garden3.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIY"�軨Ժ"NOR);
	set("long", @LONG
�������ر��ǲ軨��������ɫ��Ѥ�����ˡ�һ���ϻ���������������軨��
������ʱʱ���۷������䡣��ʯ·��ȴ����һ����Ʒ���ֲ軨(flower)��
LONG);
	set("item_desc", ([
		"flower" : RED"ʮ��ѧʿ\n"
		"    ʮ��ѧʿ�������µļ�Ʒ��һ���Ϲ���ʮ�˶仨�������ɫ��ɫ��ͬ�����\n"
		"����ȫ�죬�ϵı���ȫ�ϣ����ް�ֻ��ӡ�����ʮ�˶仨��״ҵ��䲻ͬ������\n"
		"���������ʱ�뿪лʱ��л��\n"NOR,]));
	set("objects", ([
		__DIR__"npc/huajiang": 1,
		]));                                                                  
	set("exits", ([
		"northwest" : __DIR__"garden5",
		"southwest" : __DIR__"garden2",
		]));
 	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
}
int valid_leave(object me, string dir)
{
	if (me->query_temp("garden_working")) return notify_fail("û�����������û�Ŷ���\n");  
	return ::valid_leave(me, dir);
}                                                                             
