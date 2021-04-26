// Code of ShenZhou
// yiyang.c һ��ָ��ע������

#include <ansi.h>

inherit F_SSERVER;

private int remove_effect(object me, object weapon);

int perform(object me, object target)
{
        object weapon;
        int skill, skill1;

        if (me->query_skill_mapped("force") != "kurong-changong")
                return notify_fail("�����õ��ڹ��ķ����ԣ��޷�����һ��ָ��\n");

        if (me->query_temp("yiyang"))
                return notify_fail("������һ��ָָ�����������ˣ�\n");

        if (me->query_skill("force",1)<100
                || me->query_skill("kurong-changong",1)<100
                || me->query_skill("duanjia-jian",1)<100
                || me->query_skill("yiyang-zhi",1)<120)
                return notify_fail("��Ĺ����������޷�����һ��ָָ���������ϣ�\n");

        if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type")!="staff")
                return notify_fail("��û��ʹ����ȷ���������޷���һ��ָ�������ϡ�\n");

        if (me->query("neili") <= 300)
                return notify_fail("�������������һ��ָ����\n");
        if (me->query("jingli") <= 100)
                return notify_fail("��ľ���������һ��ָ����\n");

        if (weapon->query("rigidity")>=1000)
                return notify_fail("�㷢����������ʵ��ر��Ӳ���޷���ע���������ϣ�\n");

        message("vision", HIY "\n"+me->query("name")+"����"+weapon->query("name")+"��������Ƭ�̡�\n\n" NOR, environment(me), me);
        tell_object(me, HIY "\n��������������һ��ָָ����ע��"+weapon->query("name")+"�ϡ�\n\n" NOR);

        skill = me->query_skill("kurong-changong",1);

        me->set_temp("yiyang", 25+skill/6);

        skill = me->query_skill("yiyang-zhi",1) + me->query_skill("kurong-changong",1);
        weapon->set_temp("rig", weapon->query("rigidity"));
        weapon->set_temp("yiyang", 1);
        me->set_temp("apply/attack", me->query_skill("force")/3);

        if (weapon->query("rigidity") < 100 )
                weapon->add("rigidity", 300+skill);
        else if ( weapon->query("rigidity") < 500 )
                weapon->add("rigidity", 200+skill);
        else if ( weapon->query("rigidity") < 1000 )
                weapon->add("rigidity", 100+skill);

        call_out("checking", 1, me, weapon);
        me->add("neili", -200);
        me->add("jingli", -50);

        return 1;
}

void checking(object me, object weapon)
{
        if (!me) {
                weapon->set("rigidity", weapon->query_temp("rig"));
                weapon->delete_temp("yiyang");
                weapon->delete_temp("rig");
                return;
        }
        if (me->query_temp("yiyang")) {
           if (environment(weapon)!= me || weapon!=me->query_temp("weapon")) {
                remove_effect(me, weapon);
                tell_object(me, HIY "\n���һ��ָָ����"+weapon->name()+"�����˻�����\n\n" NOR);
                return;
           }
           else if (weapon->query("weapon_prop") == 0) {
                remove_effect(me, weapon);
                tell_object(me, HIY "\n���"+weapon->name()+"�ѻ٣����ò��ջع�ע�����ϵ�һ��ָָ����\n\n" NOR);
                return;
           }
           else if (me->query_skill_mapped("force") != "kurong-changong") {
                remove_effect(me, weapon);
                tell_object(me, HIY "\n��е���Ϣ�������޷����ֹ�ע��"+weapon->name()+"�ϵ�һ��ָָ����\n\n" NOR);
                return;
           }

           me->add_temp("yiyang", -1);
           call_out("checking", 1, me, weapon);
        }
        else {
           remove_effect(me, weapon);
        tell_object(me, HIY "\n��е���Ϣ���ǣ����ò������˹�����"+weapon->name()+"���ջع�ע��һ��ָָ����\n\n" NOR);
        }
}       

private int remove_effect(object me, object weapon)
{
        weapon->set("rigidity", weapon->query_temp("rig"));
        weapon->delete_temp("yiyang");
        weapon->delete_temp("rig");
        me->delete_temp("apply/attack");
        me->delete_temp("yiyang");
        return 1;
}
