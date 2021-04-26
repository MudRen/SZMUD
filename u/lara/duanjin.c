// Code of ShenZhou
// /d/dali/npc/duanjin.c  ����  ��������
// updated by Lara 2001/12/16
inherit NPC;

string ask_me();
string ask_me1();

void create()
{
	set_name("����", ({ "duan jin", "duan"}));
	set("long", 
"    ����������й�֮�ף��ٷ��������ԭ����ԨԴ��Ψ����Ϊ���ѣ�\n"
"����ԭ�ٳ�����֮���ǲ��岻�����Ტ�ۡ������Ƕ������ܶ�����Ϊ \n"
"����֮Զ�ף��ٳ����������쿿�����ܱ����ڷ����ֲ������Թ��� \n"
"������ѵõ�һ�˲ġ��˹���ƽ����ò�ƣ����������Ũü���ۣ�˫ \n"
"���������գ��������\n");
	set("gender", "����");
	set("age", 42);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 86);
	set("int", 16);
	set("con", 22);
	set("dex", 24);

	set("combat_exp", 30000);
	set("dalinpc",1);
	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("unarmed", 70);
	set_skill("parry", 70);
	setup();

	set("inquiry", ([
		"��ְ" :  (: ask_me :),
		"����" :  (: ask_me1 :),
		]));

	carry_object("/d/dali/obj/zipao")->wear();
}


int accept_object(object who,object ob)
{
	int a, b, c, d, e;//���빦���ۻ���

	if (who->query_temp("marks/arrestee") != ob->query("name")
	|| ob->query_temp("last_damage_from") != who
	|| !who->query("dali/employee")
	|| (who->query("family/family_name") != "����μ�" && who->query("combat_exp")>5000000))
	return 0;

	a = ob->query("combat_exp");
	b = who->query("combat_exp");
	c = a*100/b;	
        d = who->query("dali/arrestmade");
        e = who->query("dali/trust");
	who->delete_temp("marks/arrestee");

	if (a > b/2){
		if (ob->query("wrong_fainted") || !ob->query("dalibandit")) {
			who->add("combat_exp", (c+random(c/2))/2);
			who->add("potential", c/6);
		}
		else {
			who->add("combat_exp", (c+random(c/2)+random(d/50)+e/10));
			who->add("potential", (c/3+random(d/100)+e/10));
		}
		if (who->query("potential") > who->query("max_potential"))
			who->set("potential",who->query("max_potential"));
	}

	if (ob->query("combat_exp") > (who->query("combat_exp")*23/10)) {
		command("courage "+who->query("id"));
		who->add("dali/trust",1);
	}
	else command("thumb "+who->query("id"));
	who->add("dali/arrestmade", 1);
	who->delete_temp("dalijobon");
	if (userp(ob)) {
		if (ob->query("combat_exp")>2500) {
			ob->add("combat_exp",-2000);
			who->add("combat_exp",1500);
		}
		call_out("jail", 1, ob);
	}
	else call_out("destroy", 1, ob);

	return 1;
}

void destroy(object ob)
{
	destruct(ob);
	return;
}

void jail(object ob)
{
	ob->move("/d/dali/laoyu");
	return;
}

void init()
{
	object ob,me=this_object();

	if (interactive(ob = this_player())
		&& ob->query("dali/employee")
		&& ob->query("family/family_name")!="����μ�"
		&& ob->query("dali/trust")<0) {
		message_vision("$N����ؾ���$n����"+RANK_D->query_respect(me)+"Ͷ�Ҵ���Ϊ�ȴ��ô��Ϊ���졢�����ۣ����Ͼ�Ҫ���㿪���ˣ���\n",me,ob);
	}

	if (interactive(ob = this_player())
		&& ob->query("dali/employee")
		&& ob->query("family/family_name")!="����μ�"
		&& (ob->query("dali/trust")<=-100
		|| ob->query("family/family_name")=="ؤ��"
		|| ob->query("family/family_name")=="������"
		|| ob->query("family/family_name")=="ѩɽ��"
		|| ob->query("family/family_name")=="Ѫ����"
		|| ob->query("family/family_name")=="����ɽ"
		|| ob->query("sg/spy")
		|| (ob->query("class") && ob->query("class")!="officer")
		|| (ob->query("PKS")>20	&& ob->query("combat_exp")/ob->query("PKS") < 10000))) {
		command("sneer "+ob->query("id"));
		message_vision("$N��$n��Ц�ŵ�����"+RANK_D->query_rude(me)+"����Ϊ��ȴ�Ļ����죬�ӹ���Ϊ�����������������С����ң�ĵط�����\n",me,ob);
		message_vision("$N�ͳ�һ���Ķ�$n�������������ֱ��л�������ȥ"+ob->query("name")+"�������ְ֮��������¼�ã���\n",me,ob);
		ob->set("dali/betrayer",1);
		ob->delete("dali/employee");
		ob->delete("dali/rank");
		ob->delete("dali/jobdone");
		ob->delete("dali/arrestmade");
		ob->delete("dali/duty");
		ob->delete("dali/lastjob");
		ob->delete("class");
		if (ob->query_skill("buddhism",1)>40) ob->set_skill("buddhism", 40);
		ob->set("dali/trust",-100);
	}

	if (interactive(ob = this_player())
		&& ob->query("dali/employee")
		&& ob->query("family/family_name")!="����μ�"
		&& (ob->query("shen")>(ob->query("combat_exp")/2)
		|| ob->query("shen")<(-ob->query("combat_exp")/2)
		|| ob->query("family/family_name")=="ȫ���"
		|| ob->query("family/family_name")=="�һ���")) {
		command("sigh "+ob->query("id"));
		message_vision("$N�����������$n���˵������"+RANK_D->query_respect(me)+"�����ڽ����������󳤣��ڴ�������Ϊ��ʵ��̫ί�����ˡ���\n",me,ob);
		message_vision("$N�ͳ�һ���Ķ�$n�������������ֱ��л�������ȥ"+ob->query("name")+"�������ְ֮��������¼�ã���\n",me,ob);
		ob->set("dali/betrayer",1);
		ob->delete("dali/employee");
		ob->delete("dali/rank");
		ob->delete("dali/jobdone");
		ob->delete("dali/arrestmade");
		ob->delete("dali/duty");
		ob->delete("dali/lastjob");
		ob->delete("class");
		if (ob->query_skill("buddhism",1)>40) ob->set_skill("buddhism", 40);
		ob->set("dali/trust",0);
	}
}

int accept_fight(object me)
{
	command("say ���¹���æ��û�������档");
	return notify_fail("������������㽻�֡�\n");
}

int accept_kill(object me)
{
	if (me->query("dali/employee"))
		command("say ����ͬ�����£��ιʼӺ����ң����Ҹ���ƴ�ˣ�\n");
	else command("say ��ү����������ɱ�ţ��������㵹ù��\n");
	me->apply_condition("dlkiller", 100);
	me->add("dali/trust",-1);
	return 1;
}

void unconcious()
{
	object ob, me=this_object();

	if (objectp(ob = me->query_temp("last_damage_from")))
		ob->add("dali/trust", -1);

	::unconcious();
}

void die()
{
	object ob, me=this_object();

	if (objectp(ob=me->query_temp("last_damage_from")))
		ob->add("dali/trust", -1);

	::die();
}

string ask_me()
{
	object who=this_player();

	if (!who->query("dali/employee"))
		return RANK_D->query_respect(who)+"���Ҵ������޹ϸ𣬺��д��ʰ���";

	if (who->query("dali/rank")<=1)
		return RANK_D->query_respect(who)+"���𻹲�����û�й�ְ���������㻹������ʵʵ����ɡ�";

	if (who->query("dali/rank")>=2) {
		if (who->query("dali/arrestmade")>=500 && who->query("dali/duty")<1) {
			who->set("dali/duty",1);
			who->set("title","������¸�����");
			return RANK_D->query_respect(who)+"������������������Ժգ��ֱ��л������������¸�������";
		}
		if (who->query("dali/arrestmade")>=1000 && who->query("dali/duty")<2) {
			who->set("dali/duty",2);
			who->set("title","������¸�����");
			return RANK_D->query_respect(who)+"������������������Ժգ��ֱ��л������������¸�������";
		}
	}

	if (who->query("dali/rank")>=3) {
		if (who->query("dali/arrestmade")>=2000 && who->query("dali/duty")<3) {
			who->set("dali/duty",3);
			who->set("title","������и�����");
			return RANK_D->query_respect(who)+"������������������Ժգ��ֱ��л������������и�������";
		}
		if (who->query("dali/arrestmade")>=4000 && who->query("dali/duty")<4) {
			who->set("dali/duty",4);
			who->set("title","������и�����");
			return RANK_D->query_respect(who)+"������������������Ժգ��ֱ��л������������и�������";
		}
		if (who->query("dali/arrestmade")>=6000 && who->query("dali/duty")<5) {
			who->set("dali/duty",5);
			who->set("title","������ϸ�����");
			return RANK_D->query_respect(who)+"������������������Ժգ��ֱ��л������������ϸ�������";
		}
	}

	if (who->query("dali/rank")>=4) {
		if (who->query("dali/arrestmade")>=8000 && who->query("dali/duty")<6) {
			who->set("dali/duty",6);
			who->set("title","������ϸ�����");
			return RANK_D->query_respect(who)+"������������������Ժգ��ֱ��л������������ϸ�������";
		}
		if (who->query("dali/arrestmade")>=10000 && who->query("dali/duty")<7) {
			who->set("dali/duty",7);
			who->set("title","��������־�����");
			command("congra");
			return RANK_D->query_respect(who)+"������������������Ժգ��ֱ��л��������������־�������";
		}
	}

	if (who->query("dali/rank")==5) {
		if (who->query("dali/arrestmade")>=15000 && who->query("dali/duty")<8) {
			who->set("dali/duty",8);
			who->set("title","����������ܹ�");
			command("congra");
			return RANK_D->query_respect(who)+"Ϊ�����ľ����������պգ��л���ּ�⣬����Ϊ�����ܹܡ�";
		}
		else return RANK_D->query_respect(who)+"�Ĺ��Ѿ��ߵò��������ˡ�";
	}

	return RANK_D->query_respect(who)+"��û�л����㹻�Ĺ��ͣ������ʸ���ְ��";
}

string ask_me1()
{
	object who=this_player();

	if (!who->query("dali/employee"))
		return RANK_D->query_respect(who)+"���Ҵ������޹ϸ𣬺��д��ʰ���";

	return RANK_D->query_respect(who)+"���Ҵ�����֮�У��Ѿ����۹��͵�"+chinese_number(who->query("dali/trust"))+"��";
}