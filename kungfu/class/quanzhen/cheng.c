// Code of ShenZhou
	// /kungfu/class/quanzhen/cheng.c
// cheng.c  ������
// sdong 08/01/98

inherit NPC;
inherit F_MASTER;

string ask_me();

int auto_perform();

void create()
{
	set_name("������", ({ "cheng yaojia", "cheng" }));
	set("long",
		"�����徻ɢ���ﲻ���ĵ��ӡ�\n"
		"������ü��Ŀ�㡣\n"
		);
	set("gender", "Ů��");
	set("age", 46);
	set("attitude", "heroic");
	set("shen_type", 1);
	set("str", 20);
	set("int", 28);
	set("con", 28);
	set("dex", 20);

	set("max_qi", 1000);
	set("max_jing", 1000);
	set("max_jingli", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 80000);
	set("score", 6000);

	set_skill("force", 70);
	set_skill("xiantian-gong", 70);
	set_skill("dodge", 70);
	set_skill("jinyangong", 70);
	set_skill("cuff", 70);
	set_skill("chunyang-quan", 70);
	set_skill("strike", 70);
	set_skill("sanhua-juding", 70);
	set_skill("parry", 70);
	set_skill("sword", 80);
	set_skill("quanzhen-jian", 80);
	set_skill("literate", 80);
	set_skill("taoism", 90);

	map_skill("force", "xiantian-gong");
	map_skill("dodge", "jinyangong");
	map_skill("cuff", "chunyang-quan");
	map_skill("strike", "sanhua-juding");
	map_skill("parry", "quanzhen-jian");
	map_skill("sword", "quanzhen-jian");

	prepare_skill("cuff", "chunyang-quan");
	prepare_skill("strike", "sanhua-juding");

	create_family("ȫ���", 3, "����");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}

void attempt_apprentice(object ob)
{
	mapping fam;
   string name,new_name;

	if(ob->query("gender",1)!="Ů��"){
		command ("say �Բ�����ֻ��Ů���ӣ�");
		return;
	}


	if( mapp(fam = ob->query("family")) && fam["family_name"] != "ȫ���" )
	{
		command ("say " + RANK_D->query_respect(this_player())
			+ "�����������ˣ�ϰ�仹���ȴӸ�λ������ɣ�");
		return;
	}

	if ((int)ob->query_skill("xiantian-gong", 1) < 20) {
		command("say ��ȫ������ڼ��书���������ڹ��ķ���");
		command("say " + RANK_D->query_respect(ob) +
			"�Ƿ�Ӧ�����������칦�϶��µ㹦��");
		return;
	}

	if ((int)ob->query("shen") < 5000) {
		command("say ��ȫ������������������ɣ��Ե���Ҫ���ϡ�");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return;
	}
	command("say �ðɣ�ƶ�����������ˡ�");
	name = ob->query("name");
	new_name = name[0..01]+"��" + name[4..5];
	command("say �ӽ��Ժ���ͽ���" + new_name + "��");
	ob->set(name,new_name);
	command("recruit " + ob->query("id"));
}


