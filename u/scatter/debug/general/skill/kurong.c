// Code of ShenZhou
//kurong.c �����ķ�
// Modify By Scatter

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int exert(object me, object target)
{
        int skill;

        if (target != me)
                return notify_fail("�����ķ������˺������ã�\n");

        if (me->query_temp("kurong"))
                return notify_fail("��������ת�����ķ��ˡ�\n");

        if (me->query_skill("kurong-changong",1) < 100
                || me->query_skill("force",1) < 100
                || me->query_skill("buddhism",1) < 100 )
                return notify_fail("�����δ��ͨ��������ǿ�˿����ķ������洦��\n");

        if (me->query("max_neili")<2000
                || me->query("neili") < me->query("max_neili")/10)
                return notify_fail("�������������ת�����ķ���\n");

        skill=me->query_skill("kurong-changong",1)+me->query_skill("buddhism",1);

        message("vision", HIW "\n"+me->query("name")+"˫�ƺ�ʮ����Ϣ��ת�£�һ����Ƭ�̼���Ѫ��ȫ��ֻʣ�ݹǣ���Ƭ�̣��ֻظ�Ѫ���ӯ��ģ����\n\n" NOR, environment(me), me);
        tell_object(me, HIW "\n��˫�ƺ�ʮ����ת�����ķ���һ�������Ե����������������ת��Ϣ������һ��һ�����֣�Ƭ�̼��ظ�������\n\n" NOR);

        me->set_temp("kurong", skill*4*me->query("max_neili")/2000);

        remove_call_out("checking");
        call_out("checking", 1, me);
        me->add("neili", - me->query("max_neili")/10);

        return 1;
}

void checking(object me)
{       
        int maxqi, amount;
        
        remove_call_out("checking");
        //reset_eval_cost();
        
        if (!me->query_temp("kurong")) {
                tell_object(me, HIW "��е������������ǣ���ת�Ŀ����ķ�����ɢȥ��\n" NOR);
                return;
        }

        if (!me->is_fighting()) {
                if (me->query_temp("kurong")<=50)
                        me->delete_temp("kurong");
                else me->add_temp("kurong",-50);
        }

        maxqi=me->query("eff_qi");

        if (me->is_ghost()) {
                me->delete_temp("kurong");
                return;
        }

        if (living(me) && (maxqi < me->query("max_qi")*95/100 && me->query("neili") > 150)) {
                amount=(me->query_skill("kurong-changong",1)+me->query_skill("buddhism",1))/5+10;
                me->add("neili", -50);
                me->receive_curing("qi", amount);
        message_vision("$N�������˼���������Ϣ��ת���˿ڵ�Ѫ���Զ�ֹס�ˡ�\n", me);
        }

        if (living(me) && (me->query("qi") < (maxqi*2/3))) {
                amount = maxqi - me->query("qi");
                if (amount > me->query_temp("kurong")) amount=me->query_temp("kurong");
                me->add_temp("kurong",-amount);
        me->receive_heal("qi", amount);
        message_vision("$N�������˼���������ɫ�������ö��ˡ�\n", me);
        }

        call_out("checking", 1, me);
        return;
}
