// Code of ShenZhou
// unset.c

inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
	if( !arg || arg=="" ) return help();
	if( arg=="all" ) me->delete("env");
	else me->delete("env/" + arg);
	write("��������ɾ���ˡ�\n");
	return 1;
}

int help()
{
	write(@TEXT
ָ���ʽ��unset <������>

���ָ������ɾ�������������趨��

�޸Ļ����ӱ����趨���� set ָ�
TEXT
	);
	return 1;
}
