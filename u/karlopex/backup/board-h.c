// Code of ShenZhou
// board.c
// by Marz@XKX 11/09/96
// modified by Jay 6/2/97

inherit F_CLEAN_UP;

int main(object me)
{
	return notify_fail("����help board�鿴���԰�ʹ�÷�����\n");
}

int help()
{
	write(@HELP

�͵꼰�������ɵ����԰�����ҽ������顢�ĵõ���Ҫ�ط���
��ʦҲͨ�����԰淢���ͣգĵĸ��ָĶ������һ��Ҫ��ʱ
�鿴�����԰�ָ���������԰棨�£���䣬�ң�����
�ȣ��ĵط�����Ч��

	list 			: �鿴�����԰�Ŀ¼
	read <��>		: �Ķ��ڣ�������
	post <title>		: �����Ҳ����д���䡭
	discard <��>		: ɾ���ڣ������ԡ�������ֻ��ɾ���Լ�����


HELP
	);
	return 1;
}
