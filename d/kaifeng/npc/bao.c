// /d/kaifeng/npc/bao.c                                   
// by bravo
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����", ({ "bao zheng", "bao" }));
        set("title", HIC"�������"NOR);
        set("gender", "����");
        set("age", 43);
        set("str", 20);
        set("dex", 20);
        set("long", "���������˾����İ����졣\n");
      set("per",40);
        set("combat_exp", 60000);
        set("shen_type", 10000);
        set("attitude", "friendly");

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
        set("max_neili", 1000);
        set("jiali", 10);

        setup();
        
        carry_object("/d/kaifeng/npc/obj/guanfu")->wear();
}
