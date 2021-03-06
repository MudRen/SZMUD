// NPC: /d/jueqing/npc/qiuqianchi.c
// Jiuer 08/18/2001

#include <ansi.h>

inherit NPC;

int auto_throw();
int ask_me();

void create()
{
	set_name("裘千尺", ({ "qiu qianchi", "qiu" }));
	set("long",
"这位老婆婆头发稀疏，几已全秃，脸上满面皱纹，然而双目炯炯有神。
她仅以若干树皮树叶遮体，想是在这石窟中已是年深日久，衣服都已破烂净尽。\n"
);	
	set("title" , "铁掌莲花");
	set("gender", "女性");
	set("age", 45);
	set("per",20);
	set("con",30);
	set("int",30);
	set("str", 28);
	set("dex", 30);
    set("attitude", "peaceful");
	set("shen_type",-1);
	set("combat_exp", 900000);

    set("max_qi", 3000);
	set("qi",3000);
	set("jing",3000);
	set("max_jing",3000);
	set("max_jingli",3000);
	set("jingli",3000);
	set("neili", 4000); 
	set("max_neili", 4000);
	set("jiali", 100);

	set_skill("force",200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("strike",200);
	set_skill("throwing",200);
	set_skill("tie-zhang",230);

	map_skill("force","bixuan-gong");
	map_skill("dodge","shuishangpiao");
	map_skill("strike","tie-zhang");
	map_skill("parry","tie-zhang");
	
	prepare_skill("strike", "tie-zhang");
		
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
			(: auto_throw :),
	}) );

	set_temp("apply/attack", 100);
	set_temp("apply/damage", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	
	set("inquiry", ([
		"name" : "老娘行不改姓，坐不改名，江湖上人称「铁掌莲花裘千尺」的便是。\n",
		"here" : "鬼知道这是什么地方? \n",
		"小柔" : "那个贱人。\n",
		"公孙绿萼" : "她是我宝贝女儿。\n",
		"绝情丹" : "那是我绝情谷中世代相传，解救情花之毒的丹药。\n",
		"裘千仞" : "哼，铁掌帮帮主「铁掌水上飘」，他是我二哥。\n",
		"裘千丈" : "他是我大哥，虽武功平平,却和我手足之情很深。\n",
		"公孙止" : (: ask_me :),
	]) );

	set_temp("tu",1);
	setup();
        
	carry_object("/clone/anqi/zaohu-ding")->set_amount(5);
}

void init()
{
	object ob = this_player();
	::init();	
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) 
	{
	case 0 :
		say("裘千尺发出一阵哭笑，叫道：「不错，我是鬼，我是鬼，哈哈，哈哈！」\n");
		break;
	case 1 :
		say("裘千尺说道：「二十年前我就已说过，公孙家那门功夫难练易破，不练也罢。」\n");
		break;
	}
}

int ask_me()
{
	object me = this_player();
	message("vision",
		HIY "裘千尺冷笑一声：「他就是我那个绝情绝义的丈夫，难道你是他派来杀我的吗。」\n"
       "看来裘千尺想杀死" + me->name() +"\n"NOR, environment(), this_object() );
	kill_ob(this_player());
	return 1;
}

int accept_object(object me, object obj)
{
	object obn;

	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(obj) ) return 0;
	if ( !present(obj, me) ) return notify_fail("你没有这件东西。\n");

	if (  (string)obj->query("id") != "tu")
		return notify_fail("什么？\n");
	
	if(this_object()->query("tu"))
	{
		command("bite");
		command("say 「你还不快去送丹药。」\n");
		return;
	}
	
	set("tu", 1);
	command("ah");
	message_vision("裘千尺说道：我闺女中了情花毒？\n
劳烦这位"+ RANK_D->query_respect(me)+"，我这里有「绝情丹」一枚，你快拿去交给她吧。\n
我女儿『绿萼』的命运，就托给你了。\n" , me);
    message_vision("裘千尺从怀里摸出一枚「绝情丹」交给你。\n", me);
    
    obn=new("/clone/drug/jueqing-dan");
    obn->set_amount(1);
    obn->move(me);
	return 1;
}

#include "/clone/npc/auto_throw.h";

