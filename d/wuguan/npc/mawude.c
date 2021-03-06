//Cracked by Kafei
// mawude.c 马五德
// qfy August 1, 1996

inherit NPC;
//string random_chat();
void create()
{
	set_name("马五德", ({ "ma wude", "ma", "wude" }));
	set("long", "馆主马五德豪富好客，颇有孟尝之风，人缘甚佳。\n");
        set("title", "扬威武馆馆主");
	set("gender", "男性");
	set("age", 55);

	set_skill("literate", 50);

	set_skill("hand", 70);
	set_skill("dodge", 60);
	set_skill("force", 75);
	set_skill("parry", 70);
        set_skill("literate", 10);
	set_skill("blade", 75);
	set_skill("wuhu-duanmen",55);
	set_skill("taixuan-gong",50);
	set_skill("liuxing-bu",65);
	set_skill("qinnashou",65);
	map_skill("hand","qinnashou");
	map_skill("blade","wuhu-duanmen");
	map_skill("force", "taixuan-gong");
	map_skill("dodge", "liuxing-bu");
	prepare_skill("hand","qinnashou");

	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 40000);
	set("shen_type", 1);

	set("inquiry", ([
		"学武" : "学武只须付五两银子，并可住在武馆里。",
		"学费" : "只须付五两银子。",
		"陈浒" : "他是二当家，擅于棒法(stick)，杖法(staff) 及拳法(cuff)。",
		"龙铨" : "他是刀刃部教头，以刀法(blade)和爪法(claw)见称。",
		"刘虹瑛" : "她是剑部教头，以剑法(sword)和掌下(strike)出名。",
		"萧飞" : "他是暗器部教头，擅于暗器(throwing)及指法(finger)。",
	]) );

        /*
        set("chat_chance", 50);
	set("chat_msg", (: random_chat :));
        */

	setup();

	carry_object("/clone/weapon/gangdao")->wield();
}

void init()
{
	object me = this_player();

	if ((int)me->query_temp("mark/马")){
		if (me->query("family/family_name") && (int)me->query("combat_exp") > 30000) {
			command( "say "+RANK_D->query_respect(me)+"功夫已有根底，我怕你在我这儿学不了多少东西，还请另投明师吧。");
			me->delete_temp("mark/马");
		}
	
		if (!me->query("family/family_name") && (int)me->query("combat_exp") > 8000) {
			command( "say "+RANK_D->query_respect(me)+"功夫已有根底，我怕你在我这儿学不了多少东西，还请另投明师吧。");
			me->delete_temp("mark/马");
		}	
	}
/*	if ( me->query("wuguan/pass") )
	{
		remove_call_out("get_out");
		call_out("get_out", 1, me);
	}*/
}

int accept_object(object who, object ob)
{
	object wage;

	if (who->query_temp("biao/ma") && ob->name()=="红镖") {
                who->delete_temp("biao/ma");
		who->delete_temp("apply/short");
                command( "say 有劳这位"+RANK_D->query_respect(who)+"了。");
                wage = new("/clone/money/silver");
                wage->set_amount(5);
                wage->move(who);
                message_vision("马五德给$N五两白银作为走镖的酬劳。\n", who);
                remove_call_out("destroy_it");
                call_out("destroy_it", 1, ob);
                return 1;
        }

	if (who->query("family/family_name") && (int)who->query("combat_exp") > 30000) {
		command( "say "+RANK_D->query_respect(who)+"功夫已有根底，我怕你在我这儿学不了多少东西，还请另投明师吧。");
		return 0;
	}

	if (!who->query("family/family_name") && (int)who->query("combat_exp") > 8000) {
		command( "say "+RANK_D->query_respect(who)+"功夫已有根底，我怕你在我这儿学不了多少东西，还请另投明师吧。");
		return 0;
	}
	
	if (!(int)who->query_temp("mark/马")) who->set_temp("mark/马", 0);

	if (ob->query("money_id") && ob->value() >= 500) {
		command( "say "+RANK_D->query_respect(who)+"不远千里而来，真是赏脸，请各部学习你所喜欢的功夫吧。");
		who->set_temp("mark/马", 1);
		return 1;
	}

	return 0;
}

void destroy_it(object obj)
{
	destruct(obj);
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("mark/马"))
                return 0;
        return 1;
}

/*int random_chat() {

    switch (random(200)) {
    case 0:
        command("say 欢迎到来扬威武馆。");
	return 1;
    case 1:
        command("say 学武只须付五两银子，并可住在武馆里。\n");
	return 1;
    case 2:
        command("say 萧飞是武馆的暗器部教头，并擅于指法。");
	return 1;
    case 3:
        command("say 刘虹瑛是武馆的剑部教头，同时掌下败将无数。");
	return 1;
    case 4:
        command("say 龙铨是刀刃部教头，以刀法和爪法见称。");
	return 1;
    case 5:
        command("say 二当家陈浒是棒杖部教头，拳法亦是一绝。");
	return 1;
    case 6:
        command("say 在此可学到内功，拳脚，兵器，轻功和招架。");
	return 1;
    case 7:
        command("say 欢迎来到新侠客行");
	return 1;
    case 8:
        command("say 行走江湖靠的不是武功，是朋友，多交朋友对你会有很多的帮助。");
	return 1;
    case 9:
        command("say 在想知道事情的时候就问，ask <npc名字> about all是最好的办法。");
	return 1;
    case 10:
        command("say 如果你见到了银子(silver)，没人要你可以捡(get)起来。");
	return 1;
    case 11:
        command("say 你饿了，有钱就买些东西，没钱向大侠们要一些。");
	return 1;
    case 12:
        command("say 该吃饭了，咦，怎么吃？噢：eat <食物>、drink <容器名>。");
	return 1;
    case 13:
        command("say 想去那边瞧瞧，怎么走呀？look ,看到了什么？出口，走就成了。");
	return 1;
    case 14:
        command("say nothwest太长啦，十分的不好打。那你试试nw。每个方向可以用头一个字母代替。");
	return 1;
    case 15:
        command("say 你想买东西？那你先list，看看有没有东西可买，试试buy <物品名>。");
	return 1;
    case 16:
        command("say 你想学功夫，那你得先拜(bai)师才能学。");
	return 1;
    case 17:
        command("say 师傅不教你？你找找他的书房，也许会有秘籍什么的。");
	return 1;
    case 18:
        command("say 他没有秘籍，那你xue <师傅ID> <功夫名>。");
	return 1;
    case 19:
        command("say 你不知道你有什么功夫？那你用skills，哇我会这么多的功夫。");
	return 1;
    case 20:
        command("say 你不会用特殊的功夫，如果有的话，先激发一下(help enable)。");
	return 1;
    case 21:
        command("say 你想知道你的身体状况吗？hp ，看看自己有多强。");
	return 1;
    case 22:
        command("say 你看不懂hp显示的东西？好吧我来告诉你");
	return 1;
    default:
	return 0;
    }
    return 1;
}

void get_out(object me)
{
	command("hmm");
	command("say " + RANK_D->query_respect(me) + "怎么还在武馆？");
	message_vision("马五德大手一挥，将$N赶到车房了。\n", me);
	me->move("/d/wuguan/cheku");
	return;
}*/
