// Code of ShenZhou

// zezhong.c ������
// qfy July 4, 1996.

inherit NPC;
inherit F_MASTER;

int auto_perform();
string ask_me();

void create()
{
	set_name("������", ({ "ning zhongze", "ning", "zhongze" }));
	//set("nickname", "���ӽ�");
	set("long", 
"����ǻ�ɽ�������ŷ��ˡ����ڽ�������������������Ⱥ���Ǹ�\n"
"������ü��Ů�к��ܡ��书������Ⱥ�������¡�\n");
	set("gender", "Ů��");
	set("age", 40);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 37);
	set("int", 20);
	set("con", 20);
	set("dex", 37);

	set("max_qi", 2000);
	set("max_jing", 1850);
	set("neili", 2500);
	set("max_neili", 2500);
	set("jiali", 120);
	set("combat_exp", 900000);
	set("score", 5000);
	set("env/wimpy",60);

	set_skill("force", 140);
	set_skill("dodge", 145);
	set_skill("parry", 140);
	set_skill("sword", 145);
	set_skill("strike", 140);
	set_skill("huashan-jianfa", 145);
	set_skill("hunyuan-zhang",140);
	set_skill("huashan-shenfa", 145);
	set_skill("zixia-gong", 140);
	set_skill("cuff", 140);
	set_skill("pishi-poyu", 140);
	set_skill("ziyin-yin", 110);
	set_skill("zhengqi-jue", 110);
	set_skill("literate", 101);

	map_skill("cuff", "pishi-poyu");
	map_skill("force", "zixia-gong");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("strike", "hunyuan-zhang");
	map_skill("dodge", "huashan-shenfa");

	prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "pishi-poyu");

	create_family("��ɽ��", 13, "���ŷ���");

	set("inquiry", ([
		 "����" : (: ask_me :),
		 "����" : (: ask_me :),
	    "����Ⱥ" : "���������ӡ�\n",
	    "�����" : "������Ů����\n",
	    "��ϼ��" : "���Ǳ����������ϵ��ڹ��ķ���\n",
	    "��ϼ��" : "���Ǳ����������ϵ��ڹ��ķ���\n",
	    "˼����" : "���Ǳ��ɵ�������˼��֮����\n",
	    "������" : "������ʦ�壬�����㻹���������Ӱɡ�\n",
	]));

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city/obj/pink_cloth")->wear();
}

void init()
{
	object ob;

	::init();

	set_heart_beat(1);

	if (interactive(ob=this_player()) && ob->query("family/master_id") == "ning zhongze"
	&& ob->query("shen") < -100 ) {
		command("say " + RANK_D->query_rude(ob) + "�������������������Ϊ��" );
		command( "expell " + ob->query("id"));
	if ( this_object()->query("qi") < 2200 ) {
		exert_function("heal");
		exert_function("heal");
		exert_function("heal");
		exert_function("recover");
		return 0;
	}

	}
}

void attempt_apprentice(object ob)
{

	if (ob->query("class")=="bonze") {
		command ("say ��ɽ��һ���ճ�����Ϊͽ������ذɡ�");
		return;
	}

	if ((string)ob->query("gender") == "����") {
		command("say �Ҳ�����ͽ��" + RANK_D->query_respect(ob) + "���ǰ������������°ɡ�");
		return;
	} 

	if ((string)ob->query("gender") == "����") {
		command("say " + RANK_D->query_respect(ob) + "�Ƕ������ˣ�ˡ�Ҳ������㡣");
		return;
	}

	if ((string)ob->query("family/family_name") == "ؤ��" && ob->query("rank") > 1 ) {
		command("say " + RANK_D->query_respect(ob) + "��ؤ����֣�ˡ�Ҳ������㡣");
		return;
	}

	if( ob->query("family/family_name") != "��ɽ��" && ob->query("combat_exp") >= 10000 ) {
		command ("say " + RANK_D->query_respect(this_player()) + "��"
			+ob->query("family/family_name")+"���֣����ɿɲ���������");
		return;
	}

	if ((int)ob->query("huashan/ning") == 1 && (int)ob->query("betrayer") > 10) {
		command("say " + RANK_D->query_respect(ob) + "�Ǹ������ķ���֮�ˣ���������ŵù��㣿");
		return;
	}

	if ((int)ob->query("shen") < 0) {
		command("say �һ�ɽ�����������������ɣ��Ե���Ҫ���ϡ�");
		command("say "+RANK_D->query_respect(ob)+"���ұ����ˣ�ˡ�Ҳ������㡣");
		return;
	}
       
	command("say �ðɣ��Ҿ��������ˡ�ϣ������Ϊ��ɽ���⣬�츣���֡�");
	ob->set("huashan/ning", 1);
	ob->set("betrayer", 0);
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	object me = this_player();
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ( !myfam || myfam["family_name"] != "��ɽ��" )
		return "���Ǻ���ԨԴ���������¸��\n";

	say("�����г�����̾��һ���������ĳ���˵��������ɽ��������Ϊ�������ڡ���\n");
	say("�����ڷ���Ϊ�����Խ�Ϊ���������˽����޼᲻�ݡ�������������ʩ�ؽ�\n");
	say("���������ڸ��ּ���������ˮ���ݣ�ͬ�Ųٸ꣡��ɽ���ʽ΢���㼴����\n");
	say("�ţ������ܽ����԰�������ɽ���ǵõ����Ҷ���д���ǡ���������������\n");
	say("�������佣·�ݺᣬ�仯�޷�������Ȼ�������ڡ���ϼ�񹦡�֮�£���ʮ��\n");
	say("���������֣�ʵ�첻ʤ��Ҳ����\n");
	return "�мǣ��мǣ�\n";
}


int accept_fight(object ob)
{
	object me = this_object();
	int my_max_qi; 
	
	my_max_qi = me->query("max_qi");

	if ( me->query("qi")*100 / my_max_qi <= 80 ) {
		me->command("say �����岻�ʣ�ˡ�����㣡");
		me->set("qi",me->query("eff_qi",1)+20);
		return 0;
	}

	if ( me->query("neili")<1500 ) {
		return 0;
	}

	auto_perform();

	return 1;
}

int accept_kill(object ob)
{
	object me = this_object();
	object ob1 = this_player();

	// if unconcious then do nothing
	if( me->query("qi",1) <= 0 || me->query("jing",1) <= 0 || me->query("jingli",1) <= 0) return 1;

	// if qi low, escape
	if ( me->query("eff_qi",1) < 1300 || me->query("neili",1) < 500) {
		me->command("halt");
		me->random_move();
		return 1;
	}

	me->command("say ԭ�����Ǹ���թ֮ͽ�����������Ϊ�������");
	me->command("follow " + ob1->query("id") );
	ob1->set_temp("kill_ning",1);
	me->set_leader(ob1);
	me->kill_ob(ob1);

	if ( me->query("eff_qi") < 1500 ) {
		me->set("eff_qi",1500);
	}

	me->set_temp("apply/armor", 120);
	me->set_temp("apply/damage", 50);
	me->set_temp("apply/dodge", 120);
	me->set_temp("apply/attack", 50);
	//me->setup();
	me->auto_perform();
	return 1;
}

int auto_perform()
{
	object me=this_object();
	object weapon=me->query_temp("weapon");
	object opp=me->select_opponent();

	if( me->query("qi",1) < 0 || me->query("jing",1) < 0 || me->query("jingli",1) < 0) return;

	if ( !me->is_fighting() ) {
					 if ( me->query("eff_qi") < me->query("max_qi") )
								me->exert_function("heal");
					 me->set("jiali", 100);

					 return 1;
		  }

		  if ( objectp(weapon) ) {
					 if ( weapon->query("skill_type") == "sword" )
								return perform_action("sword.jianzhang");
		  }
		  else if ( !me->query_temp("leidong") ) {
			return perform_action("cuff.leidong");
	}
	else if ( !me->query_temp("wuji") && opp->query_condition("hyz_damage") <= 5 ) {
			return  perform_action("strike.wuji");
	}
}
