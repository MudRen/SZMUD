// Code of ShenZhou
// arthurgu 1999.10

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string msg;
	write(CLR);
	if(!arg)
	{
		msg = "                                              
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		                                                    ";
		write(msg);
	me->set_temp("block_msg/all",1);
	return 1;}
	else if( arg == "leave")
	{
        me->delete_temp("block_msg/all");
	write(CLR);
        write("��ӭ���ػ��������磡\n");
	
      return 1;
        }
}

int help(object me)
{
     write(@HELP
ָ���ʽ: boss | boss leave

���ָ���������쵼����ǰ˲�佫��Ļ�����е�����������
�������յ�xkx��ѶϢ��ֱ��������boss leave�ָ���


HELP
    );
    return 1;
}
