// Code of ShenZhou
// persuade.c
// xuy@xkx

#include <ansi.h>

inherit F_CLEAN_UP;

string *persuade_msg = ({
        "�����˴������ˣ�ʩ�����ǰ��ֲ����˰ɣ�\n", 
        "����ˣ��л���˵����Ҫ������ᣡ\n",
        "��λ�ݵ����˺�������Ҫ�ٶ���ȥ�˰ɣ�\n",
        "�����ӷ𣬴�ҽ�����ʿ�����ؾͶ����������λ����ס�ְɣ�\n",
        "ס�ְգ������ԩ�޳𣬺α�ʧ�������еĺ�����\n",
        "������Ѷ���·, ��λ�β����ɸ�Ϊ��, ͣ�ְն�����Ϊ���أ�\n",
        "�������Ҫ�㵽Ϊֹ���αؿ���භ�����������Լ�������\n",
});
string *succeed_msg = ({
        "������Ȱ�����Ұ��֡�\n",
        "�ڴ���Ȱ�������˼ҵ������ϣ���ξ����ˡ�\n",
});

int main(object me, string who)
{
	object target;
	mapping myfam;
	int age, pp, dp, myexp, yourexp;
	mixed busy;

	object where = environment(me);

	seteuid(getuid());

	if ( !(myfam = me->query("family")) || myfam["family_name"] != "������")
		return notify_fail("����Ȱ�˰ն��������˼Ҳ�����㡣\n");
//		return notify_fail("��Ǵ�˷�����ˣ�����Ȱ�˰ն���\n");

	if ( !who ) return notify_fail("ָ���ʽ��persuade <����>\n");

	target = present(who, environment(me));
	if ( !target || target == me || !living(target) || !objectp(target) ) 
		return notify_fail("����Ȱ��˭��\n");

	if ( busy = me->query_busy() ) {
		if (intp(busy)) me->start_busy(busy+1);
		return notify_fail("��������æ�ţ�\n");
	}

	if ( target->query("race") != "����" )
		return notify_fail(target->name() + "�������˻���\n");

	if ( target->query("winner"))
		return notify_fail("ʲô��\n");

	if ( me->query_temp("persuading") )
		return notify_fail("������Ȱ�����ˣ�\n");

	if ( !target->is_fighting() ) 
		return notify_fail(target->name() + "û�ڴ�ܣ���������ģ�\n");

        if ( target->query_temp("yield") )
		return notify_fail(target->name() + "�򲻻��֣�����ȥȰȰ" + 
			gender_pronoun(target->query("gender")) + "�Ķ��ְɡ�\n");

	if ( target->query_temp("persuading") == me->query("id")) 
		return notify_fail(target->name() + "���ڿ����㣬��ͨ�˾��Լ��Ȱն���\n" + NOR);

	if ( target->query_temp("last_persuader") == me->query("id") ) {
		me->start_busy(1);
		return notify_fail("���Ȱ����" + gender_pronoun(target->query("gender"))
				+ "�������β���������Ȱ�ˡ�\n");
	}
	
	if ( (object)me->query_temp("last_persuader") == target )
	{	me->start_busy(1);
		return notify_fail("���Ȱ����" + gender_pronoun(target->query("gender"))
				+ "�������β���������Ȱ�ˡ�\n");
	}	

	if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 40 
	 || (int)me->query("jingli") * 100 / (int)me->query("max_jingli") < 40)
		return notify_fail("��̫���ˣ���Ϣһ�����Ȱ�ɡ�\n");

	me->receive_damage("jing", 15);
	me->receive_damage("jingli", 15);

	age = (int)me->query("age");
	if( age > 50 ) age = 50;
	pp = ((int)me->query_skill("persuading",1)*2+(int)me->query_skill("mahayana"))*10
	    +age*(int)me->query_per();
	if ( pp < 1 ) pp = 1;
	myexp = me->query("combat_exp");
	pp *= myexp/1000+1;

	dp = ( (int)target->query("jing") + (int)target->query("max_jing") +
	       (int)target->query("qi") + (int)target->query("max_qi") +
	       (int)target->query("jingli") ) *2/3;
	if ( dp < 1 ) dp = 1;
	yourexp = target->query("combat_exp");
	dp *= (yourexp/2 + random(yourexp))/1500+1;

        tell_object(me, HIY + "���" + EMOTE_D->normal_color(target->name())
              + "˵����" + persuade_msg[random(sizeof(persuade_msg))] + "\n" + NOR); 

        tell_object(target, HIY + me->name() + "����˵����" +
                persuade_msg[random(sizeof(persuade_msg))] + "\n" + NOR);

        message("vision", HIY + me->name() + "��" + EMOTE_D->normal_color(target->name()) 
                + "˵����" + persuade_msg[random(sizeof(persuade_msg))] + "\n" + NOR,
                where, ({ me, target }) );

	me->set_temp("persuading", target->query("id"));
	call_out("complete_persuade", 1+random(4), me, target, pp, dp);
	return 1;
} 

private void complete_persuade(object me, object target, int pp, int dp)
{
	int t_shen, myexp, yourexp, exp_factor;
	int  bonus=2;
	int expG;

	if (objectp(me)) me->delete_temp("persuading");
	else return;
	if (!objectp(target)) return;

	if (environment(target) != environment(me)) {
		tell_object(me, "���գ�" + target->name() + "�Ѿ����ˡ�\n"); 
		return;
	}

	if ( !living(target) ) {
		tell_object(me, target->name() + "�Ѳ�����ȡ���Ȱ���ˣ�\n");
		me->delete_temp("defensing");
		return;
	}

	if (!target->is_fighting()) {
		tell_object(me, "���գ�" + target->name() + "�Ѿ����а����ˡ�\n");
		me->delete_temp("defensing");
		return;
	}

	t_shen =  - (int)target->query("shen");
	while ( t_shen > 10 ) {
		bonus += 1;
		t_shen = t_shen/32;
	}
	
	dp *= bonus;
	if (target->is_fighting(me) && !me->query_temp("defensing") ) {
		dp *= 1 + bonus;
		bonus = bonus/2;
	}
	if (target->is_killing(me->query("id"))
	    && !me->query_temp("defensing") ) dp *= 2;
	if (me->is_killing(target->query("id"))) dp *= 2;

if (wizardp(me) && (string)me->query("env/combat")=="verbose" )
	 tell_object(me, sprintf("pp = %d, dp = %d\n", pp, dp));

//  lower the exp get from persuading the same npc you are fighting.
if (me == target->select_opponent())
    exp_factor = 3;
else
    exp_factor = 1;

	if ( random(pp+dp) > dp ) {

		tell_object(target, HIG + "���ܵ�" + me->name()
		  		  + "�ĸ��У��������ֲ�����\n" + NOR);
		tell_object(me, HIG + EMOTE_D->normal_color(target->name()) 
			      + "�ܵ���𷨸��У��������ֲ�����\n" + NOR);
                message("vision", CYN"ֻ��" + EMOTE_D->normal_color(target->name()) 
                        + "����һ�ݣ�˵�����ã�" + me->name() 
			+ succeed_msg[random(sizeof(succeed_msg))] + NOR, 
                        environment(target), ( {me, target} ) );

		target->remove_all_killer();
		target->start_busy(3);
		if (target->query("shen") < 0) 
			target->add("shen",-(int)target->query("shen")/20);
		me->remove_killer(target);
		me->start_busy(1);
		me->delete_temp("defensing");
		target->set_temp("last_persuader", me->query("id"));
		me->set_temp("last_persuader",target);
		call_out("delete_last_persuader", 6+random(30), me, target);

// give exp and skills points
		myexp = me->query("combat_exp");
		yourexp = target->query("combat_exp");
		bonus += (yourexp/500)/(myexp/1000+1);
		if ( pp < 3*dp/2+random(dp*8) 
		  || myexp < yourexp 
		  || (int)random(yourexp) > 150000) {
			me->improve_skill("persuading", me->query_int()+(bonus-1)*random(me->query_int()));
			me->improve_skill("mahayana", random(me->query_int())/5);
                	if ( yourexp + random(myexp) > myexp )
       		        {
       	        	   if ( me->query_skill("persuading", 1) < 144 )
       	        	   {
       	        	        expG = (me->query_skill("persuading",1)/12+2)*(1+bonus)/exp_factor;
                                if ( me->query( "combat_exp" ) > 6400000 ) expG = expG/3; 
					        me->add("combat_exp", expG );
					        log_file("job/emei",me->query("name") +" (" + me->query("id") + ") Ȱ�ܻ�� " + 
                                expG + " �㾭��  "+ ctime(time())+"\n");

					   }
					   else
					   {
					        expG = 12*(1+bonus)/exp_factor;
                                                if ( me->query( "combat_exp" ) > 6400000 ) expG = expG/3; 
				            me->add("combat_exp", expG );
					        log_file("job/emei",me->query("name") +" (" + me->query("id") + ") Ȱ�ܻ�� " + 
                                expG + " �㾭��  "+ ctime(time())+"\n");

				       }
				        
				target->add("combat_exp", 1);
				if (target->query("potential") < target->query("max_potential"))
					target->add("potential", 1);
			}
		}
	}
	else if ( !target->is_fighting(me) || me->query_temp("defensing") ) {
		if ( random(pp) < dp/3 ) {
			tell_object(me, RED + EMOTE_D->normal_color(target->name()) + "������һ������"
				       + RANK_D->query_rude(me) 
				       + "������£����У���\n" + NOR);
			tell_object(target, CYN + "���" + me->name() + "���һ������"
				          + RANK_D->query_rude(me)
				          + "������£����У���\n" + NOR);
			message("vision", CYN + "ֻ��" + EMOTE_D->normal_color(target->name()) + "����"
					+ me->name() + "���һ������"
					+ RANK_D->query_rude(me)
                                        + "������£����У���\n" + NOR, environment(target),
					( {me, target} ) );
			if ( (int)target->query("shen") < 0 )
				target->kill_ob(me);
			else
				target->fight_ob(me);
			me->start_busy(1);
			COMBAT_D->do_attack(target, me, target->query_temp("weapon"));
                        me->add("combat_exp", 1);
			me->set_temp("defensing", 1);
		}
		else {
			tell_object(me, HIR + EMOTE_D->normal_color(target->name())
			 + "�������ͷ��س����µ����������Ĵ���ȥ���ٹ����£�\n"+ NOR);
			tell_object(target, HIR "�����" + EMOTE_D->normal_color(me->name())
			 + "��м��ƲƲ�죺�������Ĵ���ȥ���ٹ����£�\n" + NOR);
			message("vision", HIR + "ֻ��" + EMOTE_D->normal_color(target->name()) + "����" 
					+ EMOTE_D->normal_color(me->name())
				+ "��м��ƲƲ�죺�������Ĵ���ȥ���ٹ����£�\n" + NOR,
				environment(target), ( {me, target} ) );
			if (!target->is_fighting(me) ) me->delete_temp("defensing");
			me->start_busy(1+random(3));
		}
	}
	else if ( target->is_killing(me->query("id")) 
		|| me->is_killing(target->query("id")) ) {
		message_vision(CYN"$N��$n��Ҳ����\n"NOR, target, me);
		target->kill_ob(me);
		me->start_busy(2);
	} else if ( target->is_fighting(me) ) {
		tell_object(target, RED"���ݺݵض�" + me->name() + "�ȵ���"
			+ RANK_D->query_rude(me) + "�������д������㻹������ϹȰ���������ɣ�\n"NOR);
		tell_object(me, RED + target->name() + "��ݺݵض���ȵ���"
			+ RANK_D->query_rude(me) + "�������д������㻹������ϹȰ���������ɣ�\n"NOR);
		message("vision", RED + target->name() + "��ݺݵض�"
			+ me->name() + "�ȵ���" + RANK_D->query_rude(me)
			+ "�������д������㻹������ϹȰ���������ɣ�\n"NOR,
			environment(target), ( {me, target} ) );
		target->kill_ob(me);
                me->add("combat_exp", 1);
		me->start_busy(1+random(5));
	}
}

private void delete_last_persuader(object me, object target)
{
	if (!target || !me) return;
	if (me->query("id") == (string)target->query_temp("last_persuader") )
		target->delete_temp("last_persuader");
	if ((object)me->query_temp("last_persuader") == target )
		me->delete_temp("last_persuader");
}

int help(object me)
{
write(@HELP
ָ���ʽ : persuade <ĳ��>

���ҵ��ӿ��Ը����Ȱ�����ƣ��ն���������������������ʱҲ���ǻ�����
HELP
    );
    return 1;
}

