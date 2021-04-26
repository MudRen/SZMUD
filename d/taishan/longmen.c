// Code of ShenZhou
// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������̩ɽʮ���̵���㡣�˴�ɽ�ƶ��ͣ���ɽ����һ����
С�ĺ����ױ����鵽�¹�֮�С�
LONG
	);

	set("exits", ([
		"northup" : __DIR__"shengxian",
		"southdown" : __DIR__"wudafu",
	]));

	set("outdoors", "taishan");
	set("cost", 3);
	setup();
}

int valid_leave(object me, string dir)
{
	
	if( random((int)me->query_skill("dodge")) <= 10) 
	{
		me->receive_damage("qi", 50, "��ɽ�Ϲ�������ˤ����");
		me->receive_wound("qi",  50, "��ɽ�Ϲ�������ˤ����");
		message_vision(HIR"$Nһ��С�Ľ���̤�˸��գ�... ��...��\n"NOR, me);
		me->move(__DIR__"daizong");
		message("vision", HIR"ֻ��" + me->query("name") + "��ɽ�Ϲ�µµ�ع������������ڵ��ϰ�������������\n"NOR, environment(me), me);
	return notify_fail(HIR"���ɽ�Ϲ���������ֻ���û����޴����ۣ������˼����ˡ�\n"NOR);
	}
	return ::valid_leave(me, dir);
}
		

