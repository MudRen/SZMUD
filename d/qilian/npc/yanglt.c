// Code of ShenZhou
// yanglt.c ����ͤ

#include <ansi.h>
inherit NPC;

string ask_job();
int ask_dongfang();
private int is_suitable(object target, object me);

void create() 
{
	set_name("����ͤ", ({ "yang lianting", "yang", "lianting" }));
	set("title", "��������ܹ�");
	set("long", "����ǵ���������̵�Ȩ��λ�صĴ��ܹܣ�����ʮ������������\n");
	set("gender", "����");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", 0);
	set("str", 21);
	set("int", 20);
	set("con", 26);
	set("dex", 21);
	
	set("max_qi", 1500);
	set("max_jing", 1200);
	set("neili", 1600);
	set("max_neili", 1600);
	set("jiali", 50);
	set("combat_exp", 100000);
	set("score", 500);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("strike", 100);
	set_skill("cuff", 100);

	set("inquiry", ([
	    "����" : (: ask_job :),
	    "job" : (: ask_job :),
		"��������" : (: ask_dongfang :),
	]));

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city/obj/cloth")->wear();
}

string ask_job()
{
	object ob = this_player();
	object me = this_object();
	object *ppls, *targets, list;
	int i, j = 0, l, *k, m = 0, num, chosen;
	string names = "";

	if ( strsrch(file_name(environment(me)), "/d/qilian/zhengtang") == -1 )
		return "���ܹ�����Ҫ������Ҫ���µĻ���������������ֶ������ҡ�";

        if ( ob->query("combat_exp") < 50000 ) {
		message_vision("$N����ؿ���$nһ�ۣ�һ�����ǲ��ǵ�������\n", me, ob);
		return "��ƾ����㱾�£�Ҳ��Ϊ���̰��£��úõĶ������������ɣ�";
	}

	if ( ob->query_temp("rysj/job") ) {
		return "�㲻���Ѿ����˲������𣿶��µ��Ļ�ȥ���°ɣ�";
	}

	message_vision("$N���϶�ʱ����Ц�ݵ����ѵ�"+ob->name()
	+RANK_D->query_respect(ob)+"Ը��Ϊ���̳�����ʵ����̫���ˣ�\n", me);
	message_vision("$N�ǳ�ʹ���˵����ֻҪ��ú�Ϊ���̰��£����ܹ�һ���������ͣ�\n", me);
	message_vision("$Nת������������̨����һ�����ӣ�˵�����ñ��ܹܲ��Ŀǰ���̵����У�����\n", me);
	
	ppls = users();
	targets = allocate(sizeof(ppls));
	k = allocate(5);

	for ( i=0; i<sizeof(ppls); i++ ) {
		if ( is_suitable(ppls[i], ob) ) {
			targets[j] = ppls[i];
			j++;
		}
	}
	
	if ( !j ) {
		message_vision("����һ�����$N��ü˵��������Ŀǰû���ʺ��������\n", me);
		return "�㻹���´������ɡ�\n";
	}
	else {
		list = new("/d/qilian/npc/obj/list");
		list->move(me);

		ob->delete_temp("rysj");

		if ( j > 5 ) {
			num = 5;

			for ( i=0; i<num; i++ ) {
				l = random(j);
				chosen = 0;

				for ( m=0; m<i; m++ ) {
					if ( k[m] == l ) {
						chosen = 1;
						i = i - 1;
					}
				}
	
				if ( !chosen ) {
					k[m] = l;
					ob->set_temp("rysj/target"+m, targets[l]->query("id"));
					list->set("name"+m, targets[l]->short(1));
				}
			}
		}
		else {
			num = j;

			for ( i=0; i<j; i++ ) {
				ob->set_temp("rysj/target"+i, targets[i]->query("id"));
				list->set("name"+i, targets[i]->short(1));
			}
		}

		ob->set_temp("rysj/job", 1);

		for ( i = 0; i<num; i++ ) {
			names += list->query("name"+i)+"\n";
		}

		list->set("long", names);
	}

	command("give "+ob->query("id")+" rysj list");
	return "������Ŀ������������������κ�һ�����ܽ������ܹܱ�����������ˣ�\n";
}

private int is_suitable(object target, object me)
{
	int value1, value2;

	value1 = target->query("combat_exp") * 10;
	value2 = me->query("combat_exp");

	if ( value2 < 50000 && value1 > value2*10 && !wizardp(target) 
	&& target->query("id") != me->query("rysj/last") ) {
		// let dummies have some fun catching people
		return 1;
	}

	if ( value1 < value2*8 || value1 > value2*12 || target->query_temp("rysj/job")
        || target->is_ghost() || target == me || wizardp(target) 
	|| target->query("id") == me->query("rysj/last") ) {
                return 0;
        }

        return 1;
}

int accept_object(object me, object obj)
{
	object ob = this_player();
	int i, success = 0;

	if ( strsrch(file_name(environment(me)), "/d/qilian/zhengtang") == -1 )
		return 0;

        if ( ob->query_temp("rysj/job") && userp(obj) ) {
		for ( i=0; i<5; i++ ) {
			if ( ob->query_temp("rysj/target"+i) == obj->query("id") ) success++;
		}
	
		if ( success ) {
			remove_call_out("reward_dest");
	   		call_out("reward_dest", 1, obj, ob);
		}
		else {
			remove_call_out("scold_failure");
			call_out("scold_failure", 1, obj, ob);
		}

	   	return 1;
	}
	else if ( userp(obj) ) {
		command( "?" );
		command( "say ������ʲô��˼���������ϱ�����ʲô��" );
	}
	else {
		command( "?" );
		command( "say ������ⶫ����ʲ�᣿" );
	}

	return 0;
}

int scold_failure(object obj, object ob)
{
	object me=this_object();

	message_vision("$N��$n�ƿڴ���쵰������ô���׽���˻����������㵱���ܹܿ���ô��\n", me, ob);
	message_vision("$N����ָ��$n�������е������ˣ���������ҷ����ȥ��\n", me, obj);

	message_vision("�ſڽ����������������������$Nһ�������Ͻ�$n���˳�ȥ��\n", me, obj);
	obj->move("/d/qilian/qitian");

	if ( ob->query_temp("rysj/fail") ) {
		message_vision("$N��������ͨ�죬��������������Ͱ��һ���С��Ҳ�첻�ã��úõ���������Űɣ�\n", me);
		message_vision("$N������ǽ��ĳ��һ����$nվ��֮����ʱ�ѿ�һ����\n", me, ob);
		message_vision("$Nһ���������������ɼ��������������ȥ��\n", ob);
		ob->move("/d/qilian/dilao");
		ob->delete_temp("rysj");
	}
	else {
		message_vision("$Nת������ָ��$n�ı���˵���������̸����ܹܽ������ϵ�Ҫ��׽������ȻҪ��ÿ���\n", me, ob);
		ob->set_temp("rysj/fail", 1);
	}

	return 1;
}
	
int reward_dest(object obj, object ob)
{
	object me=this_object();
  	int exp, amount;

	if ( ( exp = obj->query("combat_exp") ) >= 320000 ) amount = exp/1000;
	

	if ( amount < 1000 ) {
		amount = 1000;
	}
	else if ( amount > 3000 ) {
		amount = 3000;
	}

	ob->delete_temp("rysj");
	ob->add("rysj/success", 1);
	ob->set("rysj/last", obj->query("id"));

	if ( ob->query("combat_exp") < 50000 ) {
		ob->add("combat_exp", amount/100);
	}
	else {
		ob->add("combat_exp", amount);
	}

	if ( obj->query_temp("sangong_once") ) {
		obj->add("mz_neili", -(amount/10));
	}
	
	obj->add("max_neili", -(amount/10));
	obj->add("eff_jingli", -(amount/10));
        if (obj->query("eff_jingli") < 0) obj->set("eff_jingli", 0);
        if (obj->query("max_neili") <= 0) obj->set("max_neili", 1);

	log_file("RYSJ_JOB", sprintf("%s caught %s and gained %d exp.\n", geteuid(ob), geteuid(obj), amount));

	command("thumb "+ob->query("id"));
	command("say "+ob->name()+RANK_D->query_respect(ob)+"Ϊ���̲����Ϳ࣬���º����ͣ����ܹ��Ե��������ͣ�");
	tell_object(ob, "��ľ��������ˣ�\n");
	//add by wzfeng .about pixie quest
	ob->add("rysj_reward",1);

	message_vision("$N����ָ��$n�������е������ˣ�������ط��ؽ�������ȥ��\n", me, obj);
	message_vision("�ſڽ����������������������$Nһ�������Ͻ�$n���˳�ȥ��\n", me, obj);
        obj->move("/d/qilian/dilao");

	message_vision("$N�ع�ͷ��Ц����ض�$n˵�����������ˣ�������ȥ��Ϣ�ɡ�\n", me, ob);

	return 1;
}

int accept_fight(object victim)
{
	object me=this_object();

	if ( me->query("combat_exp") > victim->query("combat_exp") )
		return 1;
	else
		return 0;
}

int accept_kill(object victim)
{
	object me=this_object();
	int i;

        if ( strsrch(file_name(environment(me)), "/d/qilian/zhengtang") == 0 ) {
		command("hehe");
		message_vision("$N��м��˵���������������������Ұ����ֱ��������\n", me);
		message_vision("$N������ǽ��ĳ��һ����$nվ��֮����ʱ�ѿ�һ����\n", me, victim);
		message_vision("$Nһ���������������ɼ��������������ȥ��\n", victim);
		victim->move("/d/qilian/dilao");
		message("vision", victim->name() + "ͻȻ��ǽ�Ͽ����Ķ��ڹ��˳�����\n", environment(victim), ({victim}) );
	}

	return 1;
}


//add by wzfeng
int ask_dongfang()
{
	object obj;
	object me = this_player();
	object ob = this_object();
	
	if(me->query("rysj_reward")<3)
	{
		message_vision("$N��м�ض�$p˵������Ϊ���̰���̫�٣������ڱ��̣������������й���Ӽ����С����\n", ob,me);
		return 1;
	}
	if(obj = find_object("/d/qilian/droom"))
	{
		message_vision("$N��$p˵����������������æ���������е�ʱ���ٴ���ȥ�ɡ�\n", ob,me);
		return 1;
	}
	else
        {
        message_vision("$N��$p˵����������Ϊ���̾��İ��µķ��ϣ�������������Ƕ���������\n", ob,me);
        message_vision("$N��ǽ�����ش�һ�������ñ��Ͽ���һ�����š�\n", ob,me);
        tell_object(me,"����������˽�ȥ��\n");
        me->add("rysj_reward",-3);
        me->move("/d/qilian/droom");
		me->set("can_dfbb",1);
        }
        
        return 1;
}
