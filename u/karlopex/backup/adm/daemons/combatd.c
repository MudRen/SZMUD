//Cracked by Kafei
// combatd.c
// modified by sdong to solve overflow problem. 07/22/98
// modified by sdong for no_fight room 10/03/98
// modified by sdong to solve -exp opponent problem 04/17/2000

// #pragma optimize all

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_DBASE;

int MAXINT = 2147483647;

string *guard_msg = ({
    CYN "$Nע����$n���ж�����ͼѰ�һ�����֡�\n" NOR,
    CYN "$N������$n��һ��һ������ʱ׼���������ơ�\n" NOR,
    CYN "$N�������ƶ��Ų�����Ҫ�ҳ�$n��������\n" NOR,
    CYN "$NĿ��ת���ض���$n�Ķ�����Ѱ�ҽ��������ʱ����\n" NOR,
    CYN "$N�������ƶ����Ų����Ż����֡�\n" NOR,
});

string *catch_hunt_human_msg = ({
    HIW "$N��$n������������ۺ죬���̴���������\n" NOR,
    HIW "$N����$n��ȣ����ɶ������㣡��\n" NOR,
    HIW "$N��$nһ���棬������˵�ʹ���������\n" NOR,
    HIW "$Nһ��Ƴ��$n�����ߡ���һ�����˹�����\n" NOR,
    HIW "$Nһ����$n�����һ㶣���У����������㣡��\n" NOR,
    HIW "$N�ȵ�����$n�����ǵ��ʻ�û���꣬���У���\n" NOR,
    HIW "$N�ȵ�����$n�����У���\n" NOR,});

string *catch_hunt_beast_msg = ({
    HIW "$Nŭ��һ�������˹�������$n��\n" NOR,
    HIW "$N����$n�����ɱ��$n��\n" NOR,
    HIW "$N���������ͺ�ͻȻ���𹥻�$n��\n" NOR,});

string *catch_hunt_bird_msg = ({
    HIW "$N����$nһ��ŭ�����ɳ��˹�����\n" NOR,
    HIW "$Nŭ��������ͻȻ���𹥻�$n��\n" NOR,
    HIW "$Nһ����������Ȼ��$n����������\n" NOR,});

string *winner_msg = ({
    CYN "\n$N������Ц��˵���������ˣ�\n\n" NOR,
    CYN "\n$N˫��һ����Ц��˵�������ã�\n\n" NOR,
    CYN "\n$Nʤ�����У����Ծ�����ߣ�Ц�������ã�\n\n" NOR,
    CYN "\n$n��ɫ΢�䣬˵��������������\n\n" NOR,
    CYN "\n$n������˼�����˵�����ⳡ�����������ˣ�����������\n\n" NOR,
    CYN "\n$n���һ�ݣ�������Ҿ˵�����������ղ�������Ȼ������\n\n" NOR,
});

string *winner_animal_msg = ({
    CYN "\n$N����һ�ԣ��������$n���ӣ�\n\n" NOR,
    CYN "\n$N���ؿ���������Ȼ�������ɵض���$n��\n\n" NOR,
    CYN "\n$N���˼���������ʱ�����ٳ������\n" NOR,});

void create()
{
    seteuid(getuid());
    set("name", "ս������");
    set("id", "combatd");
}

string damage_msg(int damage, string type)
{
    string str;

//      return "��� " + damage + " ��" + type + "��\n";

    if( damage == 0 ) return "���û�ж�$n����κ��˺���\n";

    switch( type ) {
    case "����":
    case "ץ��":
//Ryu: it needs to be redifend. Cann't share same action with ����. 
//Mongol: now it can be used by unarmed skills.
        if( damage < 20 ) return "���$pֻ������ز�����һ����Ƥ��\n";
        else if( damage < 40 ) return "���$p��$l�ϱ�����һ��ϸ����Ѫ�ۡ�\n";
        else if( damage < 80 ) return "�����ৡ�����$p��$l�ϲ��һ��ƬƤ�⣡\n";
        else if( damage < 120 ) return "�����ৡ���һ������һ��Ѫ���ܵ��˿ڣ�\n";
        else if( damage < 160 ) return "�����ৡ���һ��$p��$l�ϱ�˺��Ѫ���ܵ�һƬ�⣡\n";
                     else return "���ֻ����$nһ���Һ���$p$l��Ƥ�⾡�ѣ�¶����ɭɭ�Ĺ�ͷ��\n";
        break;
    case "����":
    case "����":
    case "����":
        if( damage < 20 ) return "���ֻ������ػ���$p��Ƥ�⡣\n";
        else if( damage < 40 ) return "�����$p$l����һ��ϸ����Ѫ�ۡ�\n";
        else if( damage < 80 ) return "������͡���һ������һ���˿ڣ�\n";
        else if( damage < 120 ) return "������͡���һ������һ��Ѫ���ܵ��˿ڣ�\n";
        else if( damage < 160 ) return "������͡���һ������һ���ֳ�������˿ڣ�����$N������Ѫ��\n";
        else return "���ֻ����$nһ���Һ���$w����$p$l����һ������ǵĿ����˿ڣ���\n";
        break;
    case "����":
        if( damage < 20 ) return "���ֻ������ش���$p��Ƥ�⡣\n";
        else if( damage < 40 ) return "�����$p$l�̳�һ�����ڡ�\n";
        else if( damage < 80 ) return "������ۡ���һ��������$n$l����\n";
        else if( damage < 120 ) return "������ۡ���һ���̽�$n��$l��ʹ$p�������������˼�����\n";
        else if( damage < 160 ) return "��������͡���һ����$w����$p$l�̳�һ��Ѫ��ģ����Ѫ������\n";
        else return "���ֻ����$nһ���Һ���$w����$p��$l�Դ���������Ѫ�������أ���\n";
        break;
    case "����":
        if( damage < 20 ) return "���$p�͵�һ����û��ô���š�\n";
        else if( damage < 40 ) return "�������ߴ��һ����$p��ˤ�˸�ƨ�ա�\n";
        else if( damage < 80 ) return "���$p��$l��ʵ�ر�ˤ��һ�£�\n";
        else if( damage < 120 ) return "���$p��$l���ڵ��ϣ���ˤ�����ϣ�\n";
        else if( damage < 160 ) return "�����$p��$l��ʱ����һ��飬��Ѫ��͸�����ϣ�\n";
        else return "���$p��$l��ˤ��Ƥ����������ͷ���������������\n";
        break;
    case "����":
        if( damage < 20 ) return "���ֻ����$p$l�ϲ���һ����ӡ��\n";
        else if( damage < 40 ) return "�����$p��$l�ϳ��һ��Ѫ�ۡ�\n";
        else if( damage < 80 ) return "�����ž����һ��$p������һ���˿ڣ�\n";
        else if( damage < 120 ) return "���$p��$l�ϱ�����һ��Ѫ���ܵĴ��ڣ�\n";
        else if( damage < 160 ) return "�����ž����һ��$p��$N��$w����һ����ͷ���ŵ�Ѫӡ��\n";
        else return "���ֻ���������꡹һ����$p��$l�Ĺ�ͷ����ϣ�$w��Ⱦ��Ѫ�죡��\n";
        break;
    case "ҧ��":
        if( damage < 20 ) return "���ֻ������ز���һ��$p��Ƥ�⡣\n";
        else if( damage < 40 ) return "�����$p$lҧ��һ����ӡ��\n";
        else if( damage < 80 ) return "���$p��ҧ��һƬ������\n";
                     else if( damage < 120 ) return "���$p��Ƥ���ⱻҧ��һ��飡\n";
        else if( damage < 160 ) return "�����$p������ҧ����Ѫ��ģ����һ���$l�⣡\n";
        else return "���ֻ����$nһ���Һ���$p��$l�ϵ��ⱻһ��ҧ����¶����ͷ����\n";
        break;
    case "����":
    case "����":
        if( damage < 10 ) return "���ֻ����������������Ĳ�Ӭ��΢���˵㡣\n";
        else if( damage < 20 ) return "�����$p��$l���һ�����ࡣ\n";
        else if( damage < 40 ) return "���һ�����У�$n��$l��ʱ����һ���ϸߣ�\n";
        else if( damage < 80 ) return "���һ�����У�$n�ƺ���һ����Ȼ���˲�С�Ŀ���\n";
        else if( damage < 120 ) return "������项��һ����$n����������\n";
        else if( damage < 160 ) return "�����һ�¡��项��һ������$n�����˺ü�������һ��ˤ����\n";
        else if( damage < 240 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n";
        else return "���ֻ�������项��һ�����죬$n��һ�����ݰ���˳�ȥ����\n";
        break;
    case "����":
        if( damage < 10 ) return "���ֻ�ǰ�$n������˰벽����������\n";
        else if( damage < 20 ) return "���$nʹ��һ������$p��$l���һ�����ˡ�\n";
        else if( damage < 40 ) return "���һ�����У���$n���ʹ��������ȥ��\n";
        else if( damage < 80 ) return "���$n�ƺ���һ��������һ����һ��ף���Ȼ���˵����ˣ�\n";
        else if( damage < 120 ) return "���$n��ɫһ�±�òҰף��������������˺ü�����\n";
        else if( damage < 160 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n";
        else if( damage < 240 ) return "������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n";
        else return "���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n";
        break;
    default:
        if( !type ) type = "�˺�";
        if( damage < 10 ) str =  "���ֻ����ǿ���һ����΢";
        else if( damage < 20 ) str = "��������΢��";
        else if( damage < 30 ) str = "������һ��";
        else if( damage < 50 ) str = "������һ������";
        else if( damage < 80 ) str = "��������Ϊ���ص�";
        else if( damage < 120 ) str = "�������൱���ص�";
        else if( damage < 170 ) str = "������ʮ�����ص�";
        else if( damage < 230 ) str = "�����ɼ������ص�";
        else str =  "�����ɷǳ����µ�����";
        return str + type + "��\n";
    }
}

string eff_status_msg(int ratio)
{
    if( ratio==100 ) return HIG "��������Ѫ��ӯ����û�����ˡ�" NOR;
    if( ratio > 95 ) return HIG "�ƺ����˵����ˣ��������������������" NOR;
    if( ratio > 90 ) return HIY "�������������˵����ˡ�" NOR;
    if( ratio > 80 ) return HIY "���˼����ˣ������ƺ��������¡�" NOR;
    if( ratio > 60 ) return HIY "���˲��ᣬ������״������̫�á�" NOR;
    if( ratio > 40 ) return HIR "��Ϣ���أ�������ʼɢ�ң��������ܵ�����ʵ���ᡣ" NOR;
    if( ratio > 30 ) return HIR "�Ѿ��˺����ۣ���������֧����������ȥ��" NOR;
    if( ratio > 20 ) return HIR "�����൱�ص��ˣ�ֻ�»�������Σ�ա�" NOR;
    if( ratio > 10 ) return RED "����֮���Ѿ�����֧�ţ��ۿ���Ҫ���ڵ��ϡ�" NOR;
    if( ratio > 5  ) return RED "���˹��أ��Ѿ�����һϢ�����ڵ�Ϧ�ˡ�" NOR;
    return RED "���˹��أ��Ѿ�������в�����ʱ�����ܶ�����" NOR;
}

string status_msg(int ratio)
{
    if( ratio==100 ) return HIG "����������������һ��Ҳ���ۡ�" NOR;
    if( ratio > 95 ) return HIG "�ƺ���Щƣ����������Ȼʮ���л�����" NOR;
    if( ratio > 90 ) return HIY "������������Щ���ˡ�" NOR;
    if( ratio > 80 ) return HIY "�����ƺ���ʼ�е㲻̫��⣬������Ȼ�������ɡ�" NOR;
    if( ratio > 60 ) return HIY "�������꣬������״������̫�á�" NOR;
    if( ratio > 40 ) return HIR "�ƺ�ʮ��ƣ����������Ҫ�ú���Ϣ�ˡ�" NOR;
    if( ratio > 30 ) return HIR "�Ѿ�һ��ͷ�ؽ����ģ������������֧����������ȥ��" NOR;
    if( ratio > 20 ) return HIR "�������Ѿ����������ˡ�" NOR;
    if( ratio > 10 ) return RED "ҡͷ���ԡ�����бб��վ��վ���ȣ��ۿ���Ҫ���ڵ��ϡ�" NOR;
    return RED "�Ѿ���������״̬����ʱ������ˤ����ȥ��" NOR;
}

varargs void report_status(object ob, int effective)
{
    if( effective ) 
        message_vision( "( $N" + eff_status_msg(
            (int)ob->query("eff_qi") * 100 / (int)ob->query("max_qi") ) 
            + " )\n", ob);
    else
        message_vision( "( $N" + status_msg(
            (int)ob->query("qi") * 100 / (int)ob->query("max_qi") ) 
            + " )\n", ob);
}

// This function calculates the combined skill/combat_exp power of a certain
// skill. This value is used for A/(A+B) probability use.
varargs int skill_power(object ob, string skill, int usage)
{
    int status, level, power, jingli_bonus, exp;
    if( !living(ob) ) return 0;
    level = ob->query_skill(skill);
    exp = ob->query( "combat_exp" );
    
    switch(usage) 
    {
        case SKILL_USAGE_ATTACK:
            level += ob->query_temp("apply/attack");
            break;
        case SKILL_USAGE_DEFENSE:
            level += ob->query_temp("apply/defense");
            if (ob->is_fighting())
                level = level * ( (100 + ob->query_temp("fight/dodge")/10 ) / 100 );
            break;
    }

    jingli_bonus = 50 + (int)ob->query("jingli") / (int)ob->query("max_jingli") * 50;
    if (jingli_bonus > 150) jingli_bonus = 150;

    if( level<3 ) return (int)(exp/20 * (jingli_bonus/10) )/2;

    // here need a modification later
    // reduce skill power by half
    power = (level/3*level/2*level);
    
    // reduce exp power by half
    exp = exp/2;

    if (usage == SKILL_USAGE_ATTACK)
    {
        if( (ob->query_str()/10) *(jingli_bonus/10) >  300 ) 
            power = (power/30 + exp/30) *300;
        else
            power = (power/30 + exp/30 ) * (ob->query_str()/10)
                *(jingli_bonus/10);
    }
    else
    {
        if( (ob->query_dex()/10) *(jingli_bonus/10) >  300 ) 
            power = (power/30 + exp/30)*300;
        else
            power = (power/30 + exp/30)*(ob->query_dex()/10)
                *(jingli_bonus/10);
    }
    if ( power < 0 || power > MAXINT )
        power = MAXINT;
    return power;
}

// do_attack()
//
// Perform an attack action. This function is called by fight() or as an
// interface for some special ujinglize in quests.
//
varargs int do_attack(object me, object victim, object weapon, int attack_type)
{
    mapping my, your, prepare, action;
    string limb, *limbs, result;
    string attack_skill, force_skill, martial_skill, dodge_skill, parry_skill;
    mixed foo;
    int ap, dp, pp;
    int damage, damage_bonus, defense_factor;
    int brief; 
    int wounded = 0;

    if(victim->query("combat_exp")<0)victim->set("combat_exp",0);
    if(me->query("combat_exp")<0)me->set("combat_exp",0);

    my = me->query_entire_dbase();
    your = victim->query_entire_dbase();
    
    if (userp(me) && userp(victim))
        brief = me->query("env/brief") && victim->query("env/brief");
    else    
        brief = me->query("env/brief") || victim->query("env/brief");

    //
    // (0) Choose skills.
    //
    prepare = me->query_skill_prepare();
    if (!prepare) prepare = ([]);

    if( objectp(weapon) )   attack_skill = weapon->query("skill_type");
    else if ( sizeof(prepare) == 0) attack_skill = "unarmed";
    else if ( sizeof(prepare) == 1) attack_skill = (keys(prepare))[0];
    else if ( sizeof(prepare) == 2) attack_skill = (keys(prepare))[me->query_temp("action_flag")];
    

    //
    // (1) Find out what action the offenser will take.
    //
    me->reset_action();
    action = me->query("actions");
    if( !mapp(action) ) {
        me->reset_action();
        action = me->query("action");
        if( !mapp(action) ) {
            CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s(%s): bad action = %O",
                me->name(1), me->query("id"), me->query("actions", 1)));
            return 0;
        }
    }

    if (me->query_temp("action_flag") == 0)
        result = "\n" + action["action"] + "��\n";
    else
        result = "\n" + "������"+action["action"] + "��\n"; 

    //
    // (2) Prepare AP, DP for checking if hit.
    //
    limbs = victim->query("limbs");
    limb = limbs[random(sizeof(limbs))];

    ap = skill_power(me, attack_skill, SKILL_USAGE_ATTACK);
    if( ap < 1) ap = 1;
    
    // disable it temporarily until we find a consistent skill power system
    if (userp(me) && intp(action["dodge"]))
        me->set_temp("fight/dodge", action["dodge"]);

    dp = skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
//      if( dp < 1 || victim->query_temp("yield") ) dp = 1;
    if( victim->is_busy() ) dp /= 3;
    if( dp < 1 ) dp = 1;

    //
    // (3) Fight!
    //     Give us a chance of AP/(AP+DP) to "hit" our opponent. Since both
    //     AP and DP are greater than zero, so we always have chance to hit
    //     or be hit.
    //
    if( random(ap/2 + dp/2) < dp/2 ) {    // Does the victim dodge this hit?

        dodge_skill = victim->query_skill_mapped("dodge");
        if( !dodge_skill ) dodge_skill = "dodge";
        if (!brief)
        result += SKILL_D(dodge_skill)->query_dodge_msg(limb);

        if( dp <= ap && (!userp(victim) || !userp(me)) 
        &&      random(your["jingli"]*100/your["max_jingli"] + your["int"]) > 50 ) {
            your["combat_exp"] += 1;
            victim->improve_skill("dodge", 1);
        }

        // This is for NPC only. NPC have chance to get exp when fail to hit.
        if( (ap < dp) && !userp(me) ) {
            if( random(my["int"]) > 15 ) my["combat_exp"] += 1;
            me->improve_skill(attack_skill, random(my["int"]));
        }           

        // If we are more than 2 times tougher, victim cost jingli to dodge away.
        if( random(my["combat_exp"]) >= random(your["combat_exp"]) * 2)
        your["jingli"] -= 1;

        // We lost jingli by this missing hit.
        my["jingli"] -= my["jiajin"];

        damage = RESULT_DODGE;

    } else {

        //
        //      (4) Check if the victim can parry this attack.
        //
        if( victim->query_temp("weapon") ) {
            pp = skill_power(victim, "parry", SKILL_USAGE_DEFENSE);
            if( !weapon && undefinedp(action["weapon"]) ) pp *= 2;
        } else {
            if( weapon ) pp = 0;
            else pp = skill_power(victim, attack_skill, SKILL_USAGE_DEFENSE);
        }

        if( victim->is_busy() ) pp /= 2;
        if( pp < 1 ) pp = 1;
//          if( pp < 1 || victim->query_temp("yield") ) pp = 1;

        if( random(ap/2 + pp/2)< pp/2 ) {

            parry_skill = victim->query_skill_mapped("parry");
            if( !parry_skill || !SKILL_D(parry_skill)->parry_available()) 
            parry_skill = "parry";
            //if (!brief)
            result += SKILL_D(parry_skill)->query_parry_msg(weapon, victim);

            if( pp <= ap && (!userp(victim) || !userp(me)) 
            &&      random(your["jingli"]*100/your["max_jingli"] + your["int"]) > 50 ) {
                your["combat_exp"] += 1;
                victim->improve_skill("parry", 1);
            }

            // If we are more than 2 times tougher, victim cost jingli to parry away.
            if( random(my["combat_exp"]) >= random(your["combat_exp"]) * 2)
            your["jingli"] -= 1;

            // We lost jingli by this missing hit.
            my["jingli"] -= my["jiajin"];

            damage = RESULT_PARRY;

        } else {

            //
            //      (5) We hit the victim and the victim failed to parry
            //

            damage = me->query_temp("apply/damage");
            damage = (damage + random(damage)) / 2;
            
            // increase attack power for npc who doesn't have special skills 
            if (!userp(me))
                damage += ((int)me->query_temp("apply/attack") + 1) /10 * (damage /10);

            // disable action["damage"] temporarily
            // untill we find a consistent damage sys.
            if( action["damage"] )
                damage += action["damage"] /10 * (damage / 30);

            // equal skill, equal power
            // make weapon and unarmed has close damage power
            // if (objectp(weapon))
                damage += ((int)me->query_skill(attack_skill) + 1) /10 * (damage /10);

            damage_bonus = me->query_str();

            // Let force skill take effect.
            if( my["jiali"] && (my["neili"] > my["jiali"]) ) {
                if( force_skill = me->query_skill_mapped("force") ) {
                    foo = SKILL_D(force_skill)->hit_ob(me, victim, damage_bonus, my["jiali"]);
                    if( stringp(foo) ) result += foo;
                    else if( intp(foo) ) {
                        if( !objectp(weapon) ) damage_bonus += foo;
                        else           damage_bonus += foo / 3;
                    } else if( mapp(foo) ) {
                        result += foo["result"];
                        if( !objectp(weapon) ) damage_bonus += foo["damage"];
                        else           damage_bonus += foo["damage"] / 3;
                    }
                }
            }

            if( action["force"] ) {
                if( !objectp(weapon) )
                    damage_bonus += action["force"] /10 * (damage_bonus / 100);
                else            
                    damage_bonus += action["force"] /10 * (damage_bonus / 300);
            }

            // equal skill, equal power
            if (!objectp(weapon))
                damage_bonus += ((int)me->query_skill(attack_skill)/4 
                    + (int)me->query_skill("force")/2+1)/10* (damage_bonus /10);
            else            
                damage_bonus += ((int)me->query_skill(attack_skill)/4+1) /10* (damage_bonus /10);

            if( martial_skill = me->query_skill_mapped(attack_skill) ) {
                foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage_bonus);
                if( stringp(foo) ) result += foo;
                else if(intp(foo) ) damage_bonus += foo;
            }

            // Let weapon or monster have their special damage.
            if( weapon ) {
                foo = weapon->hit_ob(me, victim, damage_bonus);
                if( stringp(foo) ) result += foo;
                else if(intp(foo) ) damage_bonus += foo;
            } else {
                foo = me->hit_ob(me, victim, damage_bonus);
                if( stringp(foo) ) result += foo;
                else if(intp(foo) ) damage_bonus += foo;
            }

            // Let Jiajin take effect.
            if( my["jiajin"] && (my["jingli"] > my["jiajin"]) ) {
                foo = my["jingli"]/20 + my["jiajin"] - your["jingli"]/25;
                if (foo > 0) {
                    if( !objectp(weapon) ) damage_bonus += foo;
                    else           damage_bonus += foo/3;
                }
                my["jingli"] -= my["jiajin"];
            } 

            // quick attack only inflict half damage
            if( attack_type==TYPE_QUICK) damage /= 2;

            // Temporally tuning down damage power
            // Seems need not this now, player's qi are much longer.
            //if( damage_bonus > 360 ) damage_bonus = 180 + damage_bonus/2;
            //if( damage_bonus > 180 && userp(me) ) damage_bonus = 120 + damage_bonus/3;

            if( damage_bonus > 0 )
                damage += (damage_bonus + random(damage_bonus))/2;
            else    damage += (damage_bonus - random(-damage_bonus))/2;
            if( damage < 0 ) damage = 0;
            
            // Let combat exp take effect
            defense_factor = your["combat_exp"];
            while( random(defense_factor) > my["combat_exp"] ) {
                damage -= damage / 3;
                defense_factor /= 2;
            }

            // Let special armor take effect.
            if( objectp(foo = victim->query_temp("armor/cloth"))
             && foo->is_special() ) {
                foo = foo->hit_by(me, victim, damage, weapon);
                if (stringp(foo)) result += foo;
                else if (intp(foo)) damage = foo;
                else if (mapp(foo)) {
                    result += (string)foo["result"];
                    damage = (int)foo["damage"];
                }
            }

            // Let special dodge skills take effect.
            dodge_skill = victim->query_skill_mapped("dodge");
            if( dodge_skill && SKILL_D(dodge_skill)->is_special() ) {
                foo = SKILL_D(dodge_skill)->hit_by(me, victim, damage);
                if (stringp(foo)) result += foo;
                else if (intp(foo)) damage = foo;
                else if (mapp(foo)) {
                    result += (string)foo["result"];
                    damage = (int)foo["damage"];
                }
            }

            //
            //      (6) Inflict the damage.
            //


            damage = victim->receive_damage("qi", damage, me );

            if( random(damage) > (int)victim->query_temp("apply/armor")
            && ( (me->is_killing(victim->query("id"))) 
                && ((!weapon) && !random(4) || weapon && !random(2) )
                || ( (!weapon) && !random(7) || weapon && !random(4) ) )  )
            {
                // We are sure that damage is greater than victim's armor here.
                victim->receive_wound("qi",
                    damage - (int)victim->query_temp("apply/armor"), me);
                wounded = 1;
            }

            result += damage_msg(damage, action["damage_type"]);

            //
            //      (7) Give experience and yield gain
            //

            if( !userp(me) || !userp(victim) ) {
                if( (ap <= dp)
                && !me->query_temp("yield")
                && !victim->query_temp("yield")
                &&      (random(my["jingli"]*100/my["max_jingli"] + my["int"]) > 30) ) {
                    my["combat_exp"] += 1;
                    if( my["potential"] < my["max_potential"] )
                        my["potential"] += 1;
                    if( attack_skill != "unarmed")//disable unarmed skill improving.
                    me->improve_skill(attack_skill, 1);
                }
                if( random(your["max_qi"] + your["qi"]) < damage ) {
                    your["combat_exp"] += 1;
                    if( your["potential"] < your["max_potential"] )
                        your["potential"] += 1;
                }
                if( victim->query_temp("yield") 
                && damage <= your["qi"]/2
                && random(my["combat_exp"]) >= random(your["combat_exp"])
                && random(5) == 0 )
                    victim->improve_skill("parry", random(damage));
            }
        }
    } 

    result = replace_string( result, "$l", limb );
    if( objectp(weapon) )
        result = replace_string( result, "$w", weapon->name() );
    else if( stringp(action["weapon"]) )
        result = replace_string( result, "$w", action["weapon"] );
    else if( attack_skill == "finger" ) 
        result = replace_string( result, "$w", "��ָ" );
    else if( attack_skill == "cuff" )
        result = replace_string( result, "$w", "ȭͷ" );
    else if( attack_skill == "strike" )
        result = replace_string( result, "$w", "����" );
    else if( attack_skill == "claw" )
        result = replace_string( result, "$w", "��צ" );
    else result = replace_string( result, "$w", "" );

    message_vision(result, me, victim );

    if( wizardp(me) && (string)me->query("env/combat")=="verbose" ) {
        if( damage > 0 )
            tell_object(me, sprintf( GRN "AP��%d��DP��%d��PP��%d���˺�����%d\n" NOR,
                ap/100, dp/100, pp/100, damage));
        else
            tell_object(me, sprintf( GRN "AP��%d��DP��%d��PP��%d\n" NOR,
                ap/100, dp/100, pp/100));
    }

    if( damage > 0 ) {
        report_status(victim, wounded);
        if( victim->is_busy() ) victim->interrupt_me(me);
        if( (!me->is_killing(your["id"])) && 
        (!victim->is_killing(my["id"])) &&
        victim->query("qi")*2 <= victim->query("max_qi")) {
            me->remove_enemy(victim);
            victim->remove_enemy(me);
            if ( me->query("race") == "����" )
               message_vision( winner_msg[random(sizeof(winner_msg))], me, victim);
            else
               message_vision( winner_animal_msg[random(sizeof(winner_animal_msg))], me, victim);
            if (me->query_temp("protect/fighting"))
                me->delete_temp("protect/fighting");
        }
    }

    if( functionp(action["post_action"]) )
        evaluate( action["post_action"], me, victim, weapon, damage);

    // See if the victim can make a riposte.
    if( attack_type==TYPE_REGULAR
    &&      damage < 1
    &&      victim->query_temp("guarding") 
    &&      random(1-(int)victim->query_temp("apply/speed"))
          < random((1-(int)me->query_temp("apply/speed"))*6) ) {
        victim->set_temp("guarding", 0);
        if( random(my["dex"]) < 5 ) {
            message_vision("$Nһ�����У�¶����������\n", me);
            do_attack(victim, me, victim->query_temp("weapon"), TYPE_QUICK);
        } else {
            message_vision("$N��$n����ʧ�󣬳û�����������\n", victim, me);
            do_attack(victim, me, victim->query_temp("weapon"), TYPE_RIPOSTE);
        }
    }
}

//      fight()
//
//      This is called in the attack() defined in F_ATTACK, which handles fighting
//      in the heart_beat() of all livings. Be sure to optimize it carefully.
//
void fight(object me, object victim)
{
    object ob;
    
    if( !living(me) ) return;

//      if( !me->visible(victim)
//      && (random(100 + (int)me->query_skill("perception")) < 100) )
//          return;

    // If victim is busy or unconcious, always take the chance to make an attack.
    if( victim->is_busy() || !living(victim) ) {
        me->set_temp("guarding", 0);
        if( !victim->is_fighting(me) ) victim->fight_ob(me);
        do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);

        if( me->is_fighting(victim) && victim->is_fighting(me)) 
        if( (!objectp(me->query_temp("weapon")) 
           && sizeof(me->query_skill_prepare()) > 1)
        ||  ( objectp(me->query_temp("weapon")) 
           &&(me->query_temp("weapon"))->query("skill_type") == "sword"
           && me->query_skill("pixie-jian", 1) >= 60
           && me->query_skill_mapped("sword") == "pixie-jian"
           && me->query("gender") == "����") )
        {
            me->set_temp("action_flag",1);
    do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
           me->set_temp("action_flag",0);
        }

    // Else, see if we are brave enough to make an aggressive action.
    } else if( random((int)victim->query_dex()*3 ) < (int)me->query_str()*2 
                    + (int)me->query_temp("apply/speed") ) { 
        me->set_temp("guarding", 0);
        if( !victim->is_fighting(me) ) victim->fight_ob(me);  
        do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);

        if( me->is_fighting(victim) && victim->is_fighting(me)) 
        if( (!objectp(me->query_temp("weapon")) 
           && sizeof(me->query_skill_prepare()) > 1)
        ||  ( objectp(me->query_temp("weapon")) 
           &&(me->query_temp("weapon"))->query("skill_type") == "sword"
           && me->query_skill("pixie-jian", 1) >= 60
           && me->query_skill_mapped("sword") == "pixie-jian"
           && me->query("gender") == "����") )
        {
           me->set_temp("action_flag",1);
           do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);
           me->set_temp("action_flag",0);
        }

    // Else, we just start guarding.
    } else if( !me->query_temp("guarding") ) {
        me->set_temp("guarding", 1);
        message_vision( guard_msg[random(sizeof(guard_msg))], me, victim);
        return;
    } else return;
}

//      auto_fight()
//
//      This function is to start an automatically fight. Currently this is
//      used in "aggressive", "vendetta", "hatred", "berserk" fight.
//
void auto_fight(object me, object obj, string type)
{
    // Don't let NPC autofight NPC.
    if( !userp(me) && !userp(obj) ) return;

    // Because most of the cases that we cannot start a fight cannot be checked
    // before we really call the kill_ob(), so we just make sure we have no 
    // aggressive callout wating here.
    if( me->query_temp("looking_for_trouble") ) return;
    me->set_temp("looking_for_trouble", 1);

    // This call_out gives victim a chance to slip trough the fierce guys.
    call_out( "start_" + type, 0, me, obj);
}

void start_berserk(object me, object obj)
{
    int shen;

    if( !me || !obj ) return;                   // Are we still exist( not becoming a corpse )?

    me->set_temp("looking_for_trouble", 0);

    if(     me->is_fighting(obj)                // Are we busy fighting?
    ||      !living(me)                             // Are we capable for a fight?
    ||      environment(me)!=environment(obj)       // Are we still in the same room?
    ||      environment(me)->query("no_fight")      // Are we in a peace room?
    )       return;

    shen = 0 - (int)me->query("shen");
    message_vision("$N��һ������������ɨ�����ڳ���ÿһ���ˡ�\n", me);

    if( !userp(me) || (int)me->query("neili") > (random(shen) + shen)/10 ) return;

    if( shen > (int)me->query("quest_exp") 
    &&      !wizardp(obj) ) {
        message_vision("$N����$n�ȵ���" + RANK_D->query_self_rude(me)
            + "����ʵ�ںܲ�˳�ۣ�ȥ���ɡ�\n", me, obj);
        me->kill_ob(obj);
    } else {
        message_vision("$N����$n�ȵ���ι��" + RANK_D->query_rude(obj)
            + "��" + RANK_D->query_self_rude(me) + "�������˴�ܣ����������ְɣ�\n",
            me, obj);
        me->fight_ob(obj);
    }
}

void start_hatred(object me, object obj)
{
    if( !me || !obj ) return;                   // Are we still exist( not becoming a corpse )?

    me->set_temp("looking_for_trouble", 0);

    if(     me->is_fighting(obj)                // Are we busy fighting?
    ||      !living(me)                             // Are we capable for a fight?
    ||      environment(me)!=environment(obj)       // Are we still in the same room?
    ||      environment(me)->query("no_fight")      // Are we in a peace room?
    )       return;

    // We found our hatred! Charge!
    if ( me->query("race") == "����" )
        message_vision( catch_hunt_human_msg[random(sizeof(catch_hunt_human_msg))], me, obj);
    if ( me->query("race") == "Ұ��" )
        message_vision( catch_hunt_beast_msg[random(sizeof(catch_hunt_beast_msg))], me, obj);
    if ( me->query("race") == "����" )
        message_vision( catch_hunt_bird_msg[random(sizeof(catch_hunt_bird_msg))], me, obj);
    me->kill_ob(obj);
}

void start_vendetta(object me, object obj)
{
    if( !me || !obj ) return;                   // Are we still exist( not becoming a corpse )?

    me->set_temp("looking_for_trouble", 0);

    if(     me->is_fighting(obj)                // Are we busy fighting?
    ||      !living(me)                             // Are we capable for a fight?
    ||      environment(me)!=environment(obj)       // Are we still in the same room?
    ||      environment(me)->query("no_fight")      // Are we in a peace room?
    )       return;

    // We found our vendetta opponent! Charge!
    me->kill_ob(obj);
}

void start_aggressive(object me, object obj)
{
    if( !me || !obj ) return;                   // Are we still exist( not becoming a corpse )?

    me->set_temp("looking_for_trouble", 0);

    if(     me->is_fighting(obj)                // Are we busy fighting?
    ||      !living(me)                             // Are we capable for a fight?
    ||      environment(me)!=environment(obj)       // Are we still in the same room?
    ||      environment(me)->query("no_fight")      // Are we in a peace room?
    )       return;

    // We got a nice victim! Kill him/her/it!!!
    me->kill_ob(obj);
}

// This function is to announce the special events of the combat.
// This should be moved to another daemon in the future.
void announce(object ob, string event)
{
    switch(event) 
    {
    case "dead":
        message_vision(ob->query("dead_message"), ob);
        break;
    case "unconcious":
        message_vision(ob->query("unconcious_message"), ob);
        break;
    case "revive":
        message_vision(ob->query("revive_message"), ob);
        break;
    }
}

void winner_reward(object killer, object victim)
{
    killer->defeated_enemy(victim);
}

void death_penalty(object victim)
{
    int amount;
    if (!userp(victim)) return;

    if (wizardp(victim)) return;
    victim->clear_condition();
    // Give the death penalty to the dying user.
    if( (int)victim->query("combat_exp") >= 10000 * (int)victim->query("death_times") )    
    victim->add("death_times", 1);  
    victim->add("shen", -(int)victim->query("shen") / 20);
    victim->add("behavior_exp", -(int)victim->query("behavior_exp") / 20);
    amount = (int)victim->query("combat_exp") / 100;
    if (amount > 5000) amount = 5000;
    if (amount > 50) {
        victim->add("combat_exp", -amount);
        if( (int)victim->query("potential") > 0)
            victim->add("potential", - (int)victim->query("potential")/2 );
    }
    else if (victim->query("combat_exp") > 20)
        victim->add("combat_exp", -20);

    amount = (int)victim->query("balance") - 10000;
//      victim->add("balance", -amount/2);//�����󲻼�Ǯׯ���Ǯ
//     if (amount > 0)
    victim->add("death_count", 1);
    victim->delete("vendetta");
    victim->delete_temp("rob_victim");
    victim->delete_temp("initiator");
    if( victim->query("thief") )
        victim->set("thief", (int)victim->query("thief") / 2);
    victim->skill_death_penalty();
    victim->save();

} // End of death_penalty


void killer_reward(object killer, object victim)
{
    int bls;
    int time;
       
    object room;
    string vmark, mode, winner;

    if ( !environment(victim)->query("no_death")) { 

    // Call the mudlib killer apply.
    killer->killed_enemy(victim);

    if( userp(victim) ) {
        killer->add("PKS", 1);
        time = (int)killer->query("mud_age");
        killer->set("pktime",time);
        if( userp(killer) && strsrch(file_name(environment(victim)), "/d/city/") >= 0 )
            killer->apply_condition("killer", 100); // PKer pursue added by Zhuang@XKX
        
        bls = 10;

        if( killer->query("race") == "Ұ��" 
        ||  killer->query("race") == "����" 
        ||  killer->query("race") == "����"
        ||  killer->query("race") == "����" )      mode = "ҧ";
        else if( killer->query("race") == "����" ) mode = "��"; 
        else if( killer->query("race") == "����" ) mode = "��"; 
        else mode = "ɱ";

        CHANNEL_D->do_channel(this_object(), "rumor",
            sprintf("%s��%s" + mode + "���ˡ�", victim->name(1), killer->name()));
    } else {
        if(victim->query("race") == "����") killer->add("MKS", 1);
        bls = 1;
    }
    //prevent ppl gain any bonus from killing mengzhu.
    if( !objectp(room = find_object("/d/taishan/fengchan")) )
        room = load_object("/d/taishan/fengchan");
        winner = room->query("winner");
    if( victim->query("id") == winner )
        killer->set_temp("free_rider", 1);
    
    if (userp(killer) && !killer->query_temp("free_rider") 
              && killer->query("combat_exp") < victim->query("combat_exp")
              && killer->query("combat_exp") > victim->query("combat_exp") / 4 ) 
        killer->add("shen", -(int)victim->query("shen") / 10);
        killer->add("behavior_exp", -(int)victim->query("behavior_exp") / 10);

//Ryu: disalbe ppl gaining award from killing the npc that fainted by others.
    if (killer->query_temp("free_rider")){
        victim->delete_temp("my_killer");
        killer->delete_temp("free_rider");
    }

    if( userp(killer) && userp(victim) &&
        killer->query_temp("pking/"+victim->query("id")) )
    {
        killer->apply_condition("pker", killer->query_condition("pker")+120);
        victim->set("last_death",killer->query("name")+"("+killer->query("id")+")");
          }

    if( stringp(vmark = victim->query("vendetta_mark")) )
        killer->add("vendetta/" + vmark, 1);

    }
//      else CHANNEL_D->do_channel(this_object(), "rumor",
//              sprintf("%s��%sɱ���ˡ�", victim->name(1), killer->name(1)));

}


// End of File
