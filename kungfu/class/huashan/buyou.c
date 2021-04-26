// Code of ShenZhou
// buyou.c �ɲ���
// qfy Nov 14, 1996

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_SSERVER;
string ask_me();
private int check_env(object me);

void create()
{
	set_name("�ɲ���", ({ "cheng buyou", "cheng", "buyou" }));
	set("long", 
"�ɲ����ǻ�ɽ���ڵ��ӡ�����֮������һ��Ϳ�أ�����ⲻƽ��\n"
"�ӿ�������ѩ���衣�������˵ã��ѻ����洫��\n");
	set("gender", "����");
	set("age", 41);
	set("attitude", "peaceful");
	set("shen_type", 0);
	set("str", 25);
	set("int", 22);
	set("con", 25);
	set("dex", 25);
	set("shen", 0);
	
	set("max_qi", 1000);
	set("max_jing", 800);
	set("neili", 1100);
	set("max_neili", 1100);
	set("jiali", 50);
	set("combat_exp", 500000);
	set("score", 5000);
	set("huashan/feilong", 1);

	set_skill("force", 90);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("sword", 120);
	set_skill("strike", 95);
	set_skill("cuff", 95);
	set_skill("huashan-shenfa", 100);
	set_skill("zixia-gong", 90);
	set_skill("huashan-jianfa", 120);
	set_skill("hunyuan-zhang",95);
	set_skill("pishi-poyu", 95);
	set_skill("ziyin-yin", 80);
	set_skill("zhengqi-jue", 80);

	map_skill("cuff", "pishi-poyu");
	map_skill("force", "zixia-gong");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("strike","hunyuan-zhang");
	map_skill("dodge","huashan-shenfa");

	prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "pishi-poyu");

	create_family("��ɽ��", 13, "���ڵ���");
	
	set("inquiry", ([
	    "����" : "���ڲ��ǻ�ɽ����ͳ���Խ�Ϊ�ڣ�����Ϊ����������ѧ�ľ�Ҫ��\n",
	    "����" : "�ߣ������书ӹ�ײ����������ὣ�����߰��㡣\n",
	    "����Ⱥ" : "������α���ӣ��ɶ�\n",
	    "��ɽ����" : "�Ǳ��Ǳ��ɾ�ѧ������һ��һ�Ľ����������ǡ����������һ�У��ɽ�ɱ�У������ܵ���\n",
	    "��ϼ��" : "���Ǳ����ڹ��ķ���\n",
	    "˼����" : "���Ǳ��ɵ�������˼��֮����\n",
	    "������" : "�������Ѷ��겻����ʦ�壬������������䡣\n",
	    "�ɽ�" : "������������Ǳ��ɾ��У��ɽ��������������У�\n",
	    "�ɽ�ɱ��" : "������������Ǳ��ɾ��У��ɽ��������������У�\n",
	    "�������" : (: ask_me :),
	]));

	setup();
	carry_object("/d/city/obj/changjian")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}

void init()
{
	object ob, me = this_object();

	if ( interactive(ob=this_player()) ) {
	   if ( !me->is_fighting() ) {
		remove_call_out("rand_move");
		call_out("rand_move", 3+random(4), me);
	   }
	   else if ( ob->query("id") == me->query_temp("target") ) {
		message_vision( "$n����$N��ȣ�Թ��·խ����������ͷ�ˣ��������ɣ�\n", ob, me );
		me->kill_ob(ob);

		remove_call_out("rand_move");
		remove_call_out("checking");
		call_out("checking", 1, me, ob);
	   }
	}
		
	add_action("do_kill", "kill");
	add_action("do_kill", "sha");
}

int rand_move(object me)
{
	object here = environment(me);

	if ( file_name(here) == "/d/village/sexit" ) {
		command( "go north" );
	}
	else if ( file_name(here) == "/d/huashan/qingke" ) {
		command( "go northdown" );
	}
	else if ( file_name(here) == "/d/huashan/hsstreet2" 
	|| file_name(here) == "/d/huashan/hsstreet3" ) {
		if (random(2) == 1) command( "go east" );
		else command("go west");
	}
	else random_move();

	check_env(me);
	remove_call_out("rand_move");
	call_out("rand_move", 3+random(4), me);

	return 1;
}

private int check_env(object me)
{
	object *inv;
	object victim, target;
	int i;

	inv = all_inventory(environment(me));

	for( i=0; i<sizeof(inv); i++ ) {
	     if ((string)inv[i]->query("race") == "����" && inv[i] != me ) {
		if ( (!inv[i]->query("family") || inv[i]->query("family/family_name")!="��ɽ��" )
		&& inv[i]->is_killing() ) {
			victim = offensive_target(inv[i]);

		    	if ( objectp(victim) && victim != me && victim->query("family/family_name")=="��ɽ��" ) {
				remove_call_out("rand_move");
				target = inv[i];
				remove_call_out("rescue_huashan");
				call_out("rescue_huashan", 1, target, victim);
				
				return;
			}
		}
	     }
  	}

	return 1;
} 

int rescue_huashan(object target, object victim)
{
	object me = this_object();

	me->set_temp("target", target->query("id"));
	me->set_leader(target);
	
	message_vision("$N��$n���������д��������ڻ�ɽ�ĵط���ɱ��ɽ���ӡ��������������\n", me, target);
	command("say "+victim->name()+"����ߣ�����һ�����ң�");
	message_vision("$N˵�ų���һ��������ǰ��$n�Ĺ����������˹�ȥ��\n\n", me, target);
	target->remove_enemy(victim);
	victim->remove_enemy(target);
	me->kill_ob(target);
	target->kill_ob(me);
	remove_call_out("checking");
	call_out("checking", 1, me, target);

	return 1;
}

int do_kill()
{
	object me = this_object();

	remove_call_out("env_check");
	call_out("env_check", 1, me);

	return 0;
}

int env_check(object me)
{
	check_env(me);

	return 1;
}

int accept_fight(object ob)
{
	object me = this_object();
	int my_max_qi = me->query("max_qi");

	if ( me->query("qi")*100 / my_max_qi <= 80 ) {
		remove_call_out("checking");
		call_out("checking", 1, me, ob);
		return 0;
	}       

	remove_call_out("rand_move");
	remove_call_out("checking");
	call_out("checking", 1, me, ob);

	return 1;
}

int accept_kill(object ob)
{
	object me = this_object();

	command("say �üһ���㳢����ɽ���������������������Ŀ��");
	
	remove_call_out("rand_move");
	remove_call_out("checking");
	call_out("checking", 1, me, ob);

	return 1;
}

int checking(object me, object ob)
{
	int b, my_max_qi = me->query("max_qi");
	object weapon, env = environment(me);

	if ( me->is_fighting() ) {
/*	   if ( random(10) == 8 && me->query("neili") > 300 
	   && me->query_temp("weapon")->query("skill_type") == "sword") {
		message_vision(HIR"\n$N���һ�������ҵ����������\n"NOR, me);
		command("perform feilong");
	   }
*/
	   if ( !me->query_temp("weapon") && (present("changjian", env) 
	   || present("duanjian", env) || present("zhujian", env)) ) {
		command("get jian");
		command("wield jian");
	   }

	   if ( (me->query("qi")*100 / my_max_qi) <= 80 ) {
		command("exert recover");
	   }

	   call_out("checking", 1, me, ob);
	   return 1;
	}

	if ( me->query_temp("target") ) {
	   if ( !ob=find_player(me->query_temp("target")) ) {
		message_vision("$N��˵��������һ��ܵÿ죡\n", me);

		remove_call_out("rand_move");
		call_out("rand_move", 1, me);
	   }
	   else if ( ob->is_ghost() ) {
	   	if ( !me->query_temp("weapon") ) {
			command("get jian from corpse");
			command("wield jian");  
	   	}
	   	message_vision("$N��ʬ����·��Ͻ����ϵ�Ѫ��Ĩ�ɾ�������ء��ٺٺ١���Ц�˼�����\n", me);
	   
	   	remove_call_out("rand_move");
	   	call_out("rand_move", 1, me);
	   }
	   else if ( present(ob, env) && !me->is_fighting() ) {
	   	message_vision( "$n����$N��ȣ������ӣ������������ɣ�\n", ob, me );
		me->kill_ob(ob);

	   	remove_call_out("checking");
	   	call_out("checking", 1, me, ob);
	   }
	   else if ( !me->is_fighting() ) {
		message_vision("$N��˵��������һ��ܵÿ죡\n", me);

		remove_call_out("rand_move");
		call_out("rand_move", 1, me);
	   }
	
	   return 1;
	}

	if ( !me->is_fighting() ) {
	   message_vision("$N����˵������������Ҫ������ˡ�����㣡\n", me);

	   remove_call_out("rand_move");
	   call_out("rand_move", 1, me);
	   return 1;
	}
}

string ask_me()
{
	object ob = this_player(), me = this_object();
	mapping obfam;
	obfam = (mapping)ob->query("family");

	if ( !obfam || obfam["family_name"] != "��ɽ��" ) {
	   if ( ob->query_temp("feilong") < 3 ) {
		command( "sneer" );
		ob->add_temp("feilong", 1);
		return "���Ǻ���ԨԴ����������ʲô�����Ǳ�̫����ĺá�\n";
	   }
	   else {
		message_vision("$N��ɫ΢�䣬Ŀ������һ��������һ����Ц��\n", me);
		ob->delete_temp("feilong");
		me->kill_ob(ob);
		remove_call_out("checking");
		call_out("checking", 1, me, ob);
		return "�������Ĵ���̽����ɽ�����İ��ܣ������ϲ⣡�Ƿ���Ա��ɲ������㼴Ȼ�Ի�ɽ�������㿾���ֻ���û�ɽ����������·�ˡ�\n";
	   }
	}
	
	command( "look "+ob->query("id") );

	if ( ob->query_skill("huashan-jianfa", 1) < 100 )
		return "��Ļ�ɽ������Ϊ������ѧ���ˡ������������";

	if ( ob->query_skill("zixia-gong", 1) < 70 )
		return "�����Խ�Ϊ�ڣ�����Ϊ���������������ã������ϼ���ɵ�����һ���๦��";

	if ( ob->query_skill("zixia-gong", 1) > ob->query_skill("huashan-jianfa", 1) ) {
		command( "sneer" );
		return "�������ڵ��ˣ�ȴ��������̣�������ε�������";
	}

	if ( ob->query("huashan/feilong") )
		return "�ף��ҷ�ʦ�粻�Ǵ����㡸����������𣿶��¹���ú���ϰ������˻�ɽ���ڵ�������";

	return "�ã���ȥ���ҷ�ʦ��ѧ������������ɡ����������ڻ�ɽ��ɽ�";
}

void unconcious()
{
	object me = this_object();

	if ( !me->query_temp("performed") ) {
		me->set("neili", 500);
		me->set("jingli", 500);
		me->set("qi", 50);
		me->set_temp("performed", 1);
		command("perform feilong");

		return;
	}

//	message_vision("$N�û���æ���ߡ�\n", me);
//	destruct(me);
	
	remove_call_out("checking");
	remove_call_out("rand_move");

        me->disable_player(" <���Բ���>");
        me->set("jing", 0);
        me->set("qi", 0);
        COMBAT_D->announce(me, "unconcious");

        call_out("revive", random(100 - query("con")) + 30);
}

varargs void revive(int quiet)
{
        remove_call_out("revive");
        while( environment()->is_character() )
		this_object()->move(environment(environment()));
        this_object()->enable_player();
        COMBAT_D->announce(this_object(), "revive");
	remove_call_out("rand_move");
	call_out("rand_move", 1, this_object());
}

void die()
{
        object corpse, ling;
	mixed killer;

	remove_call_out("checking");
	remove_call_out("rand_move");

	if( !living(this_object()) ) revive(1);
	COMBAT_D->announce(this_object(), "dead");

	if( objectp(killer = query_temp("last_damage_from"))){
                set_temp("my_killer", killer->query("id"));
                COMBAT_D->killer_reward(killer, this_object());
	}

	if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
                corpse->move(environment());

        this_object()->remove_all_killer();
        all_inventory(environment())->remove_killer(this_object());
	
	destruct(this_object());

//	message_vision("\n$N���ˣ�\n", this_object());
//	destruct(this_object());
}
