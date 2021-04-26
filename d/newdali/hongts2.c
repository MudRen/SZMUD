// Code of ShenZhou
// Room: /d/dali/hongts2.c
// Bug Fix By Mantian Nov,11,2000

inherit ROOM;

int do_study(string);

void create()
{
	set("short", "��ʥ����");
	set("long", @LONG
�����Ǻ�ʥ�����ڲ�������ǽ���϶����з��裬�����÷�������������ģ
ӡש�������������󣬺��Ŀ��������ĵġ����ڷ��������䡱��
LONG);
	set("exits", ([
		"down" : __DIR__"hongts1.c",
		]));
	setup();
	set("cost", 3);
	set("no_clean_up", 0);
}
void init()
{
	add_action("do_study", "study");
	add_action("do_study", "du");
}
int do_study(string arg)
{
	object me = this_player();

	if (!arg || arg != "brick") return 0;

	if ( (int)me->query_skill("literate", 1) < 1)
	{ 
		write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
		return 1;
	}

	if ( (int)me->query_skill("buddhism", 1) < 100)
	{
		if ( me->query("jing", 1) > 50)
		{ 
			me->receive_damage("jing", 30);
			message_vision("$N��ר���ж�ģӡש�ϵġ����ڷ��������䡹��\n", me);
		}
		else
		{
			message_vision("$N�۵Ŀ�����ģӡש�ϵġ����ڷ��������䡹��\n", me);
			return 1;
		}
		me->improve_skill("buddhism", me->query("int"));
		write("�����ģӡש�ϵġ����ڷ��������䡹��ĥ��һ�ض��ĵá�\n");
		return 1;
	}
	write("�����ģӡש����һ�ض�������������˵�ķ���̫��ǳ�ԣ�������˵�Ѻ��������ˡ�\n");
	return 1;
}
int valid_leave(object me, string dir)
{
	int current_jingli, current_dodge;

	current_jingli = me->query("jingli");
	if (dir == "down" && current_jingli >10)
	{
		me->set("jingli",current_jingli-random(20));
		me->improve_skill("dodge", random(10));
		write("������һ��¥����Щ���ˡ�\n");
	}
	else if (dir == "down" && current_jingli <= 10)
	{
		write("���۵��߲����ˣ���Ȼ��ð���ǣ����˹�ȥ��\n");    
		me->unconcious();
		return notify_fail("");
	}
	return ::valid_leave(me, dir);
}
