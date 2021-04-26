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

	set("max_qi", 1500);
	set("max_jing", 1500);
	set("max_jingli", 1500);
	set("neili", 1800);
	set("max_neili", 1800);
	set("combat_exp", 900000);
	set("score", 110000);

	set_skill("beidou-zhenfa", 150);
	set_skill("force", 145);
	set_skill("xiantian-gong", 145);
	set_skill("dodge", 145);
	set_skill("jinyangong", 145);
	set_skill("cuff", 145);
	set_skill("chunyang-quan", 145);
	set_skill("strike", 145);
	set_skill("sanhua-juding", 145);
	set_skill("parry", 145);
	set_skill("sword", 145);
	set_skill("quanzhen-jian", 145);
	set_skill("literate", 101);
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

void init()
{
		  ::init();
		  add_action("do_kill_sb","kill");
}

int do_kill_sb(string arg)
{
		  object ob, ob1=this_object(), me = this_player();

		  if ( !arg || arg == "" ) return 0;

		  if ( !ob=present(arg, environment(me)) ) return 0;

		  if ( ob->query("family/family_name") == "ȫ���"  ) {
			  message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����ղ������������һ��\n", ob, me);
				message_vision("$Nһ����Ц���󵨿�ͽ�����ҵ�����������ɱ�ˣ�����ȫ��̺��۸�ô��\n", ob1);
				ob1->kill_ob(me);
				return 1;
		  }

		  message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����ղ������������һ��\n", ob, me);
		  return 0;
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

