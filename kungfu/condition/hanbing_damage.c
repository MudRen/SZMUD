// Code of ShenZhou

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int ml;
	ml = me->query("max_neili")/1000;
   if( !living(me) ) {
      message("vision", me->name() + "ʹ��غ���һ����\n", environment(me), me);
   }
   else {
	if(me->query("eff_jing") > me->query("max_jing")/4)
	tell_object(me, HIB"�����һ��������ֱ͸�Ŀڣ�ȫ����ʱ��ս�����ݻ�����������졣\n"NOR );
	else tell_object(me, HIB"������ؿڷ�����Ż������Ǳ��������ͼ��ס���ӣ�����������ת������ˤ����\n" NOR );
      
      message("vision", me->name() + "ͻȻ���˸���ս����ɫ��ף����罩ʬ��\n",
            environment(me), me);
   }
      me->receive_damage("qi", (duration/2)+20, "�򺮱��������������������");
      me->receive_wound("jing", (duration/2)+20, "�򺮱��������������������");

      me->apply_condition("hanbing_damage", duration - 1);
                me->apply_condition("hanbing_damage", duration - 1); 

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
