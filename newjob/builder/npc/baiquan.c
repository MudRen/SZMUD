// newjob/builder/
// Jiuer 11/2001
// baiquan.c 石百泉

#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void greeting(object);

void create()
{
	set_name("石百泉", ({ "shi baiquan", "shi", "baiquan" }));
	set_color("$YEL$");
	set("title","石铺老板");
	set("shen_type", 0);
	set("gender", "男性");
	set_max_encumbrance(100000000);
	set("age", 65);
	set("long", "这是一位满脸皱纹的干瘦小老头，他头戴一顶书生帽，
身穿一件黑色长袍，听人说这老头还中过当地的举人。\n");
	set("no_get_from", 1);			
	
	set("max_jing", 5000);			//最大精
	set("jing", 5000);				//精
	set("max_jingli", 500);			//最大精力
	set("jingli", 500);				//精力
	set("max_qi", 500);				//最大气
	set("qi", 500);					//气
	
	set_skill("force", 100);		//内功
	set_skill("parry", 100);		//招架
	set_skill("unarmed", 100);		
	set_skill("dodge", 100);		//轻功
	set_temp("apply/attack", 120);
	set_temp("apply/attack", 120);
	set_temp("apply/damage", 50);
	
	set("combat_exp", 40000);		//经验
	set("attitude", "friendly");	
		
	set("vendor_goods", ({
		 "/newjob/builder/obj/chisel",		//石凿
 		 "/newjob/builder/obj/hammer",		//锤子
      // "/newjob/builder/obj/explosive",   //炸药
		 "/newjob/builder/obj/axe",			//斧	
         "/newjob/builder/obj/saw",         //锯
		 "/clone/drug/jinchuang",			//金创药
		 "/clone/drug/gaoyao",				//狗皮膏药
	}) );
	setup();
	
	carry_object("/newjob/builder/obj/pao")->wear();	//衣服
}

void init()
{

	object ob;

	::init();
    if( interactive(ob = this_player()) && !is_fighting() && !query_temp("leading")) {
		remove_call_out("greeting");
        call_out("greeting", 1, ob);
	}

	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
    switch( random(2) ) {
	     case 0:
			 say(query("name")+"笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				 + "，可要买什么器具？\n");
			 break;
	     case 1:
			 say( query("name")+"笑咪咪地拱了拱手，说道：这位" + 
       RANK_D->query_respect(ob)+ "，请进请进。\n");
		     break;
	}
}

void unconcious()
{
	message_vision("\n突然，只见$N闪身拉开柜台下一道暗门，钻了进去，咔嚓从里边把门锁上了。\n", 
		this_object());
	destruct(this_object());
}

void die()
{
	message_vision("\n$N死了。\n", this_object());
	destruct(this_object());
}

int accept_kill(object me)
{
        command("say 光天化日之下竟敢行凶杀人，没王法了吗？\n");
        me->apply_condition("killer", 100);
        return 1;
}
