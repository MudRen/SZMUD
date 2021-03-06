// /NPC 蒙面女郎

#include <ansi.h>

inherit NPC;
int auto_perform();
void create()
{
	set_name("蒙面女郎", ({ "nv lang", "nv"}));
	set("long",
	    "这是个身材娇好的女郎, 轻纱遮面,\n"
	    "一双秀目中透出一丝杀气。\n"
	   );
	set("gender", "女性");
	set("age", 20);
	set("shen_type",0);
	set("attitude", "peaceful");

	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("qi", 5000);
	set("max_qi", 5000);
	set("jing", 3000);
	set("max_jing", 3000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 50);

	set("combat_exp", 500000);
	set("score", 100000);
	set_skill("force", 170);
	set_skill("dodge", 170);
	set_skill("parry", 170);
	set_skill("hand",170);
	set_skill("strike", 170);
	set_skill("sword",170);
	set_skill("literate",170);
	set_skill("music",170);

	set_skill("zhemei-shou",170);
	set_skill("liuyang-zhang",170);
	set_skill("tianyu-qijian",170);
	set_skill("yueying-wubu",170);
	set_skill("bahuang-gong", 170);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");

	prepare_skill("strike","liuyang-zhang");
	prepare_skill("hand","zhemei-shou");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
	create_family("灵鹫宫",3,"弟子");
	setup();
	carry_object("/d/lingjiu/obj/heiyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver",15);
}

void init()
{
	object me=this_player(1),ob=this_object();
	mapping fam;
	if ( !(fam=me->query("family")) || fam["family_name"]!="灵鹫宫" && present("wu laoda",environment())) {
		remove_call_out("greeting");
		call_out("greeting",1,me);
	}else{
		remove_call_out("getwu");
		call_out("getwu",1,me);
	}
}
void greeting(object me)
{
	message_vision("$N急忙往后一跃，跳出战圈，大叫到：“且慢动手，两位姐姐看清楚我是谁！”\n",me);
	command("say “管你是谁，还不束手就擒！”\n");
	kill_ob(me);
	remove_call_out("dest");
	call_out("dest",15,this_object());
}

void die()
{
	object ob=present("wu laoda",environment(this_object()));
	if(!ob->query_temp("nvlang")){
			ob->set_temp("nvlang",1);
	}else {
		tell_room(environment(),HIY"\n乌老大慢慢的醒了过来...\n"NOR);
		ob->revive(30);
		ob->delete_temp("ask/dahui");
		ob->delete_temp("nvlang");
	}
	tell_room(environment(),HIB"\n蒙面女郎虚晃一招，迷惑你的视线，一个倒纵。往灵鹫宫而去。\n"NOR);
	destruct(this_object());
}

void unconcious()
{
	this_object()->die();
}

void getwu(object me)
{
	object ob1;
	message_vision(HIW"$N急忙往后一跃，跳出战圈，大叫到：“且慢动手，两位姐姐看清楚我是谁！”\n"NOR,me);
	command("look "+me->query("id"));
	command("say “哦，原来是灵鹫宫的姐妹，冒昧出手，不好意思，我等还有要事在身，"+
			"先走一步了。”\n");
	if (ob1=present("wu laoda",environment(this_object()))) {
		destruct(ob1);
	       	say(HIG"说罢背起乌老大，往灵鹫宫而去。\n"NOR);
		me->set_temp("quest",1);
	}
	destruct(this_object());
}

int dest(object obj)
{
	object ob1;
       	if (this_player()->is_ghost() || this_player()->is_corpse())
		 tell_room(environment(),"黑衣少女一收招，说道：“出手稍重了点，竟然打死了？算了。”\n");
	if ( !obj->is_fighting()) {
		tell_room(environment(),"黑衣少女一收招，说道：“可惜被他溜了。”\n");
		if (ob1=present("wu laoda",environment(this_object()))) {
		       	tell_room(environment(),HIG"说罢背起乌老大，往灵鹫宫而去。\n"NOR);
			destruct(ob1);
		}
		destruct(obj);
		return 1;
	}
	remove_call_out("dest");
	call_out("dest",15,obj);
	return 0;
}

#include "/kungfu/class/lingjiu/auto_perform.h"