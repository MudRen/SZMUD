// Code Of ShenZhou
// �Ҵ� luanci.c
// by keny
/*
������������ֻ��$1ͻȻ�˽���磬����$2ৡ�ৼ�������֮��ͻȻ���У������ڵ���������$A΢΢������ֹ�� 
(�Լ��������������һ�º��������ھ�������ָ������̧������$2ৡ�ৼ����������������С�; 
 
ͻȻ$1���󼱶����˾���$A��������������������Х��������������ɫ��â��
ɲ�ļ佣�����죬�Ĵ�����$1����Ӱ��$A�Ƴ������������$2����޴��ɱܣ�ֻ���Ǳ��м��š� 
$1����һת����������$2��$2�ճ��ֵֵ���$1ͻȻ���˸�������$A����$2������ 
ֻ�����͡���һ����$2��$B������һ�飬������������������Ƶ������裬$B¶���˰װ׵�Ƥ�⡣Χ�۵��˷���һ���Ц�� 
$2������ɫ���࣬����ֻ��ҧ��Ӳ��ͷƤƴ��ȥ�� 

΢΢һЦ������˵���������ˣ�����һ�����е�$A���ֳ��ϣ����Ƹ������ͣ���ʱ���ɿ���$1����Ӱ�� 
�������ѷֲ��������ˣ����뽣��ֻ�ɼ�һ���������·��裬�����ͻ�� 
$1�������������������,�����������ۣ�Χ����Ⱥ���ڹ��Ե����ѱ������ɳ߿��⡣ 
ֻ��$2���Ƿ��ٱ�����һ��������ϵ�$B������ɨ�У�$2��ͷɢ�����Ǳ��мܣ����ϵ�$B��$1���е�$Aһ���������£������Ʋ���������裬�м������$2�����Ƴ����� 
$1��Ȼ����Ծ��Ȧ�⣬����������һ���ǳɣ�����$2��Ц��ֹ�� 
$2��ͷһ�������ϵ�$B�Ѿ������ƣ���硰߲߲����������Ʈ�ţ�����¶�Űװ׵�Ƥ�⡣Χ�۵��˱���;��һ����ô�Ц�� 
$2�޵����ݣ�������ð���ǣ���ͷһ�𣬡��ۡ������һ����Ѫ��}--->����pfm��������ֵ������� 
*/

#include <ansi.h>
#include <armor.h>
#include <combat.h>
inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
string armor; 
int skill;

if( !target ) target = offensive_target(me);  
if( !target ||  !target->is_character() || !me->is_fighting(target) )  
return notify_fail("�㲻��ս�����޷�ʩ����\n");  

if( me->query_temp("yield") )  
return notify_fail("��ֻ�����޷�ʩ����\n");  

if( (int)me->query("max_jingli", 1) < 500 )  
return notify_fail("��ľ�����Ϊ����������ʩչ���Ҵ̡���\n");  
       
if( (int)me->query("max_neili", 1) < 500 )  
return notify_fail("���������Ϊ����������ʩչ���Ҵ̡���\n");  
       
if( me->query_skill("tangshi-jian",1) < 200 )  
return notify_fail("����ʬ���������죡\n");  
              
if( me->query("neili") <= 500 )  
return notify_fail("�����������ʹ�á��Ҵ̡���\n");  
       
if( me->query("jingli") <= 500 )  
return notify_fail("��ľ�������ʹ�á��Ҵ̡���\n"); 

skill = (int)me->query_skill("sword")/2;

message_vision(HIM"ֻ��$NͻȻ�˽���磬����$nৡ�ৼ�������֮��ͻȻ���У������ڵ���������"+(me->query_temp("weapon"))->query("name")+HIM"΢΢������ֹ��\n\n\n" NOR, me,target);
tell_object(target, HIR"��ֻ���õ����������ң��������ϵ��¼׾��ƣ�\n" NOR);

message_vision(HIR"$N�Ľ����Ҵ�֮����$n�������̼�����ʹ��$n���ɴ�С�\n"NOR, me, target); 
COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
target->start_busy(1+random(2)); 
me->start_busy(1+random(2)); 
me->add("neili", -200);
me->add("jingli", -200);

if( target->query_temp("armor/cloth")){ 
message_vision(HIG "\nͻȻ$N���󼱶����˾���"+(me->query_temp("weapon"))->query("name")+HIG"��������������������Х��������������ɫ��â�� \n"
"ɲ�ļ佣�����죬�Ĵ�����$N����Ӱ��"+(me->query_temp("weapon"))->query("name")+HIG"�Ƴ������������$n����޴��ɱܣ�ֻ���Ǳ��м��š� \n" 
"$N����һת����������$n��$n�ճ��ֵֵ���$NͻȻ���˸�������"+(me->query_temp("weapon"))->query("name")+"����$n������\n" 
"ֻ�����͡���һ����$n��"+(target->query_temp("armor/cloth"))->query("name")+HIG"������һ�飬������������������Ƶ������裬��"+(target->query_temp("armor/cloth"))->query("name")+HIG"¶���˰װ׵�Ƥ�⡣Χ�۵��˷���һ���Ц��\n" 
"$n������ɫ���࣬����ֻ��ҧ��Ӳ��ͷƤƴ��ȥ��\n\n" NOR, me, target); 
target->start_busy(random(5));
COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

message_vision(HIG "\n$N΢΢һЦ������˵���������ˣ�����һ�����е�"+(me->query_temp("weapon"))->query("name")+HIG"���ֳ��ϣ����Ƹ������ͣ���ʱ���ɿ���$N����Ӱ���������ѷֲ��������ˣ����뽣��ֻ�ɼ�һ���������·��裬�����ͻ��\n" 
"$N�������������������,�����������ۣ�Χ����Ⱥ���ڹ��Ե����ѱ������ɳ߿��⡣\n" 
"ֻ��$n���Ƿ��ٱ�����һ��������ϵ�"+(target->query_temp("armor/cloth"))->query("name")+HIG"������ɨ�У�$n��ͷɢ�����Ǳ��мܣ����ϵ�"+(target->query_temp("armor/cloth"))->query("name")+"��$N���е�"+(me->query_temp("weapon"))->query("name")+HIG"һ���������£������Ʋ���������裬�м������$n�����Ƴ�����\n" 
"$N��Ȼ����Ծ��Ȧ�⣬����������һ���ǳɣ�����$n��Ц��ֹ��\n" 
"$n��ͷһ�������ϵ�"+(target->query_temp("armor/cloth"))->query("name")+HIG"�Ѿ������ƣ���硰߲߲����������Ʈ�ţ�����¶�Űװ׵�Ƥ�⡣Χ�۵��˱�����һ����ô�Ц��\n" 
"$n�޵����ݣ�������ð���ǣ���ͷһ�𣬡��ۡ������һ����Ѫ��\n\n" NOR, me, target);

armor = target->query_temp("armor/cloth"); 
if( armor->query("armor_prop/armor")){ 
armor->unequip(); 
armor->move(environment(target)); 
armor->set("name", "��" + armor->query("name")); 
armor->set("value", 0); 
armor->set("armor_prop/armor", 0); 
me->add("neili", -200);
me->add("jingli", -200);
} 
}

else {
message_vision(YEL"$n����һ�࣬����Ķ����$N�Ĺ�����\n\n" NOR, me,target); 
}
me->add("neili", -200); 
me->add("jingli", -200); 
me->start_busy(2); 
return 1;
}
