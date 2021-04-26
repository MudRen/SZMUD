// Code of ShenZhou
// pixie-jian.c ��а����
// changed by wzfeng@xkx
//last chang 2000 4 11
#include <ansi.h>
#include <combat.h>
inherit SKILL;

string *dodge_msg = ({
        "ͻȻ֮�䣬��Ӱ���ϣ�$n��󻬳����࣬��ʱ�ֻص���ԭ�أ������$N��һ�С�\n",
        "$n�ֱۻ�ת����$N������һ�ƣ�˳������һ�ԡ�\n",
        "$n�����������$N������Ѹ���ޱȵ�һ����˳������һ�ԡ�\n",
        "$n����Ʈ����������ȣ�ת�˼�ת���Ʋ���$N����󣬶����$N��һ�С�\n",
        "$Nֻ����ǰһ�����ƺ�����$n����һ�ϣ����漴�ּ�$n�ص�ԭ�أ�ȴ�ƴ�δ�뿪��\n",
        "$N�۾�һ����$n��û����Ӱ��ͻȻ$n���������һ��$N��ͷ������Ծ����\n",
        "$n��ȻһЦ������֮����$N����֪����Ǻã�ͣס�˹�����\n",
        "$n��һ������һ������һ������һ������$N���������������������²����������ް��������\n",
        "$n���ִ�Ĵָ��ʳָ��סһ���廨�룬����һ�٣���ס���ƣ�$N����ʽ��ʹ����ȥ��\n",
        "$n��������������ʳָ��������$N����Ŀ���̣��������ܾ��˵Ĵ򷨣�\n",
        "$n���ҵ���أ�Ժ�����Ͼ��������$N���ޣ����ù��򣬺ù��򣡡�\n",
});


string  *msg = ({
"$N����һ�䣬��������۵�$n��ǰ����಻��һ�ߣ�����$w�Ѿ��̵�$n��$l",
"������Ӱ������$N���е�$w��$n��$lֱ�����������籼�ף��ܲ��ɱ�",
"$N������ϣ�������$n�ļ���һ���ٺ�ɳ�ȥ�������е�$wȴָ��$n��$l",
"$NͻȻԾ�����࣬$nһ̧ͷ�����ֿ��в���$N����Ӱ����һ�ɺ���ȴ�����Ϯ��",
"$N��һ������һ������һ������һ������$n��������������������һת������$n",
"�����$N���������ϣ�˫�����õ��ģ���������֮������$n����֮�ʵ���$w����$n",
"$N����Ʈ����������ȣ�ת�˼�ת���Ʋ�������һ������$n������֮��֮�죬ֱ�Ƿ�����˼",
"$N����һ�٣�վ��Ƭ�̣�����$n����󷽻������࣬���ſ������׵Ļص�ԭ��",
"$NǱ���������������ˣ�����$n������ת������$w��ʹ����Ҳ��������һ�㣬Խ��Խ��",
"ͻȻ$N����$w����һ�ã�����$n΢һ����֮��ֱȡ$n��$l���Ƶ���������",
"����$nһ��֮�ʣ�$N����Ծ�����ߣ���������أ����Ӹ�������ˢˢ��������$n��ȥ",
"$N��Ȼ����Ϊ�����ó�����������Ӱ���ٻ���$n������$w�û����������н���$n��$l",
"$nֻ����ǰһ�����ƺ�����$N����һ�ϣ����漴�ּ�$N�ص�ԭ�أ�ȴ�ƴ�δ�뿪",
"$Nһ����У����������ڰ����һת������ޱȵķ�������������$w�ƿ�ֱ��$n$l",
"$N������������ȣ�Ʈ����ȥ��ֱ�����̣����е�$wȴ���Ƕ���$n����",
"$Nһ����Ц������Ｒ����ǰ�������Ƕ������ã�һ˲֮�䣬��$n����Ѳ���һ�ߣ����˵ı��Ӽ���Ҫ����һ��",
"$N�����������$n������Ѹ���ޱȵ�һ���������ֱۻ�ת������$n������һ��",
"$Nһ��ͦ�̣��������ţ���̬֮�У������л�ɽ��Ů������ѧ����Ů��ʮ��ʽ���ķ��ˣ�ֻ�Ǵ���������ɭɭ��а��",
"$N����һȦ����ת$w����ش̳���ˢˢˢ������ʽ�����о���ָ��$n��Ҫ��"
});


mapping *action = ({
([      "action":"ͻȻ֮�䣬��Ӱ���ϣ�$N��󻬳����࣬��ʱ�ֻص���ԭ��",
        "force" : 50,
        "dodge" : 40,
        "damage": 50,
        "lvl" : 0,
        "skill_name" : "��Ӱ��??",
        "damage_type":  "����"
]),
([      "action":"$N�����������$n������Ѹ���ޱȵ�һ����$n��Щ�����Լ�С��",
        "force" : 60,
        "dodge" : 40,
        "damage": 50,
        "lvl" : 10,
        "skill_name" : "�Լ�С��",
        "damage_type":  "����"
]),
([      "action":"�����$N�����ϣ��ڵ�$n�����̳�һ��������˲��Ծ��ԭ��",
       "force" : 70,
        "dodge" : 45,
        "damage": 60,
        "lvl" : 20,
        "skill_name" : "������",
        "damage_type":  "����"
]),
([      "action":"$nֻ����ǰһ�����ƺ�����$N����һ�ϣ����漴�ּ�$N�ص�ԭ�أ�ȴ�ƴ�δ�뿪",
        "force" : 80,
        "dodge" : 40,
        "damage": 70,
        "lvl" : 30,
        "skill_name" : "��ǰһ��",
        "damage_type":  "����"
]),
([      "action":"$NͻȻ���з�һ�䣬һ�С�����Ū�ѡ���$w�����������ʽ������ס�$n����֮�з������",
        "force" : 90,
        "dodge" : 43,
        "damage": 75,
        "lvl" : 40,
        "skill_name" : "�з�һ��",
        "damage_type":  "����"
]),
([      "action":"$N����ˣ�$n��׷������ͻȻ��$N����$n��ǰ��һ�С��������𡹣�����$wֱָ$n��$l",
        "force" : 100,
        "dodge" : 40,
        "damage": 80,
        "lvl" : 50,
        "skill_name" : "�����",
        "damage_type":  "����"
]),
([      "action":"$N����Ʈ����������ȣ�ת�˼�ת��һ�С��������������Ʋ���$n�����",
        "force" : 140,
        "dodge" : 40,
        "damage": 90,
        "lvl" : 60,
        "skill_name" : "�������",
        "damage_type":  "����"
]),
([      "action":"$Nһ����Ц��һ�С����Ǹ��¡�������Ｒ����ǰ��һ˲֮�䣬��$n����Ѳ���һ�ߣ�$w�漴�ݳ�",
        "force" : 130,
        "dodge" : 35,
        "damage": 80,
        "lvl" : 70,
        "skill_name" : "������ǰ",
        "damage_type":  "����"
]),
([      "action":"$N�ȵ������ã������㼴�γ�$w��һ�С����ഩ���������ִ̳�������ת����ȥ",
        "force" : 145,
        "dodge" : 35,
        "damage": 100,
        "lvl" : 80,
        "skill_name" : "���ִ̳�",
        "damage_type":  "����"
]),
([      "action":"$N��س嵽$n��ǰ��һ�С���ظ��Ŀ��������$wֱ��$n���ۣ�$n��æ�мܣ�����$N��$wͻȻת��",
        "force" : 190,
        "dodge" : 50,
        "damage": 125,
        "lvl" : 90,
        "skill_name" : "ֱ������",
        "damage_type":  "����"
]),
([      "action":"$N����Ծ��$ņ��һ����������$Nһ�С����Ƿɶ项������ֱ����£�����$w����$n��$l",
        "force" : 260,
        "dodge" : 60,
        "damage": 130,
        "lvl" : 100,
        "skill_name" : "����Ծ��",
        "damage_type":  "����"
]),
([      "action":"$Nһ�С�Ⱥа���ס�����֦�Ͱڣ�$n��ǰ�·�ͻȻ�������߰˸�$N���߰�ֻ$wһ�����$n",
        "force" : 320,
        "dodge" : 75,
        "damage": 135,
        "lvl" : 110,
        "skill_name" : "Ⱥа����",
        "damage_type":  "����"
]),
});


int valid_enable(string usage) 
{ 
    return usage == "sword" || usage == "dodge" || usage == "parry"; 
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
        int i, level, neili, force,damage;


        level   = (int) me->query_skill("pixie-jian",1);
        force = me->query_skill("force");
		damage= (random(force)+force)/2;
		if(damage>300) damage=300;

        neili = me->query("neili");
        if (level > 120 && force > 180 && neili > 500 
            && me->query("max_neili") > 1200
            && (random(me->query_int()) > 25
			|| random(me->query_dex()) > 27)){
            return([      
                   "action": msg[random(sizeof(msg))],                   
                   "force" : 150+random(neili/100),
                   "dodge" : 40+random(neili/100),
                   "damage": damage,
                   "damage_type" : "����",
                   ]);
            }
           for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
	if (me->query_skill("pixie-jian",1) >199)
		return 1;
        
        return notify_fail("��а���������ֹ屦����ֻ��ͨ����ϰ���������䡷��ѧϰ��\n");
}

string perform_action_file(string action)
{

        return __DIR__"pixie-jian/" + action;
}


int practice_skill(object me)
{
        object weapon;
		int lvl;
		
		lvl=me->query_skill("pixie-jian",1);

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("jingli") < 50)
                return notify_fail("��ľ���������\n");

        if (me->query_skill("pixie-jian",1) < 200) return 0;
		if((int)me->query("pixie/buyin-wan/lvl")<lvl)
			return notify_fail("������֮�����㣬�޷���ϰ���ߵȼ��ı�а������\n");
        me->receive_damage("jingli", lvl*2/10+random(10));
        return 1;
}


/*mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{                
   object weapon = me->query_temp("weapon");

   if( damage_bonus < 100 ) return 0;
   if(   ((string)weapon->query("id")=="xiuhua zhen" 
      || (string)weapon->query("id")=="qijue zhen")  
      && random(damage_bonus/2) > victim->query_str()){
        victim->receive_wound("qi", (damage_bonus - 100) / 2 );
        if (random(5) > 3) return HIR "ֻ�����͡�һ����һ��Ѫ˿��"+victim->name()+"���̵���״������\n" NOR;
        }

        if( weapon->query("poison_type") ) {
                victim->apply_condition(weapon->query("poison_type"), 
                1+weapon->query("poison_applied"));
                message_vision(RED"$N�ƺ������˿��е㷢����\n"NOR, victim);
        }
        else if( weapon->query("poison_applied") ){
                victim->apply_condition("snake_poison",
                1+weapon->query("poison_applied"));
                message_vision(RED"$N�ƺ������˿��е㷢����\n"NOR, victim);
        }
}
*/


int is_special()
{
        return 1;
}

mixed hit_by(object me, object victim, int damage)
{
	
        int ap, dp, level;
        object weapon = me->query_temp("weapon");
        mapping prepare;
        string result, attack_skill;
        if (!living(victim)
			||victim->query_skill_mapped("dodge") != "pixie-jian"
			||victim->query_skill_mapped("parry") != "pixie-jian"
			||victim->query_skill_mapped("sword") != "pixie-jian"
			||random(victim->query_dex())<10)
			
		{
			return damage;
		}

		if(!victim->query_temp("pixie/guimei"))
			return damage;
//		if(!victim->is_busy())
//			return damage;


	
		//��dugu-jiujian������pixie-jian
		if((weapon)&&me->query_skill_mapped("sword") == "dugu-jiujian" )
		{
			return damage;
		}
		//����Է�ʹ������
		prepare = me->query_skill_prepare();
		if( !prepare ) prepare = ([]);

		 if( objectp(weapon) ) attack_skill = weapon->query("skill_type");
        else switch( sizeof(prepare) )
        {
                case 0: attack_skill = "unarmed"; break;
                case 1: attack_skill = (keys(prepare))[0]; break;
                case 2: attack_skill = (keys(prepare))[me->query_temp("action_flag")]; break;
        }
		
		if(weapon)
			ap=me->query_skill(weapon->query("skill_type"));
		else 
			ap=me->query_skill(attack_skill,1);
		dp=victim->query_skill("dodge",1);
	        ap += me->query_skill("dodge",1)/2;

		if(victim->is_busy()) dp+=dp;
		

		if( wizardp(victim) &&me->query("env/pixie_test"))
		printf(HIC"guimei_start\ ap=%d\tdp=%d\t\n",ap,dp);

		if ( random(dp) > (random(ap)*2/3) &&(me->query("jingli")>300)) {
			//��dugu-jiujian������pixie-jian
			if((weapon)&&me->query_skill_mapped("sword") == "dugu-jiujian" 
				&&me->query_skill("dugu-jiujian",1)*2/3>random(victim->query_skill("dodge",1)/2))

		{
			result = HIR "$n�����䣬���������飬Ӱ�ƹ��ȣ���Ҫ�ӽ����ж����\n"NOR;
			result += HIC "$N����һ����������ת��������ָ������$n������֮����\n"NOR;
            me->add("jingli", -20+random(20));
			me->start_busy(1+random(1));
			
		}
			else {


                result = HIR "$n�����䣬�������飬Ӱ�ƹ��ȣ�$Nֻ����ǰһ������������ʽ������$n�˻��ܿ���\n"NOR;

                damage = 0;
				me->add("jingli", -20+random(20));
//				message_vision(result, me, victim);
				return ([ "result" : result, "damage" : damage ]);
			}
		}
        else if ( random(3*dp) > random(ap)&&(me->query("jingli")>300)) {
			if((weapon)&&me->query_skill_mapped("sword") == "dugu-jiujian" 
				&&me->query_skill("dugu-jiujian",1)*2/3>random(victim->query_skill("dodge",1)/2))
				{
				result = HIR "$n��һ������һ������һ������һ�����뽫$N������жȥ��\n" NOR;
				result += HIC "����$N������ת��������ָ������$n������֮����\n"NOR;
	            me->add("jingli", -20+random(20));
				me->start_busy(1+random(2));
				}
			else
			{
				result = HIR "$n��һ������һ������һ������һ������$N������жȥ��롣\n" NOR;
                damage /= 3+random(10);
	            me->add("jingli", -10+random(10));
//				message_vision(result, me, victim);
				return ([ "result" : result, "damage" : damage ]);
			}
        }
		return damage;
//		return ([ "falg" : "can", "damage" : damage ]);

}







