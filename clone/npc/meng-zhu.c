// Code of ShenZhou
// meng-zhu.c ��������

#ifndef NPCDATA
#define NPCDATA "/data/npc/"
#endif
#define MENGZHU NPCDATA + "meng-zhu"
#define SGCANGKU "/d/shenlong/cangku"

inherit NPC;
inherit F_MASTER;
inherit F_CLEAN_UP;
inherit F_UNIQUE;
inherit F_SAVE;

void auto_enable();
int do_recopy(object, object);

string query_save_file()
{
	return MENGZHU;
}

void create()
{
	seteuid(getuid());

	if (!restore()) {
	set_name("κ��˫", ({ "wulin mengzhu", "mengzhu", "zhu" }) );
	set("title", "��������" );
	set("gender", "����" );
	set("age", 40);
      set("long","�������۾����֣��������£�����պյĵ�������������\n");
	set("attitude", "heroism");
	set("generation",0);
	set("winner","none");

	set("str", 25);
	set("con", 25);
	set("int", 25);
	set("dex", 25);

	set("max_qi", 500);
	set("eff_qi", 500);
	set("qi", 500);
	set("max_jing", 300);
	set("jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 40);
	set("shen_type", 0);

	set("no_clean_up",1);
	set("combat_exp", 500000);

	set_skill("force",  100); 
	set_skill("unarmed",100);
	set_skill("sword",  100);
	set_skill("dodge",  100);
	set_skill("parry",  100);

	set("weapon", "/d/shaolin/obj/changjian");
	set("armor", "/d/city/obj/cloth");

	setup();

	carry_object("/d/shaolin/obj/changjian")->wield();
	carry_object("/d/city/obj/cloth")->wear();        
	}
	else {
		set("id", "mengzhu");
		set_name(query("name"), ({ query("id") }));
		setup();
		if( this_object()->query("weapon") ) carry_object(this_object()->query("weapon"))->wield();
		if( this_object()->query("armor") )  carry_object(this_object()->query("armor"))->wear();        
	}
}

void init()
{
	::init();
	auto_enable();
	set("no_get", 1);

	if(environment()) 
		environment()->set("winner", this_object()->query("winner"));
	// add_action("do_recopy",  "recopy");
	add_action("do_recover", "recover");
	add_action("do_kill", "kill");

}
int do_kill(string arg)
{
	object ob;
	int i;

	if (!arg || arg != "mengzhu") return 0;

	write("���ɶ�����������\n");
/*
	command("say ����ı���������������ǳ������ı��ӵ��ˣ���");
	command("say ���°�����ʿ���ڣ�");
	
	message_vision("���ܵİ�����ʿȺ���$N����������\n", this_player());

	for(i=0; i<4; i++) {
		if( objectp( ob = present("wei shi " + (i+1), environment(this_object())) ) )
				 ob->kill_ob(this_player());	
		}
		else	this_object()->kill_ob(this_player());		
*/

	return 1;
}
int accept_fight(object ob)
{
	object cangku, me  = this_object();
        mapping pkjob;
		
	if ( me->query("winner") == ob->query("id") ) 
		return notify_fail("������Լ���ʲô�ܣ���\n");

	if (wiz_level(this_player()))
		return notify_fail("��ʦ����������֮λ��\n");

	if ( me->is_fighting() ) 
		return notify_fail("�Ѿ�����������ս����������\n");

        if( stringp(me->query_temp("shan/bangzhu")) )
                return notify_fail( RANK_D->query_respect(me) + "ֻ��һС���������Ҳ̰ͼ����֮λ����\n" );

/*
        if( !(cangku = find_object(SGCANGKU)) )
	        cangku = load_object(SGCANGKU);

        if( pkjob = cangku->query("pkjob") ) 
                if( member_array(ob->query("id"), keys(pkjob)) != -1 )	    
                       return notify_fail("����������׷ɱ�㣬�㻹���������ɡ�\n"); 
*/

	me->set("eff_qi", me->query("max_qi"));
	me->set("qi",     me->query("max_qi"));
	me->set("jing",   me->query("max_jing"));
	me->set("jingli", me->query("max_jingli"));
	me->set("neili",  me->query("max_neili"));

	me->set_temp("challenger", ob);
	
	return 1;
}

int chat()
{
	object me=this_object();
	object ob=me->query_temp("challenger");
	int my_max_qi, his_max_qi;

	if ( !objectp(ob) ) return ::chat();

	if ( me->is_fighting(ob) ) return ::chat();

	me->delete_temp("challenger");
	if ( me->is_fighting() ) return ::chat();
	if ( !present(ob, environment()) ) return ::chat(); 

	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");
	if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) {
		command("say ��Ȼ��������ϲ���Ϊ��������������\n");
		command("chat �������������ǳ���������ǰ�ˣ�һ�����˻����ˣ�\n");
		command("chat ��ϲ" + ob->query("name") + "���ƾ�Ϊ��������������\n");
		remove_call_out("do_copy");
		call_out("do_copy", 1, me, ob);
		return 1;
	}

	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) {
		command("say ����" + RANK_D->query_respect(ob) + 
			"���ö����ϰ�������ڵ��������г���ͷ�� !\n");
		return 1;
	}

	return ::chat();  
}

int do_copy(object me, object ob)
{
	seteuid(getuid());

	me->add("generation", 1);	
	me->set("recovered", 0);
	me->set("name",  ob->query("name") );
	me->set("title", "��" + chinese_number(me->query("generation")) + "����������");
	me->set("short", me->query("title") + " " + me->query("name") + "(" + capitalize(ob->query("id")) + ")");
	me->delete("title");

//	if (!living(me)) me->revive();

	if (living(me)){
	ob->delete_temp("apply/short");
	ob->set_temp("apply/short", ({me->short(1)}));
	}
	
	me->set("title", "��" + chinese_number(me->query("generation")) + "����������");
	me->set("short", me->query("title") + " " + me->query("name") + "(Wuling mengzhu)");
	me->delete("title");

	remove_call_out("do_clone");
	call_out("do_clone", 0, me, ob);

	return 1;
}

int do_recopy(object me, object ob)
{
	me = this_object();
	ob = this_player();

	if ( me->query("winner") != ob->query("id") ) 
		return notify_fail("�㲻����������������\n");

	if ( me->is_killing(ob->query("id")) || me->is_fighting() )
		return notify_fail("����������æ�ţ�û�������㡣\n");

	me->set("name",  ob->query("name") );
	me->set("title", "��" + chinese_number(me->query("generation")) + "����������");
	me->set("short", me->query("title") + " " + me->query("name") + "(" + capitalize(ob->query("id")) + ")");
	me->delete("title");

	ob->delete_temp("apply/short");
	ob->set_temp("apply/short", ({me->short(1)}));

	me->set("title", "��" + chinese_number(me->query("generation")) + "����������");
	me->set("short", me->query("title") + " " + me->query("name") + "(Wuling mengzhu)");
	me->delete("title");

	remove_call_out("do_clone");
	call_out("do_clone", 0, me, ob);

	return 1;
}

int do_clone(object me, object ob)
{
	object *inv, new1;
	mapping fam, hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i, temp;

	seteuid( geteuid(me) );

	if ( mapp(fam = ob->query("family")) ) {
		me->set("family", fam);
	}

/* delete and copy skills */

	if ( mapp(skill_status = me->query_skills()) ) {
		skill_status = me->query_skills();
		sname  = keys(skill_status);

		temp = sizeof(skill_status);
		for(i=0; i<temp; i++) {
			me->delete_skill(sname[i]);
		}
	}

	if ( mapp(skill_status = ob->query_skills()) ) {
		skill_status = ob->query_skills();
		sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			me->set_skill(sname[i], skill_status[sname[i]]);
		}
	}
	
/* delete and copy skill maps */

	if ( mapp(map_status = me->query_skill_map()) ) {
		mname  = keys(map_status);

		temp = sizeof(map_status);
		for(i=0; i<temp; i++) {
			me->map_skill(mname[i]);
		}
	}

	if ( mapp(map_status = ob->query_skill_map()) ) {
		mname  = keys(map_status);

		for(i=0; i<sizeof(map_status); i++) {
			me->map_skill(mname[i], map_status[mname[i]]);
		}
	}
	
/* delete and copy skill prepares */

	if ( mapp(prepare_status = me->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		temp = sizeof(prepare_status);
		for(i=0; i<temp; i++) {
			me->prepare_skill(pname[i]);
		}
	}

	if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++) {
			me->prepare_skill(pname[i], prepare_status[pname[i]]);
		}
	}

/* unwield and remove weapon & armor */

	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++) {
		destruct(inv[i]);
	}
	set("weapon", 0);
	set("armor", 0);

/* wield and wear weapon & armor */

	inv = all_inventory(ob);
	for(i=0; i<sizeof(inv); i++) {
		if( inv[i]->is_unique()
		||  inv[i]->query("weapon_prop/damage") > 50
		||  inv[i]->query("armor_prop/armor") > 50 ) continue;

		if( inv[i]->query("weapon_prop") &&  inv[i]->query("equipped") ) {
			carry_object(base_name(inv[i]))->wield();
			me->set("weapon", base_name(inv[i]));
		}
		else if( inv[i]->query("armor_prop") &&  inv[i]->query("equipped") ) {
			carry_object(base_name(inv[i]))->wear();
			me->set("armor", base_name(inv[i]));
		}
	}

/* copy entire dbase values */

	hp_status = ob->query_entire_dbase();

		me->set("str", hp_status["str"]);
		me->set("int", hp_status["int"]);
		me->set("con", hp_status["con"]);
		me->set("dex", hp_status["dex"]);
		me->set("age", hp_status["age"]);

		me->set("max_qi",    hp_status["max_qi"]);
		me->set("eff_qi",    hp_status["eff_qi"]);
		me->set("qi",        hp_status["qi"]);
		me->set("max_jing",  hp_status["max_jing"]);
		me->set("eff_jing",  hp_status["eff_jing"]);
		me->set("jing",      hp_status["jing"]);
		me->set("max_jingli",hp_status["max_jingli"]);
		me->set("eff_jingli",hp_status["eff_jingli"]);
		me->set("jingli",    hp_status["jingli"]);
		me->set("max_neili", hp_status["max_neili"]);
		me->set("neili",     hp_status["neili"]);
		me->set("jiali",     hp_status["jiali"]);
		me->set("gender",    hp_status["gender"]);
		me->set("combat_exp",hp_status["combat_exp"]*3/2);
		me->set("death_times",hp_status["death_times"]);
		me->set("death_count",hp_status["death_count"]);

//	if( ob->query("luohan_winner") ) me->set("luohan_winner", 1);

	me->clear_condition();
	me->set("winner", ob->query("id"));
	environment()->set("winner", ob->query("id"));
	me->save();

	tell_object(ob, "״̬������ϡ�\n");


	return 1;
}

int do_recover()
{
	object me, ob;
	mapping hp_status, skill_status, skill_learned, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i;

	me = this_object();
	ob = this_player();

	if ( me->query("winner") != ob->query("id") ) 
		return notify_fail("�㲻����������������\n");;

	if( (string)me->query("family/family_name")  
	  !=(string)ob->query("family/family_name") )
		return notify_fail("���ѱ���ʦ�ţ����ܸ�ԭ�ˣ�\n");

	if( (int)me->query("family/enter_time") 
	  !=(int)ob->query("family/enter_time") )
		return notify_fail("�����Ļ�ʦ�ţ����ܸ�ԭ�ˣ�\n");
		
	if( me->query("recovered"))
		return notify_fail("���Ѿ���ԭ���ˣ�\n");

/* delete and copy skills */
	
	skill_learned = ob->query_learned();

	if ( mapp(skill_status = ob->query_skills()) ) {
		sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			ob->delete_skill(sname[i]);
		}
	}

	if ( mapp(skill_status = me->query_skills()) ) {
		sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			if( !mapp(skill_learned) )	
				skill_learned = ([sname[i] : 0]);
			else	skill_learned += ([sname[i] : 0]);

			ob->set_skill(sname[i], skill_status[sname[i]]);
		}
	}
	
/* delete and copy skill maps */

	if ( mapp(map_status = ob->query_skill_map()) ) {
		mname  = keys(map_status);

		for(i=0; i<sizeof(map_status); i++) {
			ob->map_skill(mname[i]);
		}
	}

	if ( mapp(map_status = me->query_skill_map()) ) {
		mname  = keys(map_status);

		for(i=0; i<sizeof(map_status); i++) {
			ob->map_skill(mname[i], map_status[mname[i]]);
		}
	}
	
/* delete and copy skill prepares */
//this should be disabled.
/*	if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++) {
			ob->prepare_skill(pname[i]);
		}
	}


	if ( mapp(prepare_status = me->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++) {
			ob->prepare_skill(pname[i], prepare_status[pname[i]]);
		}
	}
*/

/* copy combat exp values */
	ob->set("combat_exp", me->query("combat_exp")*2/3);

/* copy special settings */

	ob->set("death_times", me->query("death_times"));
	ob->set("death_count", me->query("death_count"));
	me->set("recovered", 1);
	write("״̬��Ԫ��ϡ�\n");

	log_file("OBJECTS", sprintf("%s(%s)��%s recovered from ������\n",
                ob->query("name"), getuid(ob), ctime(time())));

	return 1;
}

#include "/clone/npc/auto_enable.h"
