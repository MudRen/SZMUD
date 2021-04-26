// Code by ShenZhou
// guard.c ɽ������
// jiuer@SZ, 12/11/2001

#include <ansi.h>

inherit NPC;

int auto_perform();
void greeting(object me);

void create()
{
	set_name( HIW"ɽ������"NOR, ({ "shou wei", "wei"}));
    set("long",
      "�����䵱���µ��ӡ�\n"
      "����ְ��������ɽ�ţ�ӭ����ͣ�������ˡ�\n"
      "����ʮ���꣬���ǿ�������ٸ�纣���������\n"
	  );
  set("gender", "����");
  set("age", 30);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("str", 30);
  set("int", 25);
  set("con", 25);
  set("dex", 35);
        
  set("max_qi", 1000);
  set("max_jing", 1000);
  set("neili", 1000);
  set("max_neili", 1000);
  set("jiali", 100);
  set("combat_exp", 300000);

  set_skill("force", 100);
  set_skill("taiji-shengong", 100);
  set_skill("dodge", 100);
  set_skill("tiyunzong", 100);
  set_skill("cuff", 100);
  set_skill("taiji-quan", 100);
  set_skill("strike", 100);
  set_skill("mian-zhang",100);
  set_skill("parry", 100);
  set_skill("sword", 100);
  set_skill("taiji-jian", 100);
  set_skill("literate", 100);
  set_skill("taoism", 100);

  map_skill("force", "taiji-shengong");
  map_skill("dodge", "tiyunzong");
  map_skill("cuff", "taiji-quan");
  map_skill("strike", "mian-zhang");
  map_skill("parry", "taiji-jian");
  map_skill("sword", "taiji-jian");

  prepare_skill("cuff", "taiji-quan");
  prepare_skill("strike", "mian-zhang");

  create_family("�䵱��", 2, "����");
  set("class", "taoist");
    
  

  set("inquiry", 
      ([
        "name" : "����ר���䵱��������ɽ�ŵġ�",
        "here" : "�������䵱�������ţ�һֱ���ϾͿɵ���������",
        "����" : "������Ĺ�������������\n",
        "����" : "������Ĺ�������������\n",
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
	object ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() )
	       {
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
}

void greeting(object me)
{
	mapping myfam;
	object where, ob;

	ob = this_object();
	myfam = (mapping)me->query("family");
	where = environment(ob);

	if( !me || !living(ob) || strsrch(file_name(where), "/d/wudang/") < 0
		|| environment(me) != environment() )
		return;

  if ( myfam && myfam["family_name"] == "�䵱��" )
    command("say ��λ��"+(((string)me->query("gender")=="Ů��")?"��":"��")+
            "�����ˣ�");
  else if ( me->query("shen") > -100 ) 
    say("ɽ���������˸�Ҿ������λ" + RANK_D->query_respect(me)
        + "���ˣ���ӭ�����䵱ɽ��\n");
  else 
    say("ɽ��������ৡ������������λ"+RANK_D->query_respect(me)
        +"����ɱ��������������䵱�������ذɣ�\n");
}

#include "/kungfu/class/wudang/auto_perform.h"
