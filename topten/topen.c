// �����硤���μǣ���������WUHEE WIZ.GROUP
// misu

inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
	string top_id, top_name, top_prop;
	mapping tops;
	int i;

	if( !arg || arg=="" )
		return help();

	if( sscanf(arg, "%s %s %s", top_id, top_name, top_prop)==3 ) {
		if(	TOPTEN_D->add_top(top_id, top_name,top_prop) )
			write("��ɹ��Ľ�����topten "+top_id+"ʮ��"+top_name+"���а�\n");		
		return 1;
	}

	return help();
}

int help()
{
	write ( @HELP
��ָ����������һ���µ����а�.

ָ���ʽ��topen top_id top_name top_prop
�����������Ǳ����.Ʃ��Ҫ����pker�����а�,
��Ӧ����������:

	topen pker ���� PKS


������ִ�гɹ���,����һ�����а�,�Ժ��������
topten pker���鿴ʮ����˰�.
HELP
	);
	return 1 ;
}
