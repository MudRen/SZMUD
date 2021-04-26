// /NPC meijian.c
// By Xuanyuan 11/18/2001

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int auto_perform();

string ask_job();
string ask_escape();
int add_bandit(object ob);
int do_kill(object me, object dest);
int checking(object me);

void create()
{
	set_name("÷��", ({ "mei jian", "mei"}));
	set("long",
	    "���Ǹ���ò毺õ�Ů��, ��������,\n"+
	    "�������, �������.\n"+
	    "���ܾ������ļ�����.\n");
	set("gender", "Ů��");
	set("per", 28);
	set("age", 18);
	set("shen_type",0);
	set("attitude", "peaceful");

	set("per", 32);
	set("class", "scholar");
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 2000);
	set("max_jing", 2000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 50);

	set("combat_exp", 1000000);
	set("score", 10000);
	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("hand",180);
	set_skill("strike", 180);
	set_skill("sword",180);
	set_skill("literate",100);
	set_skill("music",180);

	set_skill("zhemei-shou",180);
	set_skill("liuyang-zhang",180);
	set_skill("tianyu-qijian",180);
	set_skill("yueying-wubu",180);
	set_skill("bahuang-gong", 180);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");

	prepare_skill("strike","liuyang-zhang");
	prepare_skill("hand","zhemei-shou");

	set("job_count",0);
        set("inquiry", ([
		"job" : (: ask_job :),
		"����" : (: ask_job :),
		"����" : (: ask_job :),
		"����" : (: ask_escape :), 
		"�ɲ���" : (: ask_escape :), //for escape when in job;
		"escape" : (: ask_escape :), 
        ]));

	create_family("���չ�",3,"����");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
	setup();
 	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/city/npc/obj/doupeng")->wear();
	add_money("silver",15);
}
void init()
{
	object me, ob;
	mapping fam;

	::init();
	ob = this_player();
	me = this_object();
	
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight")
	&& ((fam = ob->query("family")) && fam["family_name"] != "���չ�" )
	&& me->query("biao/owner"))
	{
		if( !ob->query_temp("warned") ) {
		command("say ����������˲��ý������չ��������뿪��");
			ob->set_temp("warned", 1);
	}
		else if( ob->query_temp("stay")<5 ) ob->add_temp("stay",1);
		else {
			command("say �󵨿�ͽ�������ô����չ�������\n");
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		}
	}
	remove_call_out("checking");
	call_out("checking", 1, me);
}

string ask_escape()
{
	mapping fam;
	object ob = this_player();
	object me = this_object();
	if (!(fam = ob->query("family")) || fam["family_name"] != "���չ�")
		return RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��";

	if((ob->query("job_status"))==1)
	{
		command("say �ðɣ������ڿ������ˡ�");
		add("job_count", -1);
		ob->remove_call_out("doing_job");
		ob->set("job_status",0);
		me->add_temp("job_girl", ob->query("id") );
		remove_call_out("clear_job_girl");
		call_out("clear_job_girl", 40 + random(40), me );
	}
	else  
		command( "say ����û�������￴�ش��ţ��⻰�Ӻ�˵��");
		ob->remove_call_out("doing_job");
	return "���Ҫ�úøɣ�\n";
}

string ask_job()
{
	mapping fam;
	object ob = this_player();
	object me = this_object();

	if (!(fam = ob->query("family")) || fam["family_name"] != "���չ�")
		return RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��";

	if((ob->query("job_status"))==2)
		return "�㻹û�����ͯ�ѵĹ�����������ʲô��\n";

	if((ob->query("combat_exp"))<100)      //      exp<100  can not do meijian's job; 
		return "�㾭�鲻�����ڴ�������Σ�ա��Ⱦ��鹻���������ҡ�\n";

	if ( me->query_temp("job_girl") == ob->query("id") ) {
		command("shake");
		return "��������Ų��ã�Ӧ����ȥ��Ϣһ���ˣ����۵Ļ�����������Ҳ�ɡ�\n";
	}

	if((ob->query("job_status"))==1)
	{
//		command("say ������һ����ô���ʣ��������¿�ʼ��");
		if(random(3)==1)
			call_out("add_bandit",4 + random(6) ,ob); //bandit has 1/4 chance;
		return "�����ɲ������ɸ���Ļ����ֱ�Ӹ���˵��ɲ��ˡ�\n";
	}
	else  if(query("job_count")>=4)
		return "�������ˣ����ŵ�λ���Ѿ��������ˡ���һ������������\n";
    else{
		command( "say ��������￴�ش��Űɡ�");
		ob->set("job_status", 1);
		me->add("job_count",1);
	 }

	if(random(3)==1)
		call_out("add_bandit",4 + random(6) ,ob); //bandit has 1/4 chance;
		ob->remove_call_out("doing_job");
//		ob->start_call_out( (: call_other, __FILE__, "doing_job", ob:),200+random(300));
		call_out("doing_job",100+random(300), ob);

	return "�����񣬲�Ҫ͵����\n";
}

int doing_job(object ob)
{
	object me = this_object();
	if((ob->query("job_status"))==1)
	{
	ob->add("combat_exp", 100+random(100));
	ob->add("potential",100 + random(50));

	if ( ob->query("potential") > ob->query("max_potential") )
	ob->set("potential", ob->query("max_potential"));

	ob->set("job_status",0);

	message_vision("\n÷��˵������ʱ�䵽�ˣ�"+ob->query("name")+"����������ˡ����Ҫ���Ŭ������\n\n", ob);
	me->add("job_count", -1);
	me->add_temp("job_girl", ob->query("id") );
	remove_call_out("clear_job_girl");
	call_out("clear_job_girl", 10 + random(20), me );
	}
}
int clear_job_girl()
{
	object me = this_object();
	if ( objectp(me) ) {
		me->delete_temp("job_girl");
	}
	return 1;
}

int add_bandit(object ob)  //if bandit come, player can 'ask mei about �ɲ���' and then escape.
{
	object me;

	mapping skill_status;
	string *sname;
	int i, max = 0, max1, j;

	me = load_object("/d/lingjiu/npc/bandit");
	me->move("/d/lingjiu/damen");

	if ( mapp(skill_status = ob->query_skills()) ) {
		skill_status = ob->query_skills();
		sname = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			if ( skill_status[sname[i]] > max ) max = skill_status[sname[i]];
		}
		
		max1 = (int)max*4/5 + 1;
		max = (int)max*4/5 + 1 + random((int)max/5);
		
		me->set_skill("dodge", max1);
		me->set_skill("parry", max1 );
		me->set_skill("force", max1);
		switch( random(4) )
		{
			case 0:
				me->set_skill("cuff", max1);
				me->set_skill("yujiamu-quan", max1);
				me->map_skill("cuff", "yujiamu-quan");
				me->prepare_skill("cuff", "yujiamu-quan");
				me->set_skill("hand", max1);
				me->set_skill("dashou-yin", max1);
				me->map_skill("hand", "dashou-yin");
				me->prepare_skill("hand", "dashouyin");
				me->set_skill("longxiang-banruo", max1);
				me->map_skill("force", "longxiang-banruo");
				me->set_skill("shenkongxing", max1);
				me->map_skill("dodge", "shenkongxing");
				switch( random(2) ) {
				   case 0:
					me->set_skill("staff", max);
					me->set_skill("jingang-chu", max);
					me->map_skill("staff", "jingang-chu");
					me->map_skill("parry", "jingang-chu");
					me->carry_object("/clone/weapon/tiezhang")->wield();
					break;
				   case 1:
					me->set_skill("sword", max);
					me->set_skill("mingwang-jian", max);
					me->map_skill("sword", "mingwang-jian");
					me->map_skill("parry", "mingwang-jian");
					me->carry_object("/clone/weapon/changjian")->wield();
					break;
				}
				break;
			case 1:
				me->set_skill("strike", max1);
				me->set_skill("chousui-zhang", max1);
				me->map_skill("strike", "xingxiu-duzhang");
				me->prepare_skill("strike", "xingxiu-duzhang");
				me->set_skill("claw", max1);
				me->set_skill("sanyin-zhua", max1);
				me->map_skill("claw", "sanyin-zhua");
				me->prepare_skill("claw", "sanyin-zhua");
				me->set_skill("huagong-dafa", max1);
				me->map_skill("force", "huagong-dafa");
				me->set_skill("staff", max);
				me->set_skill("tianshan-zhang", max);
				me->map_skill("staff", "tianshan-zhang");
				me->set_skill("zhaixinggong", max1);
				me->map_skill("dodge", "zhaixinggong");
				me->map_skill("parry", "tianshan-zhang");
				me->carry_object("/clone/weapon/tiezhang")->wield();
				break;
			case 2:
				me->set_skill("strike", max1);
				me->set_skill("lingshe-shenfa", max1);
				me->map_skill("dodge", "lingshe-shenfa");
				me->set_skill("huagu-mianzhang", max1);
				me->map_skill("strike", "huagu-mianzhang");
				me->prepare_skill("strike", "huagu-mianzhang");
				me->set_skill("kick", max1);
				me->set_skill("jueming-tui", max1);
				me->map_skill("kick", "jueming-tui");
				me->prepare_skill("kick", "jueming-tui");
				me->set_skill("dulong-dafa", max1);
				me->map_skill("force", "dulong-dafa");
				me->set_skill("ruyi-gou", max);
				me->map_skill("hook", "ruyi-gou");
				me->set_skill("hook", max);
				me->carry_object("/clone/weapon/hook")->wield();
				break;
			case 3: 
				me->set_skill("strike", max1);
				me->set_skill("hamagong", max1);
				me->set_skill("hand", max1);
				me->set_skill("shexing-diaoshou", max1);
				me->map_skill("hand", "shexing-diaoshou");
				if ( max > 100 ) {
					me->map_skill("strike", "hamagong");
					me->prepare_skill("strike", "hamagong");
				}
				else {
					me->prepare_skill("hand", "shexing-diaoshou");
				}
				me->map_skill("force", "hamagong");
				me->set_skill("staff", max);
				me->set_skill("lingshe-zhang", max);
				me->map_skill("staff", "lingshe-zhang");
				me->map_skill("parry", "lingshe-zhang");
				me->set_skill("chanchubu", max1);
				me->map_skill("dodge", "chanchubu");
				me->carry_object("/clone/weapon/tiezhang")->wield();
				break;
		}

		me->set("combat_exp", ob->query("combat_exp")+random(ob->query("combat_exp")/10));
		me->set("max_qi", ob->query("max_qi"));
		me->set("eff_qi", ob->query("max_qi"));
		me->set("max_jing", ob->query("max_jing"));
		me->set("eff_jing", ob->query("max_jing"));
		me->set("qi", me->query("max_qi"));
		me->set("jing", me->query("max_jing"));
		me->set("jiali", ob->query("jiali")*3/4);

		if ( ob->query("max_neili") > 0 ) {
			me->set("max_neili", ob->query("max_neili"));
		}
		else me->set("max_neili", 500);

		if ( ob->query("max_jingli") > 0 ) {
			me->set("max_jingli", ob->query("max_jingli"));
		}
		else me->set("max_jingli", 500);

		me->set("neili", me->query("max_neili"));
		me->set("jingli", me->query("max_jingli"));

	}
	message_vision(HIR"ͻȻɽ�³���һ��$N��������˵�������Ƿ��𹥻���\n"NOR, me);
	message_vision(CYN"$N���һ�������ȵ����Ͽ��ͯ�ѽ����������Ľ�ҩ����\n"NOR, me);

	me->kill_ob(ob);
	return 1;
}
int do_kill(object me, object dest)
{

//      write("begin kill bandit\n"); //for test

	if( objectp(dest) && present(dest, environment(me))
		 && !environment(me)->query("no_fight"))
	{
		command( "say �󵨿�ͽ�����������չ���Ұ��������츿�־��ܣ�");
		me->kill_ob(dest);
		dest->fight_ob(me);
	}
	
	call_out("checking", 0,  me, dest);
	
	return 1;
}

int checking(object me)
{
	object ob;

//      write("begin check bandit\n"); //for test

	if (me->is_fighting()) 
	{
		call_out("checking", 1, me);
	    return 1;
	}

	if( objectp(ob = present("bandit", environment(me))))
	{
		call_out("do_kill", 1, me, ob);
	return 1;
	}
	
	call_out("checking", 1, me);
	return 1;
}
#include "/kungfu/class/lingjiu/jianbi.h"
#include "/kungfu/class/lingjiu/auto_perform.h"
