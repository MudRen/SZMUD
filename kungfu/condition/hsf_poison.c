// Code of ShenZhou
// hsf_poison.c
// ��ʬ��  a very powerful one, and do nto write medicine for it please.

#include <ansi.h>

int update_condition(object me, int duration)
{
	int damage = 10;
   if( !living(me) ) {
      message("vision", me->name() + "�������ã�����Ѭ��ĳ������������ٲ�Ӭ��\n", environment(me), ({me}));
   }
   else {
      if(me->query("eff_jing") > me->query("max_jing")*2/3) {
      tell_object(me, HIR "����˿ڻ������ط�ʹ����ʼ�������˿ڱ���Ϳ�˻�ʬ���ˣ�\n" NOR );
      message("vision", me->name() + "��֫Ť�����˿�������ɫ��ŧҺ��\n",
            environment(me), ({me}));
      }
      else if(me->query("eff_jing") > me->query("max_jing")/3) {
      tell_object(me, HIR "��ȫ����ʹ����Ƭ��Ƥ�⿪ʼ���䣬�����˻�ʬ�۶��ˣ�\n" NOR );
      message("vision", me->name() + "ȫ��鴤����ɫ��ŧҺ����һ�����������ĳ�����\n",
            environment(me), ({me}));
      }
      else {
      tell_object(me, HIR "�㿪ʼ�е�ȫ��ļ����Ѿ����ڹǼ��ϣ��Ѿ����������ˣ�\n" NOR );
      message("vision", me->name() + "ͻȻˤ���ڵأ��������ã��������������\n",
            environment(me), ({me}));
      }
   }
	if (duration > 0) damage = duration;
	else damage = 10;

      me->receive_wound("qi", damage*2, "����ʬ�ۻ�����");
      me->receive_wound("jing", damage, "����ʬ�ۻ�����");
      me->receive_damage("jingli", damage, "����ʬ�ۻ�����");
	if (me->query_condition("hsf_poison")>(5+me->query_skill("poison",1)/10))
		me->apply_condition("hsf_poison", 
		duration - 5 - me->query_skill("poison",1)/10);
	else return 0;
   //return CND_CONTINUE;
   return 1;
}
