// Code of ShenZhou
// save.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object link_ob;
//            tell_object(me,HIG"����ϵͳʹ���Զ��洢ϵͳ���ڽ����к��˳�ʱ��������ݽ��д洢��\n"NOR);
//            return 1;

	seteuid(getuid());

    if (me->query_temp("saved")) return notify_fail("����������ϡ�\n");
    me->set_temp("saved", 1);
    me->start_call_out( (: call_other, me, "delete_temp", "saved" :), 300 + random(90));

	if( !objectp(link_ob = me->query_temp("link_ob")) )
		return notify_fail("�㲻�Ǿ����������߽��룬���ܴ��档\n");

	if( environment(me)->query("valid_startroom") ) {
		write("�����´����߽���ʱ��������￪ʼ��\n");
	}

	if( (int)link_ob->save() && (int)me->save() ) {
	me->set("startroom", base_name(environment(me)));
        write("����������ϡ�\n");
		return 1;
	} else {
		write("����ʧ�ܡ�\n");
		return 0;
	}
}

int help(object me)
{
	write(@HELP
ָ���ʽ��save

��������ܶ��Ľ����������
HELP
	);
	return 1;
}
