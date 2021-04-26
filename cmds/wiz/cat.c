// Code of ShenZhou
// cat.c
// modified by sdong for more security 11/02/98

#include "/doc/help.h"

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string arg)
{
	string file;
	
	seteuid(geteuid(me));
    if (!arg) return notify_fail("����Ҫ��ʾ�Ǹ�����?\n");
	file = resolve_path(me->query("cwd"), arg);
	if( file_size(file)<0 ) return notify_fail("û�����������\n");

	CHANNEL_D->do_channel(me, "sys", sprintf("����ļ�%s��", file));
	if(!SECURITY_D-> valid_read(file, this_object(), "read_file") )return notify_fail("�Բ�����û�ж����������Ȩ����\n");
	cat(file);
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : cat <����>

��ָ�������(��)ֱ�Ӷ�ȡĳ����֮��ʽ��
HELP
    );
    return 1;
}
