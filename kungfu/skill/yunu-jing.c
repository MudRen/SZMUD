// Code of ShenZhou
///kungfu/skill/yunu-jing ��Ů�ľ�
//maco�汾
#include <ansi.h>
#include <combat.h>

inherit FORCE;
string check() { return "force"; }
#include "/kungfu/skill/force_list.h"

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
        int lvl = (int)me->query_skill("yunu-jing", 1);
                mapping skl; 
        string *sname;
        int i, k=0;
        int t = 1, j;
        for (j = 1; j < lvl / 10; j++) t *= 2;
                skl=this_player()->query_skills();
        sname=sort_array( keys(skl), (: strcmp :) );

        if(me->query_skill("this_skill") > 99){

        for(i=0; i<sizeof(skl); i++) {
                if (SKILL_D(sname[i])->check() == "force")
                k++;  
        }

        if ( k >=2 )
        return notify_fail
("�����ڲ�ͬ���������ײ����������������书��\n");
        }

        if ( me->query("gender") == "����" && lvl > 49)
                return notify_fail("���޸����ԣ������������������������Ů�ľ���\n");

        if ( me->query("gender") == "����" && lvl > 80)
                return notify_fail("����Ϊ���ӣ��������������Ů�ľ���\n");

        if ( me->query("class") == "bonze" )
                return notify_fail("��Ů�ľ������������ϣ���Υ��������徻֮�⣬"
                        +RANK_D->query_respect(me)+"���޴˹������������\n");

        if ((int)me->query_skill("force", 1) < 10 
          || (int)me->query_skill("force", 1)/2 < lvl/3 )
                return notify_fail("��Ļ����ڹ���򻹲�����\n");

        if (lvl > 10 && (int)me->query("shen") < t * 100
             && me->query_skill("taoism", 1) < 100) 
                return notify_fail("�����������̫���ˡ�\n");

        return 1;
}

int practice_skill(object me)
{
        if ( me->query_skill("yunu-jing", 1) < 150 )
                return notify_fail("�����Ů�ľ���Ϊ������ֻ����ѧ(learn)�������������ȡ�\n");
        if ( me->query_temp("weapon") )
                return notify_fail("��ϰ��Ů�ľ�������֣��������ķ��ɡ�\n");
        if ( (int)me->query("qi") < 70 )
                return notify_fail("�������������ϰ��Ů�ľ���\n");
        if ( (int)me->query("jingli") < 70 )
                return notify_fail("��ľ���������ϰ��Ů�ľ���\n");
        if ( (int)me->query("neili") < 70 )
                return notify_fail("�������������ϰ��Ů�ľ���\n");

        me->add("neili", -60);
        me->receive_damage("jingli", 60, "����͸֧��������");
        me->receive_damage("qi", 60, "����͸֧��������");
        return 1;
}

string exert_function_file(string func)
{
        return __DIR__"yunu-jing/" + func;
}


mixed hit_by(object me, object victim, int damage, int damage_bonus, int factor)
{
        object weapon1 = me->query_temp("weapon");
        object weapon2 = victim->query_temp("weapon");
        int ap, dp;
        string result;

        if ( (int)victim->query_skill("yunu-jing", 1) < 80 ) return damage;

        dp = COMBAT_D->skill_power(victim, "force", SKILL_USAGE_DEFENSE);
        if (objectp(weapon2) && (string)weapon2->query("skill_type") == "sword" ) {
                if ( victim->query_skill_mapped("parry") != "yunu-jian" )
                        return damage;
                dp /= 3;
                dp += COMBAT_D->skill_power(victim, "parry", SKILL_USAGE_DEFENSE)/2;
        } else if (!objectp(weapon2) && ( victim->query_skill_mapped("parry") == "tianluo-diwang" || victim->query_skill_mapped("parry") == "yunu-jian" ) ) {
                if ( victim->query_skill_prepared("strike") != "tianluo-diwang" )
                        return damage;
                dp += COMBAT_D->skill_power(victim, "parry", SKILL_USAGE_DEFENSE);
        } else
                return damage;

        ap = COMBAT_D->skill_power(me, "force", SKILL_USAGE_ATTACK);
        if (objectp(weapon1))
                ap += COMBAT_D->skill_power(me, weapon1->query("skill_type"), SKILL_USAGE_ATTACK);
        else 
                ap *= 2;

        ap /= 100;
        dp /= 100;

if (wizardp(victim)) tell_object(victim, sprintf("ap: %d, dp: %d\n", ap, dp));
	if(me->query_temp("shentong")) {
                        result = "$n��$N����������Ҳ�����£���������Ů�ľ��ϵ��书һһ�ƽ⣡\n";
                        damage_bonus = 0;
                                me->start_busy(1+random(1));
                        result += "( $N"+ COMBAT_D->status_msg((int)me->query("qi")*100/(int)me->query("max_qi")) + " )\n";
	
	}
	
        if ( random(ap+dp+dp) > ap ) {
                if (objectp(weapon2) && objectp(weapon1) && (string)weapon1->query("skill_type") == "sword" && me->query_skill_mapped("sword") == "quanzhen-jian") {
                        result = "��֪$n��ʹ��Ů��������ȫ�潣���Ķ�ͷ������һ��������������������д���$Nһ����\n";
                                me->start_busy(1+random(1));
                        if (damage + damage_bonus > 0)
                                me->receive_damage("qi", (damage + damage_bonus)/2, victim);
                        result += "( $N"+ COMBAT_D->status_msg((int)me->query("qi")*100/(int)me->query("max_qi")) + " )\n";
                } else if (objectp(weapon2) && objectp(weapon1) && (string)weapon1->query("skill_type") == "whip" && me->query_skill_mapped("sword") == "duanyun-bian"){
                        result = "��֪$n�Զ��Ʊ޷����Ѿ���͸���������ת��$Nδ���˵У�����һ����\n";
                                me->start_busy(1+random(1));
                        if (damage + damage_bonus > 0)
                                me->receive_damage("qi", (damage + damage_bonus)/2, victim);
                        result += "( $N"+ COMBAT_D->status_msg((int)me->query("qi")*100/(int)me->query("max_qi")) + " )\n";
                }  else if (!objectp(weapon2) && !objectp(weapon1) &&  (me->query_skill_prepared("strike") == "sanhua-juding" || me->query_skill_prepared("cuff") == "chunyang-quan" ||((string)weapon1->query("skill_type") == "sword" && me->query_skill_mapped("sword") == "quanzhen-jian") 
||((string)weapon1->query("skill_type") == "whip" && me->query_skill_mapped("whip") == "duanyun-bian") ) ){

                        result = "����$n��Ȼһ�ư�������Ӱ���٣����ƾ��ƹ�$N�ֱۣ�������$N�ؿڣ�������Ů�ľ�������ȫ���书�ľ��У�\n";
                        if (damage + damage_bonus > 0)
                                me->receive_damage("qi", (damage + damage_bonus)/2, victim);

                        result += "( $N"+ COMBAT_D->status_msg((int)me->query("qi")*100/(int)me->query("max_qi")) + " )\n";


		}
                damage_bonus = -5000; // just a number negative enough
                return ([ "result" : result, "damage" : damage_bonus ]);
        } else if( random(ap+dp+dp+dp) > ap ) {
                if (objectp(weapon2)&& objectp(weapon1) &&  (me->query_skill_prepared("strike") == "sanhua-juding" || me->query_skill_prepared("cuff") == "chunyang-quan" ||((string)weapon1->query("skill_type") == "sword" && me->query_skill_mapped("sword") == "quanzhen-jian") 
||((string)weapon1->query("skill_type") == "whip" && me->query_skill_mapped("whip") == "duanyun-bian") ) ) {
                        result = "$n�������飬�ƿ�����һ��ȫ���书��\n";
                        damage_bonus = 0;
                } else if (!objectp(weapon2)&& !objectp(weapon1) &&  (me->query_skill_prepared("strike") == "sanhua-juding" || me->query_skill_prepared("cuff") == "chunyang-quan" ) ) {
                        result = "����$n��ȫ����ȭ�����о��죬���ֻ��⣬��$N���ھ�ȫ��ж��һ�ԡ�\n";
                        damage_bonus = -5000; 
                }
                return ([ "result" : result, "damage" : damage_bonus ]);
        } else 
                return damage;

}
