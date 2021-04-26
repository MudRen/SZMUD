// Code of ShenZhou
// Room: /d/shaolin/wuqiku.c
// Date: YZC 96/01/19

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����µ�������ɳ����µ�һ��ʮ�˰�����������νӦ��
���С�����һ��������ٸ��ۻ����ҡ�ǽ������һ����С���ӣ�
ÿ���������˸��ָ����ı�����ǽ��һ����׳��ɮ����ƹƹ��
�ҵ��ڴ���һ�����ȡ���һλ����ɮ������ǽ�Ƿ���һ�ѽ䵶��
�������������������������ӭ�˹�����
LONG
	);

	set("exits", ([
		"west" : __DIR__"zhulin2",
		"north" : __DIR__"fangjuku",
	]));

	create_door("west","ľ��","east",DOOR_CLOSED);
	set("objects",([
		CLASS_D("shaolin") + "/dao-chen" : 1,
		__DIR__"npc/datie-seng" : 1,
		__DIR__"obj/zhujian" : 1,
		__DIR__"obj/mudao" : 1,
	]));
	set("cost", 1);
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_kill", "kill");
}

int do_kill(string arg)
{
	object ob, me=this_player();

	if ( arg == "daochen chanshi" || arg == "daochen" || arg == "chanshi" ) {
		if ( !ob=present(arg, environment(me)) ) return 0;

		message_vision("$N����������ʦ�ȵ�������ͺ¿�����ղ������������һ��\n", me);
		me->kill_ob(ob);
		
		message_vision("$Nһ����Ц��������ǽ��һ��������ͻȻ�ѿ�һ���󶴣�$n����֮�������ȥ��\n", ob, me);
		me->move("/d/shaolin/jianyu.c");
		tell_object(me,"��������壬ֱ�䵽�����µļ����\n");

		return 1;
	}

	return 0;
}
