                   //̫������ (������)

#include <ansi.h>
inherit F_SSERVER;

void remove_effect(object me);

int perform(object me, object target)
{       
        string msg;
        int skill, intActTime, intParry, intOther;

                if(!me->query("can/mian-zhang"))
                        return notify_fail("���������ʱֹͣ��� PERFORM, �����ĸ��� POST ���䵱���԰�\n");
        
        if( !target ) target = offensive_target(me);
                
                //if( me->query_temp("mian-zhang/yunhuakai") )
        //              return notify_fail("�����ڲ���ʹ����̫�����ơ���\n");

        if( me->query_temp("mian-zhang/tjmz"))
                return notify_fail("���Ѿ��ڳ���̫�����ơ��ˡ�\n");
        
        if( objectp(me->query_temp("weapon")) ) 
                return notify_fail("���ֲ���ʩչ̫�����ƣ�\n");
        
        if( me->query_skill_mapped("strike") != "mian-zhang" )
                return notify_fail("�����õĲ��ǻ������٣�����ʩչ�������٣�\n");

        if( me->query_skill_prepared("strike") != "mian-zhang" )
        return notify_fail("�������Ĳ������ƣ�����ʩչ̫�����ƣ�\n");

                if( me->query_skill_prepared("cuff") != "taiji-quan" )
        return notify_fail("�������Ĳ���̫��ȭ������ʩչ̫�����ƣ�\n");

        if( me->query_skill_mapped("force") != "taiji-shengong" )
                return notify_fail("�����õĲ���̫���񹦣�ʹ����̫�����ƣ�\n");

        if( me->query_skill("mian-zhang", 1) < 99)
                return notify_fail("������Ʋ������죬��δ�ܳ��˾��С�\n");
        
        if( me->query_skill("taiji-shengong", 1) < 79)
                return notify_fail("���̫������Ϊ���������ܳ���̫�����ơ���\n");

        if (me->query("max_neili") < 1000)
                return notify_fail("���������Ϊ����,�޷�ʹ�á�̫�����ơ�\n");

        if (me->query("neili") < 500)
                return notify_fail("�����������,�޷�ʹ�á�̫�����ơ�\n");

        if( (int)me->query("jiali") > 2 || (int)me->query("jiajin") > 2)
                return notify_fail("�㷢�ּ������޷����������������ޣ�����������Ҫ�����ӳ�����\n");
                
                
      msg = HIY"\n$N˫��һ����װ���������µ����ӣ������������������������䵱������������ļ�ʽ��\n\n"NOR;

        message_vision(msg, me, target); 

        me->add("neili", -500);
        me->add("jingli", -40);
                me->set_temp("mian-zhang/tjmz", 1);

                intActTime = me->query_skill("taiji-shengong", 1) / 3 * 2;
                intParry = me->query_skill("mian-zhang", 1) + me->query_skill("taiji-quan", 1) + me->query_skill("taiji-shengong", 1);
                intParry = intParry / 2;
                intOther = intParry / 3;
                        
                me->set_temp("apply/parry", intParry);
                me->set_temp("apply/damage", intOther);
                me->set_temp("apply/attack", intOther);
                me->set_temp("apply/defense", intOther);
                me->set_temp("apply/speed", intOther);
                me->set_temp("apply/dodge", -1000);
                
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me:), intActTime);
                
        return 1;
}

void remove_effect(object me)
{
        me->delete_temp("apply/parry");
        me->delete_temp("apply/damage");
        me->delete_temp("apply/attack");
        me->delete_temp("apply/defense");
        me->delete_temp("apply/speed");
        me->delete_temp("mian-zhang/tjmz");
        me->delete_temp("apply/dodge");

        message_vision(HIW"$N�����������ļ�ʽ�ջأ�$N�������ջص��\n", me); 
        return;
}
