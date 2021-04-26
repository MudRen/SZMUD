// Code of ShenZhou
// enforce.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int pts;

	if( !arg || (arg!="none" && arg!="max" && !sscanf( arg, "%d", pts)) )
		return notify_fail("ָ���ʽ��enforce|jiali <ʹ�����������˵�>|none");

	if( !me->query_skill_mapped("force") )
		return notify_fail("������� enable һ���ڹ���\n");

	if(me->query_temp("n_Defensive_Combat_Mode"))
	{
		return notify_fail("���������ڷ���״̬��������ô����\n");
	}

	if( arg=="none" )
		me->delete("jiali");
	else {
		if ( arg == "max" )
			pts = (int) me->query_skill( "force" )/2;
		if( pts < 0 )
			return notify_fail("��ֻ���� none ��ʾ���������������ֱ�ʾÿһ���ü���������\n");
		if( pts > (int)me->query_skill("force") / 2 )
			return notify_fail("����ڹ����Ӳ�����ô������\n");
		me->set("jiali", pts);
	}

	write("������������" + chinese_number(pts)+"�������˵С�\n");
	return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: enforce|jiali <ʹ�����������˵�>|none
 
���ָ������ָ��ÿ�λ��е���ʱ��Ҫ�������������˵С�

enforce none ���ʾ�㲻ʹ�������� 

See Also: enable
HELP
        );
        return 1;
}
