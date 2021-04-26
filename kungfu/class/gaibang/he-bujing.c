// Code of ShenZhou
// gaibang npc code

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�β���", ({"he bujing", "he", "bujing"}));
	set("title", "ؤ���ߴ�����");
	set("gender", "����");
	set("age", 30);
	set("long", 
		"����λ������������ͷ�����ؤ���ߴ����ӡ�\n");
	set("attitude", "heroism");
	set("str", 28);
	set("int", 18);
	set("con", 24);
	set("dex", 20);

	set("rank", 7);

	set("max_qi", 880);
	set("max_jing", 600);
	set("neili", 980);
	set("max_neili", 980);
	set("jiali", 90);
	
	set("combat_exp", 240000);
	
	set_skill("force", 90); 
	set_skill("huntian-qigong", 85); 
	set_skill("strike", 85); 
	set_skill("xianglong-zhang", 85); 
	set_skill("dodge", 95); 
	set_skill("xiaoyaoyou", 90); 
	set_skill("parry", 83); 
	set_skill("begging", 60); 
	set_skill("stealing", 80); 
	
	map_skill("force", "huntian-qigong");
	map_skill("strike", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	
	prepare_skill("strike", "xianglong-zhang");

	create_family("ؤ��", 19, "����");
	setup();

	carry_object("/d/gaibang/obj/budai")->set_amount(6);
	carry_object("/d/gaibang/obj/budai")->wear();
}

void attempt_apprentice(object ob)
{
	if( ob->query("combat_exp") < 30000 ) return;

        if (ob->query("class")=="bonze") {
                if (ob->query("gender")=="Ů��")
                        command ("say ʦ̫���ǳ����ˣ���ô���ڱ������л����أ�");
                return;
        }

	if( ob->query("family/family_name") != "ؤ��" ) 
	{
	        if( ob->query("rank") > 1 ) {
       	         	command("say ����������Ϊ�ȣ����ݲ�����������������ļһ\n");
                	return;
        	}

		command("say ��ܰ���ܰɣ� ���������ðɣ��Ҿ��������ˣ�");
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
