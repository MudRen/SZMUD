// Code of ShenZhou
// longhe.c
// xuy 09/22/96

#include <ansi.h>

int exert(object me, object target)
{
        int level = me->query_skill("linji-zhuang", 1);
        int jingli, jing, extrajing;

        if (level < 90) return notify_fail("����ټ�ʮ��ׯ��Ϊ��������\n");

        if( (int)me->query("max_neili") < 5*level ) 
                return notify_fail("�������������ǿ��\n");

        if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
                return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");
        
        if( (int)me->query("eff_jing") < (int)me->query("max_jing") / 2 )
                return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

        extrajing = (int)me->query("jing") - (int)me->query("max_jing")/2;
        if (extrajing < 1)
                return notify_fail("��ľ���̫�");

        if( (int)me->query("neili") < 1 )
                return notify_fail("�������������\n");

        jingli = (int)me->query("max_jingli") - (int)me->query("jingli");
        if ( jingli < 10 )
                return notify_fail("�����ھ������档\n");
        jing = 90*jingli/level;
        if (jing < 5) jing = 5;
        if (extrajing < jing) {
                jingli = jingli * extrajing / jing;
                jing = extrajing ;
        }
        me->add("jing", -jing);
        me->receive_heal("jingli", jingli);
        
        write( HIY "�㰵��������ׯ�������ţ��յػ����۾��������پ�����������\n" NOR);
        message("vision",
                HIY + "ֻ��" + me->name() + "����ƣ������ת˲��㾫���ӡ�\n" NOR,
                environment(me), me);

        // if (level > 120) me->improve_skill("linji-zhuang", -1);
        return 1;
}
