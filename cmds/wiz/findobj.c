// Code of ShenZhou
// findobj.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string file)
{
	object *obs, ob, where;
	string msg;

	seteuid( geteuid(me) );

	if (!file) file = me->query("cwf");
	if (!file)
		return notify_fail("��ҪѰ��ʲô�����\n");

	file = resolve_path(me->query("cwd"), file);

	if( file_size(file+".c") < 0 )
		return notify_fail("û���������(" + file + ")��\n");

	obs = filter_array(children(file), (: clonep :));

	if (sizeof(obs) == 0)
		return notify_fail("�Ҳ�����������ĸ��Ƽ���\n");

	msg = sprintf("�ܹ��ҵ���%s�����Ƽ�\n", chinese_number(sizeof(obs)));
	foreach(ob in obs) {
		where = environment(ob);
		msg += sprintf("%-40s\t%s(%s)\n", sprintf("%s(%O)", ob->name(),ob),
			where ? (living(where) ? where->name() : where->query("short")) : "����",
			where ? (living(where) ? where->query("id") : base_name(where)) : "none");
	}
	me->start_more(msg);
	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : findobj <���֮�ļ���>

��ָ���г���������ĸ��Ƽ���
HELP
    );
    return 1;
}
