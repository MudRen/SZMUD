// Code of ShenZhou
// liaoshang.c ��������
// mantian may/11/2001
// only can liaoshang in sleep room or hotel 

inherit F_SSERVER;
inherit F_DBASE;
#include <ansi.h>
#include <combat.h>
#include "poison_list.h"

int exert(object me, object target)
{
	int i;
	string poison, tempLook;
	object where = environment(me);

	me = this_player();
	if( !target || target==me || !target->is_character() || target->query("race") != "����" ) return notify_fail(HIW"��ҪΪ˭���ˣ�\n"NOR);
	if (me->is_fighting() || target->is_fighting()) return notify_fail(HIW"ս�����˹����ˣ�������\n"NOR);
	if (me->query__temp("liaoshang")) return notify_fail(HIW"���Ѿ���Ϊ"+me->query__temp("liao/targetname")+"("+me->query__temp("liao/target")+")�����ˡ�\n"NOR);
	if ((int)me->query_skill("kurong-changong", 1) < 120) return notify_fail(HIW"��Ŀ���������Ϊ������Ϊ�����˹����ˡ�\n"NOR);
	if ((int)me->query_skill("yiyang-zhi", 1) < 150) return notify_fail(HIW"���һ��ָ��Ϊ������Ϊ�������ˡ�\n"NOR);
        if (!(where->query("sleep_room")) && !(where->query("hotel")&& !wizardp(me))) return notify_fail(HIW"����̫���ˣ����޷����������������ˣ�\n"NOR);

	for( i=0; i < sizeof(poison_list); i++ )
		if (me->query_condition(poison_list[i]["poison"]) > 0) return notify_fail(HIW"������"+poison_list[i]["name"]+poison_list[i]["type"]+"���޷�Ϊ�������ˡ�\n"NOR);
	for( i=0; i < sizeof(poison_list); i++ )
		if( target->query_condition(poison_list[i]["poison"]) > 0 )
		{
			poison = poison_list[i]["poison"];
			break;
		}
		if (poison == 0) return notify_fail(HIW+target->name() + "���岢��������\n"NOR);
	if( (int)me->query("neili") < 2000 ) return notify_fail(HIW"�����������Ϊ�����������衣\n"NOR);
	target->start_busy(30);
	target->set_temp("liao/healer", me->query("id"));
	me->start_busy(30);
	me->set_temp("liaoshang", 1);
	me->set_temp("liao/target", target->query("id"));
	me->set_temp("liao/targetname", target->query("name"));
	tempLook = me->short();
	tempLook += CYN" <������>"NOR;
	if (me->query_temp("apply/short")) me->set_temp("liao/short", me->query_temp("apply/short"));
	me->set_temp("apply/short", ({tempLook}));
	message_vision(CYN"$N˵�����ȿ����������ɡ�\n\n\n\n\n\n"NOR HIB"˵��$N������$n���ְ���һ������\n"NOR, me,target );
	call_out("checking_poison", 15, me, target);
	return 1;
}

void checking_poison(object me, object target)
{
	int neili_drop, poi_amount, finger_drop, i;
	string poison, poi_name, poi_type, msg, tempLook;

	for( i=0; i < sizeof(poison_list); i++ )
		if( target->query_condition(poison_list[i]["poison"]) > 0 )
		{
			poison = poison_list[i]["poison"];
			poi_name = poison_list[i]["name"];
			poi_type = poison_list[i]["type"];
			finger_drop = poison_list[i]["level"];
			neili_drop = poison_list[i]["neili"];
			break;
		}
	poi_amount = (int)target->query_condition(poison, 1);
	if (poi_amount < 4)	msg = "��������";
	else if (poi_amount < 50) msg = "���޴�";
	else if (poi_amount < 70)
	{
		msg = "�Ծ�Σ��";
		finger_drop = finger_drop+random(finger_drop/2);
		neili_drop = neili_drop+random(neili_drop/2);
	}
	else if (poi_amount < 100)
	{
		msg = "�������";
		finger_drop = finger_drop+random(finger_drop*2/3);
		neili_drop = neili_drop+random(neili_drop*2/3);
	}
	else if (poi_amount < 130)
	{
		msg = "�������";
		finger_drop = finger_drop+random(finger_drop*4/5);
		neili_drop = neili_drop+random(neili_drop*4/5);
	}
	else if (poi_amount < 160)
	{
		msg = "��������";
		finger_drop = finger_drop+random(finger_drop);
		neili_drop = neili_drop+random(neili_drop);
	}
	else
	{
		msg = "��������";
		finger_drop = finger_drop+random(finger_drop*2);
		neili_drop = neili_drop+random(neili_drop*2);
	}
	if (poison == "sxs_poison")
	{
		if (poi_amount = 3)
		{
			msg = "�������";
			finger_drop = finger_drop+random(finger_drop*4/5);
			neili_drop = neili_drop+random(neili_drop*4/5);
		}
		else if (poi_amount = 2)
		{
			msg = "��������";
			finger_drop = finger_drop+random(finger_drop);
			neili_drop = neili_drop+random(neili_drop);
		}
		else if (poi_amount = 1)
		{
			msg = "��������";
			finger_drop = finger_drop+random(finger_drop*2);
			neili_drop = neili_drop+random(neili_drop*2);
		}
	}
	if (poi_amount < 4 && poison != "sxs_poison")
	{
		message_vision(CYN"$N��˼��һ��˵�����������е�"+poi_name+poi_type+"��"+msg+"��ʵ���޴�����\n\n"NOR, me,target );
		target->delete_temp("liao/healer");
		target->start_busy(1);
		me->delete_temp("apply/short");
		if (me->query_temp("liao/short")) me->set_temp("apply/short", me->query_temp("liao/short"));
		me->delete_temp("liao");
		me->delete_temp("liaoshang");
		me->start_busy(1);
		return 0;
	}
	message_vision(CYN"$N��˼��һ��˵�����������е�"+poi_name+poi_type+"��"+msg+"����������Ϊ��ҽ�Ρ�\n\n\n\n\n\n"NOR, me,target );
	if ((int)target->query_condition("xbiao") > 0) target->set_temp("liao/xbiao", (int)target->query_condition("xbiao", 1));
	if ((int)target->query_condition("biao") > 0) target->set_temp("liao/biao", (int)target->query_condition("biao", 1));
	if ((int)target->query_condition("bonze_drug") > 0) target->set_temp("liao/bonze_drug", (int)target->query_condition("bonze_drug", 1));
	if ((int)target->query_condition("hot_drug") > 0) target->set_temp("liao/hot_drug", (int)target->query_condition("hot_drug", 1));
	if ((int)target->query_condition("cool_drug") > 0) target->set_temp("liao/cool_drug", (int)target->query_condition("cool_drug", 1));
	if ((int)target->query_condition("mang_shedan") > 0) target->set_temp("liao/mang_shedan", (int)target->query_condition("mang_shedan", 1));
	me->delete_temp("apply/short");
	tempLook = me->short();
	tempLook += BLU" <�붨��>"NOR;
	me->set_temp("apply/short", ({tempLook}));
	message_vision(YEL"$N������Ŀ��ü���붨�������������\n\n\n\n\n\n"NOR, me,target );
	me->set_temp("liao/finger_drop", finger_drop);
	me->set_temp("liao/neili_drop", neili_drop);
	me->start_busy(30);
	target->start_busy(30);
	call_out("start_heal", 15, me, target);
}

void start_heal(object me, object target)
{
	string tempLook;

	me->delete_temp("apply/short");
	tempLook = me->short();
	tempLook += HIW" <ҽ����>"NOR;
	me->set_temp("apply/short", ({tempLook}));
	message_vision(MAG"$N��Ȼ��Ծ���������أ��������ʳָ����������$nͷ���ٻ�Ѩ��ȥ��\n"
		"$n���ɼ���΢΢һ����ֻ����һ�������Ӷ���ֱ͸������\n\n\n\n\n\n"NOR, me,target );
	target->start_busy(30);
	me->start_busy(30);
	call_out("healing", 15, me, target);
}

void healing(object me, object target)
{
	message_vision(MAG"$Nһָ������������أ��ڶ�ָ�ѵ���$n�İٻ�Ѩ��һ����ִ��ĺ�Ѩ��\n"
		               "����ǿ�䣬�Ի����縮����׶���յ����������������̨һ·�㽫������\n"
					   "һ֧��ȼ��һ�룬�ѽ�$n��������ʮ��Ѩ˳�ε㵽��\n\n\n\n\n\n"NOR, me,target );
	target->start_busy(30);
	me->start_busy(30);
	call_out("end_heal", 15, me, target);
}
void end_heal(object me, object target)
{
	int a;

	a = me->query_skill("yiyang-zhi",1);
	message_vision(RED"$nͻȻ����һ��ů���Զ����룬�����³����ں�Ѫ����ǰһ�ھ�ʲôҲ�������ˣ�\n\n\n"NOR, me,target );
	target->clear_condition();
	target->start_busy(1);
	target->unconcious();
	if (target->query_temp("liao/xbiao")) target->apply_condition( "xbiao", (int)target->query_temp("liao/xbiao"));
	if (target->query_temp("liao/biao")) target->apply_condition( "biao", (int)target->query_temp("liao/biao"));
	if (target->query_temp("liao/bonze_drug")) target->apply_condition( "bonze_drug", (int)target->query_temp("liao/bonze_drug"));
	if (target->query_temp("liao/hot_drug")) target->apply_condition( "hot_drug", (int)target->query_temp("liao/hot_drug"));
	if (target->query_temp("liao/cool_drug")) target->apply_condition( "cool_drug", (int)target->query_temp("liao/cool_drug"));
	if (target->query_temp("liao/mang_shedan")) target->apply_condition( "mang_shedan", (int)target->query_temp("liao/mang_shedan"));
	me->add("shen", 1000+(int)(target->query("combat_exp")/100));
	me->add("max_neili",-(1+random(me->query_temp("liao/neili_drop"))));
	me->set_skill("yiyang-zhi",(a-(1+random(me->query_temp("liao/finger_drop")))));
	me->add("neili", -1000);
	target->delete_temp("liao/healer");
	me->delete_temp("apply/short");
	if (me->query_temp("liao/short")) me->set_temp("apply/short", me->query_temp("liao/short"));
	me->delete_temp("liao");
	me->delete_temp("liaoshang");
	me->start_busy(1);
}
