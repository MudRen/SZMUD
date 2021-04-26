// Code of ShenZhou
// exert.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string force;
        int result;
        
        seteuid(getuid());

        if( me->is_busy() )
		{
			return notify_fail("( ����һ��������û����ɣ�����ʩ���ڹ���)\n");
		}

		// Allow user to yun recover and etc in ciwan and defense mode
		if(arg != "regenerate" && arg != "recover" && arg != "refresh")
		{
			if(me->query_temp("n_Defensive_Combat_Mode"))
			{
				return notify_fail("���������ڷ���״̬���޷�ʩչ�⹦��\n");
			}

			if( (int)me->query_temp("pixie/ciwan"))
			{
                return notify_fail("��˫��Ҫ�������У��޷�ʩչ�⹦��\n");
			}
		}

        if( !arg ) 
                return notify_fail("��Ҫ���ڹ���ʲô��\n");

        if( stringp(force = me->query_skill_mapped("force")) ) {
                notify_fail("����ѧ���ڹ���û�����ֹ��ܡ�\n");
                if( SKILL_D(force)->exert_function(me, arg) ) {
/*
// for avoid player use some exert to gain skill.
// temprory disable improve_skill until we find a better way to fix it.
                        if( random(120) < (int)me->query_skill("force") )
                                me->improve_skill(force, 1, 1);
*/
                        return 1;
                } else if( SKILL_D("force")->exert_function(me, arg) ) {
/*                        if( random(120) < (int)me->query_skill("force", 1) )
                                me->improve_skill("force", 1, 1); */
                        return 1;
                }
                return 0;
        }

        return notify_fail("�������� enable ָ��ѡ����Ҫʹ�õ��ڹ���\n");
}

int help (object me)
{
        write(@HELP
ָ���ʽ��exert|yun <��������> [<ʩ�ö���>]

����������һЩ���칦�ܣ������Ҫָ��<��������>��<ʩ�ö���>����п��ޡ�
����ʹ��ĳһ���ڹ������칦��֮ǰ����������� enable ָ����ָ����Ҫʹ��
���ڹ���

��ο� help force �ɵ�֪һЩ�󲿷��ڹ����еĹ��ܣ����������õ��ڹ�����
��û�иù��ܣ���һ�Ի�ο�����˵����֪��

ע�������ı��Լ����ڹ�����ԭ�����������������ֱ��ת����ȥ������
    �ӣ���ʼ��

HELP
        );
        return 1;
}
