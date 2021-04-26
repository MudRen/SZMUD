// Code of ShenZhou
// yangren

inherit NPC;

void create()
{
        set_name("����", ({ "hu ren", "ren", "foreigner" }));
        set("gender", "����");
        set("age", 30 + random(10));

        set("long", "һ���𷢱��۵ĺ��ˣ���ֺ�������ߺ���š�\n");

        set("attitude", "friendly");

        set("combat_exp", 8000);
        set("shen_type", 1);

        set_skill("unarmed", 30);
        set_skill("blade", 40);
        set_skill("parry", 30);
        set_skill("dodge", 40);

        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 20);

        setup();

        add_money("silver", 20);
}
