
int main(object me,string arg)
{
	mixed output;
	string ow,na;
	if(!arg||arg=="")
		return notify_fail("�������ʲô��Ʒ����Ϣ��\n");
	if(me->is_busy()) return notify_fail("���������ܵ����˴������ɣ�\n");
	if(sscanf(arg,"%s��%s",ow,na)!=2) 
		return notify_fail("û����˵������������\n");
	output=TASK_D->query_location(arg);
	if(intp(output)&&output<0)
		return notify_fail("û�и����й�"+arg+"����Ϣ��\n");
	if(stringp(output))
	{
		write(output);
		me->start_busy(1);
		return 1;
	}
	return 0;
}
int help(object me)
{
        write(@HELP
	questobj + �����������е�����ȫ����
HELP
    );
    return 1;
}
