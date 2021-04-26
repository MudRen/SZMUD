// Code of ShenZhou
// Room: /d/shaolin/yaopinku.c
// Date: YZC 96/01/19

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ҩƷ��");
	set("long", @LONG
������ȫ��ɮ������ҩƷ�ĵط��������������Ź�ŨŨ
��ҩζ����ǽ��һ���Ÿ߼�������ҩ��ÿ��ҩ�����ϰ�
��װҩ��С���룬������������������ĸ��ֲ�ͷҩ������
��ǽ�߷��Ÿ��޴�İ���ɫɼľҩ���������Ÿ����з���
ӡǩ�Ĵ������һλ����ɮ��������æµ�ų���ҩƷ����ҩ
������
LONG
	);

	set("exits", ([
		"south" : __DIR__"fangjuku",
	]));

	set("objects",([
		CLASS_D("shaolin") + "/dao-xiang2" : 1,
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

        if ( arg == "daoxiang chanshi" || arg == "daoxiang" || arg == "chanshi" ) {
		if ( !ob=present(arg, environment(me)) ) return 0;

                message_vision("$N����$n�ȵ�������ͺ¿�����ղ������������һ��\n", me, ob);
                me->kill_ob(ob);

                message_vision("$Nһ����Ц��������ǽ��һ��������ͻȻ�ѿ�һ���󶴣�$n����֮�������ȥ��\n", ob, me);
		me->move("/d/shaolin/jianyu.c");
		tell_object(me,"��������壬ֱ�䵽�����µļ����\n");

		return 1;
        }

        return 0;
}
