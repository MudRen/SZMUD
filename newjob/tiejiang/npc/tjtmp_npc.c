// tjtmp_npc.c
// snowlf by 2001.10.24

#include <ansi.h>
#include <dbase.h>

inherit NPC;
inherit F_VENDOR;
int do_sell(string);
// string ask_liancost();
void create()
{
	set_name("胡启明", ({ "hu qiming", "hu", "qiming" }) );
	set("gender", "男性" );
	set("age", 30);
	set("long","胡启明是这个新建的"+HIB+"铁匠工作场所"+NOR+"的临时管理人员，他本不是做这
行的，只是因为这里一时没有合适的人来看管，受朋友之托才临时来这里的。
		
");
	set("combat_exp", 3000);
        set("str", 25);
        set("dex", 20);
        set("con", 20);
        set("int", 22);
	set("attitude", "friendly");
/*
	set("inquiry", ([

		"薛鹊" : "姜铁山的老婆。\n",
		"铁屋" : "在洞庭湖畔。\n",
                "洞庭湖" : "我可不回去了。\n",
		"程灵素" : "程姑娘可是天下第一好人。\n",
		"铁链" : "想拿掉铁链？可得化一番功夫（ask 铁链价钱）。\n",
                "铁链价钱" : (:ask_liancost:),
	]));	

	set("chat_chance", 5);
	set_skill("dodge", 25);
	set_skill("parry", 25);
	set_skill("unarmed", 30);
*/	
	setup();
        carry_object("/d/city/obj/cloth")->wear();
	add_money("coin", 200);
}


void init()
{
	object ob;

        ::init();
	if ( interactive(ob=this_player()) ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

        add_action("do_buy", "buy");
	add_action("do_list", "list");
	add_action("do_sell", "sell");

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

	command("say 欢迎这位"+RANK_D->query_respect(ob)+"光临，请随便参观。");
}
