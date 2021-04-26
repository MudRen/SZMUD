// Code of ShenZhou
// fanchang.c ��
// Summer 9/29/96.

#include <ansi.h>

//inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_SSERVER;


int exert(object me, object target)
{
	object obj, weapon;
	int xf, af, sp, ap;  
	if( !target ) target = offensive_target(me);
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("id") != "lubo")
                return notify_fail("��δִ���������������󳪡�\n");
	if ((!objectp(obj = present("kulou guan", me)) ) ||
               (!obj->query("equipped") )) 
		return notify_fail("��δ�����ùڣ����������󳪡�\n");
	if ((!objectp(obj = present("rentou lian", me)) ) ||
               (!obj->query("equipped") ))
                return notify_fail("��δ����ͷ�������������󳪡�\n");

	if( !objectp(target) || target == me)
		return notify_fail("����Ҫ����˭����\n");

	if( !target->is_character() || target->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

	if( target->query("race") != "����")
		return notify_fail(target->query("name") + "������������\n");
	if( (int)me->query("neili") < 300 )
		return notify_fail("�������������\n");

	if( (int)me->query_skill("necromancy",1) < 30 )
                return notify_fail("��Ľ���������������\n");

	if( (int)me->query_skill("lamaism", 1) < 30 )
                return notify_fail("��������ķ�����������\n");

	if( (int)me->query_skill("longxiang-banruo", 1) < 30 )
		return notify_fail("����������������������\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("�����ﲻ�ܳ���\n");
	
	if( target->query_temp("cursed", 1) || target->query_temp("block_msg/all", 1))
		return notify_fail("�����ѱ�������\n");

	if( (int)me->query_temp("curser") )
                return notify_fail("�㽵������һ���ˣ�\n");

	me->add("neili", - 150 + me->query_skill("necromancy"));
	me->receive_damage("jingli",  100 - me->query_skill("necromancy"));

	message_vision(
		BLU "$Nҡͷ���ԣ����б��д�˷𾭣����������������䡣���������ٴ죬�����з����������ɡ�\n" NOR, me);

			tell_object(target,  "�����������ȹ�޻��������Դ���һ�����ң���ǰһ�ѹ�Ӱ��������������������֫��������Ȼ��˯��\n");
		
	xf = (me->query_skill("necromancy", 1) + me->query_skill("lamaism", 1));
	ap = target->query("jing") + target->query_skill("force") + 
	target->query("con")  + target->query("int") ; 
	sp = me->query_skill("force") + xf * 2;
	sp *= me->query("combat_exp")/1000;
        ap *= target->query("combat_exp")/1000;
	if( random(sp) > ap/2 && !target->query("no_sing")){
	tell_object(target, HIR "��ֻ������ǰ��һ����������Զȥ����Ļ�����Ҫ���ϣ������������ס�\n" NOR);
	message_vision("�㿴��" +target->query("name") +"ͻȻ��ʼ���۷�ֱ������������ǰ����\n", me);
	target->remove_all_killer();
	target->set_temp("cursed", 1);
	target->set_temp("block_msg/all", 1);
	me->set_temp("curser", 1);
	if((int)target->query("combat_exp") > me->query("combat_exp")/2
	&& userp(target)){
		me->improve_skill("necromancy", me->query("int"));
		me->add("combat_exp", 1);
	}

	call_out("del_sung", me->query_skill("necromancy", 1)/2, me, target);
	return 1;
	}
	else{
	me->start_busy(random(7));
	if( !target->is_killing(me) ) target->kill_ob(me);	
	return 1;
	}
}
void del_sung(object me, object target)
{
	object link_ob;

        if ( me->query_temp("curser") )
        me->delete_temp("curser");
	if (!target) return;
	if (target->query_temp("cursed", 1))
	target->set_temp("cursed", 0);
	if (target->query_temp("block_msg/all", 1))
	target->set_temp("block_msg/all", 0);
	if (target->query_leader() ) 
        target->set_leader(0);	
	message_vision("$N���������ѹ����������ֻص����Լ������ϡ�\n", target);

/*	link_ob = target->query_temp("link_ob");

        if( link_ob ) {
                if( link_ob->is_character() ) {
                        message_vision("$N�Ļ��ǻص�" + link_ob->name(1) + "�����ϡ�\n", me, target);
                        exec(link_ob, target);
                        target->delete_temp("link_ob");
			link_ob->setup();
                        return;
                }

                link_ob->set("last_on", time());
                link_ob->set("last_from", query_ip_name(me));
                link_ob->save();
                destruct(link_ob);
        }
*/
}

