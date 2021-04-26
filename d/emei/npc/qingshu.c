// Code of ShenZhou
// Jay 9/30/96
// Modified 6/00 -xQin
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("������", ({ "song qingshu", "song", "qingshu" }));
	set("long", 
		"�����䵱��ͽ��Զ�ŵĴ���ӣ��书��˵���䵱���������������ߡ�\n"
		"�����Ű�ɫ���ۣ��ֳֳ�������òӢ������ֹ���ס�\n");
	set("gender", "����");
	set("age", 25);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	
	set("max_qi", 800);
	set("max_jing", 800);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 30);
	set("combat_exp", 100000);

	set_skill("force", 60);
	set_skill("taiji-shengong", 60);
	set_skill("dodge", 60);
	set_skill("tiyunzong", 60);
	set_skill("strike", 60);
	set_skill("mian-zhang", 60);
	set_skill("parry", 60);
	set_skill("sword", 60);
	set_skill("taiji-jian", 60);
	set_skill("taoism", 60);
  	set_skill("literate", 80);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("strike", "mian-zhang");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	prepare_skill("strike", "mian-zhang");

	create_family("�䵱��", 3, "����");
	set("class", "taoist");

	set("inquiry", 
		([
			"������" : (: ask_me :),
			"��Զ��" : "���ǼҸ���\n",
			"������" : "����ʦ�档\n",
			"����" : "�ҵ�ʦ�ܣ������У����¾���õ����١�\n",
		]));
                                

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/whiterobe")->wear();
}

void attempt_apprentice(object ob)
{
	mapping fam;

	if( mapp(fam = ob->query("family")) && fam["family_name"] != "�䵱��" 
	&&  ob->query("combat_exp") >= 10000 )
	{
		command ("say " + RANK_D->query_respect(this_player()) + "��" 
			+ fam["family_name"] + "���书���֣���ɽ�ɲ���������");
		return;
	}

	if ((int)ob->query("shen") > 0) {
		command("say " + RANK_D->query_respect(ob) +
			"����ȥ����ʦ�ܹ���ɡ�");
		return;
	}

	command("say �ðɣ�ƶ�����������ˡ�");
	command("recruit " + ob->query("id"));
}

string ask_me()
{
        object me;

        me = this_player();
           message("vision",
   HIY "�������ŭ������Ҳ�����Ů�������⣿����\n"
       "���������ɱ��" + me->name() +"\n"
   NOR, environment(), this_object() );
                   kill_ob(this_player());
   return "\n";
}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()
		&& (string)environment()->query("short") == "С����") {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object me)
{
        if (me->query("shen")<0) {
          command("say "+ RANK_D->query_rude(me) +"Ҳ��͵�üŮ�����޹���С��"
		"��ү�������㣡");
	  return ;
	}
	if (me->query_temp("miekou")) return;
	command("hi " + me->query("id"));
	command("say С���ڴ˾ú��ˡ�");
	command("follow "+me->query("id"));
	me->set_temp("miekou",1);
	remove_call_out("miekou");
	call_out("miekou", 3, this_object(), me);
	command("hehe song");
	return ;
}

int miekou(object song, object me)
{
	command("say ������������͵�üŮ���޹����������ȥ���һ������ڽ������߶���");
	tell_object(me,"��������ɱ����ڣ�\n");
        kill_ob(me);
	return 1;
}

