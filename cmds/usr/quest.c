#include <ansi.h>

int main(object me)
{
	string output;
	if(!find_object(TASK_D)) 
		return notify_fail("�����鲢δ���롣\n");
	output=sprintf(HIY"		������Թ����\n\n\n"NOR);
	output+=TASK_D->query_task_list();
	write(output);
	return 1;
}

int help(object me)
{
        write(@HELP
        ����������Questϵͳ��quest ���������г�ϵͳ�е����н�����Թ��
        ����������� questobj ����Ŀ���֮�� ���������е�������Ʒ��
        ��λ�õ���Ϣ����Ʒһ������������ NPC ���ϡ��ҵ���Ӧ��Ʒ��
        ���佻�������ˣ��Ϳ��Եõ������Լ���һ�������񡣾������ 4m 
        ����ң���һ��������ֻ�ܵõ�Ǳ�ܣ���û�о��顣
        �� job �İ�����鿴 help questjob��
HELP
    );
    return 1;
}
