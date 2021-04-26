// Code of ShenZhou
// gaibang npc code

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("��ȫ", ({"zuo quan", "zuo", "quan"}));
	set("title", "ؤ���ߴ�����");
	set("gender", "����");
	set("age", 35);
	set("long", 
		"����λ��ˬ�󷽵�ؤ���ߴ����ӣ������Ǹ����غ��ܡ�\n");
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 26);

	set("rank", 7);

	set("max_qi", 860);
	set("max_jing", 500);
	set("neili", 810);
	set("max_neili", 810);
	set("jiali", 80);
	
	set("combat_exp", 250000);
	
	set_skill("force", 83); 
	set_skill("huntian-qigong", 80); 
	set_skill("hand", 80); 
	set_skill("shexing-diaoshou", 90); 
	set_skill("dodge", 80); 
	set_skill("xiaoyaoyou", 81); 
	set_skill("parry", 80); 
	set_skill("begging", 50); 
	set_skill("checking", 50); 
	set_skill("digging", 60); 
	
	map_skill("force", "huntian-qigong");
	map_skill("hand",  "shexing-diaoshou");
	map_skill("dodge", "xiaoyaoyou");

	prepare_skill("hand", "shexing-diaoshou");
	
	create_family("ؤ��", 19, "����");
	setup();

	carry_object("/d/gaibang/obj/budai")->set_amount(6);
	carry_object("/d/gaibang/obj/budai")->wear();
}

void attempt_apprentice(object ob)
{
	if( ob->query("gender") != "����") {
		command("say ��ֻ���е��ӡ���ȥ���ұ����������Ӱɡ�");
		return;
	}

	if( ob->query("family/family_name") != "ؤ��" )
	{
	        if( ob->query("rank") > 1 ) {
                	command("say ����������Ϊ�ȣ����ݲ�����������������ļһ\n");
                	return;
        	}

		ob->set("rank", 1); 
		command("recruit " + ob->query("id"));
                ob->set("title", "ؤ��һ������");
		command("say �ðɣ�ϣ�����ܺú�ѧϰ�����书������Ϊؤ����һ��������");
	} 
	else
	{
		ob->set_temp("title", ob->query("title"));
		command("recruit " + ob->query("id"));
		ob->set("title", ob->query_temp("title"));
		ob->delete_temp("title");
	}
}

#include "/kungfu/class/gaibang/promote.h"
