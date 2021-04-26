// Code of ShenZhou
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{int i;
object *ob;	

   if( duration == 1)
	{
	tell_object(me, HIB "��Ȼȫ����Ѫ���������е������������ˣ������Ѿ�û���ˣ�\n" NOR );
	message("vision", me->name() +"������һ����ɫ��ɢ�����Ͽ�ʼ������Ѫ��\n", environment(me), me);
	me->receive_wound("jing", me->query("max_jing")*4, "��������������");
	me->receive_damage("qi",me->query("max_qi")*4,"��������������");
	}
   if( !living(me) && (duration != 1)) {
      message("vision", me->name() + "ʹ��غ���һ����\n", environment(me), me);
   }	
else {
   if( (duration <= 10) && (duration >1) && (random(10) >= 6)) 
{
        switch(random(6)) {
        case(0):       
                tell_object(me, HIB "��Ȼͷ��Ŀ�������е���������ʼ�����ˣ�\n" NOR );
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
        case(1):
                tell_object(me, HIB "��Ȼͷ��һ���ʹ�����е���������ʼ�����ˣ�\n" NOR );
                message("vision",  me->name() +"��Ŀ��ɢ�ң���ɫ�쳣������һ�������Լ���\n", environment(me), me);
                me->receive_damage("qi", 50, "��������������");
                me->receive_wound("jing", 30, "��������������");
                break;
        case(2):
                tell_object(me, HIB "��Ȼͷ��һ���ʹ�����е���������ʼ�����ˣ�\n" NOR );
                message("vision",  me->name() +"��Ŀ��ɢ�ң���ɫ�쳣���Ȼ��֪���롣\n", environment(me), me);
                command("halt");
                command("remove all");
                command("drop all");
                break;
        case(3):
                tell_object(me, HIB "��Ȼͷ��һ���ʹ�����е���������ʼ�����ˣ�\n" NOR );
                message("vision",  me->name() +"��Ŀ��ɢ�ң���ɫ�쳣���Ȼ��֪���롣\n", environment(me), me);
                command("halt");
                command("dazuo" + me->query("qi"));
                break;
        case(4):
                tell_object(me, HIB "��Ȼͷ��һ���ʹ�����е���������ʼ�����ˣ�\n" NOR );
                message("vision",  me->name() +"��Ŀ��ɢ�ң���ɫ�쳣���Ȼ��֪���롣\n", environment(me), me);
                command("halt");
                command("tuna" + me->query("jing"));
                break;
        case(5):
                tell_object(me, HIB "��Ȼͷ��һ���ʹ�����е���������ʼ�����ˣ�\n" NOR );
                message("vision",  me->name() +"��Ŀ��ɢ�ң���ɫ�쳣���Ȼ��֪���롣\n", environment(me), me);
                ob = all_inventory(environment(me));
                for(i=0; i<sizeof(ob); i++) 
                {
                        if ((string)ob[i]->query("race") == "����"  && ob[i] != me && userp(ob[i]))
                        {
                                command("propose" + ob[i]->query("id"));
                        }       
                }
                break;
        case(6):
                tell_object(me, HIB "��Ȼͷ��һ���ʹ�����е���������ʼ�����ˣ�\n" NOR );
                message("vision",  me->name() +"��Ŀ��ɢ�ң���ɫ�쳣���Ȼ��֪���롣\n", environment(me), me);
                for(i=0; i<sizeof(ob); i++) 
                {
                        if ((string)ob[i]->query("race") == "����"  && ob[i] != me && userp(ob[i]))
                        {
                                command("hit" + ob[i]->query("id"));
                        }       
                }
                break;
                }
}
 
}
   me->apply_condition("zf_poison", duration - 1);

   if( duration < 1 ) 
{	me->delete("zf");
	me->delete("zf_lv");
	return 0;
}
   return CND_CONTINUE;
}
