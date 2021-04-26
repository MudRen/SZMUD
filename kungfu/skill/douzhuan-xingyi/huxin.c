// Code of ShenZhou
// Code of ShenZhou
//huxin.  ���Ĺ���

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int exert(object me, object target)
{
        int skill;

        if (target != me)
                return notify_fail("���Ĺ�ֻ���Լ���Ч��\n");

        if (me->query_temp("huxin"))
                return notify_fail("���Ѿ���ס�����ˡ�\n");

        if (me->query_skill("douzhuan-xingyi",1) < 80
                || me->query_skill("force",1) < 80
                || me->query_skill("literate",1) < 80 )
                return notify_fail("��Ķ�ת������δ�ɣ��޷��������ģ�\n");

        if (me->query("neili") < 300)
                return notify_fail("�������̫�٣�\n");

        skill=me->query_skill("douzhuan-xingyi",1)+me->query_skill("literate",1);

        message("vision", HIW "\n"+me->query("name")+"Ǳ�ö�ת�����񹦣���ס������\n\n" NOR, environment(me), me);
        tell_object(me, HIW "\n����ת��ת�����ڹ�����ס������\n\n" NOR);

        me->set_temp("huxin", skill*8);
        me->add_temp("apply/armor",  me->query_skill("douzhuan-xingyi",1)/2);

        remove_call_out("checking");
        call_out("checking", 1, me);
        me->add("neili", -200);

        return 1;
}

void checking(object me)
{
        int maxqi, amount;

        if (!me->query_temp("huxin")) {
        	me->add_temp("apply/armor", -me->query_skill("douzhuan-xingyi",1)/2 );
                tell_object(me, HIW "��ɢȥ���Ĺ���������һ������\n" NOR);
                return;
        }

        if (!me->is_fighting()) {
                if (me->query_temp("huxin")<=50)
                        me->delete_temp("huxin");
                else me->add_temp("huxin",-50);
        }

        maxqi=me->query("eff_qi");

        if (me->is_ghost()) {
                me->delete_temp("huxin");
                return;
        }

        if (living(me) && (maxqi < me->query("max_qi")*95/100 && me->query("neili") > 150)) {
                amount=(me->query_skill("douzhuan-xingyi",1)+me->query_skill("literate",1))/3+10;
                me->add("neili", -40);
                me->receive_curing("qi", amount);
        message_vision("$Nת�����Ĺ�����ֹס�˿ڵ���Ѫ��\n", me);
        }

        if (living(me) && (me->query("qi") < (maxqi*2/3))) {
                amount = maxqi - me->query("qi");
                if (amount > me->query_temp("huxin")) amount=me->query_temp("huxin");
                me->add_temp("huxin",-amount);
        me->receive_heal("qi", amount);
        message_vision("$Nת�����Ĺ�������ɫ��ʱ�ö��ˡ�\n", me);
        }

        call_out("checking", 1, me);
        return;
}       
