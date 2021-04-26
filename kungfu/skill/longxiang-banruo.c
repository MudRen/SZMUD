// Code of ShenZhou
// longxiang-banruo.c ѩɽ ���������
// Summer, 9/29/96. 
// kane, 25/01/99

#include <ansi.h>
inherit FORCE;
string check() { return "force"; }

#include "/kungfu/skill/force_list.h"

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
        mapping skl; 
        string *sname;
        int v, k=0;

	int i, nb, nf, nh, ns, ts;
	nb = (int)me->query_skill("lamaism", 1);
	nf = (int)me->query_skill("force", 1);
	nh = (int)me->query_skill("longxiang-banruo", 1);
	        skl=this_player()->query_skills();
        sname=sort_array( keys(skl), (: strcmp :) );

        if(me->query_skill("longxiang-banruo", 1) > 99){

       for(v=0; v<sizeof(skl); v++) {
                if (SKILL_D(sname[v])->check() == "force")
                k++;  
        }

        if ( k >=2 )
        return notify_fail("�����ڲ�ͬ���������ײ����������������ڹ���\n");
        }


	if ( me->query("class") != "lama" && nh > 39)
		return notify_fail("��δ����ţ���Ե�Ѷϣ��޷���������������˿�������������������\n");

	if ( nb < 120 && nb <= nh )
		return notify_fail("��������ķ���Ϊ�������޷���������������������\n");

	if ( nf < 10 || nf/2 < nh/3 )
		return notify_fail("��Ļ����ڹ���򻹲������޷���������������\n");



	return 1;
}

string exert_function_file(string func)
{
	return __DIR__"longxiang-banruo/" + func;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	string msg;
	int ap, dp;
        int damage, myneili, yourneili, my_max, your_max;
        string force_skill;
        mixed foo;
        string result;

	ap = me->query("combat_exp")/1000;
        ap += me->query_skill("force");
        dp = victim->query("combat_exp")/1000;
        dp += victim->query_skill("force");
        ap = (ap + random(ap*2))/2;

        msg = HIR"$N�����ս���������ڲ����������ԣ�������֮����$n��ȥ��\n"NOR;

        myneili = (int)me->query("neili");
        yourneili = (int)victim->query("neili");
        my_max = (int)me->query("max_neili")*2;
        your_max = (int)victim->query("max_neili")*2;
        myneili = my_max > myneili ? myneili : my_max;
        yourneili = your_max > yourneili ? yourneili : your_max;
        me->add("neili", - factor );
        damage = myneili/20 + factor - yourneili/25;

        if( me->query_temp("longxiang") && (ap > dp) ) {
                damage *= 2;
                message_vision(msg,me,victim);
        }

        if (force_skill = victim->query_skill_mapped("force") ) {
                foo = SKILL_D(force_skill)->hit_by(me, victim, damage, damage_bonus, factor);

                if (stringp(foo)) return (string)foo;
                else if (intp(foo)) damage = (int)foo;
                else if (mapp(foo)) return foo;
        }

        if ( damage > 0 )
                damage = damage * factor / (int)me->query_skill("force") * 2;

        if( damage < 0 ) {
                if( !me->query_temp("weapon")
                && random(victim->query_skill("force")) > me->query_skill("force")/2 ) {
                        damage = - damage;
                        me->receive_damage( "qi", damage * 2, victim);
                        me->receive_wound( "qi", damage, victim );
                        if( damage < 10 ) result = "$N�ܵ�$n�����������ƺ�һ����\n";
                        else if( damage < 20 ) result = "$N��$n���������𣬡��١���һ������������\n";
                        else if( damage < 40 ) result = "$N��$n������һ���ؿ������ܵ�һ���ش�����������������\n";
                        else result = "$N��$n������һ����ǰһ�ڣ��������ɳ�������\n";
                        result += "( $N"+ COMBAT_D->status_msg((int)me->query("qi")*100/(int)me->query("max_qi")) + " )\n";
                        damage_bonus = -5000; // just a number negative enough
                        return ([ "result" : result, "damage" : damage_bonus ]);
                }
                if( damage_bonus + damage < 0 ) return - damage_bonus;
                return damage;
        }

        damage -= victim->query_temp("apply/armor_vs_force");
        if( damage_bonus + damage < 0 ) return - damage_bonus;
        if( random(me->query_skill("force")) < damage )
                return damage;
}

mapping curing_msg(object me)
{
	return ([
		"apply_short"	: me->name() +"��Ŀ��ü���붨������",
		"start_self"	: HIY"���Ŀ������������Ϣ�������ڸ�����ת�������ơ�\n"NOR,
		"finish_other"	: me->name() +"�������������ֺ���\n",
	]);
}

//int practice_skill(object me)
//{
//	return notify_fail("���������ֻ����ѧ(learn)�������������ȡ�\n");
//}

int practice_skill(object me)
{
        if ( me->query_skill("longxiang-banruo", 1) < 200 )
                return notify_fail("��������������Ϊ������ֻ����ѧ(learn)�������������ȡ�\n");
        if ( me->query_temp("weapon") )
                return notify_fail("��ϰ���������������֡�\n");
        if ( (int)me->query("qi") < 150 )
                return notify_fail("�������������ϰ�����������\n");
        if ( (int)me->query("jingli") < 150 )
                return notify_fail("��ľ���������ϰ�����������\n");
        if ( (int)me->query("neili") < 150 )
                return notify_fail("�������������ϰ�����������\n");
        if ( (int)me->query("potential") < 1)
                return notify_fail("���Ǳ�ܲ�����\n");
        if( !present("longxiang jing", me)) 
                return notify_fail("������û����������������գ�����ô��Ҳû�ã�\n");
 
        if ( me->query_skill("longxiang-banruo", 1) < 300 ) {
                me->add("neili", -80);
                me->receive_damage("jingli", 80, "����͸֧��������");
                me->receive_damage("qi", 80, "����͸֧��������");
        }
        else {
                me->add("neili", -100);
                me->receive_damage("jingli", 100, "����͸֧��������");
                me->receive_damage("qi", 100, "����͸֧��������");
        }
        return 1;
}

