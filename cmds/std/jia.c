// Code of ShenZhou
// marry.c

#include <ansi.h>
#include <dbase.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, old_app;

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

	if( !arg ) 
		return notify_fail("ָ���ʽ��marry | jia <����>\n");

	if( !(ob = present(arg, environment(me)))
	||	!ob->is_character() )
		return notify_fail("����޸�˭��\n");

       	if( !living(ob) ) 
		return notify_fail("������Ȱ�" + ob->name() + "Ū�ѡ�\n");
		
        if( (object)ob->query_temp("marriage/propose") != me ) {
        	if( (old_app = me->query_temp("marriage/accept")) == ob )
        		return notify_fail("���Ѿ���Ӧ�޸����ˣ��ߴ����Ͻ����ϯ���ָ��! \n");
        	else if( (old_app = me->query_temp("marriage/ring")) == ob )
        		return notify_fail("ϲ�ƶ����ˣ���Щȥ���ָ��! \n");
        	else if( me->is_spouse_of(ob) )
        		return notify_fail("���Ѿ��޸�����! \n");
        	else
        		return notify_fail("��ϧ" + ob->name() + "��û��������顣\n");
        }	
		
	ob->delete_temp("marriage/propose");
	
	if( me->query("age") < 16 ) {
		tell_object(ob, me->name() + "����޸��㣬����������ĵȼ��ꡣ\n");
		write("С���ӵ�ʲô��? \n");
		return 1;
	}
		
	if( me->query("gender") != "Ů��" ) {
		message_vision("$N��ƤЦ���ض�$n˵������С�๫�����һؼ�ȥ��������...��\n", me, ob);
		return 1;		
	}	
		
	if( me->query("class") == "bonze" ) {
		tell_object(ob, me->name() + "������ţ�������������İɡ�\n");
		write("�����ڷ��ţ�����֮�£�����Ҳ�գ�\n");
		return 1;
	}
	                        
	if( me->is_married() ) {
        	tell_object(ob, "��ϧ������һ����" + me->name() + "�Ѿ����������ˡ�\n");
		write("һŮ�޶���? �㲻�Ӻ���?!\n");
		return 1;
	}
		
	if( objectp(old_app) ) {
		write("��ı����ⲻ��޸�" + old_app->name() + "�ˡ�\n");
		tell_object(old_app, me->name() + "�ı����ⲻ��޸����ˡ�\n");		
		me->delete_temp("marriage/ring");
		old_app->delete_temp("marriage/banquet");
		old_app->delete_temp("marriage/ring");
	}
	                	
	message_vision("$N�ߴ��ص��ͷ, ��Ӧ�޸�$n��\n", me, ob);
	me->set_temp("marriage/accept", ob);
	ob->set_temp("marriage/banquet", me);
	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : marry|jia <����>
 
���ָ���������Ӧ�޸�ĳ�ˣ���������ȵȶԷ��� propose ָ������
��顣

��ο����ָ�� propose��love��
HELP
        );
        return 1;
}
