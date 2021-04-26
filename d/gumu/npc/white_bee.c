// white_bee.c	���Ⱥ
// by April 01.09.01

#include <ansi.h>

inherit NPC;

void create()
{
	set_name(WHT"���Ⱥ"NOR, ({ "bees" }) );
	set("race", "����");
	set("subrace", "�ɳ�");
	set("age", 1);
	set("long", "���ǹ�Ĺ��ѱ����һȺ��䣬���˵ģ���ֻ�ж��١�\n");
	set("str", 60);
	set("dex", 80);

	set("limbs", ({ "�ܼ���", "ϡ����", "����", "��Χ" }) );

	set("max_jing",1000);
	set("jing",1000);
	set("qi",1000);
	set("max_qi",1000);
	set("jingli",1000);
	set("max_jingli",1000);

	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("unarmed", 100);

	setup();
}

/*
void unconcious()
{
        object ob;

        if( base_name(environment(this_object())) == "/d/dali/chhill4" && random(6) > 0 ) {
                 ob = new(__FILE__);
                 ob->move(environment());
        	 message_vision("\n�ˣ��ˣ��ˣ��ַ���һֻ���䡣\n", this_object());
        } else {
                 message_vision("\nһ�������䴵���ˡ�\n", this_object());
        }

        destruct(this_object());
}
*/

void die()
{
	object ob;

	message_vision("\n$N���ڶ����ˣ����ϰ�ããһƬ��\n", this_object());
	destruct(this_object());
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	victim->apply_condition("yufeng_poison", 5 + random(5) +
		victim->query_condition("yufeng_poison"));
}

