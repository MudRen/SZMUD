// Code of ShenZhou
// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;

int auto_perform();
string ask_baicao();
string ask_xhwan();

void create()
{
	set_name("������", ({"liang zhanglao", "liang", "zhanglao"}));
	set("title", "ؤ��Ŵ�����");
	set("nickname", "��������");
	set("gender", "����");
	set("age", 55);
	set("long", 
		"��������ؤ�������ã��书��ߵĳ��ϣ��������������Ѿá�\n"
		"ؤ���书������ǿ������������һ�����٣������������ϡ�\n");

	set("attitude", "peaceful");
	
	set("str", 28);
	set("int", 24);
	set("con", 24);
	set("dex", 25);

	set("rank", 9);

	set("qi", 1200);
	set("max_qi", 1200);
	set("jing", 800);
	set("max_jing", 800);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 120);
	
	set("combat_exp", 700000);
	
	set_skill("force", 140); 
	set_skill("huntian-qigong", 145); 
	set_skill("strike", 110); 
	set_skill("xianglong-zhang", 110); 
	set_skill("hand", 140); 
	set_skill("shexing-diaoshou", 145); 
	set_skill("dodge", 130); 
	set_skill("xiaoyaoyou", 130); 
	set_skill("parry", 140); 
	set_skill("blade", 150); 
	set_skill("liuhe-dao", 150); 
	set_skill("begging", 100); 
	set_skill("checking", 120);
	
	map_skill("force", "huntian-qigong");
	map_skill("strike","xianglong-zhang");
	map_skill("hand",  "shexing-diaoshou");
	map_skill("blade", "liuhe-dao");
	map_skill("dodge", "xiaoyaoyou");
	
	prepare_skill("strike", "xianglong-zhang");

	set("baicao", 10);
	set("xhwan", 10);
	set("chat_chance", 3);
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );

	create_family("ؤ��", 18, "�Ŵ�����");

	set("inquiry", ([
	    "�ۻ���" : (: ask_xhwan :),
	    "�ٲݵ�" : (: ask_baicao :),
//          "job" : (: ask_job :),
	]));

	setup();

	carry_object("/d/gaibang/obj/budai")->set_amount(8);
	carry_object("/d/gaibang/obj/budai")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

void init()
{
	object ob;
	mapping myfam;
	
	::init();
	set_heart_beat(1);
	if (interactive(ob = this_player()) && !is_fighting()) 
	{
		myfam = (mapping)ob->query("family");
		if (!wizardp(ob) && (!myfam || myfam["family_name"] != "ؤ��")
		&& environment(this_object())->query("short") =="������")
		{
			remove_call_out("saying");
			call_out("saying",1,ob);
		}
	}
}

void saying(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	message_vision("\n�����Ͽ���$N�����������һ�����㲻��ؤ����ӣ����ҹ���ȥ��\n\n", ob);
	call_out("kicking", 3, ob);     
}

void kicking(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	ob->move("/d/gaibang/inhole");
	message("vision","ֻ����ƹ����һ����" + ob->query("name") +
		"��С������˳�����\n", environment(ob), ob);
}

void attempt_apprentice(object ob)
{
/*
	if (ob->query("class")=="bonze") {
		if (ob->query("gender")=="Ů��")
			command ("say ʦ̫���ǳ����ˣ���ô���ڱ������л����أ�");
		return;
	}
*/
	if ((int)ob->query_str() < 28) {
		command("say ����ؤ�������һ���Ը���Ϊ����" + 
		RANK_D->query_respect(ob) + "����̫�����ƺ�����ѧؤ��Ĺ���");
		return;
	}

	if( ob->query("family/family_name") != "ؤ��" )
	{
		if( ob->query("rank") > 1 ) {
			command("say ����������Ϊ�ȣ����ݲ�����������������ļһ\n");
			return;
		}

		command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob) +
		"�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");
		ob->set("rank", 1); 
		command("recruit " + ob->query("id"));
		ob->set("title", "ؤ��һ������");
	} 
	else
	{
		ob->set_temp("title", ob->query("title"));
		command("recruit " + ob->query("id"));
		ob->set("title", ob->query_temp("title"));
		ob->delete_temp("title");
	}
}

string ask_xhwan()
{
	object me = this_object(), ob = this_player(), wan;

	if ( !ob->query("family") || ob->query("family/family_name") != "ؤ��" ) {
		return "��Ǳ�����ӣ�������ȡ������ҩ��\n\n";
	}

	if ( !ob->query_condition("xx_poison") || !ob->query_condition("snake_poison")
	|| !ob->query_condition("insect_poison") ) {
		message_vision("$N��$n������ϸ�ش�����һ�󣬱�����üͷ��\n", me, ob);
		return "�㲢δ�ж���Ҫ�ۻ������\n\n";
	}

	message_vision("$N��$n������ϸ�ش�����һ��ץ��$n���������\n", me, ob);

	if ( me->query("xhwan") < 1 ) {
		message_vision("Ȼ��$N�����뻳�����������ã��ƺ�û���š�\n", me);
		return "�����ϴ˿�û���ۻ��裬�㻹�ǿ쵽����ȥ�Ҵ��ɣ�\n\n";
	}

	me->add("xhwan", -1);
	wan = new(DRUG_D("xh-wan"));
	wan->move(ob);

	message_vision("Ȼ��$N�����뻳��ȡ��һ���ۻ����$n��\n", me, ob);
	return "����ۻ�����£���Ҫ�ö��������ڸ���\n\n";
}

string ask_baicao()
{
	object me = this_object(), ob = this_player(), wan;

	if ( !ob->query("family") || ob->query("family/family_name") != "ؤ��" ) {
		return "��Ǳ�����ӣ�������ȡ������ҩ��\n\n";
	}

	if ( (int)ob->query("eff_qi")==(int)ob->query("max_qi")
	&& (int)ob->query("eff_jing")==(int)ob->query("max_jing") ) {
		message_vision("$N��$n������ϸ�ش�����һ�󣬱�����üͷ��\n", me, ob);
		return "�㲢δ���ˣ�Ҫ�ٲݵ�����\n\n";
	}

	message_vision("$N��$n������ϸ�ش�����һ��ץ��$n���������\n", me, ob);

	if ( me->query("baicao") < 1 ) {
		message_vision("Ȼ��$N�����뻳�����������ã��ƺ�û���š�\n", me);
		return "�����ϴ˿�û�аٲݵ����㻹�ǿ쵽����ȥ�Ҵ��ɣ�\n\n";
	}

	me->add("baicao", -1);
	wan = new(DRUG_D("baicao-dan"));
	wan->move(ob);

	message_vision("Ȼ��$N�����뻳��ȡ��һ�Űٲݵ���$n��\n", me, ob);
	return "��Ѱٲݵ����£���Ҫ�����Ƽ������أ�\n\n";
}

int auto_perform()
{
	object me = this_object();
	object target = me->select_opponent();
	object weapon = me->query_temp("weapon");

	if ( !me->is_fighting() ) {
                if ( me->query("eff_qi") < me->query("max_qi") )
                        exert_function("heal");
                me->set("jiali", 100);

                return 1;
        }

	if ( !me->query_temp("powerup") ) {
		return exert_function("powerup");
	}

	if ( !me->query_temp("shengang") ) {
		return exert_function("shengang");
	}

	if ( objectp(weapon) ) {
		if ( weapon->query("skill_type") == "blade" )
			return perform_action("blade.lianhuan");
	}
	else
		return perform_action("strike.leiting");
}       

#include "/kungfu/class/gaibang/promote.h"
