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
		
		setup();
        carry_object("/clone/armor/cloth")->wear();
        carry_object("/d/city/obj/gangdao")->wield();
}
