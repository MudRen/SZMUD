// white_bee.c	���Ⱥ
// by April 01.09.01

#include <ansi.h>

inherit NPC;

void create()
{
	set_name(WHT"���Ⱥ"NOR, ({ "yufeng qun","bees" }) );
	set("race", "����");
	set("subrace", "�ɳ�");
	set("age", 1);
        set("long", "���ǹ�Ĺ��ѱ����һȺ��䣬���˵ģ���֪�ж��١�\n");
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

void init()
{
	add_action("do_attack", "attack");
}

void die()
{
	object ob;

	message_vision("\n$N���ڶ����ˣ����ϰ�ããһƬ��\n", this_object());
	destruct(this_object());
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	object owner;
	object here = environment(me);

	if( (owner=present(me->query("owner"),here)) ){
		owner->add("combat_exp",2+random(3) );
		owner->add("potential",1+random(3) );
		if( owner->query("potential") > owner->query("max_potential") )
			owner->set("potential",owner->query("max_potential") );
		me->improve_skill("bee-training", 20+random(20), 0);
	}

	victim->apply_condition("yufeng_poison", 5 + random(5) 
		+ victim->query_condition("yufeng_poison"));
}

int do_attack(string arg){
	object env, obj, ob, me = this_player(),bees;
	string target_dir, dir, dest, victim;
	mapping exit;

	if (!arg) return 0;

	victim = arg;
	if ( victim == me->query("id") ) return notify_fail("���Ⱥ��֪���룬ֻ��Χ�����ת��\n");

	ob = present(victim, environment(me));
	bees = present("yufeng qun",environment(me));

	if (!ob) return notify_fail("���ﲢ�޴��ˣ�\n");

	message_vision(HIR "$N��������������ָ�����Ⱥ��$n��ȥ��\n" NOR, me, ob);

	if ( query("owner") != me || ob->query("race") != "����" 
		|| ob->query("family/family_name") == "��Ĺ��"){
		message_vision( "$N��֪���룬ֻ��Χ�����ת��\n" NOR, bees );
		return 1;
	}

	if( random(20) ){
		message_vision( HIW"ֻ��$N�������$n���˹�ȥ��\n" NOR, bees, ob );
		bees->kill_ob(ob);
		ob->kill_ob(me);
	}
	else
		message_vision( "$N��֪���룬ֻ��Χ�����ת��\n" NOR, bees );

	return 1;
}

