// Code of ShenZhou
// yuhuan.c 程玉环 

#include <ansi.h>
inherit NPC;
inherit F_SKILL;

void create()
{
	set_name("程玉环", ({ "cheng yuhuan", "cheng", "yuhuan" }));
        set_color("$YEL$");
	set("long", 
		"她就是程知府的独生女儿，长得如花似玉，貌赛天仙的程玉环。\n"
		"据说她曾经在武当门下学过剑法。\n");
		
	set("title", "知府千金");
	set("nickname", "玉仙姑");
	set("gender", "女性");
	set("age", 18);
	set("shen_type", 1);

	set("neili", 400);
	set("max_neili", 400);
	set("max_qi", 400);
	set("max_jing", 200);
	set("jiali", 10);

	set_skill("force", 50);
	set_skill("unarmed", 40);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("sword", 60);
	set_skill("taiji-jian", 40);
	map_skill("sword", "taiji-jian");
	map_skill("parry", "taiji-jian");

	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);

	setup();
	carry_object(__DIR__"obj/goldring")->wear();
	carry_object(__DIR__"obj/necklace")->wear();
	carry_object(__DIR__"obj/changjian")->wield();
}
int accept_kill(object me)
{
        command("say 你活得不耐烦了？看本小姐怎么收拾你！\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

