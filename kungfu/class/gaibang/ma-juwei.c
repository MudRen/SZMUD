// Code of ShenZhou
// gaibang npc code

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("���Ϊ", ({"ma juwei", "ma", "juwei"}));
	set("title", "ؤ���ߴ�����");
	set("gender", "����");
	set("age", 35);
	set("long", 
                "����λ���վ�ǿ��ȴ��Ĭ���Ե�ؤ���ߴ����ӡ�\n");
	set("attitude", "peaceful");
	set("str", 23);
	set("int", 22);
	set("con", 18);
	set("dex", 25);

	set("rank", 8);

	set("max_qi", 800);
	set("max_jing", 500);
	set("neili", 710);
	set("max_neili", 710);
	set("jiali", 60);
	
	set("combat_exp", 200000);
	
	set_skill("force", 85); 
	set_skill("huntian-qigong", 82); 
	set_skill("hand", 85); 
	set_skill("shexing-diaoshou", 85); 
	set_skill("dodge", 78); 
	set_skill("xiaoyaoyou", 80); 
	set_skill("parry", 80); 
	set_skill("blade", 85); 
	set_skill("liuhe-dao", 85); 
	set_skill("begging", 80); 
	set_skill("digging", 80); 
	
	map_skill("force", "huntian-qigong");
	map_skill("hand",  "shexing-diaoshou");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("blade","liuhe-dao");
	map_skill("parry","liuhe-dao");
	
	prepare_skill("hand", "shexing-diaoshou");

	create_family("ؤ��", 19, "����");
	setup();

	carry_object("/d/gaibang/obj/budai")->set_amount(6);
	carry_object("/d/gaibang/obj/budai")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

void attempt_apprentice(object ob)
{
        if (ob->query("class")=="bonze") {
                if (ob->query("gender")=="Ů��")
                        command ("say ʦ̫���ǳ����ˣ���ô���ڱ������л����أ�");
                return;
        }

	if( ob->query("con") < 20 ) return;

	if( ob->query("family/family_name") != "ؤ��" )
	{
	        if( ob->query("rank") > 1 ) {
                	command("say ����������Ϊ�ȣ����ݲ�����������������ļһ\n");
                	return;
        	}

		command("say �����Ϊʦ����Ҫ���óԿ��׼�����ú�����ؤ����ӣ�");
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
