//Bula 3.18
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object who,obj;


        if( !arg ) {
		if(me->query_temp("protecting") ) {
			if( objectp(obj=find_living(me->query_temp("protecting")) )){
				tell_object(me, "���������ڱ���"+obj->query("name")+"��\n");
				return 1;
			}
		}
		tell_object(me,"��Ҫ����ʲô�ˣ�\n");
		return 1;
	}
	
	if( arg=="me" || arg == me->query("id") )  
                return notify_fail("��Ҫ����ʲô�ˣ�\n");

        if( arg=="none") {
		if( !me->query_temp("protecting") ){
			tell_object(me, "�㲢û�б����κ��ˡ�\n");
			return 1;
		}
                if( objectp(obj=find_living(me->query_temp("protecting")) )) {
                        tell_object(obj, me->query("name")+"�����������ˡ�\n");
			tell_object(me, "���������"+obj->query("name")+"��\n");
			me->delete_temp("protecting");
			return 1;
		}
		tell_object(me, "������������ˡ�\n");                
		me->delete_temp("protecting");                
		return 1;
        }     

	if( !objectp(who=present(arg, environment(me))))
		return notify_fail("��Ҫ����ʲô�ˣ�\n");

	if( !living(who) )
		return notify_fail("�㲻�ܱ���"+who->query("name")+"��\n");

	if( me->query_temp("protecting") == who->query("id") )
		return notify_fail("���Ѿ��ڱ���������ˡ�\n");

	if((int)me->query_condition("no_pk_time") > 480 )
		return notify_fail("�����ɱ��̫�ࡣ����\n");

        if( who->query("combat_exp") - me->query("combat_exp") > me->query("combat_exp") / 20 )
                return notify_fail("�����΢ĩ�Ĺ���Ҫ����"+who->query("name")+"�������Բ�������\n");

	if( me->query("combat_exp") - who->query("combat_exp") < who->query("combat_exp") / 20 )
                return notify_fail("���"+who->query("name")+"�������������Ա��ɣ�\n");
		
	if( me->query_temp("protecting") ) {
                if( objectp(obj=find_living(me->query_temp("protecting")) )) {
                        tell_object(obj, me->query("name")+"�����������ˡ�\n");
			tell_object(me, "���������"+obj->query("name")+"��\n");
		}
        }

	message_vision(HIC"$N��ʼ����$n��\n"NOR, me, who);

	who->set_temp("protected", 1);
	who->set_temp("protect_ob", me->query("id"));
        me->set_leader(who);
	me->set_temp("protecting", who->query("id"));
	return 1;

}

int help(object me)
{
   write( @HELP
ָ���ʽ: baohu [<����>|<NPC>|none]

��ʼ��������������ĳ�ˡ�
����ʼ��������Զ����汻�����ˡ�
HELP
   );
   return 1;
}
