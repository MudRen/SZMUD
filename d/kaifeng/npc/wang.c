// /d/kaifeng/npc/wang.c                                   
// by bravo
inherit NPC;
void create()
{
        set_name("王朝", ({ "wang chao", "wang" }));
        set("title", "贴身侍卫");
        set("gender", "男性");
        set("age", 33);
        set("str", 20);
        set("dex", 20);
        set("long", "他是跟随包大人多年的侍卫。\n");
        set("combat_exp", 60000);
        set("shen_type", -4000);
        set("attitude", "peaceful");
        set("per",40);
        set_skill("unarmed", 100);
        set_skill("force", 100);
        set_skill("sword", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 50);

        set("neili", 1000); 
        set("max_neili", 1200);
        set("jiali", 10);

        setup();
        carry_object("/d/kaifeng/npc/obj/junfu")->wear();
        
}
