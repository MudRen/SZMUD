// Code of ShenZhou
//BY haowen May 10th 1999

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{   if( duration == 1)
        {

tell_object(me,HIR"��ͻȻȫ��Ӳ�������쳣���ѣ�ԭ���ڲ�֪���������˱��˵Ķ��֣�\n"NOR);
	me->set_temp("last_damage_from", "������Цɢ����");
	me->delete("env/immortal");
	me->die();
	
        }
   
   else {
	message("vision",me->name()+"ͻȻ��������һЦ��\n",environment(me),({me}) );
	}
   me->apply_condition("sxs_poison", duration - 1);

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
