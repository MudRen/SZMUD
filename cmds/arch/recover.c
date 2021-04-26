// Code of ShenZhou
// recover.c
// qfy, May 19, 99.

#define SUICIDE_LIST "/log/static/SUICIDE.c"

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	string file, *tmp, *Suicided;
	object ob;
	int cnt, found=0;

	Suicided = ({});

	if( me != this_player(1) ) return 0;

	if( wizhood(me) != "(arch)" && wizhood(me) != "(admin)" )
		return notify_fail("��û���㹻Ȩ�޻ָ���ҵ����ݡ�\n");

	if (!arg)
		return notify_fail("����ָ��Ǹ���ҵ����ݣ�\n");

/*
	ob = new(LOGIN_OB);
        ob->set("id", arg);
	if( ob->restore() ) {
		destruct(ob);
		return notify_fail("���ָܻ�û����ɱ��������ݡ�\n");
	}
*/

	file = read_file(SUICIDE_LIST);
	if (!file) 
		return notify_fail("ϵͳ��û����ɱ��ҵļ�¼��\n");

	tmp = explode(file, "\n");

	for( cnt=0; cnt < sizeof(tmp); cnt++ ) {
		if( tmp[cnt][0] == '#' || tmp[cnt][0] == '\n' || tmp[cnt] == "" )
			continue;
		else if ( strsrch( tmp[cnt], "*"+arg+" commits" ) >= 0 ) {
			found = 1;
			continue;
		}
		else 
			Suicided += ({ tmp[cnt] });
	}

//	Suicided = filter_array(Suicided, (:strsrch:), arg+" commits");

	if ( !found )
		return notify_fail("�����Ҳ������ڡ�\n");

	rm(SUICIDE_LIST);

	for ( cnt=0; cnt < sizeof(Suicided); cnt++ ) {
		write_file(SUICIDE_LIST, Suicided[cnt] + "\n", 0);
	}

	log_file("static/RESTORE", sprintf("%s recovered %s after suicide on %s\n", geteuid(me), arg, ctime(time())));
	write(arg + "�ٴ��������Ȩ���ָ��ˡ�\n");

	return 1;
	
}

int help(object me)
{
	write(@HELP
ָ���ʽ��recover [player id]

���������������ָ��Ѿ���ɱ������ٴ��������Ȩ����
HELP
	);
	return 1;
}
