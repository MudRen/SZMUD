// Code of ShenZhou
// Ryu, 11/20/96.
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("����", ({ "bing can"}) );
	set_color("$HIW$");
        set("race", "����");
        set("subrace", "����");
        set("age", 3);
        set("long", "��ϳ洿������΢����ɫ����Ѱ���Ĳ϶�����һ�����࣬����һ����򾣬����͸��ֱ��ˮ����\n");
        set("attitude", "peaceful");

//        set("limbs", ({ "ͷ��", "����", "����", "ǰ��" }) );

        set("combat_exp", 900);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 6);
        set_temp("apply/armor", 1);

        setup();
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        victim->apply_condition("insect_poison", 500 +
                victim->query_condition("insect_poison"));
}
