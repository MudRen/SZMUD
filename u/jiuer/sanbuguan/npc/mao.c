//Cracked by shenzhou
// mao.c 茅十八
// 酒儿  May 2002

inherit NPC;

void create()
{
        set_name("茅十八", ({ "mao shiba", "mao" }) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "他是一位江湖好汉。\n");
        
		set_skill("blade", 80);
		set_skill("wuhu-duanmen", 80);
        set_skill("dodge", 80);
		set_skill("wuxingbu", 80);
        set_skill("parry", 80);
        set_skill("wuhu-duanmen", 80);

        map_skill("dodge","wuxingbu");
		map_skill("parry","wuhu-duanmen");
		map_skill("blade","wuhu-duanmen");

        set("str", 30);
        set("int", 21);
        set("con", 24);
        set("dex", 26);

        set("max_neili", 800);
        set("jiali", 70);
		set("shen_type", 1);
     
		set("combat_exp", 50000);
        set("attitude", "peaceful");  
		
		set("chat_chance", 10);
		set("chat_msg", ({"茅十八拱手道：兄弟腿上不方便，不能起立行礼了。\n",
			"茅十八说道： 他奶奶的，我就不信鳌拜有这等厉害。我正要上北京去斗他一斗。\n",
			"茅十八朗声说道：江湖有言：“为人不识陈近南，就称英雄也枉然。”\n",
			"茅十八叹道: 用我这五虎断门刀法对付盐枭可是绰绰有余,只不知对付鳌拜行不行。\n",
		}) );
		setup();
        carry_object("/clone/armor/cloth")->wear();
        carry_object("/d/city/obj/gangdao")->wield();
}
