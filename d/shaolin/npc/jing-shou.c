// Code of ShenZhou
// jinjing-shou ��ˮ����

#include <ansi.h>

inherit NPC_TRAINEE;

void create()
{
	set_name("��ˮ����", ({ "jinjing shou", "shou", "beast" }) );
	set_weight(6000000);
	set("race", "Ұ��");
	set("age", 1000);
	set("long", "���Ǵ˴�����̶���ޣ��ݴ��ǵ�������ӵ���������������ǧ��һ�ֵĺ�����ޡ�\n" +
			"��������ͷ����һ֦����������޽ǣ��ݴ�������������������ߺ������֣��鲨���ס�\n");
	set("msg_fail",   "$n����$Nŭ��һ������ʱ׼�����˹���");
	set("msg_succ",   "$n�ǿ������Ŵ������Դ���ͣ��ҡ���ű�����ȥ");
	set("msg_trained","$n��Хһ�����쿪ǰצ��$N����ǰ��������");
	set("auto_follow",1);
	set("attitude", "heroism");

	set("wildness", 50);
	
	set("combat_exp", 100000);
	set("shen_type", 0);
	set("env/wimpy", 50);

	set("str", 100);
	set("int",  20);
	set("con", 100);
	set("dex",  50);

	set("max_jing", 1000);
	set("max_qi",   2000);
	set("max_neili",1000);
	set("neili",    1000);
	set("jiali",     100);

	set("chat_chance", 5);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
	}) );
	
	set("unicorn", 1);

	set_temp("apply/attack", 100);
	set_temp("apply/damage", 100);
	set_temp("apply/dodge",  100);
	set_temp("apply/armor",  100);

	setup();
}

void init()
{
	::init();
	if( this_object()->query_lord() != this_player() ) {
		this_object()->kill_ob(this_player());
		this_object()->set_leader(this_player());
	}
	else {
		add_action("do_qie", "qie");
		add_action("do_qie", "ge");
		add_action("do_ride", "ride");
		add_action("do_ride", "qi");
		add_action("do_unride", "unride");
		add_action("do_unride", "xia");
	}
}

int accept_object(object ob, object obj)
{
	object me = this_object();

	if( obj->query("id") == "gold" ) {
		if(me->is_fighting(ob)) me->remove_all_enemy();
		message_vision("\n$Nһ�ڰѻƽ�������ȥ�������ͷ������������촽��\n\n", me);
		me->add_temp("gold_feed", 1);
	}

	if( me->query_temp("gold_feed") >= 10 ) {
		if(me->query("auto_follow")) me->set_leader(ob);
		message_vision(me->query("msg_trained") + "��\n", ob, me);
		me->set_lord(ob);
		me->delete("chat_msg");

		add_action("do_qie", "qie");
		add_action("do_qie", "ge");
		add_action("do_ride", "ride");
		add_action("do_ride", "qi");
		add_action("do_unride", "unride");
		add_action("do_unride", "xia");
	}

	if( me->query_temp("gold_feed") >= 1 ) return 1;
	else return 0;
}

int do_qie(string arg)
{
	object ob, *inv;
	string tool;
	int i;

	if( !arg || (arg != "shou jiao" && arg != "shou" && arg != "jiao") ) 
		return notify_fail("��Ҫ�и�ʲô��\n");	

	if( !this_object()->query("unicorn") )
		return notify_fail("�޽��Ѿ�����ȡ���ˣ�\n");	

//	if( this_object()->query("qi")*100 / this_object()->query("max_qi") < 10 
//	&&  this_object()->query("qi")*100 / this_object()->query("max_qi") >  5 )
//		return notify_fail("�޽�Ҫ�ñ�ˮ��������ȫ��������������ʱ���������г���\n");	

	inv = all_inventory(this_player());
        
	for(i=0; i<sizeof(inv); i++) {
          if( inv[i]->query("weapon_prop") 
	    &&  inv[i]->query("equipped") 
	    && (inv[i]->query("skill_type") == "blade"
	    ||  inv[i]->query("skill_type") == "sword") )
		tool = 	inv[i]->query("name");
	}	

	if( !stringp(tool) ) return notify_fail("��û�г��ֵĹ������и��޽ǣ�\n");	

	if( this_object()->query_lord() != this_player() ) {
		message_vision(HIR "\nһ��$N������" + tool + "����ˮ���޾��춯�صؾ޺�һ��������������\n" NOR,
					this_player());
		this_object()->kill_ob(this_player());
		this_object()->set_leader(this_player());
	}

	this_object()->set("unicorn", 0);

	ob = new("/d/shaolin/obj/shou-jiao");
	ob->move(this_player());
	message_vision("\n$N��" + tool + "�ѱ�ˮ������ֻ����������޽��������������ڻ��\n", 
				this_player());

	return 1;
}

int do_ride(string arg)
{
	object me, ob;
	me = this_object();
	ob = this_player();

	if ( !arg || (arg != "jinjing shou" && arg != "shou" && arg != "beast")) 
		return notify_fail("��Ҫ��ʲô��\n");

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

void die()
{
	message_vision("\n�����ű�ˮ���޻���һ����⣬ͻ�������������ʧ�ˡ�\n", 
			this_object());
	destruct(this_object());
}

