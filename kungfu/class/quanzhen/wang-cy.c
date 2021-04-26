// Code of ShenZhou
// /kungfu/class/quanzhen/wang-cy.c
// wang-cy.c ������
// sdong 08/01/98

inherit NPC;
inherit F_MASTER;

string ask_me();

int auto_perform();

void create()
{
	set_name("������", ({ "wang chongyang", "wang" }));
	set("nickname", "����ͨ");
	set("long",
		"������ȫ��̵Ŀ�ɽ���桢���ڵ�һ�λ�ɽ�۽�������Ⱥ�ۣ��¶��һ�����������ˡ�\n"
		"���������ʮ����ĸߴ�ü�������һ��Ӣ��������ֻ��������������һϮ��������\n"
		"��������Ʈ�����ľ��ɷ����֮��������Ϊ֮���ۡ�\n");
	set("gender", "����");
	set("age", 90);
	set("attitude", "heroic");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 14000);
	set("max_jing", 5000);
	set("max_jingli", 9000);
	set("neili", 10000);
	set("max_neili", 10000);
	set("jiali", 300);
	set("combat_exp", 6400000);
	set("score", 60000);
	set("shentong",100);

	set_skill("force", 400);
	set_skill("xiantian-gong", 400);
	set_skill("dodge", 400);
	set_skill("jinyangong", 400);
	set_skill("cuff", 400);
	set_skill("chunyang-quan", 400);
	set_skill("strike", 400);
	set_skill("sanhua-juding", 400);
	set_skill("parry", 400);
	set_skill("sword", 400);
	set_skill("quanzhen-jian", 400);
	set_skill("literate", 101);
	set_skill("taoism", 400);

	map_skill("force", "xiantian-gong");
	map_skill("dodge", "jinyangong");
	map_skill("cuff", "chunyang-quan");
	map_skill("strike", "sanhua-juding");
	map_skill("parry", "quanzhen-jian");
	map_skill("sword", "quanzhen-jian");

	prepare_skill("cuff", "chunyang-quan");
	prepare_skill("strike", "sanhua-juding");

	create_family("ȫ���", 1, "��ɽ��ʦ");
   

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );


	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();

}

void attempt_apprentice(object ob)
{
	mapping fam;
	string name,new_name;

	if( mapp(fam = ob->query("family")) && fam["family_name"] != "ȫ���" )
	{
		command ("say " + RANK_D->query_respect(this_player())
			+ "�����������ˣ�ϰ�仹���ȴӸ�λ������ɣ�");
		return;
	}

	if ((int)ob->query_skill("xiantian-gong", 1) < 180) {
		command("say ��ȫ������ڼ��书���������ڹ��ķ���");
		command("say " + RANK_D->query_respect(ob) +
			"�Ƿ�Ӧ�����������칦�϶��µ㹦��");
		return;
	}

	if ((int)ob->query("shen") < 1000000) {
		command("say ��ȫ������������������ɣ��Ե���Ҫ���ϡ�");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return;
	}
	command("say �ðɣ�ƶ�����������ˡ�");
	name = ob->query("name");
	new_name = name[0..01]+"��" + name[4..5];
	command("say �ӽ��Ժ���ͽ���" + new_name + "��");
	ob->set("name",new_name);
	command("recruit " + ob->query("id"));
}


#include "auto_perform.h"

