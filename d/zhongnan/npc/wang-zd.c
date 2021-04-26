// Code of ShenZhou
// /kungfu/class/quanzhen/wang-zd.c
// wang-zd.c  ��־̹
// sdong 08/01/98

inherit NPC;

void create()
{
	set_name("��־̹", ({ "wang zhidan", "wang" }));
	set("long",
		"����һλȫ��̵��������ӡ�\n"
		);
	set("gender", "����");
	set("age", 46);
	set("attitude", "heroic");
	set("shen_type", 1);
	set("str", 20);
	set("int", 28);
	set("con", 28);
	set("dex", 20);

	set("max_qi", 1000);
	set("max_jing", 1000);
	set("max_jingli", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 200000);
	set("score", 6000);

	set_skill("force", 100);
	set_skill("xiantian-gong", 100);
	set_skill("dodge", 100);
	set_skill("jinyangong", 100);
	set_skill("cuff", 100);
	set_skill("chunyang-quan", 100);
	set_skill("strike", 90);
	set_skill("sanhua-juding", 90);
	set_skill("parry", 100);
	set_skill("sword", 110);
	set_skill("quanzhen-jian", 110);
	set_skill("literate", 80);
	set_skill("taoism", 90);
	set_skill("beidou-zhenfa", 100);

	map_skill("force", "xiantian-gong");
	map_skill("dodge", "jinyangong");
	map_skill("cuff", "chunyang-quan");
	map_skill("strike", "sanhua-juding");
	map_skill("parry", "quanzhen-jian");
	map_skill("sword", "quanzhen-jian");

	prepare_skill("cuff", "chunyang-quan");
	prepare_skill("strike", "sanhua-juding");

	create_family("ȫ���", 3, "����");



	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}

void init()
{
		  object ob = this_player();

		  if( interactive(ob))
		  {

		  }

		  add_action("do_kill_sb","kill");
		  add_action("do_kill_sb","hit");
		  add_action("do_throw","throw");
}

int do_throw(string arg)
{
		  object victim, ob1, ob, me = this_player();
		  string what, who;

		  if( !arg
		  ||      sscanf(arg, "%s at %s", what, who)!=2)
					 return notify_fail("�����ʽ: throw <��Ʒ> at <ĳ��>��\n");

		  ob = present(what, me);
		  if( !ob ) ob = present(arg, environment(me));
		  if( !ob ) return notify_fail("��Ҫ��ʲô��\n");

		  if (ob->query("no_drop"))
					 return notify_fail("������������뿪�㡣\n");

		  if (!(victim = present(who, environment(me))))
					 return notify_fail("����û�����Ŀ�ꡣ\n");

		  if (!victim)
					 return notify_fail("���ﲢ�޴��ˣ�\n");

		  if (!living(victim))
					 return notify_fail("�ⲻ�ǻ��\n");

		  if ( victim->query("id") == me->query("id")  ) {
					 return notify_fail("�Լ�ɱ�Լ���\n");
		  }

		  if ( victim->query("family/family_name") == "ȫ���"  && victim != this_object() ) {
				message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����У���\n", victim, me);
				message_vision( "$Nһ����Ц���󵨿�ͽ�����ҵ��������������ˣ�����ȫ��̺��۸�ô��\n", this_object() );
				this_object()->kill_ob(me);
				return 1;
		  }

	return 0;
}


int do_kill_sb(string arg)
{
		  object ob, ob1=this_object(), me = this_player();

		  if ( !arg || arg == "" ) return 0;

		  if ( !ob=present(arg, environment(me)) ) return 0;

		  if ( ob->query("id") == me->query("id")  ) {
					 return notify_fail("�Լ�ɱ�Լ���\n");
		  }

		  if ( ob->query("family/family_name") == "ȫ���"  && ob != this_object() ) {
			  message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����ղ������������һ��\n", ob, me);
				message_vision("$Nһ����Ц���󵨿�ͽ�����ҵ�����������ɱ�ˣ�����ȫ��̺��۸�ô��\n", ob1);
				ob1->kill_ob(me);
				return 1;
		  }

		  //message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����ղ������������һ��\n", ob, me);
		  return 0;
}


int accept_object(object me, object obj)
{
		  object ob = this_player();

		  command( "say "+obj->name()+"?");

		  if (
				 obj->query("id") == "ling pai" &&
				 obj->query("name") == "ȫ�������"
			)
			{

			  if ( ob->query("family/family_name") == "ȫ���" ) {
					 call_out("reward_dest", 1, obj, ob);
			  }
			  else {
					 call_out("thank_dest", 1, obj, ob);
			  }

			  return 1;
		  }

		  if ( obj->query("id") == "ouyang feng" )
		  {
			  if ( ob->query("family/family_name") == "ȫ���" ) {
					 call_out("reward_feng", 1, obj, ob);
			  }
			  else {
					 call_out("thank_feng", 1, obj, ob);
			  }
			  return 1;
		  }

		  command( "hmm" );
		  command( "say ������ⶫ����ʲ�᣿" );

		  return 0;
}

void close_door()
{
	object here = environment(this_object());
	here->delete("exits/down");
	message_vision("$N������ʯ����һ����֨��һ����������С�š�\n", this_object());
}

void reward_dest(object lingpai,object me)
{
	object here = environment(this_object());
	if(lingpai)destruct(lingpai);
	command( "pat "+me->query("id"));

	if( me->query_temp("qz/feng") )
	{
		command( "say "+me->query("name")+"��Ȼ���������ƣ������ŷ�����ȥ�㻯�ɣ�\n");
		here->set("exits/down", "/d/zhongnan/yuxuhole.c");
		message_vision("$N������ʯ����һ����֨��һ������һ��С�š�\n", this_object());
		call_out("close_door",3);
	}
	else
		command( "say "+me->query("name")+"��Ȼ���������ƣ����ҵ�ŷ�����ȥ�㻯�ɣ�\n");
}


void thank_dest(object obj,object ob)
{
	command( "jump");
	command( "say ��л����\n");
	destruct(obj);
}

void reward_feng(object obj,object ob)
{
	command( "jump");
	command( "say ��û�뵽���ܽ�ŷ����������̫������\n");

	command( "thumb "+ob->query("id"));
	command( "say ��Ȼŷ���������ˣ���������������ҵ���һ���������е�����������Ϊ���Σ�\n���ܵ㻯ŷ����һ������������ʦ�ֲ���������������鶴����ʱ��㻯�ɣ�\n");
	command("drop feng");

	command( "say ֻҪ�������������ƾͿ��Խ�ȥ��\n");

	ob->set_temp("qz/feng",1);
}

void thank_feng(object obj,object ob)
{
	command( "jump");
	command( "say ��û�뵽���ܽ�ŷ������������л����\n");
	call_out("do_destroy",1,obj);
}


void do_destroy(object ob)
{
		  if( ob ) destruct(ob);
}


