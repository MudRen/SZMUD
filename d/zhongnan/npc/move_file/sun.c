// Code of ShenZhou
// /kungfu/class/quanzhen/sun.c
// sun.c �徲ɢ���ﲻ��
// sdong 08/01/98

inherit NPC;
inherit F_MASTER;

string ask_me();

int auto_perform();

void create()
{
	set_name("�ﲻ��", ({ "sun buer", "sun" }));
	set("nickname", "�徲ɢ��");
	set("long",
		"������ȫ�������е��ﲻ���������徲ɢ�ˣ������ڳ�����ǰ��Ȣ�����ӡ�\n"
		);
	set("gender", "Ů��");
	set("age", 62);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 20);
	set("int", 28);
	set("con", 28);
	set("dex", 25);

	set("max_qi", 2500);
	set("max_jing", 2000);
	set("max_jingli", 2000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 50);
	set("combat_exp", 600000);
	set("score", 70000);

	set_skill("force", 150);
	set_skill("xiantian-gong", 150);
	set_skill("dodge", 150);
	set_skill("jinyangong", 150);
	set_skill("cuff", 140);
	set_skill("chunyang-quan", 145);
	set_skill("strike", 140);
	set_skill("sanhua-juding", 145);
	set_skill("parry", 140);
	set_skill("sword", 150);
	set_skill("quanzhen-jian", 150);
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
	if (clonep()) carry_object("/clone/unique/cy-jian");
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

	if ((int)ob->query_skill("xiantian-gong", 1) < 50) {
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


int accept_kill(object me)
{
		  command("say ԭ�����Ƕ�����������Ϊ�������\n");
		  if (present("chongyang jian", this_object())){
		  command("wield chongyang jian");
		  }
		  set_leader(me);
		  kill_ob(me);
		  return 1;
}


#include "auto_perform.h"
