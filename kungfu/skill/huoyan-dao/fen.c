// Code of ShenZhou
// /kungfu/skill/huoyan-dao/fen.c  perform ��
// Summer, 11/10/96.
// kane, 25/11/98.

#include <ansi.h>
#include <armor.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        object armor;
        int damage, jiali, jiajin, ap, dp, pp, dmg, lvl, my_exp, max_dmg;
		int att, attt;    // temp
        string *limbs, limb, type, result, str, dodge_skill;

        my_exp = me->query("combat_exp");
        type = "����";

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�㲻��ս���С�\n");

        if ( objectp(me->query_temp("weapon")) )
                return notify_fail("�㲻�ǿ��֡�\n");

        if( (lvl=(int)me->query_skill("huoyan-dao", 1)) < 120 )
                return notify_fail("��Ļ��浶��Ϊ������\n");

        if ( me->query_skill_mapped("force") != "xiaowuxiang"
        && me->query_skill_mapped("force") != "longxiang-banruo")
                                         return notify_fail("�������ڹ����ԣ�\n");

        if( me->query("neili") <= lvl*2 )
                                         return notify_fail("�������������\n");

        if( me->query("jingli") <= 150 )
                                         return notify_fail("��ľ���������\n");

        message_vision(HIR "$N����һ�������������������������Ʊ��ͨ�죬���һ������������$n����Ӱ��������һ�Ż���֮�С�\n\n" NOR, me,target);
        lvl = (int)(lvl / 5);
        me->add("neili", -lvl*2); 
        me->add("jingli", -100);  
        jiali = me->query("jiali");
        jiajin = me->query("jiajin");

		att = (me->query("neili", 1) + me->query("qi", 1))/200;   // temp
		att = random(att);			// temp
		me->add_temp("apply/attack", att);		//temp
		


/*
        attack = me->query("combat_exp")/1000; // 800k /1k = 800
        attack += me->query("max_neili")/5; // assume u have 4k max neili only, it's 4000/5 = 800
        attack += me->query("neili")/5; // now you dazuo to 7k temp neili, you have 7k/5 = 1400
        defense = target->query("combat_exp")/1000; // 800k /1k = 800
        defense += target->query_skill("parry"); // now assume ur opponent has 300 enable parry, it's 300
        defense += target->query_skill("dodge"); // and assume has 300 enable dodge, it's 300
        defense += target->query("jingli"); // add jingli factor, usually 1200 jingli 800k exp
        attack = (attack+random(attack*2))/2; // now  (3000 + random(6000))/2 = 1500 + random(3000)
*/

        ap = COMBAT_D->skill_power(me,"strike", SKILL_USAGE_ATTACK);
        pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE)/3;
        dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE)/3;

	if (wizardp(me))
		printf("ap = %d , pp = %d , dp = %d .\n",ap*2,pp,dp);	// check overflow

        ap = (ap+random(ap*2))/2.5;

        if( ap > dp ) {
            tell_object(target, RED"��ֻ��һ���������棬�����ؿ�һ���ʹ��\n"NOR);
            if( target->query_temp("armor/cloth")){
                armor = target->query_temp("armor/cloth");
                if( armor->query("armor_prop/armor") < 150){
                
		if( armor->query("id") == "armor")
                     message_vision(HIY"ֻ��$N���ϵ�$n"+HIY+"�ѱ���÷��飬���һ�����Ƭ���·�ɢ��\n"NOR, target, armor);
		else message_vision(HIY"ֻ��$N���ϵ�$n"+HIY+"�ѱ���÷��飬���һ����Ʋ����ڵ��ϡ�\n"NOR, target, armor);

                     armor->unequip();
                     armor->move(environment(target));
                     armor->set("name", "�����" + armor->query("name"));
                     armor->set("value", 0);
                     armor->set("armor_prop/armor", 0);
                     target->reset_action();
                }
			}
            dmg = me->query_skill("force")+me->query_skill("strike")+me->query("jiajin");
            dmg = (dmg + random(dmg*2))/2;   
            damage = dmg*(1+random(me->query("jiali")/15)); 
            max_dmg = 2000;
            // set the max damage according to player level
            // since now player can do way more damage to 2k
            // so for a 5M player here, his max damage is 4k
            if (my_exp > 1000000) {
                max_dmg = max_dmg + (int)((my_exp-1000000)/2000);
            }
            if( damage > max_dmg )
            {  
                damage = max_dmg;
            }
            if( ap < pp ) damage = random(damage);
            //damage = random((int)me->query_skill("strike"))*5;  
            target->receive_damage("qi", damage,  me);
            target->receive_wound("qi", damage/2+random(damage/2), me);
            target->start_busy(1+random(2));                                                                        // target busy time > own busy time
            me->start_busy(2+random(2));
            if(jiali > me->query("neili"))
                jiali = me->query("neili");
            if(jiajin > me->query("jingli"))
                jiajin = me->query("jingli")-1;
            
            me->add("neili", -jiali-lvl);                                                               // cost neili 140
            me->add("jingli", -jiajin-lvl/2);                                           // cost jingli 120

            limbs = target->query("limbs");

            result = COMBAT_D->damage_msg(damage, type);
            result = replace_string( result, "$l", limbs[random(sizeof(limbs))]);
            result = replace_string( result, "$p", target->name() );
            message_vision(result, me, target);

            str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
            message_vision("($N"+str+")\n", target);

			me->add_temp("apply/attack", -att);		// temp
        
        } else {
/*
        dodge_skill = target->query_skill_mapped("dodge");
        if( !dodge_skill ) dodge_skill = "dodge";
        limb = limbs[random(sizeof(limbs))];
        str = SKILL_D(dodge_skill)->query_dodge_msg(limb);
        message_vision(str, me, target);
*/
            message_vision(HIY "$p�Ͻ�����Ծ�����ɣ��㿪$P�Ĺ�����\n" NOR, me, target);
			me->add_temp("apply/attack", -att);		// temp
            me->start_busy(1+random(3));
        }


        return 1;
}
