// Code of ShenZhou
// gaibang npc code

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����", ({"li sheng", "li", "sheng"}));
	set("title", "ؤ��˴�����");
	set("gender", "����");
	set("age", 38);
	set("long", 
		"����λ���Ը�ֱ����������ؤ��˴����ӡ�\n");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 18);
	set("con", 20);
	set("dex", 23);

	set("rank", 8);

	set("max_qi", 1000);
	set("max_jing", 600);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 60);
	
	set("combat_exp", 350000);
	
	set_skill("force", 91); 
	set_skill("huntian-qigong", 102); 
	set_skill("strike", 25); 
	set_skill("xianglong-zhang", 35); 
	set_skill("hand", 105); 
	set_skill("shexing-diaoshou", 75); 
	set_skill("dodge", 100); 
	set_skill("xiaoyaoyou", 102); 
	set_skill("parry", 102); 
	set_skill("blade", 100); 
	set_skill("liuhe-dao", 100); 
	set_skill("begging", 70); 
	set_skill("digging", 80); 
	
	map_skill("force", "huntian-qigong");
	map_skill("hand",  "shexing-diaoshou");
	map_skill("strike","xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("blade","liuhe-dao");
	map_skill("parry","liuhe-dao");
	
	prepare_skill("hand", "shexing-diaoshou");

	create_family("ؤ��", 19, "����");
	setup();

	carry_object("/d/gaibang/obj/budai")->set_amount(7);
	carry_object("/d/gaibang/obj/budai")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

void attempt_apprentice(object ob)
{
	if( ob->query("shen") < 0 ) {
		command ("say �㿴������Щ��Ϊ�������Ҳ������㡣");
		return;
	}

/*
        if (ob->query("class")=="bonze") {
                if (ob->query("gender")=="Ů��")
                        command ("say ʦ̫���ǳ����ˣ���ô���ڱ������л����أ�");
                return;
        }
*/

	if( ob->query("family/family_name") != "ؤ��" )
	{
	        if( ob->query("rank") > 1 ) {
                	command("say ����������Ϊ�ȣ����ݲ�����������������ļһ\n");
                	return;
        	}

		command("say �ã���������һ��һ���˲�����ͽ�ܣ��һ�ϲ���������أ�");
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

#include "/kungfu/class/gaibang/promote.h"
