//Created by Zyu on k1-08-20
// jiang.c 花匠

inherit NPC;
#include <ansi.h>

void create()
{
	set_name("老花匠", ({ "hua jiang", "jiang" }));
	set("long", "这是一位满头银发的老花匠，额上刻满了岁月的印记。双眼却有神，是位心境年轻的老人。\n");
	set("gender", "男性");
	set("age", 67);

	set_temp("apply/attack", 1);
	set_temp("apply/defense", 1);
	set_temp("apply/damage", 1);

	set("combat_exp", 1);
	set("shen_type", 1);

	set("inquiry", ([
		"工作" : (: ask_job :),
		"job" : (: ask_job :),
		"马五德" : "馆主老人家的名讳岂是我们随便叫的。",
		"大理" : "我的几个徒儿先后都往那边去了，也不知如今怎样了。",
	]) );

	set("chat_chance", 10);
	set("chat_msg", (: random_chat :) );	
	setup();

	carry_object("/clone/weapon/gangdao")->wield();
}

void init()
{
	object me = this_player();
	int exp = me->query("combat_exp");

	remove_call_out("check_exp");
	call_out("check_exp", 0, me, exp);
}

void check_exp(object me,int exp)
{
	if ( exp <= 4000 )
		return RANK_D->query_respect(me) + "的修行不够啊。";
	else if (exp >= 8000 )
		return RANK_D->query_respect(me) + "在我这儿恐怕难有什么收获了。";
}

int random_chat()
{
    switch ( random(86) ) {
    case 0:
        command("say 能到这儿的都是武馆里中上的主儿了。");
        return 1;
    case 1:
        command("say 我这里多少有些活，如果想做就(ask jiang about job)。");
        return 1;
    case 2:
        command("say 这些新开的花儿马上就要往外送了，乌为什么就没人愿意做呢。");
        return 1;
    case 3:
        command(":)");
        return 1;
    case 4:
	command("ah");
	return 1;
    case 5;
	command("say 这两天没什么日头，花都快谢完啦。");
	return 1;
    default:
        return 0;
    }
    return 1;
}

void ask_job()
{
	return;
}