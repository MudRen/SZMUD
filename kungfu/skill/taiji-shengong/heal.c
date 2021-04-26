// Code of ShenZhou
// heal.c ̫����
// Modified by xQin 11/98

#include <ansi.h>

int exert(object me, object target)
{
	string name, *sname;
	object deadman, *list;
	mapping skill_status, learned_status;
	int i, j, tao_level, tjsg_level, new_exp, neili_drop, sneili_drop, skill_amount;

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹����ˣ�\n");

/*
 * the following code is making ���쾢����Ծ�� for �׻�������
 * still under construction. xQin.
 */
	if( !target || target == me ) return 0;
	
	if (target->id("corpse")) 
	{
	if (!wizardp(me))
		return notify_fail("���޷����������������������\n");

        if ((tao_level = me->query_skill("taoism", 1)) < 120 )
                return notify_fail("��ĵ�ѧ�ķ���Ϊ��������\n");
                        
        if ((tjsg_level = me->query_skill("taiji-shengong", 1)) < 120 )
                return notify_fail("���̫������Ϊ��������\n");
                        
        if ( target->id("corpse") && !target->is_character() ) 
                return notify_fail("��Ҫ�ȵ����Ѿ���̫���ˣ�\n");
                
        neili_drop = 150 - tjsg_level/2; 
        sneili_drop = 300 - tjsg_level;
        if (neili_drop <= 20) neili_drop = 20;

        name = target->query("victim_name"); 
                
        list = users();
        for ( i = 0; i < sizeof(list); i++)
        if ( name == list[i]->name(1) ) break;
        
        if (i == sizeof(list)) 
                return notify_fail(name+"�Ĺ�겻�ڡ�\n");
                        
        deadman = list[i];      
        if ( !deadman->is_ghost() )
                return notify_fail(name+"���������������αض��һ�٣�\n");
                        
        message_vision(
                HIW "$N˫��ʳָ��Ĵָ���ã��ɡ����쾢���ƣ�\n"
                "��ʳָָ�����"+name+"���������ִ��ġ���Ծ�ϡ�������������΢΢�ڶ�����\n\n"NOR, me);

        if ( me->query("neili") < 1000 || random(tao_level+tjsg_level) < 24 )     
        {
                me->set("neili", 0);
                me->add("max_neili", -10); 
                        
                message_vision( HIY"$NͻȻͣ����������Ȼ�����ܵ��������ˣ�\n"NOR, me);
                return notify_fail( HIY"��ϧ���������ã��޷������ȥ�ˣ�\n"NOR );
        } 
                
        me->add("neili", -1000); 
        me->add("max_neili", - neili_drop ); 
        me->receive_damage("qi", 3*neili_drop, "����������ȶ����ˡ�"); 
        me->receive_wound("qi", 2*neili_drop, "����������ȶ����ˡ�"); 

        message_vision( HIY"ֱ�ڵ���ʮ�£�$N˫����ɽ������������£�����˫ȡ"+ name +"���ճ�Ѩ����\n"
		"$N���ֵ���������������ϣ��������֣�һ��һ���������任��\n"
		+ "������ʮ����ʱ��" + name +"����ſ��˿ڣ���������ҩ������С�"NOR, me);

        tell_object(deadman, HIY "һ��������������㣬ʹ���㼸��������ȥ��\n" NOR);

        message("vision",  
		HIY"һ���������������"+name+"��ʧ�ˣ�\n"NOR, environment(deadman), deadman );

	deadman->reincarnate();
	learned_status = deadman->query_learned();

	if ( mapp(skill_status = deadman->query_skills()) )
	{
		sname = keys(skill_status);
		for(i=0; i<sizeof(skill_status); i++) {
			skill_amount = (skill_status[sname[i]]+1) * (skill_status[sname[i]]+1) / 2;

			if( !mapp(learned_status) ) learned_status = ([ sname[i] : skill_amount ]);
			else {
				if( learned_status[sname[i]]  < skill_amount )
					learned_status[sname[i]] += skill_amount;
				else {
					learned_status[sname[i]] -= skill_amount;                                                                    - (skill_status[sname[i]]) * (skill_status[sname[i]]);
					deadman->set_skill(sname[i], skill_status[sname[i]]+1);
				}
			}
		}
	}


	new_exp = (int)deadman->query("combat_exp") / 99;
	new_exp = new_exp > 5000 ? 5000 : new_exp;
	deadman->add("combat_exp", new_exp);
	deadman->set("qi",1); 
	deadman->set("eff_qi",1); 
	deadman->set("jing",1); 
	deadman->set("eff_jing",1); 
	deadman->set("jingli",1); 

	deadman->move(environment(me));
	destruct(target);
	deadman->unconcious();

        return 1;       
        } else

	if ((!target) || (target == me))
	{

	if ((int)me->query_skill("taiji-shengong", 1) < 20)
		return notify_fail("���̫������Ϊ��������\n");

	if( (int)me->query("neili") < 50 )
		return notify_fail("�������������\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

	write( HIW "����ϥ���µ�Ϣ��ֻ��������ů���ء������õأ�������������̼�������֫�ٺ���\n" NOR);
	message("vision",
		HIW"ֻ��" + me->name() + "��Ŀ���£�Ƭ��֮�䣬ͷ������˿˿�������͵����һ�ţ��³�������Ѫ��\n" NOR,
		environment(me), me);

	me->receive_curing("qi", 10 + (int)me->query_skill("force")/5 );
	me->add("neili", -50);
	me->set("jiali", 0);

	return 1;
        }
        
	if ((int)me->query_skill("taiji-shengong", 1) < 50)
		return notify_fail("���̫������Ϊ��������\n");

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("���������Ϊ������\n");

	if( (int)me->query("neili") < 150 )
		return notify_fail("�������������\n");

        if( !living(target) )
                return notify_fail("������Ȼ�������޴Ӿ���\n");

	if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
		return notify_fail( target->name() +
			"�Ѿ����˹��أ����ܲ�����������𵴣�\n");

	message_vision(
		HIC "$N������һ��������������һ��ů���ӵ��������ϣ�����˫�ۣ���ס$n�ġ���̨Ѩ����\n"
		HIW "����һ�ᣬ$Pͷ�������뵰��������ǳ�����ȫ��������������\n"
		HIC "�����á�������һ����һ�ƺ�Ѫ��$p�˿��м����������Ѫ����ת�졣\n" NOR,
		me, target );

	target->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );
	target->add("qi", 10 + (int)me->query_skill("force")/3 );
	if( (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));

	me->add("neili", -150);
	me->set("jiali", 0);

	return 1;

}
