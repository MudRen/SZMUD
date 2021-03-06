//Created by Lisser on k1-08-17
// tester.c 考官

inherit NPC;
#include <ansi.h>

string ask_me();
void welcome(object me);

void create()
{
        set_name("杨风", ({ "yang feng", "yang", "tester" }));
	set("gender", "男性");
	set("age", 30);
        set("title",HIY"扬威武馆考官"NOR);
	set("long", "他是一个三十多岁的青年人，在这里检验武馆弟子的武功，看是否有能力出去闯荡江湖！\n");
	set("combat_exp", 6500);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set_skill("unarmed", 30+random(3));
	set_skill("dodge", 30+random(3));
	set_skill("parry", 30+random(3));
	set_skill("force", 30+random(3));
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

        set("inquiry", ([
                "检测" : (: ask_me :),
                "exam" : (: ask_me :),
        ]));

	setup();
}

void init()
{
	object me = this_player();

	if ( interactive(me) )
	{
		remove_call_out("welcome");
		call_out("welcome", 1, me);
	}
}

void welcome(object me)
{
	string name = (me->query("colorname"))?(me->query("colorname")):(me->query("name"));

	command("smile " + me->query("id"));
	command("say " + name + CYN"，你可以问我有关「"HIC"检测"NOR + CYN"("HIC"exam"NOR + CYN")」的事。"NOR);

	return;
}

string ask_me()
{
	object me = this_player();
	string nick = (me->query("gender")=="男性")?"小兄弟":"小姑娘";
	string yesno = nick + "，可以开始了吗？(如果可以了请输入：「好」或 「can」)";
	command("bow " + me->query("id"));

	if ( wizardp(me) )
	{
		command("hmm");
		command("say " + "阁下已经是仙人了，又为何还要和小的开这种玩笑呢？");
		return "阁下若是闲着了，还是去别处散心吧。";
	}

	add_action("do_test", "好");
	add_action("do_test", "can");
	return yesno;
}

int do_test(int count)
{
	object me = this_player();
	object ob = this_object();
	string nick = (me->query("gender")=="男性")?"小兄弟":"小姑娘";
	string letgo = nick + "，那么我们就开始了。";
	string time, word;

	if ( count < 8 )
	{
		 switch ( (count) )
		{
			case 0: time = "一";
				break;
			case 1: time = "二";
				break;
			case 2: time = "三";
				break;
			case 3: time = "四";
				break;
			case 4: time = "五";
				break;
			case 5: time = "六";
				break;
			case 6: time = "七";
				break;
			case 7: time = "八";
				break;
		}

		 switch ( random(7) )
		{
			case 0: word = "注意了，这是第" + time + "招。";
				break;
			case 1: word = "第" + time + "招了，加油啊！";
				break;
			case 2: word = "已经是第" + time + "招了，别泄劲啊。";
				break;
			case 3: word = "都第" + time + "招了，努力。";
				break;
			case 4: word = "成功就在眼前，已经是第" + time + "招了！";
				break;
			case 5: word = "坚持！都" + time + "招了。";
				break;
			case 6: word = "小心！第" + time + "招！";
				break;
			case 7: word = "挡住这第" + time + "招啊！";
				break;
		}

		command("say " + word);
	        COMBAT_D->do_attack(ob, this_player(), query_temp("weapon"));
	        if( (int)this_player()->query("qi") < 0 || !present(this_player(), environment(this_object())) )
		{
			me->reincarnate();
			move("/d/wuguan/damen");
			me->move("/d/wuguan/damen");
			command("shake" + me->query("id"));
			command("say " + nick + "修行不够啊！");
			command("sigh2");
			return;
		}else{
		        count = count + 1;
			call_out("do_test", 1+random(1), count);
			}
	}
	else
	{
		command("congra " + me->query("id"));
		command("say " + nick + "，此番离去，你我恐怕就再难见面了！江湖险恶，要小心啊！");
		me->move("/d/wuguan/cheku");
		return;
	}

}