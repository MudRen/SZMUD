// giveall.c
//BY cnnetgame.com's WFoxd 2000-9-15
/*�벻Ҫ����ʹ�ñ�����ر������˶��ʱ�򣬻��ϵͳ�����ܴ󸺵�*/

inherit F_CLEAN_UP;
#include <ansi.h>

int main(object me, string what)
{
    object ob, *ob_list, ob1;
    int i;
    string str;
    
    if(!what) return notify_fail("ָ���ʽ giveall ��Ʒ·��\n");
    
    if( sscanf(what, "%*s.c") != 1) return notify_fail("·�����Ϸ����޷��ҵ���Ʒ��\n");
    
    if( file_size(what) < 0 )
		return notify_fail("û���������(" + what + ")��\n");    
    
    seteuid(getuid());

    ob_list = users();

    for(i=0; i<sizeof(ob_list); i++)
    {
        ob = ob_list[i];
        ob1 = new(what);
        ob1 -> move(ob); 
        tell_object(ob, HIW "\n\n��Ȼ�Ӽ��߼�Զ������м��ٽ���һֻ���������"HIR"���"HIW"��������ҫ�߲ʹ�â��\n" NOR);
        tell_object(ob, HIC "��צ���ƺ�ץ��ʲô������ͻȻ"HIR"���"HIW"�ɿ���צ���и�����ֱ�������������\n" NOR);
        tell_object(ob, HIG "����һ��������һԾ�ɸ߽�����ץ�����У���������Ʈ����档\n\n" NOR);
        
    }
    str = sprintf("���� %d λ��ҵõ���%s��\n", sizeof(ob_list), what->query("name"));    
    me->start_more(str);
    return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ��giveall ��Ʒ·��

�����ߵ��������һ����Ʒ��
HELP
        );
        return 1;
}
