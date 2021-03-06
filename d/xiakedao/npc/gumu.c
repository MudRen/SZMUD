//Cracked by Roath
// Based on Jay 10/7/96
// 侠客岛，雪山弟子
inherit NPC;
#include <ansi.h>

string* menpai = ({
	"say 
          古墓派祖师林朝英，当年与全真教祖师王重阳携手共走江
	湖，两人虽有夫妻之情，却无夫妻之缘。林朝英心高气傲，以她
	绝世之姿，妙龄之年，竟在古墓中幽居一生，因此创出古墓一派。
	林朝英传下小龙女、李莫愁两枝，一正一邪。",
});
int ask_menpai(string* message);

void create()
{
	set_name("月冰心", ({ "xueshan dizi", "dizi", "jyxuanb" }));
	set("long", "古墓派女弟子。\n");
	set("gender", "女性");
	set("age", 18);


	set("str", 28);
	set("int", 21);
	set("con", 27);
	set("dex", 21);

	set("combat_exp", 140);

	set("attitude", "peaceful");
	set("shen_type", 1);

	create_family("古墓派", 5 , "弟子");
	set("inquiry", ([
			"古墓派"   :  (: ask_menpai, menpai:),
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
	        command("flirt " + me->query("id"));
		command("idle2");
		command("say 这位" + RANK_D->query_respect(me) + "想来我们古墓清修吗？我们虽然比较寂寞，但是也很好玩。\n"+
	     "你有什麽问题问我就好啦。"+HBRED+HIW"(ask dizi about 古墓) (help gumu)"NOR);
		me->set_temp(this_object()->query("id"), 1);
	}
 }

#include "/d/xiakedao/npc/xkdnpc.h"
