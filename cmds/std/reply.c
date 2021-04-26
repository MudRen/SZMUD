// Code of ShenZhou
// reply.c

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string target, mud;
	object obj;

	if( !arg || arg=="" )
		return notify_fail("��Ҫ�ش�ʲô��\n");

	if( !stringp(target = me->query_temp("reply")) )
		return notify_fail("�ղ�û���˺���˵������\n");

	if( sscanf(target, "%s@%s", target, mud)==2 ) {
		GTELL->send_gtell(lower_case(mud), lower_case(target), me, arg);
		write("��·ѶϢ���ͳ�������Ҫ�Ժ���ܵõ���Ӧ��\n");
		return 1;
	}

	obj = find_player(target);
	if( !obj )
		return notify_fail("�ղź���˵�����������޷������㣬�����Ѿ��뿪��Ϸ�ˡ�\n");
	if (!wizardp(me) && wizardp(obj) && obj->query("env/block")=="YES")
                return notify_fail(obj->name()+"��æ����ʲô�´������˵�ɡ�\n");
        if (!wizardp(me) && obj->query("env/block") == (string)me->query("id"))
                return notify_fail(obj->name()+"��������������\n");

	if( me->query_condition("reply_c")) return notify_fail("����ЪЪ�ɣ�һ����˵��\n");
        if( arg==(string)me->query_temp("last_reply_msg") )
                me->add_temp("reply_msg_cnt", 1);

        if( living(me) )
        {
                me->set_temp("last_reply_msg", arg);
        }

	if (me->query_temp("reply_msg_cnt") > 20)
	{
		me->apply_condition("reply_c", 2);
		return notify_fail("��˵�ķϻ�̫�࣬ЪЪ�ɣ�\n");
	}

	write(GRN "��ش�" + obj->name(1) + "��" + arg + "\n" NOR);
	tell_object(obj, sprintf(GRN"%s(%s)�ش��㣺%s\n"NOR,
		me->name(1), me->query("id"), arg ));

	obj->set_temp("reply", me->query("id"));
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��reply <ѶϢ>

����������ָ��͸ղ��� tell ����˵����ʹ����˵����

see also : tell
HELP
	);
	return 1;
}
