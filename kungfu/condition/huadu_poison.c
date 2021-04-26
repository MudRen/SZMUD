// Code of ShenZhou
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
    int i;
    object *ob;	

    if( duration == 1)
	{
    	tell_object(me, HIB "��Ȼȫ����Ѫ�������綾���ģ������Ѿ�û���ˣ�\n" NOR );
    	message("vision", me->name() +"������һ����ɫ��ɢ�����Ͽ�ʼ������Ѫ��\n", environment(me), me);
    	me->receive_wound("jing", me->query("max_jing")*4, "�綾��������");
    	me->receive_damage("qi",me->query("max_qi")*4,"�綾��������");
	}
    if( !living(me) && (duration != 1)) {
        message("vision", me->name() + "ʹ��غ���һ����\n", environment(me), me);
    }	
    else 
    {
        if( duration > 1 && random(10) > 6) 
        {
            switch(random(2)) 
            {
            /*case(0):       
                tell_object(me, HIB "�����ڶ���������������ɢ���ж����ܿ���\n" NOR );
                message("vision", me->name() + "��Ŀ��ɢ�ң���ɫ�쳣�����µ�Ц��һ�¡�\n",
                environment(me), me);
                ob = all_inventory(environment(me));
                for(i=0; i<sizeof(ob); i++) 
                {
                        if ((string)ob[i]->query("race") == "����"  && ob[i] != me )
                        {
                                message_vision(HIR "$N�����ƵĴ��һ����ʧ�����ǵĹ���������\n" NOR, me);
                                me->kill_ob(ob[i]);
                                ob[i]->fight_ob(me);
                         }       
                }
                break;
            */
            case(0):
                tell_object(me, HIB "��Ȼ�θ�һ���ʹ�������ڵĶ��������ˣ��������ζ������ĸ����ͣ�\n" NOR );
                message("vision",  me->name() +"��Ŀ��ɢ�ң���ɫ�쳣�����Ϸ���һ�������\n", environment(me), me);
                me->receive_damage("qi", 150, "�綾��������");
                me->receive_wound("jing", 100, "�綾��������");
                break;

            case(1):
                tell_object(me, HIB "��Ȼ�θ�һ���ʹ�������ڵĶ��������ˣ�\n" NOR );
                message("vision",  me->name() +"��Ŀ��ɢ�ң���ɫ�쳣�����Ϸ���һ�������\n", environment(me), me);
                me->receive_damage("qi", 50, "�綾��������");
                me->receive_wound("jing", 30, "�綾��������");
                break;
/*        case(2):
                tell_object(me, HIB "��Ȼͷ��һ���ʹ�������ڵĶ��������ˣ�\n" NOR );
                message("vision",  me->name() +"��Ŀ��ɢ�ң���ɫ�쳣���Ȼ��֪���롣\n", environment(me), me);
                command("halt",me);
                command("remove all",me);
                command("drop all",me);
                break;

        case(3):
                tell_object(me, HIB "��Ȼͷ��һ���ʹ�������ڵĶ��������ˣ�\n" NOR );
                message("vision",  me->name() +"��Ŀ��ɢ�ң���ɫ�쳣���Ȼ��֪���롣\n", environment(me), me);
                for(i=0; i<sizeof(ob); i++) 
                {
                        if ((string)ob[i]->query("race") == "����"  && ob[i] != me && userp(ob[i]))
                        {
                                command("hit" + ob[i]->query("id"),me);
                        }       
                }
                break;*/
            }
        }
 
    }
   me->apply_condition("huadu_poison", duration - 1);

   if( duration < 1 ) 
		return 0;
   return CND_CONTINUE;
}
