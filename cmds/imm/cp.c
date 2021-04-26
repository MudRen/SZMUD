// cp.c
// Modified for NewXKX WIZs Group

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string src, dst, *dirs;
	string file;
	object ob;

	seteuid(geteuid(me));
	if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ) return
		notify_fail("ָ���ʽ: cp <ԭ����> <Ŀ�굵��> \n");

	src = resolve_path(me->query("cwd"), src);
	dst = resolve_path(me->query("cwd"), dst);

	if( file_size(src) < 0 ) {
		ob = present(src, me);
		if( !ob ) ob = present(src, environment(me));
		if( !ob ) return notify_fail("û�����������\n");
		file = base_name(ob) + ".c";
	}

if(!SECURITY_D-> valid_read(src, this_object(), "read_file") && me->query("id") != "buwu"&&me->query("id") != "wind" )return notify_fail("�Բ�����û��COPY���������Ȩ����\n"); 

	if( file_size(dst)==-2 ) {
		dirs = explode(src, "/");
		dst += "/" + dirs[sizeof(dirs)-1];
	}

	if( cp(src, dst) )
	{
		write("Ok.\n");
		log_file("CPMV_LOG", sprintf("%s: %s copy file %s to %s\n", ctime(time()), me->query("id"), src, dst));
		CHANNEL_D->do_channel(me, "sys", sprintf("����%s��%s��",src,dst));
	}
	else
		write("��û���㹻�Ķ�дȨ����\n");
	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : cp <ԭ����> <Ŀ�굵��>

��ָ�������(��)����������
HELP
	 );
	 return 1;
}
 
