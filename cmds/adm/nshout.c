// Code of ShenZhou
// nshout.c
// Modify by Scatter
// V. 1.01
#include <ansi.h>
inherit F_CLEAN_UP;

#define SHOUT_LIST      ({ })
int main(object me, string arg)
{
//      if( !wizardp(me) && me->query("id") != "sad" &&
//      me->query("id") != "long" )
        if (!wizardp(me) && member_array(me->query("id"), SHOUT_LIST) == -1)
                return notify_fail("Ŀǰ�ݲ�������� shout��\n");
        if (!arg) return notify_fail("����Ҫ���ʲô��\n");
        shout( HIG "��ϵͳ�����棺" + arg + "\n" NOR );
        write( HIG "��ϵͳ�����棺" + arg + "\n" NOR );
        return 1;
}
