// Code of ShenZhou
// Room: /d/shaolin/hantan3.c

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "��ź�̶");
	set("long", @LONG
���Ǻ�̶֮�С�����ˮ�����һ��ʹ����̶ˮ�ڴ˴����
��ϡ��һ�������ܵı���������һ����飬����˫������͸����
�������⣬ȫ��������Ѷ������ã�ֻ������ˮ�������������
��ȥ��
LONG
	);

	set("cost", 3);
	setup();
}

void init()
{
	call_out("down", 10, this_player());
}

void down(object me)
{
	tell_object(me, HIR "\nͻȻһ���ޱȾ޴�ĺ�����޴���ӭ�����������ʱ���˹�ȥ ... \n\n" NOR);
	me->set_temp("block_msg/all", 1);
	me->unconcious();
	me->move("/d/kunlun/river1");
}
