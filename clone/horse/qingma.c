// Code of ShenZhou
// daqing-ma.c 大青马
inherit NPC_TRAINEE;
#include "/clone/horse/horse.h"
int return_home(object home);
int condition_check();
void create()
{
	set_name("大青马", ({ "daqing ma", "ma", "horse" }) );
        set("race", "家畜");
        set("age", 15);
	set("long", "这是一匹青色的大马，生得龙颈狮鬃，四蹄飞青，确是匹好马。\n");
	set("msg_fail", "$n冲着$N怒嘶一声，人立起来！");
        set("msg_succ", "$n摇着头打转，蹄子击打着地面，似乎打不定主意");
        set("msg_trained","$n低嘶一声，走到$N身边挨挨擦擦，显得十分高兴！");
        set("attitude", "peaceful");

	set("wildness", 4);
	set("value", 50);
	set("ability", 4);

	set("ridable", 1);
        set("str", 90);
	set("con", 35);
	set("dex", 25);
        set("int", 20);
	set("max_qi", 700);
	set("qi", 700);
	set("max_jingli", 550);
	set("combat_exp", 12000);
	set("chat_chance", 50);
        set("chat_msg", ({
                (: condition_check :),
        }) );
        set_weight(100000);

        setup();
}

int return_home(object home)
{
        return 1;
}
