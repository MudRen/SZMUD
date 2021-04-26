// Code of ShenZhou
// Room: /d/shaolin/fangjuku.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "���߿�");
	set("long", @LONG
����һ��ܴ�ķ��䣬��ǽ����ط���һ��������ӣ�����
�����ų����ţ�¶������ĸ��ַ��ߣ�Ʒ��֮�࣬������ƽ������
һλ����ɮ������ͷ����һ������Ļ��ߡ��������Ҳû��ע�⡣
LONG
	);

	set("exits", ([
		"north" : __DIR__"yaopinku",
		"south" : __DIR__"wuqiku",
	]));

	set("objects",([
		CLASS_D("shaolin") + "/dao-xiang" : 1,
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

