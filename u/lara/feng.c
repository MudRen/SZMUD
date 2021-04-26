// Code of ShenZhou
// feng.c �򹷰����־�
// Lara 2001/11/11
// �����������
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
inherit F_DBASE;

int perform(object me, object target)
{
        string* msghit, msg;
        object weapon;
        int  feng_busy;
        int feng_addspeed;
        int feng_cost;
        int feng_duration;
        int feng_parry;
        string *limb, type, limb_hurt;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) 
        ||          !living (target) )
                return notify_fail("���־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( target->is_busy() ) {
                me->add("neili", -10);
                me->add("jingli", -5);
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");
        }

        if( me->query_temp("ban",1) )
                return notify_fail("������ʹ�ð��־���\n");

        if( me->query_temp("pfmfeng",1) )
                return notify_fail("������ʹ�÷��־���\n");

        if( me->query_skill_mapped("force") != "huntian-qigong" )
                return notify_fail("�����õĲ��ǻ����������޷�ʩչ���־���\n");

        if( me->query_skill("force") < 250 )
                return notify_fail("��Ļ����������δ�����޷�ʩչ���־���\n");

        if( me->query_skill("stick") < 250 )
                return notify_fail("��Ĵ򹷰�����Ϊ���㣬������ʹ�÷��־���\n");

        if( me->query("neili") <= 1000 )
                return notify_fail("�������������\n");

        if( me->query("jingli") <= 600 )
                return notify_fail("��ľ���������\n");

        if( !objectp(weapon = me->query_temp("weapon")) )
                 return notify_fail("�������ʹ�÷��־�����\n");

                msghit = ({
                        "\n$N����򹷰����еġ��⡹�־�������ȫ�Ǻ�ʹ����������������һ��"+(string)weapon->query("name")+HIG"����һƬ��ǽ���������š�\n",
                        "\n$N���һ��������"+(string)weapon->query("name")+HIG"��ʹ���򹷰����ġ��⡹�־���������ס�Ż���\n",
                        "\n$N����"+(string)weapon->query("name")+HIG"��ʹ���򹷰����ġ��⡹�־�����ס��ǰ����ס���ơ�\n",
                        "\n$N����"+(string)weapon->query("name")+HIG"��ʹ���򹷰����е�һ�С���Ȯ��·�����������⡹�־���\n"
                });
                msg = HIG"\n"+ msghit[random(sizeof(msghit))] +"\n" NOR;
                message_vision(msg, me, target);

        if(random(me->query("combat_exp")) * me->query_skill("stick") > random(target->query("combat_exp")) * (target->query_skill("dodge")*3/4+ target->query_skill("parry"))/4)
        {
                msghit = ({
                        "���⡹�־����Ǿ����ͻ���壬$n���в�֧�����¹���ȫ����ס��\n",
                        "ֻ����ӰƮƮ�����⡹�־���ʱ��$n��ǰ����֮�ؾ�����ס�ˡ�\n",
            "$nͻ��"+(string)weapon->query("name")+HIY"���������޷���һʱ��Ȼ��������Թ��롣\n"
                });
                msg = HIY"\n"+ msghit[random(sizeof(msghit))] +"\n" NOR;
                message_vision(msg, me, target);

                feng_busy= me->query_skill("stick")/15;
                feng_addspeed=me->query_skill("stick")/30 ;
                feng_parry = feng_busy * 10;
                
                me->add_temp("apply/parry", feng_parry);
                me->add_temp("apply/speed", feng_addspeed);
                target->add("qi",-me->query_skill("stick")/5);
                target->add("jing",-me->query_skill("stick")/5);
                target->set_temp("feng",1);
                me->set_temp("pfmfeng",1);
                target->start_busy(1+random(3));


        feng_duration= feng_addspeed + feng_busy/( weapon->weight()/1000);
                
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me,target, feng_parry, feng_addspeed  :), feng_duration);
//                call_out("remove_effect",2 + feng_busy/( weapon->weight()/1000),me,target,feng_busy);
                }
        else
        {
                msghit = ({
                        "$n��ʱ������ʱ�ϣ���û�б���ס��\n",
                        "$n���ٱ��У���æ�м����������ܿ��ˡ��⡹�־���\n"
                });
                msg = CYN"\n"+ msghit[random(sizeof(msghit))] +"\n" NOR;
                me->start_busy( 1 + random(4));
                message_vision(msg, me, target);
        
        }

        feng_cost = me->query_skill("stick") / 2;
        me->add("neili", -feng_cost );
        me->add("jingli", -feng_cost/2 );

        return 1;
}


private int remove_effect(object me, object target, int feng_parry, int feng_addspeed)
{
	int skills;
        object weapon;
        skills = me->query_skill("stick")/15;
//        me->add_temp("apply/parry",  -skills * 10);
        me->add_temp("apply/parry",  -feng_parry);
        me->add_temp("apply/speed",  -feng_addspeed);
        if(living (target))
                target->delete_temp("feng");
        me->delete_temp("pfmfeng");
//        tell_object(me, HIY"\n�����е�����̫�����أ�����֮���б仯���顣\n"NOR); 
//        tell_object(me, HIY"\n��İ��ж��䣬�򹷰��ġ��⡹�־���Ȼ�߽⡣\n"NOR); 
        if(objectp(me) && objectp(target) && target->is_fighting(me) )
                message_vision(HIG"\n$N�İ��ж��䣬�򹷰��ġ��⡹�־���Ȼ�߽⡣\n"NOR ,me,target); 
        return 1;
}
