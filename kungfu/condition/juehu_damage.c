// Code of ShenZhou
// juehu_damage.c
// xQin 8/99

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( !living(me) )
		message("vision", me->name() + "ʹ���������һ����\n", environment(me), me);
	else
	{
		if( duration > 400 )
		{
			tell_object(me, HIR "��ֻ����������ʹ���̡�\n" NOR );
			message("vision", CYN + me->name() + "˫����סС�����¡�\n"NOR,
				environment(me), me);
		}
		else if( duration > 200 )
		{
			tell_object(me, HIR "��ֻ����������ʹ����������\n" NOR );
			message("vision", CYN + me->name() + "�ͺ���һ�����ƺ��ܵ���ʲ��ʹ����\n"NOR,
				environment(me), me);
		}
		else
		{
			tell_object(me, HIR "��ֻ����������ʹ��Ȼ����������\n" NOR );
			message("vision", CYN + me->name() + "üͷ΢΢һ�壬�ƺ��о���ʲ�ᡣ\n"NOR,
				environment(me), me);
		}

	}


	if( !me->query_temp("wudang/juehu_damage") )
	{
		me->add_temp("apply/attack", -duration);
		me->add_temp("apply/defense", -duration);
		me->set_temp("wudang/juehu_damage", 1);
	}

	me->apply_condition("juehu_damage", duration - 1);
	me->add_temp("apply/attack", 1);
	me->add_temp("apply/defense", 1);

	if( duration < 1 )
	{
		tell_object(me, "����������ʹ���ƺ������ˡ�\n");
                me->delete_temp("wudang/juehu_damage");
		if( me->query("ori_gender") == "����" )
		{
			me->delete("ori_gender");
			me->set("gender", "����");
			tell_object(me, HIY "�����»ָ������˵����ţ�\n" NOR );
		}
		return 0;
	}

	return CND_CONTINUE;
}