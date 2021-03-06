// Code of ShenZhou
// bai-ma.c 白马

inherit NPC_TRAINEE;
#include "/clone/horse/horse.h"
int condition_check();
int return_home(object home);

void create()
{
        set_name("白马", ({ "bai ma", "ma", "horse" }) );
        set("race", "家畜");
        set("age", 10);
	set("long", "这是一匹白色的大宛马，生得龙颈狮鬃，四蹄飞青，似乎是匹好马。\n");
	set("msg_fail", "$n冲着$N怒嘶一声，竖立起来！");
        set("msg_succ", "$n摇着头打转，蹄子击打着地面，似乎打不定主意");
        set("msg_trained","$n低嘶一声，走到$N身边挨挨擦擦，显得十分高兴！");
        set("attitude", "peaceful");

        set("wildness", 6);
        set("value", 80);
	set("ability", 4);

	set("ridable", 1);
        set("str", 80);
	set("con", 30);
        set("dex", 40);
        set("int", 20);
	set("apply/attack", 75);

	set("max_jingli", 630);
	set("combat_exp", 10000);
        set_weight(100000);
	set("chat_chance", 50);
        set("chat_msg", ({
                (: condition_check :),
        }) );
        setup();
}

int return_home(object home)
{
        return 1;
}
