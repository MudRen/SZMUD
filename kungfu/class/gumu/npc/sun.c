// Gumu NPC: Sun 
// /d/gumu/npc/sun.c 
// By jiuer--08/05/2001
// update april 01.11.04

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_job();
string ask_ping();
string ask_jiedu();

void create()
{
	set_name("������", ({
		"sun popo",
		"sun",
		"nanny",
	}));
	
	set("title", "��Ĺ�ܼ�");
	set("long",
"����С�������������衣������һ��������Ƥ���ĳ����������������㣬
����Ц�ݸ���ʮ�ֳ�ª�������֮��ȴ���ʴ�����֮�⣬��ʱ�������ие�
һ����ů��\n"
	);

	set("gender", "Ů��");
	set("attitude", "peaceful");

	set("age", 50);
	set("shen_type",1);

	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("combat_exp", 80000);
	set("score", 1000);
	

	set_skill("force", 90);
	set_skill("yunu-xinjing", 90);
	set_skill("dodge", 90);
	set_skill("feiyan-gong", 90);
	set_skill("bee-training", 90);
	set_skill("sword",90);
	set_skill("yunu-jianfa",90);
	set_skill("parry", 90);
	set_skill("throwing",90);

	map_skill("force", "yunu-xinjing");
	map_skill("dodge", "feiyan-gong");
	map_skill("parry", "yunu-jianfa");
	map_skill("sword", "yunu-jianfa");
    
	create_family("��Ĺ��", 5, "�ܼ�");

	set("inquiry", ([
		"job" : (: ask_job :),
		"���ƿ" : (: ask_ping :),
		"�ⶾ" : (: ask_jiedu :),
        ]));

	set_temp("job_pos",10);

	setup();

        carry_object("/kungfu/class/gumu/obj/pao")->wear();

}

void init()
{
	object ob;

	::init();
	return;
}


string ask_job()
{
	object ob2;
	object ob = this_player();
	object me = this_object();

	if ( ob->query("family/family_name") != "��Ĺ��" )
	return "��λ"+RANK_D->query_respect(ob)+"���ҹ�Ĺ�ɵ��ӣ�����ͷ���\n";

        if(ob->query("scheming")) return "���ڽ�ֹ�� Scheme ����������\n"; 
        if(ob->query_temp("gm_xunfeng")){
		command("hmm "+ob->query("id"));
		return "�㻹û������񣬾�����Ҫ�µģ�\n";
	}


	if( time() < ob->query( "mp_job_time" ) +180 )
	{

		tell_object( ob, "����ȥЪϢһ�°�.\n" );
		return "\n";
	}
	ob->set( "mp_job_time", time() );
	me->add_temp("job_pos", -1);

	command("nod");
	command("say �ã�������������"+RANK_D->query_respect(ob)+"��������ȥ��Щ���۰ɡ�");
	ob2 = new("/kungfu/class/gumu/obj/beehive");
	ob2->set("owner",ob);
	ob2->set("mi_lvl",0);
	if(!ob->query_temp("bee_count")){
		ob->set("bee_count",ob->query("bee_count")-2);
		if (ob->query("bee_count")<1) ob->set("bee_count",1);
		ob->set_temp("bee_count",ob->query("bee_count"));
	}
	if(ob->query_temp("bee_count") > 5) ob->set_temp("bee_count",5);
	ob2->set("bee_count",ob->query_temp("bee_count"));
	ob2->set_amount(ob->query_temp("bee_count"));
	ob2->move(ob);
	ob->set_temp("gm_xunfeng",1);
	ob->set("gm/job",1);
	ob->set("gm/time",time());
	message_vision("$N��$n"+chinese_number(ob2->query_amount())
		+"��"+HIW"����䡣\n"NOR, me, ob);
	return "��ȥ��أ�С����ȸ��\n";
}

string ask_ping()
{
	object pl = this_player();
	object me = this_object();
	object *inv;	// ���ϴ��Ķ���
	int i,j;
	object ping;

	if ( pl->query("family/family_name") != "��Ĺ��" )
		return "���ƿ�����棬ȴ��Ϊ���ɵ���������\n";

	inv = all_inventory(pl);
	j=0;
	for(i=0; i<sizeof(inv); i++)
		if( inv[i]->query("name") == CYN"���ƿ"NOR )
			j += 1;
	if (j > pl->query_temp("bee_count") + 4){
		command("hmm "+pl->query("id"));
		command("smile "+pl->query("id"));
        return ("Ҫ��ô�����ƿ��ʲô��\n");
	}
	
	command("nod");
	ping = new("/kungfu/class/gumu/obj/qingci-ping");
	ping->set("liquid/remaining",0);
	ping->move(me);
	command("give ping to "+pl->query("id"));
	return ("�����ƿ��С�ִ࣬��Ū���ˣ�\n");
}

string ask_jiedu()
{
	object pl = this_player();
	object me = this_object();
	object ping,xiang;

	if ( pl->query("family/family_name") != "��Ĺ��" ) {
		if ((int)pl->query_condition("yufeng_poison")) {
			command("laugh "+pl->query("id"));
			command("shrug");
			return ("��ϲ��������䶾Ҳûʲô�����ģ�ֻ������ҩ�ɽ���ѣ�\n");
		}
		else return 0;
	}

	if (present("qingci ping", pl))
		return ("�㲻���н�ҩ��\n");

	if (!(int)pl->query_condition("yufeng_poison")) return ("��û�ж�ѽ��");
	
	ping = new("/kungfu/class/gumu/obj/qingci-ping");
	ping->move(me);

	xiang = present("feng xiang", pl);
	if ( xiang && xiang->query("mi_lvl")>1) {
		message_vision("$N�����������ĸ��ӡ�\n", me);
		message_vision("$N�������һ��װ������۵�ľ�塣\n", me);
		message_vision("$N�������������װ�����ƿ��\n", me);
		message_vision("$N�������ָ�ԭ״��\n", me);

		ping->set("liquid/remaining",xiang->query("mi_lvl")/2 +1);
		xiang->set("mi_lvl",0);
	}
	else ping->set("liquid/remaining",1);

	command("give ping to "+pl->query("id"));
	return ("�Ͻ���ȥ�ðɣ�");
}

void attempt_apprentice(object ob)
{
	mapping fam;
	string ttt;

	command("look "+ob->query("id"));
	if ( ob->query("class")=="bonze" ) {
		command ("say �����书�ֱɵý�����ʦ��Ц�ˡ�");
	    return;
	}

	if( ob->query("family/family_name") && ob->query("family/family_name") != "��Ĺ��" ) {
		command ("say �ҹ�Ĺ���Ѿ�������������ȥ�ɡ�");
		ob->set("was_gumu",1);
		return;
	}

	if (ob->query("family/family_name") == "��Ĺ��"){
		command ("hmm " + ob->query("id"));
		command ("sigh " + ob->query("id"));
		return;
	}

	if (ob->query("combat_exp") > 10000 || ob->query("age") >16 
		|| ob->query("was_gumu") ) {
		command ("say "+ RANK_D->query_respect(ob) + 
			"�����ָ��֣��ڽ����պ�����������Ϊʦ����ȡЦ�������ˡ�");
		return;
	}

	if (ob->query("gender") == "Ů��")
		ob->set("title","��Ĺ����Ů");
	else if (ob->query("gender") == "����")
		ob->set("title","��Ĺ�ɼ�ϰ����");
	else {
		command ("sigh " + ob->query("id"));
		command("say �����ĺ��ӣ���ô���......");
		command("say ��ȥ�ɣ����ڹ�Ĺûǰ;�ġ�");
		return;
	}

	command("say �����ĺ��ӣ��Ժ�������������ɣ�");
	command("recruit " + ob->query("id"));

	if (ob->query("gender") == "Ů��")
		ob->set("title","��Ĺ����Ů");
	else if (ob->query("gender") == "����")
		ob->set("title","��Ĺ�ɼ�ϰ����");

	return;
}
