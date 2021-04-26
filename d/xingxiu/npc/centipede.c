// Code of ShenZhou
// Ryu, 11/20/96.

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("���", ({ "wu gong", "centipede" }) );
	set_color("$RED$");
        set("race", "����");
        set("subrace", "����");
        set("age", 3);
        set("long", "һֻ�ֺ�ɫ�ľ޴����򼣬����һ�����ȣ�ȫ�����⣬ͷ��͹��һ��С������Ѱ��������ͬ��\n");
        set("attitude", "peaceful");

//        set("limbs", ({ "ͷ��", "����", "����", "ǰ��", "β��" }) );
//        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 900);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 6);
        set_temp("apply/armor", 1);

        setup();
}
void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) &&
                random(ob->query_kar() + ob->query_per()) < 30) {
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob);
        }
}
void die()
{
        object ob;
        message_vision("\n$N����һ�������ˡ�\n", this_object());
        ob = new(__DIR__"wg_shell");
        ob->move(environment(this_object()));
        destruct(this_object());
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        victim->apply_condition("insect_poison", 10 +
                victim->query_condition("insect_poison"));
}
