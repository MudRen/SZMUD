/*-------------------------------------------------------------
** 文件名: zhangfang.c
** Copyright (c) 2000-2001
** 创建人: 武馆工作组
** 日  期: 2001/08/13
** 描  述: 武馆帐房先生
**-----------------------------------------------------------*/

#include <ansi.h>
inherit NPC;

string ask_end();
 
void create()
{
	set_name("张风", ({ "zhang feng","zhang","zhangfang"}));
	set("title", "扬威武馆账房先生");
	set("gender", "男性");
	set("age", 50);
	set("str", 27);
        set("int", 23);
        set("con", 19);
	set("dex", 26);
	set("long", "一个五十多岁的老人，打得一手好算盘，在武馆中专管奖惩的人。\n");
	set("combat_exp", 5000);
	set("shen_type", 1);

	set_skill("literate", 70);
	set_skill("unarmed", 35);
	set_skill("dodge", 30);
	set_skill("parry", 30);

        set("qi", 500);
	set("max_qi", 500);
	set("neili", 100); 
	set("max_neili", 100);

	set("inquiry", 
           ([
             "完成" : (: ask_end :),
             "finish" : (: ask_end :),
             ]));

	setup();
}

string ask_end()
{
        object me;
        object ob, wage;
        ob=this_player();
        me=this_object();

	if ( ob->query("wuguan/end") == 1 )
	   return("还没做完就想要奖赏？快去工作！\n");

	if ( ob->query("wuguan/end") ==0 )
	   return("你还没要工作？你要先工作才能得到奖赏。\n");
	   
	if ( ob->query("wuguan/end") > 1 )
	   {
		ob->set("wuguan/end", 0);
		ob->add("combat_exp", 50+random(50));
		ob->add("potential", 30+random(20));
		ob->delete("wuguan/job_pending");
		ob->delete_temp("wuguan_job");
		wage = new("/clone/money/silver");
		wage->set_amount(ob->query("wuguan/job_times"));
		wage->move(ob);
		command("nod "+ob->query("id"));
		return ob->name()+"干的不错，这是你的奖赏。";
	  }
}