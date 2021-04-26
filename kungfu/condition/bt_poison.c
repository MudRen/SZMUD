// Code of ShenZhou
// bt_poison.c
// �������߶�����ʬ�۵�ĸ��

#include <ansi.h>

int update_condition(object me, int duration)
{
	int damage = 1;
   if( !living(me) ) {
      message("vision", me->name() + "�������ã�����Ѭ��ĳ������������ٲ�Ӭ��\n", environment(me), ({me}));
   }
   else {
      if(me->query("eff_jing") > me->query("max_jing")*2/3) {
      tell_object(me, HIR "����˿ڷ��飬ȫ��ֱ������ʹ�����ⲻ����ͨ���߶���\n" NOR );
      message("vision", me->name() + "��֫Ť�����Ų����ġ�\n",
            environment(me), ({me}));
      }
      else if(me->query("eff_jing") > me->query("max_jing")/3) {
      tell_object(me, HIR "��ȫ����ľ������־ȴ�쳣���ѣ��������������߶��ˣ�\n" NOR );
      message("vision", me->name() + "ֻϥ�����������������£����з����������޵ĺɺ�֮����\n",
            environment(me), ({me}));
      }
      else {
      tell_object(me, HIR "�㿪ʼ�е�ȫ�����������ѵ���ƫƫ�ֶ������ã�\n" NOR );
      message("vision", me->name() + "��Ȼ����ѻ�������Ц���Եù������ס�\n",
            environment(me), ({me}));
      }
   }
	if (duration > 0) damage = duration;
	else damage = 10;

      me->receive_wound("jing", damage/2, "�����������߶�������");
      me->receive_damage("jingli", damage/2, "�����������߶�������");

	if (me->query_condition("bt_poison")>(5+me->query_skill("poison",1)/10))
		me->apply_condition("bt_poison", 
		duration - 5 - me->query_skill("poison",1)/10);
	else return 0;
   //return CND_CONTINUE;
   return 1;
}
