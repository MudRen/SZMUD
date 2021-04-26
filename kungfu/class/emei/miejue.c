// Code of ShenZhou
// Npc: /kungfu/class/emei/miejue.c ���ʦ̫
// Date: xbc 96/09/24
// Modified by xQin 8/00

#include <ansi.h>
inherit F_UNIQUE;
inherit NPC;
inherit F_MASTER;

string ask_for_job();
string ask_for_join();
string ask_for_huansu();
string ask_piaoxue();
string ask_huansu();
int ask_ji();
int auto_perform();
int check_score(mixed);
int start_miejue_event(object, object);

void create()
{
	set_name("���ʦ̫", ({ "miejue shitai", "miejue", "shitai" }));
	set("long", 
		"һ���׷���Ȼ�����ᣬ���Ƕ��������������ʦ̫��\n"
		"����ò��ü�����������üëбб�´���һ��������ü��ǹ��죬\n"
		"�����е��Ϸ̨�ϵĵ�����ζ����\n");

	set("gender", "Ů��");
	set("attitude", "heroism");
	set("class", "bonze");

	set("age", 45);
	set("shen_type", 1);

	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("max_qi", 3500);
	set("max_jing", 3500);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 150);
	set("combat_exp", 3000000);
	set("score", 8000);
	set("PKS", 100000000); //Ryu: Avoid Yitian-jian be begged away!!!

	set_skill("force", 380);
	set_skill("linji-zhuang", 380);
	set_skill("claw", 320);
	set_skill("throwing", 320);
	set_skill("strike", 320);
	set_skill("jinding-zhang", 320);
	set_skill("finger", 300);
	set_skill("tiangang-zhi", 300);
	set_skill("sword", 360);
	set_skill("emei-jian", 360);
	set_skill("blade", 300);
	set_skill("yanxing-dao", 300);
	set_skill("parry", 300);
	set_skill("dodge", 340);
	set_skill("zhutian-bu", 340);
	set_skill("literate", 101);
	set_skill("persuading", 380);
	set_skill("mahayana", 360);

	map_skill("force", "linji-zhuang");
	map_skill("strike", "jinding-zhang");
	map_skill("finger", "tiangang-zhi");
	map_skill("sword", "emei-jian");
	map_skill("blade", "yanxing-dao");
	map_skill("parry", "jinding-zhang");
	map_skill("dodge", "zhutian-bu");

	prepare_skill("strike", "jinding-zhang");
	prepare_skill("finger", "tiangang-zhi");

	create_family("������", 3, "������");

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}));

	set("inquiry",([
		"����"  : (: ask_for_join :),
		"Ʈѩ����"  : (: ask_piaoxue :),
		"Ʈѩ������"  : (: ask_piaoxue :),
		"����ܽ" : (: ask_ji :),
		"����" : (:ask_for_huansu:),
                "job" : (:ask_for_job:),
	]));

	setup();
	if( clonep() )
	{
		carry_object("/clone/weapon/yitian-jian");
		//carry_object(__DIR__"obj/xtring")->wear();
		carry_object("/d/emei/npc/obj/nun-cloth")->wear();
		carry_object("/d/emei/npc/obj/emei-shoes")->wear();
	}
}

int ask_ji()
{
	object me = this_player();

	if( !me->query("emei/ji_killer") )
		message_vision(CYN "���ʦ̫˻����ɤ��˵��������Ȳ�֪���ܵ���ͽ�������������к��ã���\n"NOR, me);
	else
	{
		switch( me->query_temp("emei/asked_ji") )
		{
			case 0 : command("hmm " + me->query("id")); break;
			case 1 : command("consider " + me->query("id")); break;
			case 2 : command("hit " + me->query("id")); break;
			case 3 : command("kill " + me->query("id")); break;
		}
		me->add_temp("emei/asked_ji", 1);
	}
	return 1;
}

int accept_object(object ob, object obj)
{
	object me = this_object();
	mapping family = me->query("family");
	int mudage = me->query("mud_age");

	if( obj->query("id") == "ji xiaofu" )
	{
		command("thank " + ob->query("id"));
		ob->set("emei/ji_killer", 1);
		if( family["family_name"] == "������" )
			me->set("emei/loyal2mj", mudage+random(mudage/2));
		call_out("ji_event", 2, me, obj, 1);
		return 1;
	}

	return 0;
}

int ji_event(object miejue, object ji, int stage)
{
	string msg;

	switch( stage )
	{
		case 1 :
			msg = "";
			if( !living(ji) )
			{
				message_vision(CYN"$NͻȻ��ת����ȥ����ָ��$n����Ѩ��һ����\n"NOR, miejue, ji);
				ji->revive();
			}
			ji->start_busy(20);
			break;
		case 2 :
			msg = "$N������$n��������������һ�Σ���Ը��Ը��ȥ��ɱ�Ǹ�"
			"ħ�̵���ͽ������\n�󹦸��֮����������ң��ұ㽫�²������콣������"
			"���㣬����Ϊ�������ŵļ̳��ˡ���\n";
			break;
		case 3 :
			msg = "$n��ͷ��˼�����ڼ����ҡ��ҡͷ�����ǲ������ʦ��֮����\n";
			break;
		case 4 :
			msg = "ֻ��$N�������ƣ���Ҫ���䣬������ͣ�ڰ�գ�ȴ�����£�������$n������ڻ���ת�⡣\n";
			break;
		case 5 :
			msg = "ֻ��$nͻȻ˫ϥ��أ�ȴ�����ҡ��ҡͷ��\n";
			break;
		case 6 :
			msg = "$N�������䣬����$n�Ķ��š�\n";
			ji->receive_wound("qi", ji->query("max_qi")+200);
			break;
	}
	message_vision(CYN+msg+NOR, miejue, ji);
	if( stage < 6 ) call_out("ji_event", 1, miejue, ji, ++stage);

	return 1;
}

void attempt_apprentice(object ob)
{
  mapping fam;
  string name, newname;

  if (!mapp(fam = ob->query("family")) || (string)ob->query("family/family_name") != "������")
    {
      command ("say " + RANK_D->query_respect(this_player())
               + "�����Ҷ��������ˣ�ϰ�仹���ȴ��ҵĵ������￪ʼ�ɡ�");
      return;
    }

  if (ob->query("class") != "bonze" 
      && ob->query_int() < 38+2*(int)(ob->query("gender")=="����") ) {
    // can't input chinese now, shall add some words here later
    command("say �����ӷ�ƶ�᲻���׼ҵ��ӡ�");
    return;
  }

  if ((int)ob->query_skill("linji-zhuang", 1) < 90 ) {
    command("say �Ҷ��������ڼ��书���������ڹ��ķ�����Ӧ�����ټ�ʮ��ׯ�϶��µ㹦��"); 
    return;
  }

  if ((int)ob->query("shen") < 0) 
    {
      command("hmm " + ob->query("id"));
      command("say �Ҷ��������������������ɣ��Ե���Ҫ���ϡ�");
      message_vision(
                     "$n����$N˵�������������������ʦ��֪�����Ҳ����㣬����ȥ������������������ɡ�\n",
                     ob, this_object() );
      return;
    }

  command("say �ðɣ������������㡣ϣ�����ܽ����Ҿ�������");
  if (fam["generation"] != 4 && ob->query("class") == "bonze" ) {
    name = ob->query("name");
    newname = "��"+name[2..3];
    ob->set("name", newname);
    command("say �ӽ��Ժ�����������¾��ֱ����ӣ�����"+newname+"��");
    command("chat " + name + "�������£���Ϊ�����ɾ��ֱ����ӣ�����"+newname+"��");
  }
  command("recruit " + ob->query("id"));

}


void init()
{
	int score;
	object ob;

  add_action("do_kneel", "kneel");

  ::init();
  set_heart_beat(1);

  if (interactive(ob=this_player()) 
      && ob->query("family/master_id") == "miejue shitai"
      && ob->query("shen") < -100) 
    {
      message_vision(
                     "$n����$N˵��������ô����������£�\n",
                     ob, this_object() );
      command("say �Ҷ��������������������ɣ�" +
              "�Ե���Ҫ���ϡ��Ҳ����������㣬��ȥ�ɡ�\n");
      command("expell " + ob->query("id"));
      return;
    }
  if (interactive(ob=this_player())
      && this_object()->is_killing(ob->query("id"))
      || present("yitian jian", ob))
    {
      set_leader(ob);
      kill_ob(ob);
      return;
    }
	if( interactive(ob=this_player()) &&
	ob->query("loyal2mj") + 10000 > ob->query("mud_age") &&
	this_object()->query("eff_qi") < this_object()->query("max_qi")/5 &&
	(score = check_score(ob)) > 13 )
		start_miejue_event(this_object(), ob);
}

int check_score(mixed arg)
{
	int i, exp, rate, lvl, mark = 1;
	object me, xqin;
	string *skills;
	mapping family;

        if( stringp(arg) ) me = find_living(arg);
        else if( objectp(arg) ) me = arg;
        else return 0;
        if( !objectp(me) ) return 0;
	xqin = find_player("xqin");

	exp = me->query("combat_exp");
	rate = exp / ( me->query("age")-14 );
	family = me->query("family");
	skills = ({ "linji-zhuang", "emei-jian", "yanxing-dao", "jinding-zhang",
		    "tiangang-zhi", "zhutian-bu" });

	if( rate >= 90000 ) mark += 5;
	else if( rate >= 80000 ) mark += 4;
	else if( rate >= 70000 ) mark += 3;
	else if( rate >= 60000 ) mark += 2;
	else if( rate >= 50000 ) mark += 1;
	tell_object(xqin, "for get exp speed, "+me->name()+" have get "+mark+" marks\n");

	for( i=0; i < sizeof(skills); i++ )
	{
		lvl = me->query_skill(skills[i], 1)+10;
		if( lvl*lvl*lvl > exp*10 )
		{
			mark += 1;
			tell_object(xqin, me->name()+" have gain 1 mark for "+skills[i]+" skill\n");
		}
	}

	if( family["master_name"] == "���ʦ̫" && family["master_id"] == "miejue shitai" )
		mark += 3;
	switch( me->query("betrayer") )
	{
		case 0 : mark += 3; break;
		case 1 : mark += 1; break;
	}

	if( me->query("class") == "bonze" ) mark += 2;
	else if( !me->query("married_times") ) mark += 2;

	tell_object(xqin, me->name()+" have get "+mark+" marks for total score!\n");
	return mark;
}

string ask_piaoxue()
{
  object db;
  string msg="";
  int    rate, history;
  mapping info;
  object player = this_player();

  if (!mapp( player->query("family")) || (string)player->query("family/family_name") != "������")
    {
      command ("say " + RANK_D->query_respect(player)
               + "�����Ҷ��������ˣ���֪�˻��Ӻ�˵��");
      return 0;
    }

  db = find_object("/clone/obj/skill_db");
  if (!objectp(db)) db = new("/clone/obj/skill_db");
  if (!objectp(db)) return "ʲô��";

  info=db->update_usage("piaoxue", this_object(), 0, 0);
  // temporarily set the history
  if (time()-info["last_use"] > info["history"]) {
    history = info["history"];
    info["history"] = time() - info["last_use"];
  }
  rate = db->compute_rate(info);
  info["history"] = history;

  if (rate <= 10) {
    msg = "����һ�಻�����ĵ����ǵ�������Ʈѩ�����ƣ�����Ѳ���ʲô��������";
  }else if (rate <= 50) {
    msg = "�ף�Ʈѩ������Ҳ����ʲô��µĹ�����ʦ��û����ô��";
  }else if (rate <= 100) {
    msg = "Ʈѩ���������Ƕ�ü�Ʒ���Ҫ���ҵ�ͽ���Ƕ���ɡ�";
  }else if (rate <= 200) {
    msg = "Ʈѩ��������ʵĪ�⣬�˵������޷��������ü��Ҳ���һ�ʹ����";
  }else {
    msg = "�����ഫ��Ʈѩ��������ʵĪ�⣬���ǽ����ϵ�һ�����ܡ�";
  }
  remove_call_out("more_piaoxue");
  call_out("more_piaoxue", random(20), player, rate);
  return msg;
}

void more_piaoxue(object player, int rate) 
{
  object me = this_object();
  object room = environment(me);

  if (environment(player) != room) return;

  message_vision("\n���ʦ̫���˶٣���$N��ͷ�����ðɣ����Ҿͽ̽���ɡ�\n", player);
  message_vision("$N˵����Ʈѩ�����������ڼ��������������ǰ�����ʹ��������˸��\n"+
        "�õ���������ͷ�ԡ�������Ҫ���䲻����ǧ�򲻿��ڽ��������á�\n", me);
  if (rate <= 10) return;

  if (random(rate) < 30) 
      message_vision("\n$N����˵����������ʹʱ�������һʵ������һʵ���˻�����һʵ��\n"+
        "����Ҫ���õ��˲��������ȴ�ֲ���Ҫ�죬Ȼ�����ֱ�롣\n", me);
  if (rate <= 30) return;

  if (random(rate) < 50) 
      message_vision("\n$N����˵����Ʈѩ������ʹ��ȥ����˲���ȫ�������\n"+
        "��ʱ���������Ȼ����������������°빦����\n", me);
  if (rate <= 50) return;

  if (random(rate) < 100)
      message_vision("\n$N����˵�����ټ�׮���Ƕ�üһ������Ʈѩ������ҲҪ���úܡ�\n"+
        "���ǵ���Ҳ�����ټ�׮���ǾͲ���Ҳ�ա�\n", me);
  if (rate <= 100) return;
        
  if (random(rate) < 300)
      message_vision("\n$N����˵�����Ʒ���ָ��������¯���࣬����ʹ�÷���˳�֡�\n"+
        "�������ϵ��˶��ý����ƻ���ȭ�����ң��Ǿͼ���Щ��\n", me);
  if (rate <= 300) return;

  me->command("whisper "+player->query("id")+" ����Ҫ��������Ҫ�������һ���͸�ɣ�\n");
  
}

int accept_fight(object me)
{
  write("���ʦ̫һ����Ц���㲻����ҹ��С�\n");
  return 0;
}
int accept_kill(object me)
{
  command("say ����������ɱ�ţ��������㵹ù��\n");
  if (present("yitian jian", this_object())){
    command("wield yitian jian");
  }
  set_leader(me);
  kill_ob(me);
  return 1;
}



#include "/kungfu/class/emei/auto_perform.h"
#include "/kungfu/class/emei/nun.h"
#include "./persjob.h"
