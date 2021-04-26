// Code of ShenZhou
// /kungfu/class/quanzhen/qiu.c
// qiu.c �𴦻�
// sdong 08/01/98

inherit NPC;
inherit F_MASTER;

string ask_me();
string ask_job();
void reward_dest(object obj,object ob);
void thank_dest(object obj,object ob);

int auto_perform();

void create()
{
	set_name("�𴦻�", ({ "qiu chuji", "qiu" }));
	set("nickname", "������");
	set("long",
		"������ȫ���������ʢ�����𴦻������ų����ӣ�����ȫ����ƽ����ˡ�\n"
		"���������ʮ����Ŀ��࣬������⣬�������\n");
	set("gender", "����");
	set("age", 69);
	set("attitude", "heroic");
	set("shen_type", 1);
	set("str", 27);
	set("int", 25);
	set("con", 25);
	set("dex", 26);


		  set("max_qi", 3200);
        set("max_jing", 2100);
        set("neili", 2800);
        set("max_neili", 2800);
		  set("jiali", 80);
		  set("combat_exp", 1000000);
		  set("score", 5000);

		  set_skill("force", 170);
		  set_skill("dodge", 150);
		  set_skill("parry", 150);
		  set_skill("sword", 160);
		  set_skill("strike", 150);
		  set_skill("cuff", 150);

	set_skill("xiantian-gong", 170);
	set_skill("jinyangong", 150);
	set_skill("chunyang-quan", 150);
	set_skill("sanhua-juding", 150);
	set_skill("quanzhen-jian", 160);
	set_skill("literate", 150);
	set_skill("taoism", 160);

	map_skill("force", "xiantian-gong");
	map_skill("dodge", "jinyangong");
	map_skill("cuff", "chunyang-quan");
	map_skill("strike", "sanhua-juding");
	map_skill("parry", "quanzhen-jian");
	map_skill("sword", "quanzhen-jian");

	prepare_skill("cuff", "chunyang-quan");
	prepare_skill("strike", "sanhua-juding");

	set("class","taoist");

	create_family("ȫ���", 2, "���ӡ��ƽ�����");

	set("inquiry", ([
		"�ؼ�" : (: ask_me :),
		"miji" : (: ask_me :),
		"����" : (: ask_job :),
		"job" : (: ask_job :),
	]));

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );

	set("book_count", 3);
	set_temp("job_pos",10);


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

	if ((int)ob->query_skill("xiantian-gong", 1) < 80) {
		command("say ��ȫ������ڼ��书���������ڹ��ķ���");
		command("say " + RANK_D->query_respect(ob) +
			"�Ƿ�Ӧ�����������칦�϶��µ㹦��");
		return;
	}

	if ((int)ob->query("shen") < 50000) {
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

string ask_me()
{
	mapping fam;
	object ob, *obs,ob2 ;

	if (!(fam = this_player()->query("family")) || fam["family_name"] != "ȫ���")
		return RANK_D->query_respect(this_player()) +
		"�뱾��������������֪�˻��Ӻ�̸��";

	if (query("book_count") < 1)
		return "�������ˣ����ɵ��ڹ��ķ����ڴ˴���";

	obs = filter_array(children(__DIR__"force_book.c"), (: clonep :));
		  if (sizeof(obs) > 2)
		return "�������ˣ����ɵ��ڹ��ķ����ڴ˴���";

	ob=new(__DIR__"force_book");
	ob->move(this_player());
	add("book_count", -1);
	command ("rumor "+this_player()->query("name")+"Ū����һ�������ڹ��ķ���");
	return "�ðɣ��Ȿ�������ڹ��ķ������û�ȥ�ú����С�";
}


string ask_job()
{
	  mapping job_stat;
	  object ob2;
	  object ob = this_player();
	  object me = this_object();

	  job_stat = ob->query_temp("qz_caiyao");

	  if ( ob->query("family/family_name") != "ȫ���" )
					 return "��λ"+RANK_D->query_respect(ob)+"����ȫ��̵��ӣ�����ͷ���\n";

	  if(job_stat){
				command("hmm "+ob->query("id"));
				return "�㻹û������񣬾�����Ҫ�µģ�\n";
	  }

	  if ( me->query_temp("job_pos") == 0 ) {
					 return "����ûʲôҪ������ȥ������ȥ��Ϣ�ɡ�\n";
	  }

	  me->add_temp("job_pos", -1);

	  command("nod");
	  command("say �ã���������õĲ�ҩ�������ˣ���ȥɽ��������ȥ��һЩ������");
	  ob2 = new("/d/zhongnan/obj/yaochu");
	  ob2->move(me);
	  ob->set_temp("qz_caiyao",1);
	  command("give yao chu to "+ob->query("id"));

	  return "��ȥ��أ�·��ҪС��һЩ��\n";
}

int accept_object(object me, object obj)
{
		  object ob = this_player();

		  command( "say "+obj->name()+"?");

		  if (
				 obj->query("id") == "chuanbei" ||
				 obj->query("id") == "fuling" ||
				 obj->query("id") == "gouzhi zi" ||
				 obj->query("id") == "heshouwu" ||
				 obj->query("id") == "huanglian" ||
				 obj->query("id") == "jugeng" ||
				 obj->query("id") == "jinyin hua" ||
				 obj->query("id") == "shengdi"
			)
			{

			  if ( ob->query("family/family_name") == "ȫ���" ) {
					 remove_call_out("reward_dest");
					 call_out("reward_dest", 1, obj, ob);
			  }
			  else {
					 remove_call_out("thank_dest");
					 call_out("thank_dest", 1, obj, ob);
			  }

			  return 1;
		  }

		  command( "hmm" );
		  command( "say ������ⶫ����ʲ�᣿" );

		  return 0;
}

void reward_dest(object obj,object ob)
{
	object yaochu = present("yao chu",this_player() );
   if(yaochu)destruct(yaochu);
	command( "pat "+ob->query("id"));
	command( "say "+ob->query("name")+"�ɵĲ�����ȥ��Ϣһ�°ɣ�\n");
	if(ob->query_temp("qz_caiyao",1) )
	{
		ob->delete_temp("qz_caiyao");
		add_temp("job_pos", 1);
	}
	destruct(obj);
}


void thank_dest(object obj,object ob)
{
	command( "jump");
	command( "say ���Ǻ���Ҫ��Щҩ�ģ���л����\n");
	destruct(obj);
}





#include "auto_perform.h"

