// Code of ShenZhou

#include <ansi.h>

int update_condition(object me, int duration)
{
	int damage=1;
   if( !living(me) ) {
      message("vision", me->name() +"��ɫ��䣬������Ѫ���磬���ڵ��ϡ�\n", environment(me), ({me}));
   }
   else {
        switch( random(3) )
        {
                case 0:
			tell_object(me, HIR"��ֻ����ͷ����Ѩ΢΢һʹ������΢��ѣ�Ρ�\n" NOR);
      			message("vision", me->name() +
"��ɫһ�䣬�е�����������ӡ�\n",environment(me), ({me}));
                       break;
                case 1:
			tell_object(me, HIR"���ϱ�����Ѩ��Ȼ���������ѵ��������������ۣ�\n"NOR );
      			message("vision", me->name() +
"�������ǣ��ƺ��ٲ�ά������ӡ�\n",environment(me), ({me}));
                       break;
                case 2:
			tell_object(me, HIR"����������Ѩ�ٸ���ʹ��������Ҳ�������ˣ�\n" NOR);
      			message("vision", me->name() +
"����һ�����򣬲��һ��ˤ����\n",environment(me), ({me}));
                       break;
        }
   }
	if (duration > 0) damage = duration;
	else damage =1;
      me->receive_wound("qi", damage*2, "����ȭ���˷�������");
      me->receive_wound("jing", damage, "����ȭ���˷�������");
      me->receive_damage("jingli", damage, "����ȭ���˷�������");
	
	if (me->query_condition("qs_damage")>(5+me->query_skill("qishang-quan",1)/10))
		me->apply_condition("qs_damage", 
		duration - 5 - me->query_skill("qishang-quan",1)/10);
	else return 0;

   return 1;
}
