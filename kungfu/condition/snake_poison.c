// Code of ShenZhou
// snake_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
   if( !living(me) ) {
      message("vision", me->name() + "ʹ��غ���һ����\n", environment(me), me);
   }
   else {
      if(me->query("eff_jing") > me->query("max_jing")/2) {
      tell_object(me, HIB "����һ�����ĵ���ʹ���㿪ʼ�е���֫���飬�߶������ˣ�\n" NOR );
      message("vision", me->name() + "ͻȻ�沿�鴤����֫ɪɪ�ض���������\n",
            environment(me), me);
      }
      else if(me->query("eff_jing") > me->query("max_jing")/4) {
      tell_object(me, HIB "��е��������ѣ���ľ�ĸо�˳����֫�����У��߶������ˣ�\n" NOR );
      message("vision", me->name() + "ͻȻ���۷�ֱ��ȫ��鴤������\n",
            environment(me), me);
      }
      else {
      tell_object(me, HIB "�㿪ʼ�е�������ת�����ܾ��ﶼ����������Զȥ���߶������ˣ�\n" NOR );
      message("vision", me->name() + "ͻȻˤ���ڵأ��Ŵ���ͣ��ֽ������س鶯�š�\n",
            environment(me), me);
      }
   }
      if(me->query("poisoner")){
      me->receive_damage("qi", duration/2, me->query("poisoner"));
      me->receive_wound("jing", duration/3, me->query("poisoner"));
      }
      else {	
      me->receive_damage("qi", duration/2, "�߶���������");
      me->receive_wound("jing", duration/3, "�߶���������");
      }
	if (me->query_condition("snake_poison")>(5+me->query_skill("poison",1)/10))
		me->apply_condition("snake_poison", 
		duration - 5 - me->query_skill("poison",1)/10);
	else return 0;
   //return CND_CONTINUE;
   return 1;
}
