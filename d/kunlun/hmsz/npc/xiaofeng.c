// xiaofeng.c 

inherit NPC;
//inherit F_SKILL;

void create()
{
	set_name("小凤", ({ "xiao feng", "xiao", "feng" }));
	set("long", 
		"她就是红梅山庄的丫鬟，一张鹅蛋脸，乌丝垂肩.\n"
		"身上穿着不知名的绫罗绸缎，闪闪发光、腕上戴着金镯\n");
		
	set("title", "丫鬟");
	set("gender", "女性");
	set("age", 16);
	set("shen_type", 1);

        set_skill("dodge", 50);
        set_skill("unarmed", 50);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 15);

	set("combat_exp", 10000);

	setup();
        carry_object("/clone/misc/cloth")->wear();
}
