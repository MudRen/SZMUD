// Code of ShenZhou
// yield.c
 
inherit F_CLEAN_UP;
 
int help();
 
int main(object me, string arg)
{
	if( me != this_player(1) ) return 0;
 
	if( !arg || arg=="" )
		return notify_fail("�����ս����ֻ���򲻻��֣�YES��ʾֻ����NO��ʾ���Ի��֡�\n");

	if( arg=="yes" ) {
		write("��������ʱֻ���򲻻��֡�\n");
		me->set_temp("yield",1);
		return 1;
	}
 
	if( arg=="no" ) {
		write("��������ʱ���Ի��ַ�����\n");
		me->set_temp("yield",0);
		return 1;
	}
	return help();
}
 
int help()
{
	write(@TEXT
ָ���ʽ��yield <yes/no>
 
���ָ������������ʱֻ���򲻻��֣���Ȼ����������ȴ��ֱ�����
�мܺ����㷽��ļ��ܡ�
 
TEXT
	);
	return 1;
}
