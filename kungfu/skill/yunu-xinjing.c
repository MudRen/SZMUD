// yunu-xinjing ��Ů�ľ�
// by April 01/08/06
// update April 01/08/08
// update by chchong 2001/08/12

// COLOR DEFINE
// RED - ��ɫ              HIR - ����ɫ
// GRN - ��ɫ              HIG - ����ɫ
// YEL - ����ɫ            HIY - ��ɫ
// BLU - ����ɫ            HIB - ��ɫ
// MAG - ǳ��ɫ            HIM - �ۺ�ɫ
// CYN - ����ɫ            HIC - ����ɫ
// WHT - ǳ��ɫ            HIW - ��ɫ

#include <ansi.h> 
#include <combat.h>

inherit FORCE;
string check() { return "force"; }
#include "/kungfu/skill/force_list.h"

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// cant learn
{
        return notify_fail
			("�㳢����һ�£������ƺ���Ҳ����Ҫ�졣����������Ů�ľ���һ����Ҫ��ʵ������ߵ��ڹ���\n");
}

int practice_skill(object me)	// ��ʵ���´��붼�޷����е�... :)
{
	int xj_lvl;		// �ľ�lvl
	int v,i,j,k;		// ��ʱ����
	int cost;		// ��ϰʱ�ĺķ�
	mapping skl;	// ����skill
	string *sname;	// skill����
	object *inv;	// ���ϴ��Ķ���


	xj_lvl = me->query_skill("yunu-xinjing", 1);

	// lvlС��30������
	if (xj_lvl<30)
		return notify_fail("����������һ��������������Ȼ��Ů�ľ���Ϊ�����������޷���ת��\n");

	// �������
	if ( me->query_temp("weapon") )
        return notify_fail("��ϰ��Ů�ľ�������֣��������ķ��ɡ�\n");

	// ��������
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
		if( inv[i]->query("equipped") 
			&& inv[i]->query("armor_type")=="cloth")
			i = sizeof(inv)+1;
	if (i==sizeof(inv)+2)
        return notify_fail("��ϰ��Ů�ľ������½󳨿����ܼ�ʱɢ��������\n");

	// �ڹ�Ҫ�����������Ԫ��
	skl=this_player()->query_skills();
	sname=sort_array( keys(skl), (: strcmp :) );
    for(v=0; v<sizeof(skl); v++) {
		if (SKILL_D(sname[v])->check() == "force")
			k++;  
    }
    if ( k >=2 ) {
		// ������߻���ħ�˺�
        me->set("neili", 0);
        me->set("jingli", 50);
        me->set("qi", 50);
		i=(int)(me->query("max_jing")*0.65);
		me->set("eff_jing",i);
	
		return notify_fail("�����ڲ�ͬ���������ײ���������������Կ��ơ� \n"
			+"����һҧ��������һ����Ѫ���Ų������߻���ħ��\n");
	}

	// ���ܿ���ϰ���� ---- 30n-1ʱ�������
	if ( (xj_lvl<270) && ((xj_lvl+1)/30*30 == xj_lvl ) )
		return notify_fail("�������ϰ����Ů�ľ�����Ȼ��������һ��... \n"
			+"���ƺ��������޷�ͻ��ƿ����������ʱ������ˡ� \n");

	// ������������
	cost = (int)((sqrt(xj_lvl/150))*60);
	if ( (int)me->query("qi") < cost+10 )
		return notify_fail("�������������ϰ��Ů�ľ���\n");
	if ( (int)me->query("jingli") < cost+10 )
		return notify_fail("��ľ���������ϰ��Ů�ľ���\n");
	if ( (int)me->query("neili") < cost+10 )
		return notify_fail("�������������ϰ��Ů�ľ���\n");

	// ����
	me->add("neili", -cost);
	me->receive_damage("jingli", cost, "����͸֧��������");
	me->receive_damage("qi", cost, "����͸֧��������");
    
    return 1;
}

string exert_function_file(string func)
{
	return "/kungfu/skill/yunu-xinjing/" + func;
}
mixed hit_by(object me, object victim, int damage, int damage_bonus, int factor)
{
         if (victim->query_temp("ngsuxin"))
         {
                 return 0;
          }
          else return damage;
}

mapping curing_msg(object me)
{
	return ([
		"start_self"    : WHT"��͵���������ʹ��Ů�ľ����ˣ���Ϣ�Ķ���ʱ�������ڣ���������ܡ�\n"NOR,
		"start_other"   : WHT+me->name()+ "�͵������������������ʼ�˹����ˡ�\n"NOR,
		"finish_self"   : "��߶���Ů�ľ����˶�ʱ��һ��������������ת�ް��������Ѿ��ָ�������վ��������\n",
		"finish_other"  : WHT"ֻ��"+ me->name()+ "ͷ�����������������ɰױ�죬��Ȼ��һ����Х��վ��������\n"NOR,
		]);
}


