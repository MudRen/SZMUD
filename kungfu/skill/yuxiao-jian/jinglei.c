// Code of ShenZhou
//jinglei ��ָ����(������｣��ʱ)
// kane 12/9/1997
// maco 26/8/1999�޸�

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int level;
	string msg;
	object w,myw;

        level   = (int) me->query_skill("tanzhi-shentong",1);

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��ָ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	        
	w = target->query_temp("weapon");
	myw = me->query_temp("weapon");

        if (!w) return notify_fail("�Է�û����������Ҫ�õ�ָ�����𣿣�\n");

        if( !me->query_temp("th_jianzhi") )
                return notify_fail("������û�����ý�ָ����Ĺ��ƣ������ڳֽ�ʱʩչ��ָ���ף�\n");

        if( me->query_skill_mapped("finger") != "tanzhi-shentong")
                return notify_fail("����ʩչ��ָ�����ǵ�ָ��ͨ��\n");

        if( me->query_skill_prepared("finger") != "tanzhi-shentong")
                return notify_fail("�㻹û��������ʩչ��ָ��ͨ��\n");

	if( me->query_skill_mapped("force") != "bitao-xuangong")
                return notify_fail("�����õ��ڹ��롸��ָ���ס��ķ���㣣�\n");

        if( me->query_skill("bitao-xuangong", 1) < 120 )
                return notify_fail("����ڹ���Ϊ���δ������δ���򡸵�ָ���ס���\n");

	if( me->query_skill("finger",1) < 120 )
		return notify_fail("�����ָ����Ϊ����������δ���򡸵�ָ���ס���\n");

	if( me->query_skill("tanzhi-shentong",1) < 120 )
                return notify_fail("�㵯ָ��ͨ��Ϊ����������δ���򡸵�ָ���ס���\n");
        
	if( me->query("neili") <= 600 )
                return notify_fail("�����������������������ʩչ��ָ���ף�\n");
	
	message_vision(HIG"$N������ת�����죬��ɫ�ɺ�ת�ף����ɰ�ת�࣬����"+myw->name()+HIG"����˿������������ָ��ȴ�Ѱ����ھ���\n"NOR,me,target);        
        if (me->query("combat_exp")>random(target->query("combat_exp")*3/2) ) {
        //neili��jingli���ĽϿ���ʱΪ��

		me->add("neili", -150);
		me->add("jingli", -60);
                remove_call_out("bash_weapon");
                call_out("bash_weapon", random((int)(600/level)), me, target);
        } else {
		message_vision(HIW"$N��֮�£�����һ�ּ�����$n���ò�ɢȥ������ȫ���мܣ�\n"NOR, target, me);
		COMBAT_D->do_attack(target, me, target->query_temp("weapon"));
	}

	return 1;
}

int bash_weapon(object me, object victim)
{
        object ob,myw;
        int wap, wdp, busy;

	if ( !victim ) return 1;
        ob = victim->query_temp("weapon");
        myw = me->query_temp("weapon");
	busy = me->query("max_neili") + me->query("max_jingli");
	if(busy > 3000) busy = 3000;

	me->start_busy(1);
        me->reset_action();

	message_vision(HIY"$Nһ����Ц��Ȧת"+myw->name()+HIY"��ס����������ָһ��һ�ţ���$n���е�"+ob->name()+HIY"��ȥ��ָ�����ն�����������΢΢������žž������֮������\n"NOR,me,victim);
        
	if( me->is_fighting(victim) && me->query("neili") > 100 ) {
                wap = (int)me->query("max_neili") / 10
                        + (int)me->query("neili")
                        + (int)me->query_str()
                        + (int)me->query_skill("finger")
			+ (int)me->query("combat_exp")/1000;
                wdp = (int)ob->weight() / 800
                        + (int)victim->query("neili")
                        + (int)victim->query_str()
                        + (int)victim->query_skill("parry")
			+ (int)victim->query("combat_exp")/1000;
                wap = (wap+random(wap))*3/4;
                if( wap > 2 * wdp && ob->query("weapon_prop/damage") < 80 ) {
			message_vision(HIW "ֻ������ž����һ����$N���е�"+ob->name()+HIW"�Ѿ���Ϊ���أ�\n"NOR, victim );                        
                        ob->unequip();
                        ob->move(environment(victim));
                        ob->set("name", "�ϵ���" + ob->query("name"));
                        ob->set("value", 0);
                        ob->set("weapon_prop", 0);
                        victim->reset_action();
			victim->start_busy(3+busy/300);
                } else if( wap > wdp ) {
			message_vision(HIW "$Nֻ��������"+ob->name()+HIW"�ѳֲ��������ַɳ���\n"NOR,victim);                        
                        ob->unequip();
                        ob->move(environment(victim));
                        victim->reset_action();
			victim->start_busy(3+random(busy/300));
                } else if( wap > wdp / 2 ) {
                        message_vision("$Nֻ��������"+ob->name()+"һ����Щ���֣�\n",victim);
                	victim->start_busy(random(3)+2);
		}
                else {
                        message_vision("$N��ָ������$n��"+ob->name()+"�ϣ�ð�����Ļ��ǡ�\n", me, victim);
                	me->start_busy(random(2));
		}
        }
}

