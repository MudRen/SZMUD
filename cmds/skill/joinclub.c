// Code of ShenZhou
// joinclub.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob, old_app;
        mapping family, skills;
        int i;
        string *skname;

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if( !arg ) 
                return notify_fail("ָ���ʽ��joinclub <����>\n");

        if( !(ob = present(arg, environment(me)))
        ||      !ob->is_character() )
                return notify_fail("�������˭�İ��ɣ�\n");

        if( !living(ob) ) 
                return notify_fail("������Ȱ�" + ob->name() + "Ū�ѡ�\n");

        if( ob==me ) 
                return notify_fail("�����Լ��İ��ɣ���������û���á�\n");
        
        if (!ob->query("in_club"))
                return notify_fail("�Է������ް����ɰ���\n"); 
        if (me->query("in_club"))
                return notify_fail("��������˰���ܴ�����\n"); 
        
        me->start_busy(1);
        me->set_temp("joinclub",ob->query("id"));
        message_vision(HIR"����$N�����$n�İ��ɡ�\n",me,ob);
        return 1;
}


int help(object me)
{
        write(@HELP
ָ���ʽ : joinclub <����>
��������������һ�����ɡ� 
HELP
        );
        return 1;
}
