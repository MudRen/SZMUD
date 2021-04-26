// Code of ShenZhou
// by aln  2/98
// modified by aln  4/98

inherit F_CLEAN_UP;

#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
        me->apply_condition("lmjob", duration - 1);

        if( duration < 1 ) {
                if( strsrch(base_name(environment(me)), "/d/hangzhou/xiaoyuan") == 0 ) {
                me->set_temp("lmjob/ok", 1);
                message_vision(HIR"\nһ����ͷ������$N˵������ʦ�����ˣ�����Ϣһ�°ɡ�\n"NOR, me);
                }

        return 0;
        }

        return 1;
}
