// Code of ShenZhou
// /kungfu/class/quanzhen/li.c
// li.c ��־��
// sdong 08/01/98

inherit NPC;
inherit F_MASTER;

string ask_me();

int auto_perform();

void create()
{
	set_name("��־��", ({ "li zhichang", "li" }));
	set("long",
		"���������ڵĴ������־����\n"
		);
	set("gender", "����");
	set("age", 52);
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
	set("combat_exp", 300000);
	set("score", 6000);

	set_skill("beidou-zhenfa", 100);
	set_skill("force", 100);
	set_skill("xiantian-gong", 100);
	set_skill("dodge", 100);
	set_skill("jinyangong", 100);
	set_skill("cuff", 100);
	set_skill("chunyang-quan", 100);
	set_skill("strike", 100);
	set_skill("sanhua-juding", 90);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("quanzhen-jian", 100);
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

		  if ( ob->query("id") == me->query("id")  ) {
					 return notify_fail("�Լ�ɱ�Լ���\n");
		  }

		  if ( ob->query("family/family_name") == "ȫ���"  && ob != ob1 ) {
			  message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����ղ������������һ��\n", ob, me);
				message_vision("$Nһ����Ц���󵨿�ͽ�����ҵ��������������ˣ�����ȫ��̺��۸�ô��\n", ob1);
				ob1->kill_ob(me);
				return 1;
		  }

		  //message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����ղ������������һ��\n", ob, me);
		  return 0;
}

int do_throw(string arg)
{
        object victim, ob1, ob, me = this_player();
		  string what, who;

        if( !arg
        ||      sscanf(arg, "%s at %s", what, who)!=2)
					 return notify_fail("�����ʽ: throw <��Ʒ> at <ĳ��>��\n");

		  ob = present(what, me);
		  if( !ob ) ob = present(arg, environment(me));
		  if( !ob ) return notify_fail("��Ҫ��ʲô��\n");

		  if (ob->query("no_drop"))
					 return notify_fail("������������뿪�㡣\n");

		  if (!(victim = present(who, environment(me))))
					 return notify_fail("����û�����Ŀ�ꡣ\n");

		  if (!victim)
					 return notify_fail("���ﲢ�޴��ˣ�\n");

		  if (!living(victim))
					 return notify_fail("�ⲻ�ǻ��\n");

		  if ( victim->query("id") == me->query("id")  ) {
					 return notify_fail("�Լ�ɱ�Լ���\n");
		  }

		  if ( victim->query("family/family_name") == "ȫ���"  && victim != this_object() ) {
				message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����У���\n", victim, me);
				message_vision( "$Nһ����Ц���󵨿�ͽ�����ҵ��������������ˣ�����ȫ��̺��۸�ô��\n", this_object() );
				this_object()->kill_ob(me);
				return 1;
		  }


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
	ob->set("name",new_name);
	command("recruit " + ob->query("id"));
}

#include "auto_perform.h"


