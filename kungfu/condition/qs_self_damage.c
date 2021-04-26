// Code of ShenZhou
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	object *ob;
	int i;
	string msg;

   	if( !living(me) ) {
      		message("vision", me->name() + "ʹ���������һ����\n", environment(me), me);
   	}
   	else {
      		tell_object(me,HIR"��ֻ��������һ���������У����з�����Ż��\n" NOR );
		message_vision(HIW"$N�۾������������â�����������\n"NOR,me);
   	}

      	me->receive_wound("qi", 10, "��������ȭ�߻���ħ����");
      	
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( ob[i]->query("race") != "����" 
		|| ob[i]==me || !me->visible(ob[i]) ) 
			continue;
	        tell_object(me, "\n"+ob[i]->name()+"������ȵ�����"
                + RANK_D->query_rude(me)+"�����ղ������������һ��\n\n");
	        tell_object(me, HIR "�����Ҫ��" + ob[i]->name()
                        + "�����ಫ������Ҳ���������һ�� kill ָ�\n"NOR);
		if (me->query_temp("yield")) me->set_temp("yield", 0);
		me->kill_ob(ob[i]);
	}

	me->apply_condition("qs_self_damage", duration - 1);
	
   	if( duration < 1 ) return 0;
   	return CND_CONTINUE;
}
