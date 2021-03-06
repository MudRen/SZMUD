//Cracked by shenzhou
// tea seller.c 卖茶老头
// 酒儿  May 2002

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("卖茶老头", ({ "tea seller", "seller", "man" }) );
        set("gender", "男性" );
        set("age", 55);
        set("long", "这位卖茶老头正笑咪咪地忙著，看见你走过来，忙用白巾子掸了掸茶桌。\n");
        set("combat_exp", 300);
        set("attitude", "friendly");
        set("no_get", "1");
        set("rank_info/respect", "老哥哥");
        set("vendor_goods", ({
        	"/d/city/npc/tea/qimen_hongcha",
        	"/d/city/npc/tea/wuyi_yancha",
        	"/d/city/npc/tea/yinzhen",
        	"/d/city/npc/tea/maofeng",
        	"/d/city/npc/tea/longjing",
			"/d/city/npc/tea/biluo_chun",
			"/d/city/npc/obj/baozi",
			"/d/city/npc/obj/gaodian",
        }));
        setup();
        carry_object("/clone/misc/cloth")->wear();

}

void init()
{       
        object ob; 
        mapping myfam; 

        ob = this_player();

        ::init();
        if( interactive(ob) && !is_fighting() ) {
                if ( (myfam = ob->query("family")) 
                && myfam["family_name"] == "丐帮" 
                && ob->query_skill("begging",1) > 10 )
                {
                        remove_call_out("saying");
                        call_out("saying", 0, ob);
                }
                else
                { 
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
                }
        }

        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) 
		{
			case 0:
				say( "卖茶老头笑咪咪地说道：这位" + RANK_D->query_respect(ob)
					+ "，您请这儿坐！\n");
				break;
			case 1:
				say( "卖茶老头用白毛巾掸了掸木凳，说道：这位" + RANK_D->query_respect(ob)
					+ "，远道而来，坐这儿消消饥渴吧，我这儿可备了些好茶水！\n");
				break;
		}
}
