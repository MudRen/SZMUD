// Code of ShenZhou
// huagong-dafa.c ������
// by yucao
// modified by cleansword

#include <ansi.h>
#include <combat.h>

inherit FORCE;
string check() { return "force"; }
int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        int i = (int)me->query_skill("huagong-dafa", 1);
        int t = 1, j;
        for (j = 1; j < i / 10; j++) t*= 2;
        if ((int)me->query_skill("force", 1) < 10
          ||(int)me->query_skill("force", 1)/2 < i/3 )
                return notify_fail("��Ļ����ڹ�����㣬����ѧ�����󷨡�\n");
        if (i > 10 && i < 200 && (int)me->query("shen") > t * 100)
                return notify_fail("ѧ�����󷨣�Ҫ�ĺ���������������������ò���ѽ��\n");
        if ( me->query_skill("buddhism",1) || me->query_skill("taoism",1)
          || me->query_skill("mahayana",1) || me->query_skill("lamaism", 1))
                return notify_fail("������ͺ¿ţ�����ǵ��ķ�����ѧ��������ʲ�ݣ�\n");
        if ( me->query_skill("hunyuan-yiqi",1) || me->query_skill("linji-zhuang", 1)
        || me->query_skill("huntian-qigong",1) || me->query_skill("longxiang-banruo", 1)
        || me->query_skill("taiji-shengong",1) || me->query_skill("zixia-gong",1)    
        || me->query_skill("dulong-dafa", 1) || me->query_skill("kurong-changong", 1)
        || me->query_skill("bitao-xuangong", 1) )
                return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�����󷨣���\n");
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("������ֻ����ѧ(learn)�������������ȡ�\n");
}


mixed hit_by(object me, object victim, int damage, int damage_bonus, int factor)
{
        object weapon1 = me->query_temp("weapon");
        object weapon2 = victim->query_temp("weapon");

        int ap, dp;
        string result;

	if ((int)victim->query_temp("hua")!=1) return damage;
	
	dp = (int)victim->query_skill("huagong-dafa",1);

        if (objectp(weapon2) ){
                dp += victim->query_skill("tianshan-zhang",1);
        } else if (!objectp(weapon2) ) {
                if ( victim->query_skill_prepared("strike") != "chousui-zhang"  || victim->query_skill_prepared("claw") != "sanyin-zhua")
                        return damage;
                dp += victim->query_skill("chousui-zhang",1);
        } else return damage;

        ap = me->query_skill("force",1);
        if (objectp(weapon1))
                ap += me->query_skill("dodge");
        else
                ap *= 2;

        if ( random(ap+dp) > ap ) {
                if ( objectp(weapon2) && objectp(weapon1)) {
                        if (damage + damage_bonus > 0)
                        {                 
		                me->add("neili", -victim->query_skill("huagong-dafa",1)/3*2);
				victim->add("neili", victim->query_skill("huagong-dafa",1)/3*2);
                                result = HIB"$n���������˵����ϣ���$N�ı����ཻ��$NͻȻ��������ԴԴ�����ӵ����˳�ȥ��\n"NOR;
                        }
                        else result = HIB"ֻ��$n�����ȷ����������⣬$N����һ�����������������������˻�ȥ��\n"NOR;
                }
                else if(objectp(weapon2) && !objectp(weapon1)){
                        if (damage + damage_bonus > 0)
			{
			        result = HIB"$n��������Ȼ��Ȼ������$NͻȻ��������ԴԴ�����ӵ����˳�ȥ��\n"NOR;                      
                                me->add("neili", (-victim->query_skill("huagong-dafa",1)-me->query("jiali"))/3*2);
	            		victim->add("neili", victim->query_skill("huagong-dafa",1)/3*2);
			}
                	else result = HIB"ֻ��$n���΢΢��Ц���ƺ��������֣�$N����һ�������������������и�Ϊ���С�\n"NOR;
		}
        	else if( !objectp(weapon2) && objectp(weapon1) ) {
                        if (damage + damage_bonus > 0)
                        {                 
		                me->add("neili", -victim->query_skill("huagong-dafa",1)/3*2);
				victim->add("neili", victim->query_skill("huagong-dafa",1)/3*2);
                                result = HIB"$n������һ�ȣ�˳�ְ�$N�ı���һ����$NͻȻ��������������ʧ��\n"NOR;
                        }
                        else result = HIB"ֻ��$n�ٺ�һЦ����Ȼ���в��ܣ�$N����һ�����������������������˻�ȥ��\n"NOR;
                }
                else{
                        if (damage + damage_bonus > 0)
                        {                 
		                me->add("neili", -victim->query_skill("huagong-dafa",1)/3*2);
				victim->add("neili", victim->query_skill("huagong-dafa",1)/3*2);
                                result = HIB"$N�����ƺ�$n������һ�������������ɿ�����˳�ȥ��\n"NOR;
                        }
                        else result = HIB"ֻ��$n�ٺ�һЦ����Ȼ���в��ܣ�$N����һ�����������������������˻�ȥ��\n"NOR;
                }
	}
        return ([ "result" : result, "damage" : damage_bonus ]);
}


string exert_function_file(string func)
{
        mapping skl;
        string *sname;
        int v, k=0;

        skl=this_player()->query_skills();
        sname=sort_array( keys(skl), (: strcmp :) );

        for(v=0; v<sizeof(skl); v++) {
                if (SKILL_D(sname[v])->check() == "force")
                k++;
        }
        if ( k >=2 ){
        tell_object(this_player(), "�����ڲ�ͬ���������ײ������ʩչ�����󷨡�\n");
        return 0;
        }

        return __DIR__"huagong-dafa/" + func;
}
