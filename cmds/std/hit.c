// Code of ShenZhou
// fight.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object obj, old_target;
        int time,i,l,a;
        time = ((me->query("mud_age"))-(me->query("pktime")));

        if( environment(me)->query("no_fight") )
                return notify_fail("�����ֹս����\n");

        if(!arg || !objectp(obj = present(arg, environment(me))))
                return notify_fail("���빥��˭��\n");

        if( !obj->is_character() )
                return notify_fail("�����һ�㣬�ǲ��������\n");
                
        if( obj->query_temp("surrender/ownder")!=0)
                return notify_fail("����Ͷ���������ڲ���͵Ϯ��");
           
        if( me->query_temp("surrender/ownder")!=0)
                return notify_fail("���Ͷ�������ڲ���͵Ϯ���ˣ�");
                
       if(userp(obj)&& userp(me) &&me->query("combat_exp")/3>obj->query("combat_exp") )
                return notify_fail(obj->query("name")+"�����书���̫Զ���ò���͵Ϯ��ֱ����kill�ɡ�\n");

      if(userp(obj)&& userp(me) &&me->query("combat_exp")<obj->query("combat_exp")/3 )
               return notify_fail("�����΢ĩ�书����͵Ϯ�˼ң��������ˡ�\n");
  		
	  i=obj->query("qi");
	  l=obj->query("eff_qi");
	  a=obj->query("max_qi");
		if ( userp(me) && userp(obj) && ((i*10/a)<4 || (l*10/a)<4))
                return notify_fail("�Է��Ѿ��������������ٺ����д��ˡ�\n");

	   if(((string)SECURITY_D->get_status(me)=="(immortal)" )
         && ((string)SECURITY_D->get_status(obj)!="(immortal)" ))
                return notify_fail("�㲻�ܹ�������ˣ�\n");

        if( !userp(obj) )
                return notify_fail("��ֻ��͵Ϯ��ҡ�\n");
	      if(me->query_temp("yield") )
			  return notify_fail("�����ڴ�ܲ����������͵Ϯ�أ�\n");


        if( !living(obj) || obj->query_temp("cursed") )
                return notify_fail("�����ȴ����������ܽ����д���ԡ�\n");

        if( obj->is_fighting(me) )
                return notify_fail("���ͣ����ͣ����ͣ�\n");

        if( me->query_temp("hitting") )
                return notify_fail("���ͣ����ͣ����ͣ�\n");
/*
        if( !living(obj) )
                return notify_fail(obj->name() + "�Ѿ��������㻹Ҫ�򣬹����˵�ɣ�\n"); 
*/

        if(obj==me)     return notify_fail("���Լ�������ô�벻����\n");

        if( strsrch(file_name(environment(me)), "/d/xiakedao/") >= 0 && userp(obj))
                return notify_fail("��������������ڵ��Ϲ������ˣ�\n");


        if( userp(obj) ) {
                if( (int)obj->query("mud_age") < 18000 ) 
                        return notify_fail("��С����ʲô�У�\n");
                message_vision("\n$N����$n���һ�������У�\n\n", me, obj);
                me->set_temp("hitting");
                // cyz&&kitten@xeno 99/05/08
                // addded a temp array for determine who initiated the fight
                // if some1 feels the need the reduce its size, feel free to
                // do so.
                obj->add_temp("initiate_pk", ({me->query("id")}));
                remove_call_out("do_hit");
                call_out("do_hit", 1, me, obj);
                return 1;
        }

        return notify_fail("���ָ��ֻ����������������д�һ�С�\n");
}

void do_hit(object me, object obj)
{
        if(objectp(present(obj, environment(me)))) {

                COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
  	      if(!obj->query_temp("yield") )
                COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
        }
        me->delete_temp("hitting");
        return;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : hit <����>
 
���ָ������͵Ϯһ�����������ʽ��ս��������Ҫ���öԷ���ͬ�⡣
 
�������ָ��: kill, fight

HELP
    );
    return 1;
}
