// Code of ShenZhou
// mv.c
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        string src, dst;
 
        seteuid(geteuid(me));
        if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ) return
        notify_fail("ָ���ʽ: mv <ԭ����> <Ŀ�굵��> \n");
 
        src = resolve_path(me->query("cwd"), src);
        dst = resolve_path(me->query("cwd"), dst);
        if(!SECURITY_D->valid_read(src, this_object(), "read_file") )return notify_fail("�Բ�����û�ж����������Ȩ�
���\n");

 
        if( !rename(src, dst) )
        {
                write("Ok.\n");
		log_file("CPMV_LOG", sprintf("%s: %s move file %s to %s\n", ctime(time()), me->query("id"), src, dst));
		CHANNEL_D->do_channel(me, "sys", sprintf("%s����move�ļ�����%s��%s��", me->query("name"), src, dst));
        }
        else
                write("��û���㹻�Ķ�дȨ����\n");
        return 1;
}
 
int help(object me)
{
  write(@HELP
ָ���ʽ : mv <ԭ����> <Ŀ�굵��>
 
��ָ�������(��)�޸�ĳ��������Ŀ¼���ơ�
HELP
    );
    return 1;
}
 
