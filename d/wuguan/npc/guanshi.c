/*-------------------------------------------------------------
** 文件名: guanshi.c
** Copyright (c) 2000-2001
** 创建人: 武馆工作组
** 日  期: 2001/08/13
** 描  述: 武馆管事
**-----------------------------------------------------------*/

#include <ansi.h>
inherit NPC;

string ask_job();
string random_chat();

void create()
{
	set_name("吴明", ({ "wu ming","wu","guan shi","guan"}));
	set("title", "扬威武馆管事");
	set("gender", "男性");
	set("age", 30);
	set("str", 27);
        set("int", 23);
        set("con", 19);
	set("dex", 26);
	set("long", "这人相貌和蔼，笑呵呵的，在武馆中给人分配工作。\n");
	set("combat_exp", 30000);
	set("shen_type", 1);

	set_skill("literate", 50);
	set_skill("hand", 60);
	set_skill("dodge", 60);
	set_skill("force", 68);
	set_skill("parry", 68);
	set_skill("blade", 68);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

        set("qi", 2000);
	set("max_qi", 2000);
	set("neili", 2500); 
	set("max_neili", 2500);
	set("jiali", 150);

	set("inquiry", 
           ([
             "工作" : (: ask_job :),
             "job" : (: ask_job :),
             ]));

        set("chat_chance", 50);
	set("chat_msg", (: random_chat :));

	setup();
}

void init()
{
	object ob;

	::init();

	set_heart_beat(1);

	if ( interactive( ob = this_player() ) ) {
	   if ( ob->query("title") == "武馆学徒" ) {
//		remove_call_out("check_student");
		call_out("check_student", 1, ob);
	   }
        }
}

int check_student(object ob)
{
	mapping job_stat;
	object me = this_object();

	if ( ob->query("wuguan/job_pending") && !ob->query_condition("wuguan_job") ) {
		job_stat = ob->query_temp("wuguan_job");

		if ( sizeof(job_stat) < 5 ) {
			ob->apply_condition("wuguan_job", 10);
			message_vision("$N皱着眉头对$n说道：我叫你到武馆各处好好巡视，但你似乎还没到各处去过吧。\n", me, ob);
			command("say 你马上给我回去好好巡逻！");
		}else if ( ob->query("wuguan/end") == 1 ){
			ob->add("wuguan/job_times", 1);
			ob->set("wuguan/end",2);
			command("nod");
			command("say 很好，"+ob->name()+"你的任务完成的很好，找帐房先生要奖励去吧。");
		}
	}

	return 1;
}

string ask_job()
{
	mapping job_stat;
	object ob = this_player();
	object me = this_object();

	job_stat = ob->query_temp("wuguan_job");

	if ( ob->query_condition("wuguan_job") > 0 && sizeof(job_stat) == 5 )
		return "你没仔细巡察吧？你要对你的工作负责任！\n";

	else if ( ob->query_condition("wuguan_job") > 0 )
		return "你还没完成我交待的工作，怎麽又来问我？\n";

	if ( ob->query("title") != "武馆学徒" )
		return "哎！"+RANK_D->query_respect(ob)+"非武馆弟子，岂敢劳烦。\n";

	if ( ob->query("wuguan/end") > 1 ){
		ob->set("wuguan/end", 2);
		command("hmm "+ob->query("id"));
		return ob->name()+"你的活已经干完了，快找帐房先生要奖励吧！";
	}else{
	ob->set("wuguan/job_pending", 1);
	ob->set("wuguan/end", 1);
	ob->apply_condition("wuguan_job", 10+random(20));
	command("nod");
	command("say 近来有些人对我武馆中的学徒图谋不轨，你去巡察一下。");
	return "行事千万要小心！多多助人！\n";
	}
}
/*
string ask_job()
{
        object me;
        object ob;
        string target;
        ob=this_player();
        me=this_object();

        if ( ob->query("wuguan/start")==1 )
                return ("你不是已经领了工作吗？还不快去做。\n");

        if (ob->query("combat_exp")>=50000)
                return ("你功夫这么高，这里没有什么适合你的工作了。\n");

	command("ok "+ob->query("id"));
	command("say 你到武馆各处巡察一下吧，看看有没有捣乱的人。");
	ob->set("wuguan/start",1);
}
*/
int random_chat() {

    switch (random(200)) {
    case 0:
        command("say 欢迎到来扬威武馆。");
	return 1;
    case 1:
        command("say 我这里有些活，如果想做就(ask wu about job)。");
	return 1;
    case 2:
        command("say 如果做完了工作，请向帐房张先生要奖赏(ask zhang about 完成)。");
	return 1;
    case 3:
        command("hi");
	return 1;
    default:
	return 0;
    }
    return 1;
}