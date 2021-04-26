// Code of ShenZhou
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 * // COMBAT_D								*
 * // Experiment by xQin on 8/99					*
 *									*
 * (01) Heart_beat.							*
 * (02) Use atb system to check if we can do attack in this tick.	*
 * (03) Find out what action the attacker will take.			*
 * (04) Use compute_damage to calculate out the damage.			*
 * (05) Use action_power system to calculate out the attack power.	*
 * (06) Find out what dodge action the defender will take.		*
 * (07) Use action_power system to calculate out the dodge power.	*
 * (08) Check if dodge power enough to dodge the attack.		*
 * (09) Find out what parry action the defender will take.		*
 * (10) Use action_power system to calculate out the parry power.	*
 * (11) Check if parry power enough to parry the attack and its damage.	*
 * (12) Reduce the damage by target's armor and force and exp.		*
 * (13) Inflict the damage.						*
 * (14) Check is there a post_action.					*
 *									*
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <combat.h>
#define PRIMARY 1
#define SECONDARY 2

string damage_msg(int damage, string type)
{
        string str;

        if( damage == 0 ) return "���û�ж�$n����κ��˺���\n";

        switch( type )
	{
        case "����":
                if( damage < 100 ) return "���$p�͵�һ����û��ô���š�\n";
                else if( damage < 200 ) return "�������ߴ��һ����$p��ˤ�˸�ƨ�ա�\n";
                else if( damage < 400 ) return "���$p��$l��ʵ�ر�ˤ��һ�£�\n";
                else if( damage < 800 ) return "���$p��$l���ڵ��ϣ���ˤ�����ϣ�\n";
                else if( damage < 1600 ) return "�����$p��$l��ʱ����һ��飬��Ѫ��͸�����ϣ�\n";
                else return "���$p��$l��ˤ��Ƥ����������ͷ���������������\n";
                break;
        case "ҧ��":
                if( damage < 100 ) return "���ֻ������ز���һ��$p��Ƥ�⡣\n";
                else if( damage < 200 ) return "�����$p$lҧ��һ����ӡ��\n";
                else if( damage < 400 ) return "���$p��ҧ��һƬ������\n";
                else if( damage < 800 ) return "���$p��Ƥ���ⱻҧ��һ��飡\n";
                else if( damage < 1600 ) return "�����$p������ҧ����Ѫ��ģ����һ���$l�⣡\n";
                else return "���ֻ����$nһ���Һ���$p��$l�ϵ��ⱻһ��ҧ����¶����ͷ����\n";
                break;
        case "����":
        case "����":
        case "����":
                if( damage < 100 ) return "���ֻ����������������Ĳ�Ӭ��΢���˵㡣\n";
                else if( damage < 200 ) return "�����$p��$l���һ�����ࡣ\n";
                else if( damage < 400 ) return "���һ�����У�$n��$l��ʱ����һ���ϸߣ�\n";
                else if( damage < 800 ) return "���һ�����У�$n�ƺ���һ����Ȼ���˲�С�Ŀ���\n";
                else if( damage < 1200 ) return "������项��һ����$n����������\n";
                else if( damage < 1600 ) return "�����һ�¡��项��һ������$n�����˺ü�������һ��ˤ����\n";
                else if( damage < 2400 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ����\n";
                else return "���ֻ�������项��һ�����죬$n��һ�����ݰ���˳�ȥ����\n";
                break;
        case "����":
                if( damage < 100 ) return "���ֻ�ǰ�$n������˰벽����������\n";
                else if( damage < 200 ) return "���$nʹ��һ������$p��$l���һ�����ˡ�\n";
                else if( damage < 400 ) return "���һ�����У���$n���ʹ��������ȥ��\n";
                else if( damage < 800 ) return "���$n�ƺ���һ��������һ����һ��ף���Ȼ���˵����ˣ�\n";
                else if( damage < 1200 ) return "���$n��ɫһ�±�òҰף��������������˺ü�����\n";
                else if( damage < 1600 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n";
                else if( damage < 2400 ) return "������䡹��һ����$nȫ����Ѫ������������Ѫ�����������\n";
                else return "���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n";
                break;
	case "����":
		if( damage < 100 ) return "���$p�ɻ�ؿ���$Pһ�ۣ��ƺ�û�ио���ʲôʹ����\n";
		else if( damage < 200 ) return "���$p����һ�Σ����㲻����������Ҫˤ����\n";
		else if( damage < 400 ) return "���$p���㲻����������ˤ����������۵�һ�������һ����Ѫ��\n";
		else if( damage < 800 ) return "���$p�۵�һ�������һ����Ѫ��ί���ڵأ�����һ�����࣡\n";
		else if( damage < 1600 ) return "���$p���ӱ���һ�����ݰ㣬�ڿ���ƽƽ�ķ��˳�ȥ������ˤ�ڵ��£�������Ѫ���磡\n";
		else if( damage < 2400 ) return "���ֻ��һ�����죬$p������Ѫ���磬ȫ��������ѣ���\n";
		else return "���ֻ��һ�����죬$pȫ��������ѣ����Ʊ�����ɽ�������һ�������Ӵ�������أ���\n";
		break;
        case "����":
        case "ץ��":
                if( damage < 100 ) return "���$pֻ������ز�����һ����Ƥ��\n";
                else if( damage < 200 ) return "���$p��$l�ϱ�����һ��ϸ����Ѫ�ۡ�\n";
                else if( damage < 400 ) return "�����ৡ�����$p��$l�ϲ��һ��ƬƤ�⣡\n";
                else if( damage < 800 ) return "�����ৡ���һ������һ��Ѫ���ܵ��˿ڣ�\n";
                else if( damage < 1600 ) return "�����ৡ���һ��$p��$l�ϱ�˺��Ѫ���ܵ�һƬ�⣡\n";
                else return "���ֻ����$nһ���Һ���$p$l��Ƥ�⾡�ѣ�¶����ɭɭ�Ĺ�ͷ��\n";
                break;
        case "����":
        case "����":
        case "����":
                if( damage < 100 ) return "���ֻ������ػ���$p��Ƥ�⡣\n";
                else if( damage < 200 ) return "�����$p$l����һ��ϸ����Ѫ�ۡ�\n";
                else if( damage < 400 ) return "������͡���һ������һ���˿ڣ�\n";
                else if( damage < 800 ) return "������͡���һ������һ��Ѫ���ܵ��˿ڣ�\n";
                else if( damage < 1600 ) return "������͡���һ������һ���ֳ�������˿ڣ�����$N������Ѫ��\n";
                else return "���ֻ����$nһ���Һ���$w����$p$l����һ������ǵĿ����˿ڣ���\n";
                break;
        case "����":
                if( damage < 100 ) return "���ֻ������ش���$p��Ƥ�⡣\n";
                else if( damage < 200 ) return "�����$p$l�̳�һ�����ڡ�\n";
                else if( damage < 400 ) return "������ۡ���һ��������$n$l����\n";
                else if( damage < 800 ) return "������ۡ���һ���̽�$n��$l��ʹ$p�������������˼�����\n";
                else if( damage < 1600 ) return "��������͡���һ����$w����$p$l�̳�һ��Ѫ��ģ����Ѫ������\n";
                else return "���ֻ����$nһ���Һ���$w����$p��$l�Դ���������Ѫ�������أ���\n";
                break;
        case "����":
		if( damage < 20 ) return "���ֻ���������ײ����$nһ�£�û�����ʲô�˺���\n";
		if( damage < 60 ) return "���$wֻ��$n��$l�ҳ�һ�����졣\n";
		if( damage < 120 ) return "�����ž����һ����$w����$n��$l����ʱ����һ���ϸߣ�\n";
		if( damage < 240 ) return "���$w���صû���$n��$l�����$p�������������ۡ����³�һ�����Ѫ��\n";
		if( damage < 380 ) return "���ֻ�������𡹵�һ�����죬$w����$n���ϣ���$p��һ�����ݰ���ɳ�ȥ��\n";
		return "ֻ��$w���ص�ײ����$n�����ϣ������������У�$p��ɢ�˼��Ƶ�̱����ȥ����\n";
                break;
        case "����":
                if( damage < 100 ) return "���ֻ����$p$l�ϲ���һ����ӡ��\n";
                else if( damage < 200 ) return "�����$p��$l�ϳ��һ��Ѫ�ۡ�\n";
                else if( damage < 400 ) return "�����ž����һ��$p������һ���˿ڣ�\n";
                else if( damage < 800 ) return "���$p��$l�ϱ�����һ��Ѫ���ܵĴ��ڣ�\n";
                else if( damage < 1600 ) return "�����ž����һ��$p��$N��$w����һ����ͷ���ŵ�Ѫӡ��\n";
                else return "���ֻ���������꡹һ����$p��$l�Ĺ�ͷ����ϣ�$w��Ⱦ��Ѫ�죡��\n";
                break;
	case "����":
	case "����":
		if( damage < 100 ) return "���ֻ�ǰ�$p��$l����һ�¡�\n";
		else if( damage < 200 ) return "���$p��$l��$w���˵����˸�С�塣\n";
		else if( damage < 400 ) return "���$p��$l��$w�յú�����ʹ��ʹ�ò�סð��ҧ����\n";
		else if( damage < 800 ) return "������͡�һ�����죬$p���$l��һƬ��ʹ���ѱ�$w�ճ��˰���ɫ�����罹̿��\n";
		else if( damage < 1600 ) return "��������͡�һ�������ȥ��$n��ɫʹ���ѵ���$l��$w�յ�һƬ���ڣ�����ֱð��\n";
		else return "���ֻ����$n�����Һ����ڵ��ϲ�ס�����$l�ѱ�$w�յ�Ƥ�⾡�ã��������磡��\n";
		break;
	case "����":
		if( damage < 100 ) return "���$p���Ǿ���$l��Щ���쬵أ���ͦ����ġ�\n";
		else if( damage < 200 ) return "���$p��$l��������Щ��ľ��\n";
		else if( damage < 400 ) return "���$p������ش��˸�������\n";
		else if( damage < 800 ) return "���$p��ɫһ�䣬������Щ��Ӳ������Ҳ���ɪɪ������\n";
		else if( damage < 1600 ) return "���$p���Ӵ������ɫ�԰ף��촽���÷��ϣ����ظ��ֱ�죡\n";
		else return "���������$n����һ�ƣ����ϲҰ׵�û���Ѫɫ���������ݣ�����ѪҺ�ƺ�������˱�����\n";
        default:
                if( !type ) type = "�˺�";
                if( damage < 100 ) str =  "���ֻ����ǿ���һ����΢";
                else if( damage < 200 ) str = "��������΢��";
                else if( damage < 300 ) str = "������һ��";
                else if( damage < 500 ) str = "������һ������";
                else if( damage < 800 ) str = "��������Ϊ���ص�";
                else if( damage < 1200 ) str = "�������൱���ص�";
                else if( damage < 1700 ) str = "������ʮ�����ص�";
                else if( damage < 2300 ) str = "�����ɼ������ص�";
                else str =  "�����ɷǳ����µ�����";
                return str + type + "��\n";
        }
}

string query_dodge(object me)
{
	string dodge_skill;

	dodge_skill = me->query_skill_mapped("dodge");
	if( !dodge_skill ) return "dodge";

	return dodge_skill;
}

string query_parry(object me)
{
	string parry_skill;
	object weapon;
	mapping prepare;
	int i, check;

	parry_skill = me->query_skill_mapped("parry");

	if( !parry_skill ) return "parry";

	if( objectp(weapon = me->query_temp("weapon"))
	&& me->query_skill_mapped(weapon->query("skill_type")) != parry_skill )
		return "parry";

	prepare = me->query_skill_prepare();
	if( !mapp(prepare) ) return "parry";

	for( i=0; i < sizeof(prepare); i++ )
		if( prepare[(keys(prepare))[i]] == parry_skill )
		{
			check++;
			break;
		}
	if( !check ) return "parry";

	return parry_skill;
}

varargs int action_power(object ob, string skill, mapping action, int usage)
{
        int level, power, jingli_bonus;

        if( !living(ob) ) return 0;

	// �����parry����Ҫ��query_parry���ж�parry���õ������书�Ƿ���ʹ��������ʹ�õġ�
	// ������ǣ�levelӦ��ֻ���(parry, 1)��level��
        level = ob->query_skill(skill);

        switch( usage )
	{
                case SKILL_USAGE_ATTACK:
			level += ob->query_temp("apply/attack");
			if( action["attack"] )
				level = level * ( 100 + action["attack"]/10 ) / 100;
                        break;
                case SKILL_USAGE_DEFENSE:
                        level += ob->query_temp("apply/defense");
			if( action["parry"] )
				level = level * ( 100 + action["parry"]/10 ) / 100;
			if( action["dodge"] )
				level = level * ( 100 + action["dodge"]/10 ) / 100;
                        break;
        }

	// ����Ӧ�ü���jiajin��bonus��jiajinԽ�ߣ�������/������Խ�ߡ�
        jingli_bonus = 50 + (int)ob->query("jingli") * 50 / ((int)ob->query("max_jingli")+1);
        if( jingli_bonus > 150 ) jingli_bonus = 150;
	jingli_bonus = jingli_bonus + ob->query("jiajin") / 2;

        if( level < 1 ) return (int)(ob->query("combat_exp")/2 * jingli_bonus/100);

        // here need a modification later
        power = (level*level*level) / 3;

        if( usage == SKILL_USAGE_ATTACK )
                return (power + ob->query("combat_exp")) /30 * ob->query_int() 
                                /100 *jingli_bonus;
        else
                return (power + ob->query("combat_exp")) /30 * ob->query_dex() 
                                /100 *jingli_bonus;
}

// ���function������xkx��һ�㲻ͬ���ǣ�����xkx�����жԷ��ż���damage��
// ��������һ���оͼ���damage�����ҽ��ڡ����˷ֿ���
// ������������ܱ�����xkx�ĸߣ���Ϊ����xkx��һ�߼���һ��reduce damage by victim��
// ��������ǵ�������damage��Ȼ���������ط�ִ����victim reduce damage������
// ���ҵ���������receive_wound��Ҳ����max_qi�����˵���receive_damage��Ҳ����qi��
// ��Щ����Ҫ�����Ὣ�������������֯�뾭��Ѩ����֯�ֿ����ſ�������ʵ�֡�
// ���Ҿ�������ʾ��
mapping compute_damage(mixed user, mixed armed, string attack_skill, mapping action)
{
	int wound, damage, damage_bonus; // ��Щvar�����ָĳ������İɡ�
	// wound�����ˣ�damage������
	object me, weapon;
	mapping my, prepare;

	// ����������������ֱ����call�����в��Եġ�
	if( objectp(user) ) me = user;
	else if( stringp(user) ) me = find_living(user);
	else return 0;
	if( !objectp(me) ) return 0;

	my = me->query_entire_dbase();
	// ��Ϊ���⹥�������Զ�ȡԤ���������Ҳ������ϵͳ�����жϡ�
	// ���㱾�����������Ϊ�˷���ĳЩ���������Ҳ�����ų�������Ϊ���������
	if( objectp(armed) ) weapon = armed;
	else if( intp(armed) )
	{
		switch( armed )
		{
			case PRIMARY : 
				me->query_temp("weapon"); break;
			case SECONDARY :
				me->query_temp("secondary_weapon"); break;
		} 
	}

	// �ڲ�δԤ���ú����书��Ϊ�������������£�ϵͳ�����жϡ�
	if( !attack_skill )
	{
		prepare = me->query_skill_prepare();
		if( !prepare ) prepare = ([]);

		if( objectp(weapon) )	attack_skill = weapon->query("skill_type");
		else switch( sizeof(prepare) )
		{
			case 0: attack_skill = "unarmed";
				break;
			case 1: attack_skill = (keys(prepare))[0];
				break;
			case 2: attack_skill = (keys(prepare))[me->query_temp("action_flag")];
				break;
			default:attack_skill = (keys(prepare))[random(sizeof(prepare))];
				break;
		}
	}

	// �ڲ�δԤ�����ĸ�������Ϊ�������������£�ϵͳ�����жϡ�
	if( !mapp(action) )
	{
		me->reset_action();
		action = me->query("actions");
		if( !mapp(action) )
		{
			me->reset_action();
			action = me->query("action");
			if( !mapp(action) )
			{
				CHANNEL_D->do_channel( this_object(), "sys",
					sprintf("%s(%s): bad action = %O",
					me->name(1), me->query("id"), me->query("actions", 1)));
				return 0;
			}
		}
        }

	/******** �Ӵ˴���ʼ����damage ********/
	// ��Ȼxkx��ʱ��δ�����Ƶ�damage system��
	// ����Ϊ�˷��㽫���ķ�չ������woundΪ�ⲿ�˺���damageΪ�ڲ��˺���

	// apply/damageͨ��ָ�������������ɱ��������������ɱ������ĳЩperform���ӵĶ����˺�����
	// ���Դ���Ϊ���˵ļ��㿪ʼ��
	damage = me->query_temp("apply/damage") + me->query_str();
	damage = ( damage + random(damage) ) / 2;

	// increase attack power for npc who doesn't have special skills 
	if( !userp(me) ) damage += ((int)me->query_temp("apply/attack") + 1) / 10 * damage /10;

	// �����������������ⲿɱ������
	if( action["damage"] ) damage += action["damage"] /10 * damage /30;

	// ���������书�ĵȼ����м��㡣
	damage += ((int)me->query_skill(attack_skill) + 1) /10 * damage /10;

	// ���ڹ��ȼ���Ϊ���˵ļ��㿪ʼ
	wound = (int)me->query_skill("force");

	// �����Ҫ�޸ġ�
	if( my["jiali"] && (my["neili"] > my["jiali"]) && me->query_skill_mapped("force") )
	{
		damage_bonus = my["max_neili"] / 2 + my["neili"];
		damage_bonus = damage_bonus / 10 + my["jiali"];
		damage_bonus = damage_bonus * my["jiali"] / (int)me->query_skill("force") * 2;

		if( !objectp(weapon) )	wound += damage_bonus;
		else			wound += damage_bonus / 3;

		my["neili"] -= my["jiali"];
	}

	// ���Ҳ��Ҫ�޸ġ�
	if( my["jiajin"] && (my["jingli"] > my["jiajin"]) )
	{
		damage_bonus = my["jingli"]/20 + my["jiajin"];

		if( !objectp(weapon) )  wound += damage_bonus;
		else			wound += damage_bonus / 3;

		my["jingli"] -= my["jiajin"];
	} 

	// �����������������ڲ�ɱ������
	if( action["force"] )
	{
		if( !objectp(weapon) )
			wound += action["force"] /10 * wound / 100;
		else                    
			wound += action["force"] /10 * wound / 300;
	}

	// equal skill, equal power // ���Ҳ��Ҫ�ģ�������������Ҳ��������ˡ�
	if( !objectp(weapon) )
		wound += ((int)me->query_skill(attack_skill)/4 
				+ (int)me->query_skill("force")/2+1)/10 * damage /10;
	else
		wound += ((int)me->query_skill(attack_skill)/4+1)/10 * damage /10;

	return ([ "damage" : damage, "wound" : wound ]);

}
