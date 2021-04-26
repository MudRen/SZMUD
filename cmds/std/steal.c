// Code of ShenZhou
// steal.c
// 04/16/97: xbc modified this file.  The exp and pot rewards depends on
// relative exp of me and victim, but same for both gb and non-gb dizi.  
//changed by wzfeng 99 12 3
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string what, who;
	object ob, victim;
	mapping myfam, vtfam;
	int sp, dp;

	if( environment(me)->query("no_fight") )
		return notify_fail("�����ֹ���ԡ�\n");

	if( me->query_temp("stealing") )
		return notify_fail("���Ѿ����һ��������ˣ�\n");

	if( me->is_busy() )
		return notify_fail("����æ���أ�\n");

	if( !arg || sscanf(arg, "%s from %s", what, who)!=2 ) return
		notify_fail("ָ���ʽ��steal <��Ʒ> from <����>\n");

	if( what == "all" ) return notify_fail("���ż�������һ��һ�����ɡ�\n");
	victim = present(who, environment(me));
	if( !victim || victim==me) return notify_fail("�������ԵĶ��������\n");
	if( !victim->is_character() ) return notify_fail("͵"+victim->name()+"��������ë������\n");
	if( !wizardp(me) && wizardp(victim) )
		return notify_fail("��Ҳ���͵��ʦ���ϵĶ�����\n");
		//////////////////////////////////////////////add by wzfeng
	if(victim->query("id")=="tang nan" 
	|| victim->query("id")=="lao chaofeng"
	|| victim->query("id")=="he hongyao"
	|| victim->query("id")=="wang tiejiang"
	|| victim->query("id")=="feng tiejiang"
	|| victim->query("dealer"))
		return notify_fail("͵��������������͵�����Ǻ�ע��Ү��\n");
/////////////////////////////////////////////////////////////


	ob = present(what, victim);

	if( !ob ) {
		object *inv;
		inv = all_inventory(victim);
		if( !sizeof(inv) || (sizeof(inv)==1 && inv[0]->query("no_steal")) )
			return notify_fail( victim->name() + "���Ͽ�����û��ʲ��ֵǮ�Ķ�����͵��\n");
		ob = inv[random(sizeof(inv))];
	}

	if( ob->query("no_steal") || ob->query("no_get")) 
	return notify_fail("�ⶫ������͵��\n");

	sp = (int)me->query("jing")/10 + (int)me->query("kar") + (int)me->query_dex();
	sp *= (int)me->query_skill("stealing", 1)/10;

	if ( (myfam = me->query("family")) && myfam["family_name"] == "ؤ��" )
	sp *= 2;

	if( sp < 1 ) sp = 1;

	if( me->is_fighting() ) {
		sp /= 2;
		me->start_busy(3);
	}
	dp = (int)victim->query("jing") + (int)ob->weight()/25 + victim->query("combat_exp")/700;
	if( victim->is_fighting() ) dp *= 10;
	if( ob->query("equipped") ) dp *= 10;

	write("�㲻����ɫ����������" + victim->name() + "���ȴ��������� ...\n\n");

	me->set_temp("stealing", 1);
	me->start_busy(3);
	call_out( "compelete_steal", 3, me, victim, ob, sp, dp);

	return 1;
}

private void compelete_steal(object me, object victim, object ob, int sp, int dp)
{
	mapping myfam, vtfam;

	me->delete_temp("stealing");

	if( !me || !victim || !ob) return;

	if( environment(victim) != environment(me) ) {
		tell_object(me, "̫��ϧ�ˣ������ֵ�Ŀ���Ѿ����ˡ�\n");
		return;
	}

	if( !living(victim) || (random(sp+dp) > dp) ) {
		if( !ob->move(me) ) {
			tell_object(me, "������һ" + ob->query("unit") + ob->name() 
				+ "�����Ƕ������̫���ˣ����ò�������\n");
			return;
		}
		if ( ob->query("money_id") ) victim->save();
		tell_object(me, HIW "�����ˣ�\n\n" NOR);
		tell_object(me, "��ɹ���͵��һ" + ob->query("unit") + ob->name() + "��\n");

		if( living(victim) ) {
			if (me->query("combat_exp") <= (int)victim->query("combat_exp")*3/2) {
				me->add("potential",random(2));
				me->add("combat_exp",random(2));
				me->improve_skill("stealing", random(me->query("int")));
			if (me->query("potential") > me->query("max_potential"))
			me->set("potential", me->query("max_potential"));
			}
		}

		if( random(sp) > dp/2 )
			message("vision", "�㿴��" + me->name() + "�������ش�"
				+ victim->name() + "����͵����һ" + ob->query("unit")
				+ ob->name() + "��\n", environment(me), ({ me, victim }) );
	} else {
		if( random(sp) > dp/3 ) {
			tell_object(me, victim->name() + "�������һתͷ���㼱æ�������˻�ȥ��\n"
				"���ã�û�б����֡�\n");
			return;
		}
		tell_object(me, HIR "��⣡��ʧ���ˣ�\n\n" NOR);
//	      message_vision("$Nһ��ͷ�����÷���$n������ץ��$P���ϵ�" + ob->name() + "��\n\n"
//		      + "$N�ȵ�������ʲô����\n\n", victim, me);

		if ( victim->query("race") == "����" ) 
			message_vision("$Nһ��ͷ�����÷���$n������ץ��$P���ϣ��ȵ�������ʲô����\n\n", victim, me);
		else
			message_vision("$Nһ��ͷ�����÷���$n������ץ��$P���ϣ��Ե�ʮ�ַ�ŭ��\n\n", victim, me);

		me->improve_skill("stealing", 1, 1);
		if( userp(victim) ) victim->fight_ob(me);
		else victim->kill_ob(me);
		me->fight_ob(victim);
		me->start_busy(2);
		me->add("thief", 1);
	}
}

int help(object me)
{
write(@HELP
ָ���ʽ : steal <ĳ��> from <ĳ��>

���ָ�������л���͵���������ϵĶ������ɹ���, ��Ȼ����ܻ��
������Ʒ������, ����ʧ��, ������ʧ���ʱ��, ����ʧ��ʱ��Ȼ��
�ø�������, �����ʲô����......�����Լ�ȥ�����ޡ�
HELP
    );
    return 1;
}
