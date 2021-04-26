// yahuan.c

inherit NPC;

void create()
{
	set_name("小丫鬟", ({ "ya huan","yahuan","ya" }) );
	set("gender", "女性");
	set("age", 16);
	set("long",
		"她是迎宾馆的小丫鬟，大约十多岁，正在这里忙着打扫。\n");
	set("combat_exp", 200);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set("apply/attack", 10);
	set("apply/defense", 10);

	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_skill("dodge", 20);

	setup();

	carry_object("/clone/misc/cloth")->wear();
}
