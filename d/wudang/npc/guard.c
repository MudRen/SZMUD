// Code by ShenZhou
// guard.c 山门守卫
// jiuer@SZ, 12/11/2001

#include <ansi.h>

inherit NPC;

int auto_perform();
void greeting(object me);

void create()
{
	set_name( HIW"山门守卫"NOR, ({ "shou wei", "wei"}));
    set("long",
      "他是武当门下弟子。\n"
      "他的职务是守卫山门，迎接香客，驱逐敌人。\n"
      "他三十多岁，体格强健，发髻高绾，两眼有神。\n"
	  );
  set("gender", "男性");
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

  create_family("武当派", 2, "弟子");
  set("class", "taoist");
    
  

  set("inquiry", 
      ([
        "name" : "我是专在武当负责守卫山门的。",
        "here" : "这里是武当的玄岳门，一直南上就可到紫霄宫。",
        "守卫" : "我这里的工作就是守卫。\n",
        "工作" : "我这里的工作就是守卫。\n",
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

  if ( myfam && myfam["family_name"] == "武当派" )
    command("say 这位道"+(((string)me->query("gender")=="女性")?"姑":"兄")+
            "辛苦了！");
  else if ( me->query("shen") > -100 ) 
    say("山门守卫作了个揖道：这位" + RANK_D->query_respect(me)
        + "请了，欢迎来到武当山！\n");
  else 
    say("山门守卫「唰」抽出长剑：这位"+RANK_D->query_respect(me)
        +"满脸杀气，如果不是来武当敬香就请回吧！\n");
}

#include "/kungfu/class/wudang/auto_perform.h"
