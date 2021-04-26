// Code of ShenZhou
// jiuyang-shengong ������
// by wsky


#include <ansi.h>
#include <combat.h>

inherit FORCE;
string check() { return "force"; }
int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        int i = (int)me->query_skill("jiuyang-shengong", 1);
        int t = 1, j;
        for (j = 1; j < i / 10; j++) t*= 2;

        if ((int)me->query_skill("force", 1) < 10
          ||(int)me->query_skill("force", 1)/2 < i/3 )
                return notify_fail("��Ļ����ڹ�����㣬����ѧϰ�����񹦡�\n");

        if ( me->query_skill("buddhism",1) || me->query_skill("taoism",1)
          || me->query_skill("mahayana",1) || me->query_skill("lamaism", 1))
                return notify_fail("������ͺ¿ţ�����ǵ��ķ�����ѧ��������ʲ�ݣ�\n");

        if ( me->query_skill("hunyuan-yiqi",1) || me->query_skill("linji-zhuang", 1)
        || me->query_skill("huntian-qigong",1) || me->query_skill("longxiang-banruo", 1)
        || me->query_skill("taiji-shengong",1) || me->query_skill("zixia-gong",1)    
        || me->query_skill("dulong-dafa", 1) || me->query_skill("kurong-changong", 1)
        || me->query_skill("bitao-xuangong", 1) || me->query_skill("hamagong", 1) )
                return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�����󷨣���\n");
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("������ֻ�ܿ����򡶾����澭�������������ȡ�\n");
}


mixed hit_by(object me, object victim, int damage, int damage_bonus, int factor)
{
        object weapon1 = me->query_temp("weapon");
        object weapon2 = victim->query_temp("weapon");

        int ap, dp;
        string result;

        dp = (int)victim->query_skill("jiuyang-shengong",1)+(int)victim->query_skill("parry",1);

        ap = me->query_skill("force",1);
        if (objectp(weapon1))
                ap += me->query_skill("dodge");
        else
                ap *= 2;

        if ( random(ap+dp) > ap ) {
                if ( objectp(weapon1)) {
                        if (damage + damage_bonus > 0)
                        {                 
                                damage_bonus=-random(4000);
                                result = HIM"$n����һ�࣬��$N�����ϵ�����жȥ��롣\n"NOR;
                        }
                        else {
                                result = MAG"$n����һ�࣬��$N�����ϵ�����жȥ��롣\n"NOR;
                                damage_bonus=-random(4000);
                        }
                }
                else if(!objectp(weapon1)){
                        if (damage + damage_bonus > 0)
                        {
                                damage_bonus=-random(4000);
                                result = HIG"$n��������Ȼ��Ȼ������������$N������һ����\n"NOR;                      
                        }
                        else {
                                result = MAG"$n��������Ȼ��Ȼ������������$N������һ����\n"NOR;
                                damage_bonus=-random(4000);
                        }
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
        if ( k >=2 && this_player()->query("id")!="wsky"){
        tell_object(this_player(), "�����ڲ�ͬ���������ײ������ʩչ�����񹦡�\n");
        return 0;
        }

        return __DIR__"jiuyang-shengong/" + func;
}