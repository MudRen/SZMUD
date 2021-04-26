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
		"������ȫ�������е��ﲻ���������徲ɢ�ˣ������ڳ�����ǰ��Ȣ�����ӡ�\n�������ϻ���һ�����ã�ԭ�������������㻯�ﲻ��֮ʱ��������һ������֮ͼ\n��������˼˵���ٶ̴٣�ٿϢ���ţ���Ϊ���ã��뵱�����Ľ������ﲻ������\n��ʦ������ͼ�����ڵ���֮�ϡ�"
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
	set_skill("literate", 101);
	set_skill("taoism", 150);
	set_skill("beidou-zhenfa", 140);

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


void init()
{
		  object ob = this_player();

		  ::init();

		  add_action("do_kill_sb","kill");
		  add_action("do_kill_sb","hit");
		  add_action("do_throw","throw");
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

		  if ( victim->query("family/family_name") == "ȫ���"  ) {
				message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����У���\n", victim, me);
				message_vision( "$Nһ����Ц���󵨿�ͽ�����ҵ��������������ˣ�����ȫ��̺��۸�ô��\n", this_object() );
				this_object()->kill_ob(me);
				return 1;
		  }

	return 0;
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
				message_vision("$Nһ����Ц���󵨿�ͽ�����ҵ�����������ɱ�ˣ�����ȫ��̺��۸�ô��\n", ob1);
				ob1->kill_ob(me);
				return 1;
		  }

		  //message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����ղ������������һ��\n", ob, me);
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
		  kill_ob(me);
		  return 1;
}


#include "auto_perform.h"
