// qiaofu.c  (kunlun)

inherit NPC;

void create()
{
	set_name("乔福", ({ "qiao fu", "fu" }));
	set("gender", "男性");
	set("age", 35);
	set("long", "他是红梅山庄的一个下人。\n");
	set("combat_exp", 20000);
        set_skill("dodge", 50);
        set_skill("strike", 50);
        set_temp("apply/attack",  50);
        set_temp("apply/defense", 50);
	set("shen_type", -1);
	setup();

	add_money("silver",30);
	carry_object("/clone/misc/cloth")->wear();
}

