// Code of ShenZhou
// Room: /d/shaolin/beilin3.c
// Date: YZC 96/01/19

inherit ROOM;

int do_study(string);

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ƿ������µĵ������ҡ�������С��ȴҲ�����ȫ��
ʯ��ʯ�Σ�ʯ��ʯ���������ڷŵļ�������Ҳ����ʯ�Ƶġ�
�����ƺ��ܾ���ǰ����������ס�������е�ʯ����ƽ����һ��
������ʯ�壬����������Щʲô��
LONG
	);

	set("objects",([
		"d/shaolin/obj/book-stone" : 1,
	]));

	set("item_desc", ([
		"table" : "����һ�����ʯ��ɵ�ʯ�����������Щ��ֵ�ͼ�Ρ�\n",
	]));

	set("invalid_startroom", 1);

	set("cost", 0);
	setup();
}

void init()
{
	add_action("do_study", "study");
	add_action("do_study", "du");
}

int do_study(string arg)
{
	object me;

	me = this_player();

	if ( !arg || arg != "table" )
		return notify_fail("ʲô��\n");

//	if( file_name(environment(me)) != "/d/shaolin/beilin3" ) {
//		return notify_fail("��ʲô��\n");	

	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");

	if (me->query("jing") < 60)
		return notify_fail("��ľ���������\n");

	me->receive_damage("jing", random(60), "��ʯ���ϵĹŹ�ͼ��������");

	message_vision("$N��ר���ж�ʯ���ϵĹŹ�ͼ�Ρ�\n", me);

	switch( random(5) ) 
	{
	    case 0:
		if ( (int)me->query_skill("finger", 1) < 100)
		{
			me->improve_skill("finger", me->query_int());
			write("�����ʯ����ĥ��һ�ض����ƺ���ָ���е��ĵá�\n");
			me->set_temp("stone_learned",1);
		}
	    case 1:
		if ( (int)me->query_skill("claw", 1) < 100)
		{
			me->improve_skill("claw", me->query_int());
			write("�����ʯ����ĥ��һ�ض����ƺ���צ���е��ĵá�\n");
			me->set_temp("stone_learned",1);
		}
	    case 2:
		if ( (int)me->query_skill("strike", 1) < 100)
		{
			me->improve_skill("strike", me->query("int"));
			write("�����ʯ����ĥ��һ�ض����ƺ����Ʒ��е��ĵá�\n");
			me->set_temp("stone_learned",1);
		}
	    case 3:
		if ( (int)me->query_skill("cuff", 1) < 100)
		{
			me->improve_skill("cuff", me->query_int());
			write("�����ʯ����ĥ��һ�ض����ƺ���ȭ���е��ĵá�\n");
			me->set_temp("stone_learned",1);
		}
	    case 4:
		if ( (int)me->query_skill("hand", 1) < 100)
		{
			me->improve_skill("hand", me->query_int());
			write("�����ʯ����ĥ��һ�ض����ƺ����ַ��е��ĵá�\n");
			me->set_temp("stone_learned",1);
		}
	}

	if ( !me->query_temp("stone_learned") )
	{
		write("�����ʯ����ĥ��һ�ض�������������˵��̫��ǳ�ԣ�������˵�Ѻ��������ˡ�\n");
	}
	return 1;
}

