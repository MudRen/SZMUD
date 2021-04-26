// Code of ShenZhou
// feng.c ������
// qfy July 16, 1996.

#ifndef NPCDATA
#define NPCDATA "/data/npc/"
#endif
#define FENG NPCDATA + "feng"

inherit NPC;
inherit F_MASTER;
inherit F_CLEAN_UP;
inherit F_UNIQUE;
inherit F_SAVE;

int auto_perform();

string query_save_file()
{
	return FENG;
}

void create() 
{
	seteuid(getuid());

	set_name("������", ({ "feng qingyang", "feng", "qingyang" }));
	set("long", 
"����ǵ������𽭺��Ļ�ɽ���޷�������������ۣ��������������ֽ��\n");
	set("gender", "����");
	set("age", 70);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 4500);
	set("max_jing", 4000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 100);
	set("combat_exp", 3600000);
	set("score", 5000);

	set_skill("force", 360);
	set_skill("dodge", 360);
	set_skill("parry", 360);
	set_skill("sword", 450);
	set_skill("strike", 360);
	set_skill("dugu-jiujian", 450);
	set_skill("hunyuan-zhang",360);
	set_skill("zixia-gong", 360);
	set_skill("huashan-shenfa", 360);
	set_skill("literate", 101);
	set_skill("cuff", 360);
	set_skill("pishi-poyu", 360);
	set_skill("ziyin-yin", 360);
	set_skill("zhengqi-jue", 360);

	map_skill("cuff", "pishi-poyu");
	map_skill("force", "zixia-gong");
	map_skill("parry", "dugu-jiujian");
	map_skill("sword", "dugu-jiujian");
	map_skill("strike","hunyuan-zhang");
	map_skill("dodge","dugu-jiujian");

	prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "pishi-poyu");

	create_family("��ɽ��", 12, "���ڳ���");

	restore_object("/data/npc/feng");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}

void init()
{
	object ob, me = this_object();

	::init();

	if( interactive(ob = this_player()) && ob->query("family/master_id") == "feng qingyang" ) {
		remove_call_out("check_student");
		call_out("check_student", 1, ob );
	}
	else if( ob->query("family/master_id") != "feng qingyyang" && sizeof(ob->query_temp("win")) != 6 
	&& file_name(environment(me)) == "/d/huashan/xiaofang" && !wizardp(ob) ) {
   	if(!userp(ob) ) return;
		remove_call_out("revenge");
		call_out("revenge", 1, ob );
	}
	else if( ob->query("family/master_id") != "feng qingyang" 
	&& (int)ob->query_skill("dugu-jiujian", 1) > 1 ) {
		remove_call_out("check_betrayal");
		call_out("check_betrayal", 1, ob);
	}
	else if( !ob->is_fighting() && !ob->query("feng") 
	&& file_name(environment(me)) == "/d/huashan/xiaofang" ) {
		remove_call_out("improve_sword");
		call_out("improve_sword", 1, ob );
	}

	add_action("do_steal", "steal");
        add_action("do_throw", "throw");
}

int revenge(object ob)
{
	object me=this_object();

	command( "say �üһﾹ��ı���ҹ����ɣ��������ɣ�" );
	me->kill_ob(ob);

	remove_call_out("auto_perform");
	call_out("auto_perform", 1);
	return 1;
}

int check_betrayal(object ob)
{
	object me=this_object();
	mapping std_status;
	string *stdname;
	int i;

	restore_object("/data/npc/feng");

	if ( mapp(std_status = me->query("students")) ) {
		std_status = me->query("students");
		stdname = keys(std_status);
		for(i=0; i<sizeof(std_status); i++) {
			if ( ob->query("family/family_name") != "��ɽ��" && ob->query("id")==stdname[i]
			 && ob->query("death_count")==me->query("students/"+ob->query("id")) ) {
				command( "say ��ʦ����ļһ���㻹�����������ң�" );
				me->delete( "students/"+ob->query("id") );
				me->set( "no_accept/"+ob->query("id"), 1);
				save();
				restore_object("/data/npc/feng");       
			}
		}
	}

	return 1;
}       

int check_student(object ob)
{
	int death_time;
	string std_id;
	object me = this_object();

	restore_object("/data/npc/feng");

	death_time = ob->query("death_count");
	std_id = ob->query("id");

	if ( death_time != me->query("students/"+std_id) ){
		message_vision( "�����￴�˿�$N�������ֳ����ݵ���ɫ��\n", ob );
		me->set("students/"+(string)ob->query("id"), ob->query("death_count"));
		save();
		restore_object("/data/npc/feng");
	}
	if ( ob->query("shen") < 0 ) {
		command( "say �ø���������������Ϊ��������" );
		command( "expell "+std_id );
	}

	if ( (int)ob->query_skill("zixia-gong", 1) < 100 ) {
		command( "say ��˵�����ؽ����������㾹Ȼ���������Ӳ��ɽ�Ҳ��" );
		command( "expell "+std_id );
	}


	return 1;
}

int improve_sword(object ob)
{
	int my_sword, add_level;

	my_sword = ob->query_skill("sword", 1);
	command( "say "+RANK_D->query_respect(ob)+"��Ȼһ�����������ҿ�ν��Ե������ָ����һЩ�����ɡ�");
	message_vision( "�����￪ʼΪ$N��˵���������ľ��塣\n", ob );

	if ( my_sword < 119 ) {
		add_level = my_sword + 20 + random(ob->query_int());
	}else if ( my_sword < 149 ) {
		add_level = my_sword + 10 + random(ob->query_int());
	}else if ( my_sword < 199 ) {
		add_level = my_sword + 5 + random(ob->query_int());
	}else {
		message_vision( "���������$N���ȵء���������һ����\n", ob );
		command( "say "+RANK_D->query_respect(ob)+"�Ľ�����Ȼ�������ң����಻ʤ�����\n");
		tell_object( ob, "��Ļ��������ѳ�¯����֮������������ûʲô��ָ��������ˣ�\n");
		ob->set("feng", 1);

		return 1;
	}
	if (add_level >= 1) tell_object( ob, "��Ļ�������������"+chinese_number(add_level)+"����\n");
	ob->set_skill("sword", add_level);
	ob->set("feng", 1);
	ob->add("combat_exp", 15000);

	return 1;
}

void attempt_apprentice(object ob)
{
	object ob1, room, me = this_object();
	mapping no_status, student_stat;
	string mengzhu, *noname;
	int i;

	restore_object("/data/clone/feng");

	if ( mapp(no_status = me->query("no_accept")) ) {
		no_status = me->query("no_accept");
		noname = keys(no_status);
		for (i=0; i<sizeof(no_status); i++) {
			if ( ob->query("id") == noname[i] ) {
				command("say ������Զ���������������ʦ����ļһ�ģ�");
				return;
			}
		}
	}
	
	if(!( room = find_object("/d/taishan/fengchan")) )
		room = load_object("/d/taishan/fengchan");

	if( objectp(ob1 = present("mengzhu", room)) )
		mengzhu = ob1->query("winner");

        if ( ob->query("family/family_name") && ob->query("family/family_name") != "��ɽ��" ) {
                command("say "+RANK_D->query_respect(ob)+"������"+ob->query("family/family_name")+"�ĵ��ӣ���Ϊ��ҪͶ�뻪ɽ���£�");
                command("say ��˲���֮ͽ��ˡ�һ�ɽ�ɲ���������");
		return;
	}
	
	if( this_player()->query("id") == mengzhu ) {
		command("say "+RANK_D->query_respect(ob)+"��Ϊ����֮���Ϸ����򲻸����㡣");
		return;
	} 

	if ( (string)ob->query("id") == me->query("pending") ) {
		command("say �Ϸ���������Ϊͽ���㻹���߰ɡ�");
		return;
	}

/*        if ( mapp(student_stat = me->query("students")) && sizeof(student_stat) >= 5 ) {
                command("say �Ϸ�������ͽ�������յ����ˡ�");
		return;
	}*/

	if ( (string)ob->query("gender") == "����" ) {
		command("say " + RANK_D->query_respect(ob) + "�Ƕ������ˣ�ˡ�Ҳ������㡣");
		return;
	}

	if (ob->query("class")=="bonze") {
		command ("say �Ϸ��ճ�����Ϊͽ������ذɡ�");
		return;
	}
	
	if ( (int)ob->query("rank")  > 1 ) {
		command("say " + RANK_D->query_respect(ob) + "����ؤ�ﲻ�ٺô����α��Ѱ��԰���Ϊʦ�أ�");
		return;
	}       

	if ( (int)ob->query_int() < 35 ) {
		command("say " + RANK_D->query_respect(ob) + "���ʲ�����ѧ���˶��¾Ž���");
		return;
	}

	if ( (int)ob->query("shen") < 100000 ) {
		command("say �һ�ɽ�����������������ɣ��Ե���Ҫ���ϡ�");
		command("say "+RANK_D->query_respect(ob)+"���в�����ˡ�Ҳ������㡣");
		return;
	}

	if ( (int)ob->query_skill("sword", 1) < 99 ) {
		command("say "+RANK_D->query_respect(ob)+"�Ļ���������Ϊ������ˡ�Ҳ������㡣");
		return;
	}

	if ( (int)ob->query_skill("strike", 1) < 49 ) {
		command("say "+RANK_D->query_respect(ob)+"�Ļ����Ʒ���Ϊ������ˡ�Ҳ������㡣");
		return;
	}

	if ( (int)ob->query_skill("dodge", 1) < 74 ) {
		command("say "+RANK_D->query_respect(ob)+"�Ļ����Ṧ��Ϊ������ˡ�Ҳ������㡣");
		return;
	}

	if ( (int)ob->query_skill("parry", 1) < 74 ) {
		command("say "+RANK_D->query_respect(ob)+"�Ļ����м���Ϊ������ˡ�Ҳ������㡣");
		return;
	}

	if ( (int)ob->query_skill("force", 1) < 99 ) {
		command("say "+RANK_D->query_respect(ob)+"�Ļ����ڹ���Ϊ������ˡ�Ҳ������㡣");
		return;
	}

	if ( (int)ob->query_skill("zixia-gong", 1) < 99 ) {
		command("say "+RANK_D->query_respect(ob)+"����ϼ����Ϊ�������ҵ�Ҫ��ˡ�Ҳ������㡣");
		return;
	}

/*	if ( (int)ob->query_skill("taiji-jian") > 0 || (int)ob->query_skill("damo-jian") > 0
	|| (int)ob->query_skill("fumo-jian") > 0 || (int)ob->query_skill("huashan-jianfa") > 0 
	|| (int)ob->query_skill("emei-jianfa") > 0 || (int)ob->query_skill("yuxiao-jian") > 0
	|| (int)ob->query_skill("mingwang-jian") > 0 || (int)ob->query_skill("duanjia-jian") > 0
	|| (int)ob->query_skill("huifeng-jian") > 0 || (int)ob->query_skill("jinshe-jianfa") > 0
	|| (int)ob->query_skill("tangshi-jian") > 0 || (int)ob->query_skill("wugou-jianfa") > 0 ) {
		command("say ���¾Ž���Ҫּ������������ð�ԭ����ѧ�Ľ�����ȫ��ȴ������ͻ�ƽ������档");
		command("say "+RANK_D->query_respect(ob)+"���д˾��ģ�");
		return;
	}*/

	command("say �ðɣ��Ҿ��������ˡ�");
	command("chat ���������¾Ž��������д����ˣ�"+ob->name()+"����Ϊ�ҵ��ӣ����λͬ�������ա�");
	command("recruit " + ob->query("id"));
	me->set("students/"+(string)ob->query("id"), ob->query("death_count"));

	if ( me->query("pending") ) {
		me->delete("pending");
	}
	log_file("/bai_feng",sprintf("[%s] %s(%s) �� ������ Ϊʦ", ctime(time()),me->name(), me->query("id")));//add by lisser 

	save();
	restore_object("/data/clone/feng");
}

int accept_fight(object ob)
{
	object me = this_object();

	int my_max_qi = me->query("max_qi");

	if ( me->query("qi")*100 / my_max_qi <= 80 ) {
		return 0;
	}

	remove_call_out("auto_perform");
	call_out("auto_perform", 1);

	return 1;
}

int accept_kill(object ob)
{
	object me = this_object();

	command("say �Ϸ�������Թ�޳𣬺���ʹ�¶��֣����Ϸ�Ϊ�������");
	remove_call_out("auto_perform");
	call_out("auto_perform", 1);	

	return 1;
}

int auto_perform()
{
	object me = this_object();
        object ob = me->select_opponent();
	object weapon, my_weapon;
	string action;

	if ( !me->is_fighting() ) {
                if ( me->query("eff_qi") < me->query("max_qi") )
                        exert_function("heal");
                me->set("jiali", 100);

                return 1;
        }
	else {
	 if ( objectp(my_weapon=me->query_temp("weapon")) ) {
	   if ( !weapon = ob->query_temp("weapon") ) {
	      switch (random(3)) {
	      case 0:
		action = "sword.po";
		break;
	      case 1:
		action = "sword.poqi";
		break;
	      case 2:
		action = "sword.pozhang";
		break;
	      }
	   }
	   else if ( (string)weapon->query("skill_type") == "sword" ) {
	      switch (random(3)) {
	      case 0:
		action = "sword.po";
		break;
	      case 1:
		action = "sword.poqi";
		break;
	      case 2:
		action = "sword.pojian";
		break;
	      }
	   }
	   else if ( (string)weapon->query("skill_type") == "blade" ) {
	      switch (random(3)) {
	      case 0:
		action = "sword.po";
		break;
	      case 1:
		action = "sword.poqi";
		break;
	      case 2:
		action = "sword.podao";
		break;
	      }
	   }
	   else if ( (string)weapon->query("skill_type") == "staff"
	   || (string)weapon->query("skill_type") == "stick"
	   || (string)weapon->query("skill_type") == "club" ) {
	      switch (random(3)) {
	      case 0:
		action = "sword.po";
		break;
	      case 1:
		action = "sword.poqi";
		break;
	      case 2:
		action = "sword.poqiang";
		break;
	      }    
	   }
	   else if ( (string)weapon->query("skill_type") == "hammer" ) {
	      switch (random(3)) {
	      case 0:
		action = "sword.po";
		break;
	      case 1:
		action = "sword.poqi";
		break;
	      case 2:
		action = "sword.pobian";
		break;
	      }
	   }
	   else if ( (string)weapon->query("skill_type") == "whip" ) {
	      switch (random(3)) {
	      case 0:
		action = "sword.po";
		break;
	      case 1:
		action = "sword.poqi";
		break;
	      case 2:
		action = "sword.posuon";
		break;
	      }
	   }
	   else {
		switch (random(2)) {
	      case 0:
		action = "sword.po";
		break;
	      case 1:
		action = "sword.poqi";
		break;
	      }
	   }
	
	   remove_call_out("auto_perform");
	   call_out("auto_perform", 1+random(5));
	   return perform_action(action);
	 }
	 else if ( !me->query_temp("leidong") ) {
			remove_call_out("auto_perform");
			call_out("auto_perform", 1+random(5));
			return perform_action("cuff.leidong");
	 }
	 else if ( !me->query_temp("wuji") && ob->query_condition("hyz_damage") <= 5 ) {
			remove_call_out("auto_perform");
			call_out("auto_perform", 1+random(5));
			return perform_action("strike.wuji");
	 }
	}
}

int do_steal()
{
	remove_call_out("auto_perform");
	call_out("auto_perform", 1+random(5));

	return 0;
}

int do_throw()
{
	remove_call_out("auto_perform");
	call_out("auto_perform", 1+random(5));

	return 0;
}
