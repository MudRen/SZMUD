// Code of ShenZhou
// npc: /d/xingxiu/npc/caiyaoren.c
// Jay 3/18/96

inherit NPC;

void create()
{
        set_name("��ҩ��", ({ "caiyao ren", "caiyao", "ren" }));
        set("gender", "����");
        set("age", 30 + random(10));

        set("long", "һ�����๤���Ĳ�ҩ�ˡ�\n");
        set("attitude", "friendly");

        set("combat_exp", 1000);
        set("shen_type", 1);

        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("hammer", 50);
        set("apply/attack", 35);
        set("apply/defense", 35);
        set("apply/damage", 15);
        setup();
        add_money("coin", 50);
        carry_object(__DIR__"obj/yaochu")->wield();
}

