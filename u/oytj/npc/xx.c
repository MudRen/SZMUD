// xx_npc.c 

#include <ansi.h>

inherit NPC;

int auto_perform();
int unarmed();
int weapon();
int do_tansan(string arg);

void create()
{
	set_name("星宿派陪练", ({"xingxiu", "xx"}));
	set("gender", "男性");
	set("age", 65);
	set("long", 
		"这个是彩虹从西域找回来的陪练，听说功夫了得。\n");
 	
	set("attitude", "peaceful");
	
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	

	set("chat_chance", 1);
	set("chat_msg", ({
		(: command("say 老子我最利害，不服气就和我比划一下！") :),
		(: command("grin") :),
	}));

	
	set("neili", 58000);
	set("eff_neili", 58000);
	set("max_neili", 54000);
	set("jingli", 54000);
	set("max_jingli", 52000);
	set("eff_jingli", 54000);
	set("jiali", 300);
	set("jiajin",30);
	
	set("combat_exp", 10400000);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
              (: auto_perform :),
        }) );

	create_family("星宿派", 2, "弟子");

	set_skill("force", 400);		
	set_skill("huagong-dafa", 400);		
	set_skill("strike", 400);
	set_skill("claw", 400);
	set_skill("sanyin-zhua", 400);	
	set_skill("tianshan-zhang", 400);	
	set_skill("dodge", 400);		
	set_skill("zhaixinggong", 400);		
	set_skill("chousui-zhang", 400);		
	set_skill("parry", 400);		
	set_skill("staff", 400);			
	set_skill("feixing-shu", 400);
	set_skill("poison", 400);

	map_skill("force", "huagong-dafa");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-zhua");
	map_skill("dodge", "zhaixinggong");
	map_skill("parry", "tianshan-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-zhua");
	

	set("inquiry", ([ 
                "unarmed"   : (: unarmed :),
                "staff"    : (: weapon :),

	]) );

	setup();
	
     carry_object("/d/xingxiu/obj/yellow-cloth")->wear();
	carry_object("/d/xingxiu/obj/blzhen");
    carry_object("/d/xingxiu/obj/lianxin");
	carry_object("/d/xingxiu/obj/sanxiao");
	carry_object("/d/xingxiu/obj/sanxiao");
	carry_object("/d/xingxiu/obj/yudi");

}

void init()
{ 
	set_heart_beat(1);
	::init();
   	add_action("do_tansan", "tansan");
}


// auto perform function (dispatched by chat_combat_msg)

int auto_perform()
{
        object me = this_object();
        object target = me->select_opponent();


        //if ( !objectp(target)
        //  || !random( (int)me->query("combat_exp") * 2
        //           / (int)target->query("combat_exp") + 1) ) return 0;

        if(random(10)>3) {
        	if( objectp(me->query_temp("weapon")) ) {
                	command("perform jinxian");
        	}
        	else
        	{
                	if( !target->query_temp("huagong") )
						    command("perform sanyin");
                	else
                        	command("blow di");
        	}
        }
        else if(random(10)>6) {
        	command("yun qisuck "+target->query("id"));
        }
        else
        {
          	if( present("sanxiao san", me) ){
          		command("throw san at " + target->query("id"));
          	}
          else if ( present("bilin zhen", me) ) {
          	command("throw zhen at " + target->query("id"));
          	}
          else if ( present("lianxin dan", me) ) {
          	command("throw dan at " + target->query("id"));
          	}
          
         }

		return 1;
		
}

int unarmed(){
	command("unwield gangzhang");
	map_skill("parry", "chousui-zhang");
	command("blow di");
	command("say 用掌法！\n");
	return 1;
}

int weapon(){
	command("wield gangzhang");
	map_skill("parry", "tianshan-zhang");
	command("say 用杖法！\n");
	return 1;
}


int do_tansan(string arg)

{
	object victim, ob, me;
	string name;
	
	ob = this_object();
	me = this_player();
	name = arg;
	

	if (!arg) return notify_fail("你要暗算谁？\n");

        //if( sscanf(arg, "%s", name) != 1 ) return notify_fail("指令错误！\n");

	if ( name == me->query("id") ) return notify_fail("你疯啦？要寻死也不必如此麻烦！\n");

	
	victim = present(name, environment(me));
        if (!victim) return notify_fail("这里并无你想暗算的目标！\n");
	if (!living(victim)) return notify_fail("你想暗算的目标不是活物！\n");

	if (name == "shunz" || name == "aha" ) return notify_fail("大胆！竟想谋害巫师！\n");

	if ( !me->query("env/invisibility") )   
		message_vision(HIR "$N诡笑着在星宿派陪练耳边私语，偷偷地伸手指了指"+victim->name()+"。\n", me);
	message("vision", HIR "只见星宿派陪练失魂落魄似的向"+victim->name()+"发动猛烈的攻击，欲制其于死地！\n" NOR, environment(me));
	
	if( present("sanxiao san", ob) )
		{
		command("throw san at "+victim->query("id"));
          	}
          else if ( present("bilin zhen", ob) ) 
          	{
          	command("throw zhen at " + victim->query("id"));
          	}
          else if ( present("lianxin dan", ob) ) 
          	{
          	command("throw dan at " + victim->query("id"));
          	}
          	
	
	return 1;

}
