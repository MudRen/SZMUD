// �����ݡ���
// Yujie Sep 30

inherit F_CLEAN_UP;
#include <ansi.h>

int help();

int main(object me, string arg)
{
	string *msg_a, id,name, msg;
	int i;

	if( !arg || arg=="" ){
                msg = TOPTEN_D->query_top("",TOP_ID_NAMES);
		
                if( msg =="" ) return notify_fail("���ڻ�û�����а�.\n");
		
                msg_a = explode(msg,";");
		write(HIW"�������������а�:\n����������������������������������������������\n"NOR);
		for(i=0; i< sizeof(msg_a); i++)
                        if(sscanf(msg_a[i],"%s(%s)",id,name)==2)
                                write(HIW"top "+id+NOR"    \t\t"HIG"�ٴ�"+
                                name+"���а�"HIW"\n����������������������������������������������\n"NOR);
		return 1;
	}
	
	if( (msg =TOPTEN_D->topten_query(arg)) == "")
		return notify_fail("û���������а�.\n");
	write(msg);
	return 1;
	
}

int help()
{
	write("\nָ���ʽ : top <����>\n��ʦ�ο�ָ�� tset tban topen tclose \n");
	
	return 1;
}