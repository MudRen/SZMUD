// xfang.c (kunlun)

inherit NPC;

string ask_me_1(string name);

void create()
{
        set_name("杏芳", ({ "xing fang", "xing" }));
        set("gender", "女性" );
        set("age", 18);
        set("long", "她是何太冲原配夫人班淑娴的贴身使婢\n");

        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        set("combat_exp", 10000);
	set("shen_type", -1);
        set("str", 25);
        set("dex", 20);
        set("con", 18);
        set("int", 15);
        set("attitude","frindly");
        set("inquiry", ([
		"琥珀蜜梨酒" : (: ask_me_1, "honey" :)
        ]) );
	set("honey_count", 2);
	set("jiuping_count",1);
        setup();
        
        set("chat_chance", 10);
        set("chat_msg", ({
"杏芳自言自语道：先生也太不像话了,天天陪着五姑,老夫人气坏了!\n",
"杏芳狠狠地道: 我一定要用琥珀蜜梨酒毒死五姑这个妖精,看到她那副德性老妇人就来气.\n",
        }) );
        carry_object("/d/kunlun/obj/cloth")->wear();
}

string ask_me_1(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "昆仑派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";

	if (  present(name, this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"不是刚给你喝了一杯吗，怎麽又来要了?";

	if (query("honey_count") < 1)
		return "抱歉，你来得不是时候，本山的琥珀蜜梨酒已经喝完了。剩下的都被夫人下了蜈蚣毒!";

	ob = new("/d/kunlun/obj/" + name);
	ob->move(this_player());

	add("honey_count", -1);

	message_vision("杏芳给$N一杯" + ob->query("name") + "。\n", this_player());

	return "此酒来之不易,有驱寒,活血,恢复体力的妙效,你快喝(he)了吧。";
}
