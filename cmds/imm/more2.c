// Code of ShenZhou
// cat.c
// modified by sdong for more security 11/02/98

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string file;
	object ob;

	seteuid(geteuid(me));
	if (!arg) return notify_fail("ָ���ʽ : more <����>|<�����> \n");
	file = resolve_path(me->query("cwd"), arg);
	if( file_size(file) < 0 ) {
		ob = present(arg, me);
		if( !ob ) ob = present(arg, environment(me));
		if( !ob ) return notify_fail("û�����������\n");
		file = base_name(ob) + ".c";
	}

	//��¼�鿴���ļ�/log/cmds/more   ɽè(adx)
	//��¼�鿴���ļ���Ϊ/log/static/more   ���(April)
	log_file("static/more",
	sprintf("%s(%s) more %s on %s\n",
	me->name(1), //��¼ʹ�����������
	geteuid(me), //��¼ʹ�������ID
	file,        //��¼��ȡ�ļ���·��
	ctime(time()) ) ); //��¼ʹ�������ʱ��	

	CHANNEL_D->do_channel(me, "sys", sprintf("����ļ�%s��", file));
	if(!SECURITY_D-> valid_read(file, this_object(), "read_file") && me->query("id") != "buwu" )return notify_fail("�Բ�����û�ж����������Ȩ����\n");

	me->start_more( read_file(file));
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : more <����>|<�����>
 
��ҳ��ʾ�������ݡ�
 
more ģʽ�µ�ָ��:
q      : �뿪 more.
b      : ��ʾǰһҳ������.
[ENTER]: ��ʾ��һҳ������.

HELP
    );
    return 1;
}
