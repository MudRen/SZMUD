//Cracked by Roath
// Based on Jay 10/7/96
// 侠客岛，雪山弟子
inherit NPC;
#include <ansi.h>

string* menpai = ({
	"say 
		  姑苏慕容祖宗慕容氏，乃是鲜卑族人。到了五代末年，慕
	容氏中出了一位武学奇才慕容龙城，创出「斗转星移」的高妙武
	功。",
});
int ask_menpai(string* message);

void create()
{
	set_name("寒月", ({ "xueshan dizi", "dizi", "hotjc" }));
	set("long", "一个十来岁的小书童。\n");
	set("gender", "男性");
	set("age", 18);


	set("str", 28);
	set("int", 21);
	set("con", 27);
	set("dex", 21);

	set("combat_exp", 140);

	set("attitude", "peaceful");
	set("shen_type", -1);

	create_family("姑苏慕容", 20 , "传人");
	set("inquiry", ([
			"姑苏慕容"   :  (: ask_menpai, menpai:),
		]));

	setup();
        carry_object("/d/xueshan/obj/lamajiasha")->wear();
	carry_object("/d/qilian/obj/faling")->wield();
}

void init()
{
        object me = this_player();        

        ::init();

        if( interactive(me) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

void greeting(object me)
{	
        if (me->query_temp(this_object()->query("id")) == 0 )
	{	
	        command("bow " + me->query("id"));
		command("poem");
		command("say 这位" + RANK_D->query_respect(me) + "想来太湖参合庄么？我们这儿吃喝玩乐什么都有。\n"+
	     "你有什麽问题问我就好啦。"+HBRED+HIW"(ask dizi about 姑苏慕容) (help murong)"NOR);
		me->set_temp(this_object()->query("id"), 1);
	}
 }

#include "/d/xiakedao/npc/xkdnpc.h"
