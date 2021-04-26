// Code of ShenZhou
#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
	set_name(HIB"��ʬ"NOR, ({ "poison corpse","corpse" }));
	set_weight(28000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ�߾���ҩ�ﰾ����ʬ�壬������֫������С��ͭƤ���ǣ������ޱȣ����������綾��\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$Nȡ��һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$nС�������պá�\n");
	}
  	init_staff(25);
	setup();
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        object obj;

	if( random(me->query_skill("poison",1)) <
victim->query_skill("force")/3*2 ) {
		message_vision(HIB
"$NͻȻ˫Ŀһ��������$nһ�ۣ���\n"NOR,this_object(), victim);
		tell_object(victim, HIB
"��ֻ��˫Ŀһʹ������һ�Σ��ƺ���������һ���޵���Ԩ��\n");
		victim->start_busy(random(me->query_skill("poison",1)/20));
	}

        if( random(me->query_skill("poison", 1)) > 100 ) {
                victim->apply_condition("xx_poison",
                query_temp("poison_effect")*2+victim->query_condition("xx_corpse_poison"));
        if(victim->query("poisoner") != me)
        victim->set("poisoner", me);
        }
}
