// Code of ShenZhou
// jiang ����ʤ

#include <ansi.h>

inherit NPC;
string check_qualification();

void create()
{
	seteuid(getuid());

	set_name("����ʤ", ({ "jiang baisheng", "jiang", "baisheng" }) );
	set("gender", "����" );
	set("age", 30);
	set("long", "������������κ��˫֮����֮�ױ��ӳ���\n");
	set("attitude", "heroism");
	set("generation",0);
	set("winner","none");

	set("str", 25);
	set("con", 25);
	set("int", 25);
	set("dex", 25);

	set("max_qi", 400);
	set("eff_qi", 400);
	set("qi", 400);
	set("max_jing", 200);
	set("jing", 200);
	set("neili", 300);
	set("max_neili", 300);
	set("jiali", 30);
	set("shen_type", 0);

	set("no_clean_up",1);
	set("combat_exp", 50000);

	set_skill("force", 80); 
	set_skill("unarmed", 100);
	set_skill("dodge", 80);
	set_skill("parry", 80);

	set("fight_times", 0);	

	set("inquiry", ([
		"��ɽ" : (: check_qualification :),
	]));

	setup();
        
}

int accept_fight(object ob)
{
	int times;
	object me  = this_object();
		
	if ( me->is_fighting()) return 0;

	if ( !present(ob, environment()) ) return 0;

	times = me->query("fight_times");
	if ( times >= 10 )
		return notify_fail("����ʤ�Ѿ�ȫ��������ſ�ڵ��ϴ�ڵش��Ŵ�����\n");	

	me->set("eff_qi", me->query("max_qi"));
	me->set("qi",     me->query("max_qi"));
	me->set("jing",   me->query("max_jing"));
	me->set("neili",  me->query("max_neili")*(10-times)/10);
	me->add("fight_times", 1);

	remove_call_out("checking");
	call_out("checking", 1, me, ob);
	
	return 1;
}

int checking(object me, object ob)
{
	object obj;
	int my_max_qi, his_max_qi;

	if ( !present(ob, environment()) ) return 1; 

	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if( me->is_fighting() ) 
	{
		if (( (int)me->query("qi")*100 / my_max_qi) <= 80 ) 
		{
			say(GRN "\n����ʤ˵���� κ���������£����ò����� �����˼������Ųߣ����޲��ˣ����޲�ʤ��\n" NOR);
			say(GRN "\n����ʤ˵���� κ����һ�仰�����°��´���������ֱǰ�� ����ѩ�����ﴳ����ɽ�𺣾͸�ȥ��\n" NOR);
			message_vision(HIY "\n����ʤ˵�꣬ȫ��֪������ð������һ����������������������ȭ��Ҳ���ͺö౶��\n" NOR, ob);

			me->set("eff_qi", me->query("max_qi"));
			me->set("qi",     me->query("max_qi"));
			me->set("jing",   me->query("max_jing"));
			me->set("jingli", me->query("max_jingli"));
//			me->set("neili",  me->query("max_neili"));
		}
		else if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
		{
			say(GRN "\n����ʤ˵���� ������С�Ӹ��һ�����һ����أ���ȥ����ʮ�������ɣ�\n");
			return 1;
		}

		if ( present(ob, environment()) ) call_out("checking", 1, me, ob);
	}

	return 1;  
}

string check_qualification()
{
	object ob = this_player();
	mapping skill_status;
	string *sname;
        int i, qualified_skills_no = 0;

	if ( mapp(skill_status = ob->query_skills()) ) {
                skill_status = ob->query_skills();
		sname = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			if ( ob->query_skill(sname[i],1) >= 90 ) qualified_skills_no++;
		}
	}

	if ( qualified_skills_no > 5 ) {
		ob->set_temp("qualified", 1);
		command( "bow" );
		return "��λ"+RANK_D->query_respect(ob)+"���Ա㡣";
	}
	else {
		message_vision("����ʤ����ؿ���$Nһ�ۡ�\n", ob);
		return "��������λʹ��û������㡣";
	}
}

int accept_object(object who, object ob)
{
        object wage;

        if (who->query_temp("biao/jiang") && ob->name()=="����") {
                who->delete_temp("biao/jiang");
		who->delete_temp("apply/short");
                command( "say ������λ"+RANK_D->query_respect(who)+"�ˣ���������ˡ�");
                wage = new("/clone/money/silver");
                wage->set_amount(5);
                wage->move(who);
                message_vision("����ʤ��$N����������Ϊ���ڵĳ��͡�\n", who);
                remove_call_out("destroy_it");
                call_out("destroy_it", 1, ob);
                return 1;
        }

	return 0;
}

void destroy_it(object obj)
{
        destruct(obj);
}
