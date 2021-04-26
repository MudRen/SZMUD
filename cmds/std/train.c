//Cracked by Roath
// train.c

#include <ansi.h>

inherit F_CLEAN_UP;

string *training_msg = ({
	"ȫ���ע��������",
	"������ֵ�ʳָ��Сָָ��",
	"һ������ߴߴ��������Щ��ֵ����ڣ�һ�������߽�",
	"����һ���������µ����ӣ�������ɫ�ؿ���"
});

int main(object me, string arg)
{
	string what, who;
	object victim, lord;
	int sp, dp, cost;


	if( me->query_temp("training") )
		return notify_fail("������������ͼѱ������\n");

	if( !arg) return notify_fail("ָ���ʽ��train <����>\n");

	victim = present(arg, environment(me));
	if( !victim || victim==me) return notify_fail("����ѱ���Ķ��������\n");

	if(!living(victim)) return notify_fail("����������˵�ɡ�\n");

	if( !(victim->is_trainee()))
		return notify_fail("��ѱ�������������ˣ�\n");

	if( objectp(lord = victim->query_lord()) 
	&& environment(lord) == environment(me) && lord != me)
		return notify_fail("������������ô�ɣ�����̫�ðɣ�\n");
	if (me == lord)
		return notify_fail("���Ѿ������������ˡ�\n");

	if( environment(me)->query("short") == YEL"���"NOR)
                return notify_fail("�ڱ��˼���ѱ�ޣ��ⲻ̫�ðɡ�\n");

	if (victim->query_temp("prelord") == me->query("id")) {
		write("��������ʶ��һ�������˹�����\n");
		victim->train_it(me, victim,101);
		return 1;
	}	

	cost = me->query("max_jingli")/(2*(int)me->query_skill("training",1)/10 + 1) - 10;
	cost = 200/((int)me->query_skill("training",1)/5 + 1);

	if ( me->query("jingli") <= cost )
                return notify_fail("������̫���ˣ�С�ķ����亦��\n");

	me->add("jingli", - cost );
	if( me->query("jingli") <= 0 ) me->unconcious();

	sp = (int)me->query_skill("training", 1) + (int)me->query("kar")/4;

	if( sp < 1 ) sp = 1;

	if( me->is_fighting() ) {
		sp /= 2;
		me->start_busy(3);
	}
	dp = (int)victim->query("wildness");

	message_vision("$N" + training_msg[random(sizeof(training_msg))] +
		"$n��\n", me, victim);

	me->set_temp("training", 1);
	call_out( "compelete_train", 1, me, victim, sp, dp);

	return 1;
}

private void compelete_train(object me, object victim, int sp, int dp)
{
	int pts;
	string msg_fail, msg_succ;

	if( !me || !victim ) return;

	me->delete_temp("training");
	if(!(msg_fail = victim->query("msg_fail")))
		msg_fail = "$n����$Nһ�ۣ�ת������$N";
	if(!(msg_succ = victim->query("msg_succ")))
		msg_succ = "$n������˰벽���ƺ���Щ��$N";

	if( environment(victim) != environment(me) ) {
		tell_object(me, "̫��ϧ�ˣ�����ѱ����Ŀ���Ѿ����ˡ�\n");
		return;
	}

	pts = random(sp+dp);
	//tell_object(me, chinese_number(sp) + "��" + chinese_number(dp) +
		//"��" + chinese_number(pts) + "\n");
	if( living(victim) && (pts > 2*dp) ) {
		//victim->train_it(me, victim);
		if( living(victim) ) {
			message_vision(msg_succ + "��\n", me, victim);
			me->improve_skill("training", random(me->query("int")));
			if (me->query("family/family_name")=="����ɽ" ||
			    me->query("family/family_name")=="ؤ��")
                        if (me->query("combat_exp") < 100000000 )
			{
                                me->add("combat_exp",2);
                                me->add("potential",1);
				if (me->query("potential") > me->query("max_potential"))
					me->set("potential", me->query("max_potential"));
			}
		}
		victim->train_it(me, victim, pts);

	} else {
		if( pts > dp/2 ) 
		{
			message_vision(msg_fail + "��\n", me, victim);
			return;
		}
		//message_vision("$n��ɱ��$N��\n", me, victim);
		me->improve_skill("training", 1, 1);
		victim->kill_ob(me);
		me->fight_ob(victim);
		me->start_busy(3);
	}
}

int help(object me)
{
write(@HELP
ָ���ʽ : train <����>

��ָ�������ѱ��ĳ��������Ѿ�ѱ���Ķ�����Խ�������ָ�

����ָ�
	gen(come) <������>: 	�ö�����������ж�;
	ting(stay): 			ֹͣ����ĸ���״̬;
	yao(attack <ĳ��>): 	�ö��﹥������;
	zhi(stop) <������>:		�ö���ֹͣ���˵Ĺ���;
	fang(release): 			������ū״̬����������롣

����ָ���ֻ��ĳЩ�������ã�
	qi(ride) <������>:		���������������ȡ�
	xia(unride) <������>:	�£��뿪���
	wei(feed) <������>:		�涯��ιʳ��
	yin <������>:			��������ˮ��

HELP
    );
    return 1;
}
