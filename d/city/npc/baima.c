// Code of ShenZhou
// baima.c ����

inherit NPC_TRAINEE;

void create()
{
	set_name("����", ({ "bai ma", "ma", "horse" }) );
	set("race", "����");
	set("age", 10);
	set("long", "����һƥ��ɫ�Ĵ�������������ʨ�ף�������࣬ȷ��ƥ������ǧ����\n");
	set("msg_fail", "$n����$Nŭ˻һ��������������");
	set("msg_succ", "$nҡ��ͷ��ת�����ӻ����ŵ��棬�ƺ��򲻶�����");
	set("msg_trained","$n��˻һ�����ߵ�$N��߰����������Ե�ʮ�ָ��ˣ�");
	set("auto_follow",1);
	set("attitude", "peaceful");

	set("wildness", 3);
	
	set("str", 30);	
	set("con", 40);
	set("dex", 40);	
	set("int", 20);

	set("combat_exp", 10000);
	set_weight(100000);

	setup();
}

void init()
{	
	::init();
	add_action("do_ride", "ride");
	add_action("do_unride", "unride");
}

int do_ride()
{
	object me, ob;
	me = this_object();
	ob = this_player();

	if( me->query_lord() == ob ) 
	{
		if( !ob->query_temp("riding") )
		{
			if( !me->query_temp("rider") ) 
			{
				ob->set_temp("riding", me->name());
				me->set_temp("rider",  ob->name());
				me->set_leader(ob);

				message_vision("\n$Nһ�����������ݵ�������" + me->name() +"���ϡ�\n", ob);
				return 1;
			}
			else    return notify_fail( me->query_temp("rider") + "�Ѿ��������������ˣ�\n");
		}
		else	return notify_fail("���Ѿ�����" + ob->query_temp("riding") + "���ˣ�\n");
	}
	else return notify_fail("�㲻���������ˣ�\n");

	return 0;
}

int do_unride()
{
	object me, ob;
	me = this_object();
	ob = this_player();

	if( ob->query_temp("riding") == me->name() && me->query_temp("rider") == ob->name() ) 
	{
		ob->delete_temp("riding");
		me->delete_temp("rider" );
		message_vision("\n$Nһ������" + me->name() +"����Ծ��������\n", ob);
		return 1;
	}
	else return notify_fail("�㻹û�����أ�\n");

	return 0;
}
