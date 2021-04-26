// Code of ShenZhou
// /kungfu/class/quanzhen/wang.c
// wang.c ����������һ
// sdong 08/01/98

inherit NPC;
inherit F_MASTER;

string ask_me();

int auto_perform();

void create()
{
	set_name("����һ", ({ "wang chuyi", "wang" }));
	set("nickname", "������");
	set("long",
		"������ȫ�������е�����һ�����������ӣ����������ĵ������书�������𴦻���\n"
		"��ĳ�����˶�ʤ�������������ƾ���������֮�ϣ�����ƮƮ��ǰҡ��ڣ�ֻ�ŵ�\n"
		"ɽ���ӱ���ʮλӢ�ۺú�Ŀ����ѣ�����಻�£�������˸��������ɡ������š�\n"
      );
	set("gender", "����");
	set("age", 67);
	set("attitude", "heroic");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 3000);
	set("max_jing", 2000);
	set("max_jingli", 2500);
	set("neili", 3500);
	set("max_neili", 3500);
	set("jiali", 50);
	set("combat_exp", 900000);
	set("score", 110000);

	set_skill("force", 165);
	set_skill("xiantian-gong", 165);
	set_skill("dodge", 165);
	set_skill("jinyangong", 165);
	set_skill("cuff", 165);
	set_skill("chunyang-quan", 165);
	set_skill("strike", 150);
	set_skill("sanhua-juding", 150);
	set_skill("parry", 150);
	set_skill("sword", 165);
	set_skill("quanzhen-jian", 165);
	set_skill("literate", 120);
	set_skill("taoism", 150);

	map_skill("force", "xiantian-gong");
	map_skill("dodge", "jinyangong");
	map_skill("cuff", "chunyang-quan");
	map_skill("strike", "sanhua-juding");
	map_skill("parry", "quanzhen-jian");
	map_skill("sword", "quanzhen-jian");

	prepare_skill("cuff", "chunyang-quan");
	prepare_skill("strike", "sanhua-juding");

	create_family("ȫ���", 2, "����");

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

	if ((int)ob->query_skill("xiantian-gong", 1) < 70) {
		command("say ��ȫ������ڼ��书���������ڹ��ķ���");
		command("say " + RANK_D->query_respect(ob) +
			"�Ƿ�Ӧ�����������칦�϶��µ㹦��");
		return;
	}

	if ((int)ob->query("shen") < 35000) {
		command("say ��ȫ������������������ɣ��Ե���Ҫ���ϡ�");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return;
	}
	command("say �ðɣ�ƶ�����������ˡ�");
	name = ob->query("name");
	new_name = name[0..01]+"־" + name[4..5];
	command("say �ӽ��Ժ���ͽ���" + new_name + "��");
	ob->set("name",new_name);
	command("recruit " + ob->query("id"));
}


#include "auto_perform.h"

