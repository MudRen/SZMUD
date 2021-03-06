// Code of ShenZhou
// yishi.c 武林同盟义士

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("武林同盟义士", ({ "yi shi", "shi", "warrior" }) );
	set("gender", "男性");
	set("age", 45);
	set("long",
		"这是武林同盟的普通办事人员，曾经都是江湖风云人物。\n");
	set("combat_exp", 1000000);
        set("shen_type", 1);
	set("attitude", "heroism");

	set("str", 30);
	set("con", 30);
	set("int", 30);
	set("dex", 30);

	set("max_qi", 1000);
	set("eff_qi", 1000);
	set("qi", 1000);
	set("max_jing", 700);
	set("jing", 700);
	set("neili", 2000);
	set("max_neili", 2000);
        set("jingli", 1000);
	set("max_jingli", 1000);
	set("jiali", 100);
	set("shen_type", 0);

	set_temp("apply/attack",  50);
	set_temp("apply/defense", 50);

	set_skill("sword", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);

	set("no_get", "你扛不动义士");

	setup();

        carry_object("/d/city/obj/gangjian")->wield();
        carry_object("/d/city/obj/tiejia")->wear();
}
/*
void init()
{
	object ob1, ob2, ob3;
	string mengzhu, shangshan, fae;
	
	::init();
	if(!( ob1 = find_living("mengzhu")) )
	ob1 = load_object("/clone/npc/meng-zhu");
	mengzhu = ob1->query("winner");

	if(!( ob2 = find_living("shangshan")) )
	ob2 = load_object("/clone/npc/shang-shan");
	shangshan = ob2->query("winner");

	if(!( ob3 = find_living("fae")) )
	ob3 = load_object("/clone/npc/fa-e");
	fae = ob3->query("winner");

	if( this_player()->query("id") == mengzhu ) {
		message_vision(HIY "白衣武士举起长剑，向$N齐声大喊：盟主万岁，万岁，万万岁！\n" NOR, 
		this_player());
	}	
	else if( this_player()->query("id") == shangshan ) {
		message_vision(HIY "白衣武士举起长剑，向$N齐声大喊：赏善使者好！\n" NOR, 
		this_player());
	}	
	else if( this_player()->query("id") == fae ) {
		message_vision(HIY "白衣武士举起长剑，向$N齐声大喊：罚恶使者好！\n" NOR, 
		this_player());
	}	
}               */
