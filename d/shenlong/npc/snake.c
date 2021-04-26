// Code of ShenZhou
// /d/shenlong/npc/snake.c
// ALN Sep / 97

inherit NPC;

int snake_attspeed(object);

void create()
{
        set_name("����", ({ "snake", "she" }) );
        set("race", "����");
        set("age", 4 + random(10));
        set("long", "һֻ�����������Դ����ߣ�β��ɳɳ���졣\n");
        set("attitude", "peaceful");

        set("str", 26);
        set("cor", 30);

        set("jingli", 300);

        set("combat_exp", 5000 + random(5000));

        set_temp("apply/attack", 15+random(10));
        set_temp("apply/damage", 6+random(10));
        set_temp("apply/armor", 2+random(10));

        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        victim->apply_condition("snake_poison", 20 + random(40) +
                victim->query_condition("snake_poison"));
}

#include "/d/shenlong/npc/snake.h"

