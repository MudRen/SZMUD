// Code of ShenZhou
// finger.c

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	if( !arg ) {
		if( !wizardp(me) )
	                return notify_fail("�������˭����Ϣ��\n");
		me->start_more( FINGER_D->finger_all() );
	} else {
		if( (int)me->query("jing") < 15 )
			return notify_fail("��ľ����޷����С�\n");
		if( !wizardp(me) )
			me->receive_damage("jing", 15);
		write( FINGER_D->finger_user(arg, me ) );
	}
	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : finger [ʹ��������]
 
���ָ��, ���û��ָ��ʹ��������, ����ʾ�����������������
����������. ��֮, �����ʾ�й�ĳ����ҵ�����, Ȩ�޵�����.
��ʹ������������վ�����ƣ������ʾ�й�ĳ������ڸ�վ�����
�ϡ�
 
������ finger buwu
���ָ� who, locate, mudlist
HELP
    );
    return 1;
}
 
