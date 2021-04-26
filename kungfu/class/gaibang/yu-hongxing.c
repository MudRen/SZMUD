// Code of ShenZhou
// gaibang npc code

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�����", ({"yu hongxing", "yu", "hongxing"}));
	set("title", "ؤ��˴�����");
	set("gender", "����");
	set("age", 30);
	set("long", 
		"����λЦ���е�ؤ��˴����ӣ����Զ��ǣ����С���á�\n");
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 30);
	set("con", 22);
	set("dex", 20);

	set("rank", 8);

	set("max_qi", 920);
	set("max_jing", 630);
	set("neili", 1120);
	set("max_neili", 1120);
	set("jiali", 90);
	
	set("combat_exp", 300000);
	
	set_skill("force", 98); 
	set_skill("huntian-qigong", 96); 
	set_skill("hand", 98); 
	set_skill("shexing-diaoshou", 80); 
	set_skill("dodge", 90); 
	set_skill("xiaoyaoyou", 102); 
	set_skill("blade", 100); 
	set_skill("liuhe-dao", 100); 
	set_skill("parry", 101); 
	set_skill("begging", 100); 
	set_skill("stealing", 90); 
	set_skill("checking", 90); 
	set_skill("training", 90);
	
	map_skill("force", "huntian-qigong");
	map_skill("hand",  "shexing-diaoshou");
	map_skill("blade","liuhe-dao");
	map_skill("parry","liuhe-dao");
	map_skill("dodge", "xiaoyaoyou");
	
	prepare_skill("hand", "shexing-diaoshou");

	create_family("ؤ��", 19, "����");
	setup();

	carry_object("/d/gaibang/obj/budai")->set_amount(7);
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

	if( ob->query("int") < 25 ) return;

	if( ob->query("family/family_name") != "ؤ��" )
	{
	        if( ob->query("rank") > 1 ) {
                	command("say ����������Ϊ�ȣ����ݲ�����������������ļһ\n");
               	 	return;
        	}

		command("say �����������Ϊ����ֻ���߹������˼Һ��Ҳ��ر���Щ����ͽ����");
		command("say ��Ҷ�ҪΪ��Զ���밡��");
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
