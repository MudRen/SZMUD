// /NPC li.c 
// By Xuanyuan 12/7/2001

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int auto_perform();
int ask_youming();
int ask_guizhao();

void create()
{
	set_name("李秋水", ({ "li qiushui", "li", "qiushui" }));
	set("long",
	    "她身着白色衣衫，身形苗条婀娜，脸上蒙了块白绸，瞧不见她面容。\n");
	set("title", "西夏国皇太妃");
	set("gender", "女性");
	set("per", 13);
	set("age", 80);
	set("shen_type",-1);
	set("attitude", "peaceful");

	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 30);

	set("max_qi", 6000);
	set("max_jing", 3200);
	set("neili", 7500);
	set("max_neili", 7500);
	set("jiali", 100);

	set("combat_exp", 3500000);

	set_skill("force", 350);
	set_skill("dodge", 350);
	set_skill("parry", 350);
	set_skill("hand",350);
	set_skill("strike", 350);
	set_skill("sword",350);
	set_skill("blade",350);
	set_skill("literate",100);
	set_skill("music",350);
	set_skill("claw",350);

	set_skill("youming-guizhao",350);
	set_skill("zhemei-shou",350);
	set_skill("liuyang-zhang",350);
	set_skill("tianyu-qijian",350);
	set_skill("yueying-wubu",350);
	set_skill("bahuang-gong", 350);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "youming-guizhao");
	map_skill("sword", "tianyu-qijian");
	map_skill("claw", "youming-guizhao");

	prepare_skill("claw","youming-guizhao");

	set("inquiry", ([
		"幽冥鬼爪" : (: ask_youming :),
		"亡魂鬼爪" : (: ask_guizhao :),
	]));
	set("lingjiu/guizhao",1);

	create_family("灵鹫宫",1,"弟子");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
	setup();
	carry_object("/d/zhongnan/obj/baipao")->wear();
}

void init()
{
	object ob = this_player();

	add_action("do_learn","learn");
	add_action("do_learn","xue");
	::init();
	if (ob->query_skill("beiming-shengong") && ob->query("id") != "wuya zi" || 
		ob->query_skill("lingbo-weibu") && ob->query("id") != "wuya zi" ) {
//	if (ob->query("got_beiming")) {
		message_vision(HIY "$N突然对$n喝到：居然擅闯琅寰福地，留下你的命吧！\n"NOR, this_object(), ob );
		kill_ob(ob);
	   }
}

int ask_youming()
{
        object ob = this_player();
        
        if (ob->query("family/family_name") != "灵鹫宫") {
                command("sneer");
                command("say 师姐却不知我练了这幽冥鬼爪，等她闭关还童之时要叫她受点苦头。");
                return 1;
        }
		if (ob->query("family/master_name") == "天山童姥") {
                command("say 师姐派你来偷学我的幽冥鬼爪？那就让你见识见识！");
				kill_ob(ob);
				return 1;
		}     
        if (ob->query("lingjiu/li")) {
                command("say 我不是已经开始教你了么？");
                return 1;
        }
        if (ob->query_skill("claw",1) < 99) {
                command("say 要使用这样的绝招需要高深的爪法，你还是多练习练习再说吧。");
                return 1;
        }
		command("say 好，我就教你这套“幽冥鬼爪”，将来帮我对付那个贱人！\n");
        ob->set("lingjiu/li", 1);
        return 1;
}
int ask_guizhao()
{
        object ob = this_player();
        
        if (ob->query("family/family_name") != "灵鹫宫") {
                command("sneer");
                command("say 师姐却不知我练了这幽冥鬼爪，等她闭关还童之时要叫她受点苦头。");
                return 1;
        }
		if (ob->query("family/master_name") == "天山童姥") {
                command("say 师姐派你来偷学我的幽冥鬼爪？那就让你见识见识！");
				kill_ob(ob);
				return 1;
		}     
        if (!ob->query("lingjiu/li")) {
                command("say 谁叫你来偷学我武功的？");
                return 1;
        }
        if (ob->query_skill("claw",1) < 180) {
                command("say 要使用这样的绝招需要高深的爪法，你还是多练习练习再说吧。");
                return 1;
        }
        if (ob->query_skill("youming-guizhao",1) < 180) {
                command("say 要使用这样的绝招需要高深的爪法，你还是多练习练习“幽冥鬼爪”再说吧。");
                return 1;
        }

		command("say 好，我就教你一式“亡魂鬼爪”，将来帮我对付那个贱人！\n");
        ob->set("lingjiu/guizhao", 1);
        return 1;
}
int do_learn(string arg)
{
	object me=this_player();
	string skill, teacher, skill_name;
	object ob;
	int master_skill, my_skill, gin_cost, rand;

        if (me->is_busy())
                return 0;

	if(!arg || (sscanf(arg, "%s %s", teacher, skill)!=2 ))
		return 0;
	if (teacher != "li" && teacher != "qiushui" && teacher != "li qiushui")
		return 0;
	if( me->is_fighting() )
		return 0;
	if( !(ob = present(teacher, environment(me))) || !ob->is_character()) {
		write("你要向谁求教？\n");
		return 1;
	}
	if( !living(ob) ) {
		write("嗯....你得先把" + ob->name() + "弄醒再说。\n");
		return 1;
	}
	if( !me->query("lingjiu/li")) {
		write("李秋水对着你喝道：谁叫你来偷学我武功的？\n");
		return	1;
	}
	if (me->query("family/master_name") == "天山童姥") {
		command("say 你既已拜入我师姐门下，还来学我这幽冥鬼爪做什么！");
		me->delete("lingjiu/li");
		kill_ob(me);
		return 1;
		}     
	if (skill != "youming-guizhao" && skill != "幽冥鬼爪") {
		write("这项技能你恐怕必须找别人学了。\n");
		return 1;
	}
	my_skill = me->query_skill(skill, 1);
	master_skill = ob->query_skill(skill, 1);
	if( my_skill >= master_skill ) {
		write("你在幽冥鬼爪上的造诣已经不下李秋水了！\n");
		return 1;
	}
	if( !SKILL_D(skill)->valid_learn(me) ) {
		write("你必须是空手并且有足够的内功和内力才可以学习幽冥鬼爪。\n");
		return 1;
	}
	gin_cost = 150 / (int)me->query("int");

	if( !my_skill ) {
		gin_cost *= 2;
		me->set_skill(skill,0);
	}
	rand = random(20);
	if (rand == 4)
		gin_cost *= 2;
	else if (rand == 15)
		gin_cost += 4;
	if( (int)me->query("potential") < 1 ){
		write("你的潜能已经发挥到极限了，没有办法再学了。\n");
		return 1;
	}
	message_vision("$N向$n请教有关「幽冥鬼爪」的问题。\n", me, ob);
	if( (int)me->query("jing") > gin_cost ) {
		if( (string)SKILL_D(skill)->type()=="martial"
		&&	my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) {
			write("也许是缺乏实战经验，你对李秋水的讲解总是无法领会。\n");
		} 
		else {
			if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
				write("你听了李秋水的指导，对「" + skill_name + "」这一招似乎有些心得。\n");
			else
				write("你听了李秋水的指导，似乎有些心得。\n");
			me->add("potential", -1);
			me->improve_skill(skill, random(me->query_int()));
		}
	} 
	else {
		gin_cost = me->query("jing");
		write("你今天太累了，结果什么也没有学到。\n");
	}

	me->receive_damage("jing", gin_cost );

	return 1;
}

int auto_perform()
{
	object me=this_object();
	object weapon=me->query_temp("weapon");
	object opp=me->select_opponent();

	if( me->query("qi",1) < 0 || me->query("jing",1) < 0 || me->query("jingli",1) < 0) return 1;

	if ( !me->is_fighting() ) {
					 if ( me->query("eff_qi") < me->query("max_qi") )
								me->exert_function("heal");
					 me->set("jiali", 50);

					 return 1;
		  }

	if ( !me->query_temp("lingjiu/youming") ) {
			return perform_action("claw.youming");
			}
			else return perform_action("claw.guizhao");
}
