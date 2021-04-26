// Code of ShenZhou
// wujiang.c �佫

#include <ansi.h>
inherit NPC;
inherit F_SKILL;

void create()
{
        set_name(YEL"�佫"NOR, ({ "wu jiang", "wu", "jiang" }));
        set("gender", "����");
        set("age", random(10) + 30);
        set("str", 25);
        set("dex", 16);
        set("long", "���Ǽ����ص��ؽ���\n");
        set("combat_exp", 75000);
        set("shen_type", 1);
        set("attitude", "peaceful");

        set_skill("unarmed", 55);
        set_skill("force", 55);
        set_skill("sword", 55);
        set_skill("dodge", 55);
        set_skill("parry", 55);
        set_temp("apply/attack", 55);
        set_temp("apply/damage", 30);

        set("neili", 300); 
        set("max_neili", 300);
        set("jiali", 10);

        setup();
        carry_object(__DIR__"obj/gangjian")->wield();
        carry_object(__DIR__"obj/tiejia")->wear();
}
int accept_fight(object me)
{
        command("say ��ү���ر߹��۵�Ҫ����û�պ�" + RANK_D->query_respect(me)
                + "�����档\n");
        return 0;
}

