// Code of ShenZhou
//��а����֮����
//wzfeng@xkx 99 9
// snowyu fix yun reverse then pxj guimei dodge 

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "pixie_superskill.c"

void checking(object me);

int perform(object me, object target)
{
object weapon;
        
        int level;

        if( !target ) target = offensive_target(me);

        if(me->query("canuse_guimei")!=1)
			    return notify_fail("ʲô��\n");

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("�����ȡ�ֻ����ս����ʹ�á�\n");


		if( (int)me->query_temp("pixie/guimei") )
                return notify_fail("�������˹���!\n");
            if( (int)me->query_temp("reverse") )
                return notify_fail("���������о�����ת,�޷�ʹ�á����ȡ�!\n");
        if( me->query("jingli") <=1000  )
                return notify_fail("��ľ�������������ʹ�á����ȡ���\n");
        if( me->query("neili") <=200  )
                return notify_fail("�����������������ʹ�á����ȡ���\n");

weapon = me->query_temp("weapon");
if( !objectp(weapon) || weapon->query("skill_type") != "sword" ) 
return notify_fail("������Ρ����ȡ�����\n"); 


        if( (level = (int)me->query_skill("pixie-jian", 1)) < 120 )
                return notify_fail("��ı�а����������죬���ܲ��ܽ����������С�\n");

        if( (string)me->query_skill_mapped("dodge") != "pixie-jian" )
                return notify_fail("��û�н���а�����������ϣ��޷�ʹ�������ȡ���\n");
        if( (string)me->query_skill_mapped("parry") != "pixie-jian" )
                return notify_fail("��û�н���а���������м��ϣ��޷�ʹ�������ȡ���\n");                

        message_vision(HIB"\n$N�ٺٺ�һ���Ц����Ӱ�������Ȼ�ӿ죬Ʈ���������������ȣ�\n"NOR, me);
		
        me->add("neili", -50);
        me->set_temp("pixie/guimei",level/5);

		remove_call_out("checking");
		call_out("checking", 1, me);
		
        return 1;
}

void checking(object me)
{

	if(me->query_skill_mapped("sword") != "pixie-jian"
		||me->query_skill_mapped("dodge") != "pixie-jian"
			||me->query_skill_mapped("parry") != "pixie-jian"
			||!objectp(me->query_temp("weapon")))
	{
		tell_object(me,"��ʹ�����������书�����Ƚ���ʧȥ��Ч��\n");
        message_vision(HIB"\n$N�������˿ڣ�����������������\n"NOR, me);
        me->delete_temp("pixie/guimei");
		   me->delete_temp("pixie_noop");
		   me->delete_temp("pixie_use");
		   me->delete_temp("pixie_superskill");
		   me->delete_temp("pixie_performtime");

       return ;

	}

       if( !living(me) || me->is_ghost() )
        {
                me->delete_temp("pixie/guimei");
			   me->delete_temp("pixie_noop");
		   me->delete_temp("pixie_use");
		   me->delete_temp("pixie_superskill");
		   me->delete_temp("pixie_performtime");

                return ;
        }
		if( !me->is_fighting() )
        {
		        message_vision(HIB"\n$N�������˿ڣ���ס�ǹ��ȹ�а�����Σ�\n"NOR, me);
                me->delete_temp("pixie/guimei");
						   me->delete_temp("pixie_noop");
		   me->delete_temp("pixie_use");
		   me->delete_temp("pixie_superskill");
		   me->delete_temp("pixie_performtime");

                return ;
        }
		if( me->query_temp("pixie/guimei") <= 0 )
        {
		        message_vision(HIB"\n$N�������˿ڣ�����������������\n"NOR, me);
               me->delete_temp("pixie/guimei");
			   		   me->delete_temp("pixie_noop");
		   me->delete_temp("pixie_use");
		   me->delete_temp("pixie_superskill");
		   me->delete_temp("pixie_performtime");

                return ;
        }
		me->add_temp("pixie/guimei",-1);
		call_out("checking", 1, me);
		return;
}


