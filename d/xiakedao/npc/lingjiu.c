//Cracked by Roath
// Based on Jay 10/7/96
// 侠客岛，雪山弟子
inherit NPC;
#include <ansi.h>

string* menpai = ({
	"say 
		  灵鹫宫的开山祖师天山童老，师承是逍遥派。逍遥派的武功
    是道家一脉，一直以来都是武林中的一个最大的神秘组织。灵鹫宫
	有一种阴损的武功－－生死符，中者无不生不如死，痛苦万分，只
	能永远臣服于灵鹫宫。由于灵鹫宫弟子行事隐秘，武功高强，招式
	狠毒，所中者轻则缺手断腿，重则残废。所以武林中人对灵鹫宫闻
	风丧胆。",
});
int ask_menpai(string* message);

void create()
{
	set_name("凤凰", ({ "lingjiu dizi", "dizi", "phoenia" }));
	set("long", "一个面目清秀的女子，只是眉目间一股杀气。\n");
	set("gender", "女性");
	set("age", 18);


	set("str", 28);
	set("int", 21);
	set("con", 27);
	set("dex", 21);

	set("combat_exp", 140);

	set("attitude", "peaceful");
	set("shen_type", 1);

	create_family("灵鹫宫", 5 , "弟子");
	set("inquiry", ([
			"灵鹫宫"   :  (: ask_menpai, menpai:),
		]));

	setup();
 	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/lingjiu/obj/qingyi")->wear();
	carry_object("/d/city/npc/obj/doupeng")->wear();
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
	        command("wanfu " + me->query("id"));
		command("lovelook");
		command("say 这位" + RANK_D->query_respect(me) + "想来我们天山灵鹫宫吗？我们这儿吃喝玩乐什么都有。\n"+
	     "你有什麽问题问我就好啦。"+HBRED+HIW"(ask dizi about 灵鹫宫) (help lingjiu)"NOR);
		me->set_temp(this_object()->query("id"), 1);
	}
 }

#include "/d/xiakedao/npc/xkdnpc.h"
