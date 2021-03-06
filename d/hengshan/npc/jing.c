// jing.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
/*
定静师太一双肉掌上下翻飞，使
开恒山派“天长掌法”，在四般兵刃间翻滚来去。她年近六旬，身手矫捷却不输少
年。
定静师太举起长剑，凝神
将攒射过来的暗器一一拍开。黑夜之中，唯有星月微光，长剑飞舞，但听得叮叮之
声连响，十多枚暗器给她尽数击落。只是给暗器这么一阻，那魔教七人却逃得远了。
只听得身后那人叫道：“恒山派万花剑法精妙绝伦，今日教人大开眼界。”
*/
void create()
{
        set_name("定静师太", ({ "dingjing shitai", "shitai", "dingjing" }) );
        set("gender", "女性");
        set("class", "bonze");
        set("age", 45);
        set("attitude", "peaceful");
        set("per", 24);
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 2400);
        set("max_neili", 2400);
        set("jiali", 30);
        set("max_qi",2000);
        set("max_jing",1200);
        set("combat_exp", 1000000);
        set("shen_type", 1);

        set_skill("sword", 130);
        set_skill("force", 130);
        set_skill("parry", 130);
        set_skill("dodge", 130);
        set_skill("hengshan-jian", 130);
        set_skill("lingxu-bu", 130);
        set_skill("ding-force", 130);
        map_skill("force", "ding-force");
        map_skill("sword", "hengshan-jian");
        map_skill("parry", "hengshan-jian");
        map_skill("dodge", "lingxu-bu");

        create_family("恒山派", 13, "弟子");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

