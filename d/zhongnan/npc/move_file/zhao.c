// Code of ShenZhou
// /kungfu/class/quanzhen/zhao.c
// zhao.c ��־��
// sdong 08/01/98

inherit NPC;
inherit F_MASTER;
#include <ansi.h>


string *bd_fighters = ({
					 ("/d/zhongnan/npc/wang-zd.c"),
					 ("/d/zhongnan/npc/shen.c"),
					 ("/d/zhongnan/npc/cui.c"),
					 ("/d/zhongnan/npc/chen-zy.c"),
					 ("/d/zhongnan/npc/li.c"),
					 ("/d/zhongnan/npc/yin.c")
});

string ask_me();
string ask_beidouzhen();
int start();
void killer_show(object me);
int do_throw(string arg);
int auto_perform();

void create()
{
	set_name("��־��", ({ "zhao zhijing", "zhao" }));
	set("long",
		"����������һ�Ĵ������־������ȫ��̵������������书��ߡ�\n"
		"����һ��������ˣ�������ȴ��Щɷ����\n"
		);
	set("gender", "����");
	set("age", 49);
	set("attitude", "heroic");
	set("shen_type", 0);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 1500);
	set("max_jing", 1000);
	set("max_jingli", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 400000);
	set("score", 0);

	set_skill("force", 110);
	set_skill("xiantian-gong", 110);
	set_skill("dodge", 120);
	set_skill("jinyangong", 120);
	set_skill("cuff", 120);
	set_skill("chunyang-quan", 120);
	set_skill("strike", 120);
	set_skill("sanhua-juding", 120);
	set_skill("parry", 120);
	set_skill("sword", 130);
	set_skill("quanzhen-jian", 130);
	set_skill("literate", 100);
	set_skill("taoism", 90);
	set_skill("beidou-zhenfa", 120);

	map_skill("force", "xiantian-gong");
	map_skill("dodge", "jinyangong");
	map_skill("cuff", "chunyang-quan");
	map_skill("strike", "sanhua-juding");
	map_skill("parry", "quanzhen-jian");
	map_skill("sword", "quanzhen-jian");

	prepare_skill("cuff", "chunyang-quan");
	prepare_skill("strike", "sanhua-juding");

	create_family("ȫ���", 3, "����");

	set("inquiry", ([
						"ȫ���" : "",
						"�������" : (: ask_beidouzhen :),
						"beidouzhen" : (: ask_beidouzhen :),
	]));



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
		  add_action("do_kill_sb","hit");
		  add_action("do_throw","throw");
}

int do_kill_sb(string arg)
{
		  object ob, ob1=this_object(), me = this_player();

		  if ( !arg || arg == "" ) return 0;

		  if ( !ob=present(arg, environment(me)) ) return 0;

		  if ( ob->query("family/family_name") == "ȫ���"  ) {
			  message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����ղ������������һ��\n", ob, me);
				message_vision("$Nһ����Ц���󵨿�ͽ�����ҵ��������������ˣ�����ȫ��̺��۸�ô��\n", ob1);
				ob1->kill_ob(me);
				return 1;
		  }

		  message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����ղ������������һ��\n", ob, me);
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

		  if ( victim->query("family/family_name") == "ȫ���"  ) {
				message_vision("$n����$N�ȵ�����"+RANK_D->query_rude(ob)+"�����У���\n", victim, me);
				message_vision( "$Nһ����Ц���󵨿�ͽ�����ҵ��������������ˣ�����ȫ��̺��۸�ô��\n", this_object() );
				this_object()->kill_ob(me);
				return 1;
		  }


	return 0;
}



string ask_beidouzhen()
{
	string msg, name;
	object me = this_player();

	command("look "+me->query("id"));

  if ( me->query("family/family_name") != "ȫ���" )
  {
		msg = "�������������ȫ��̵Ľ�����������!";
		return msg;
  }

	if( me->query_temp("asked_beidouzhen") )
	{
	  msg="��ʲô��ʱ��һ���ͻῪʼ��ϰ��������󡹣�\n";
	  return msg;
	}

	if( !me->query_temp("qz/bdgranted" ) )
	{
		msg = "û�������˵���ɣ�����������ϰ���������!";
		return msg;
	}



	if( me->query_temp("pending/beidouzhen") )
	{
		msg="�ú���ϰ��������󡹣�\n";
		command("addoil " + me->query("id"));
		return msg;
	}

	if(query_temp("pending/beidouzhen") || is_busy() )
	{
		msg="û����������æ��\n";
		return msg;
	}

	if(query_temp("count")>=6)
	{
		msg="��ϧ�������ѹ��ˣ�\n";
		return msg;
	}

	if ( me->query_skill("quanzhen-jian",1) <60 || me->query("combat_exp",1)<50000 ||
		  me->query_skill("dodge") <60
		)
	{
		msg = "��ϧ"+me->query("name")+"�书̫�������ϰ��������󡹡�\n";
		return msg;
	}


	me->set_temp("asked_beidouzhen",1);
	msg = "�ã���������׼������һ������������ƶ��һ����ϰ��������󡹣�\n";
	set_temp("fighter/" + time(), me->query("id") );
	me->delete_temp("qz/bdgranted" );
	add_temp("count",1);

	remove_call_out("start");
	call_out( "start", 50+ random(50) );
	return msg;
}


int start()
{
	object me = this_object();
	object ob1,ob2,ob3,ob4,ob5,ob6,ob7,ob;
	object here = environment(me);
	mapping fighter;
	int i, *times,j;
	string arg;

	if( !(fighter = me->query_temp("fighter")) )
	{
		return 0;
	}

	times = keys(fighter);
	j = 0;
	for(i = 0; i < sizeof(times); i++) {
	  if( !( ob = present( fighter[times[i]],here) ) )
		  if( !( ob = find_player( fighter[times[i]]) ) )
			continue;
	  message_vision(HIY"$N����$n������׼����\n"NOR, me,ob);
	  ob->delete_temp("asked_beidouzhen");
	  ob->move("/d/zhongnan/dajiaochang");
	  if(j==0)ob1=ob;
	  else if(j==1)ob2=ob;
	  else if(j==2)ob3=ob;
	  else if(j==3)ob4=ob;
	  else if(j==4)ob5=ob;
	  else if(j==5)ob6=ob;
	  else if(j==6)ob7=ob;
	  j++;
	}

	message_vision(HIY"$N���������ţ�\n"NOR, me);

	for( i = j;i<6;i++)
	{
	  if(i==0){ob1=new( bd_fighters[i] );ob1->move(environment(me));message_vision(HIY"$N�첽���˹�������鮵������͸�λ���־õ��ˣ�\n"NOR, ob1);}
	  else if(i==1){ob2=new( bd_fighters[i] );ob2->move("/d/zhongnan/dajiaochang");message_vision(HIY"$N�첽���˹�������鮵������͸�λ���־õ��ˣ�\n"NOR, ob2);}
	  else if(i==2){ob3=new( bd_fighters[i] );ob3->move("/d/zhongnan/dajiaochang");message_vision(HIY"$N�첽���˹�������鮵������͸�λ���־õ��ˣ�\n"NOR, ob3); }
	  else if(i==3){ob4=new( bd_fighters[i] );ob4->move("/d/zhongnan/dajiaochang");message_vision(HIY"$N�첽���˹�������鮵������͸�λ���־õ��ˣ�\n"NOR, ob4); }
	  else if(i==4){ob5=new( bd_fighters[i] );ob5->move("/d/zhongnan/dajiaochang");message_vision(HIY"$N�첽���˹�������鮵������͸�λ���־õ��ˣ�\n"NOR, ob5); }
	  else if(i==5){ob6=new( bd_fighters[i] );ob6->move("/d/zhongnan/dajiaochang");message_vision(HIY"$N�첽���˹�������鮵������͸�λ���־õ��ˣ�\n"NOR, ob6); }
	}


	arg = me->query("id") + "," + ob1->query("id") + "," + ob2->query("id") + "," +
		ob3->query("id") + "," + ob4->query("id") + "," + ob5->query("id") + "," +
		ob6->query("id");

	message_vision(HIG"$N���������������˵�����ã�ʱ���ѵ������ڿ�ʼ��ϰ��������󡹣�\n"NOR,me);
	"/d/zhongnan/dajiaochang"->do_beidouzhen2( arg );

	me->delete_temp("fighter");
	me->delete_temp("count");

	remove_call_out("killer_show");
	call_out( "killer_show",random(10),me );
}


void killer_show(object me)
{
  object ob;

  /*
  if( (ob = present("killer", environment(me))) ) {
	 ob->kill_ob(me);
	 me->kill_ob(ob);
	 return;
  }
  */

  if( !(me->query_temp("pending/beidou")) ) return;

  ob=new("/d/zhongnan/npc/killer.c");
  ob->move("/d/zhongnan/dajiaochang");
  ob->kill_ob(me);
  me->kill_ob(ob);
  message_vision(HIR"\nͻȻɽ�³���һ��$N��\n"NOR, ob);

  remove_call_out("killer_show");
  call_out( "killer_show",80+random(60),me );
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

	if ((int)ob->query_skill("xiantian-gong", 1) < 30) {
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
