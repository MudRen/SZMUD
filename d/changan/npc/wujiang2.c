// Code of ShenZhou
// wujiang.c 武将

#include <ansi.h>

inherit NPC;
inherit F_SKILL;

void create()
{
        set_name("武将", ({ "wu jiang", "wu", "jiang" }));
        set_color("$YEL$");
        set("title","长安城");
        set("gender", "男性");
        set("age", random(10) + 30);
        set("weight", 100000);
        set("str", 25);
        set("dex", 16);
        set("long", "他站在那里，的确有说不出的威风。\n");
        set("combat_exp", 75000);
        set("shen_type", 0);
        set("attitude", "peaceful");

        set_skill("unarmed", 60);
        set_skill("force", 60);
        set_skill("sword", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 30);

        set("neili", 400); 
        set("max_neili", 400);
        set("jiali", 10);

        setup();
        carry_object(__DIR__"obj/gangjian")->wield();
        carry_object(__DIR__"obj/tiejia")->wear();
}




