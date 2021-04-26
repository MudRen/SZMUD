// Code of ShenZhou
// tail.c
// modified by sdong for more security 11/02/98

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string file;

	seteuid(geteuid(me));
    if (!arg) return help(me);
	file = resolve_path(me->query("cwd"), arg);
	if( file_size(file)<0 ) return notify_fail("û�����������\n");
	if(!SECURITY_D-> valid_read(file, this_object(), "read_file") )return notify_fail("�Բ�����û�ж����������Ȩ����\n");
	tail(file);
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : tail <����>

��ָ�������(��)ֱ�Ӷ�ȡĳ������ĩβ�ļ��С�
HELP
    );
    return 1;
}
