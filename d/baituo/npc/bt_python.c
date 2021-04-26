// Code of ShenZhou
// baituo python ����ɽ�߹ȵĴ��ߡ�����
// by maco 
#include <ansi.h>

inherit NPC;

int auto_perform_duwu();
int auto_perform_chan();

void create()
{
	int s, poison;

	s = random(40);
	poison = random(3);

	switch( poison )
	{
	case 0:
		set_name("����", ({ "ju mang", "she", "mang", "python" }) );
		set("long", "һ����ڴ�ϸ������ͷ�����������ɶ೤��\n");
		set("chat_msg_combat", ({
			(: auto_perform_chan :),
		}));
		break;
	case 1:
		set_name("����", ({ "da she", "she", "snake", "dashe" }) );
		set("long", "һ�������ɣ������˱۵Ĵ��ߣ�ȫ������ɫ��һ��ͷ�������Σ����˵�ȭͷ����\n"
		"Ѱ�������޶���������˾޴�ȴ�Ƕ��ߣ�ʵ�ں�����\n");
		set("snake_poison", 340 +random(61));
		set("chat_msg_combat", ({
			(: auto_perform_duwu :),
		}));
		break;
	case 2:
		set_name("����", ({ "du mang", "she", "mang", "snake", "python"}) );
		set("long", "һ��������µĴ����ߣ���ͷ�������Σ�ͷ���ϸ߸�����һ��\n"
		"����͹͹�������������ɣ������ֱۡ�\n"
		"���߱����޶�����������ȴ���������״���־߾綾��ʵ��ϣ����\n");
		set("snake_poison", 380 +random(61));
		set("chat_msg_combat", ({
			(: auto_perform_chan :),
			(: auto_perform_duwu :),
		}));
		break;
	}
	set("race", "����");
	set("age", 100);
	set("attitude", "peaceful");

	set("str", 30 + poison );
	set("con", 40 + poison );
	set("int", 10);
	set("dex", 30 + poison );
	
	set("max_jing", 4000);
	set("max_qi", 4000);
	set("max_jingli", 2000);

	set("combat_exp", poison*100000 + 500000);
	set("chat_chance_combat", 30);

	set_temp("apply/attack", 300 + s);
	set_temp("apply/damage", 200 + s);
	set_temp("apply/armor", 400 + s);
	set_temp("apply/parry", 300 + s);
	set_temp("apply/dodge", 260 + s);
	set("bt_snake", 1);

	setup();
}

void init()
{
	object me;
	::init();
	me = this_object();
	add_action("convert","bian");
	add_action("do_struggle","struggle");
	add_action("do_struggle","zhengza");

	if (!me->is_fighting() && living(me) && !me->is_busy()
	&& !environment(me)->query("no_fight") ) {
		remove_call_out("hunting");
		call_out("hunting", 1, me, this_player());
	}
}

void hunting(object me, object ob)
{
	if(random(4) != 0 && !me->is_fighting() && living(me) && !me->is_busy() 
	&& !environment(me)->query("no_fight")) 
		set_temp("hunting", ob->query("id"));

	if (present(ob, environment(me))) {
		if (!ob->is_character() && ob->query("my_killer") != me->query("id")) {
			message_vision("$N��$n�Ա����˼�Ȧ��˻��һ���ţ����������ο����ƺ�������Ȥ��\n", me, ob);
			return;
		}
		else if( query_temp("hunting") && !me->is_fighting() && living(me) 
		&& !me->is_busy() && !environment(me)->query("no_fight") ){

			if(random(2) == 0) {
			message("vision", HIR"���Ȼ�ŵ�һ���ȷ磬�ͼ�"+me->name()+"�ſ���ڣ�¶�����������"+ob->name()+"ҧȥ��\n"NOR, environment(ob), ob);
			tell_object(ob,HIR"����к���˻˻���죬һ���ɼ䣬����ȳ�ӭ�棬"+me->name()+"��Ȼ�����ſ�������\n"NOR);
			COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
			kill_ob(ob);
			delete_temp("hunting");
			}
			else {
			remove_call_out("hunting");
			call_out("hunting", 2, me, ob); 
			}
			return;
		}

		else message_vision("$N����$n��������Ϣ����ʱ�������ţ�������ͷ�����Ѫ�����ͷ��˻˻������\n", me, ob);
	}
	return;
}


void chaning(object me, object ob)
{
	int ap, dp, pp, jingli, damage;

	string *chan_msg = ({
		HIR"\n$n���˾������뽫�������ϵ�$N���ϡ���$N���ӿ��������ֻ�Լ����죬������ϡ�\n"NOR,
		HIR"\n$N����������ֻ����$n���Ǽ����۶ϡ�\n"NOR,
		HIR"\n$N����һ��$n��Խ��Խ������Ҳ���ţ�$n������$N���ô�����������\n"NOR,
		HIR"\n$n��$N��ס����������ŭ����޷�������Ϊ��\n"NOR,
	});
	string *chan_beast_msg = ({
		HIR"\n$N��������������$n�л������ѡ�\n"NOR,
		HIR"\n$N����һ��$n��Խ��Խ������Ҳ���ţ�$n������$N���ô�����������\n"NOR,
		HIR"\n$n��$N��ס������ʧ�˿���֮������ϢԽ��Խ��΢����\n"NOR,
	});

	string *chan_snake_msg = ({
		HIR"\n$N�������������ι�ס$n���ߴ硣\n"NOR,
		HIR"\n$N����һ��$n��Խ��Խ������Ҳ���ţ�$n������$N���ô�����������\n"NOR,
		HIR"\n$N��$n������ס������ʩ����$n��Ȼ����Ť������ȴҲ�޷�������\n"NOR,
	});
	string *chan_bird_msg = ({
		HIR"\n$N����������ֻ����$n˫�Ἰ���۶ϡ�\n"NOR,
		HIR"\n$n��$N��ס��֨֨�ҽУ����ͣ�˴�\n"NOR,
		HIR"\n$N����������$në�����ţ������࿹���ۼ���֧��\n"NOR,
	});

	string chan;
	switch (ob->query("race")) {
	case "����" :	chan = chan_msg[random(sizeof(chan_msg))];	break;
	case "����" :	chan = chan_bird_msg[random(sizeof(chan_bird_msg))];	break;
	case "����" :	chan = chan_snake_msg[random(sizeof(chan_snake_msg))];	break;
	case "Ұ��" :
	case "����" :	chan = chan_beast_msg[random(sizeof(chan_beast_msg))];	break;
	default:	return 0;
	}
	
	
	jingli = me->query("jingli");
	ap = jingli + random(jingli);
	pp = ob->query("jiali") + ob->query_str()*random(10) + (int)ob->query_skill("force");
	damage = (ap - pp)/3;
	
	if(damage > 1000 ) damage = 1000;
	if(damage < 100 ) damage = 100;
	
	if(wizardp(ob)) 
	tell_object(ob,sprintf("ap��%d ,pp��%d ,damage��%d \n" ,ap,pp,damage));

	if(!ob) {
		me->delete_temp("chaning");
		return;
	}
	if (present(ob, environment(me))) {
	
		if( !me->query_temp("chaning") || !ob->query_temp("snake_chan") ) {
		me->delete_temp("chaning");
		ob->delete_temp("snake_chan");
		return;
	}

		if (!living(ob) ) {  //������˾�ҧ��
			if(ob->query("race") == "����") 
				message_vision(HIR"��ʱ$n�Ѹ�$N��������һϢ��$N�ſ���ڣ�ҧס��$n���Ƚ������߿ڣ������ĸ��������䣬�������ؿڡ�\n"NOR, me, ob);
			else message_vision(HIR"��ʱ$n�Ѹ�$N��������һϢ��$N�ſ���ڣ�һ�ڱ㽫$nҧ����\n"NOR, me, ob);
			ob->receive_wound("qi", (ob->query("qi")+100), "��"+me->name()+"ҧ����");
			ob->receive_damage("qi", (ob->query("qi")+100), "��"+me->name()+"ҧ����");
			ob->delete_temp("snake_chan");
			me->delete_temp("chaning");

			return;
		}

		else if (!ob->is_character() ) {  //�������˾ͷſ�
			message_vision("$N�ɿ����ӣ��ſ���$n�������������ߡ�\n", me, ob);
			ob->delete_temp("snake_chan");
			me->delete_temp("chaning");
			return;
		}
		else {

			if(ap < random(pp) || jingli < 500 ) {
			message_vision("$N�ƺ��в���$n�ľ����������ɿ����ӣ��ſ���$n�������������ߡ�\n", me, ob);
			ob->delete_temp("snake_chan");
			me->delete_temp("chaning");
			}
			else {
			message_vision(chan , me, ob);
			ob->start_busy(3);
			me->start_busy(2);
			me->add("jingli", -(pp/20));

			ob->add("jingli", -damage/4);
			ob->receive_wound("qi", random(damage/10), "��"+me->name()+"������");
			ob->receive_damage("qi", damage/2, "��"+me->name()+"������");

			remove_call_out("chaning");
			call_out("chaning", 1, me, ob); 
			}
			return;
		}
	}

	return;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( me->query("snake_poison") > 0 && !victim->query("snake_poison")) 
	victim->apply_condition("snake_poison", 20 + me->query("snake_poison")/5 +
		victim->query_condition("snake_poison") );

	if(me->query_temp("try_chan")) {
	me->set_temp("chaning", victim->query("id"));
	victim->set_temp("snake_chan",1);
	victim->start_busy(3);
	me->start_busy(2);
	remove_call_out("chaning");
	call_out("chaning", 1, me, victim); 
	
	if(victim->query("race") == "����") return HIR"$nһ�����������ѱ�$N��ס��$N�漴��$n�����������ѣ����ֱ�Ҳ�������У���$p��Ҳû�����ܡ�\n"NOR;
	else return HIR"��һ��$nû�ж㿪��$N������$p�������˼��ѣ�$n��ʱ�������á�\n"NOR;
	}

}

int convert(string arg)
{
	object me = this_player();
	object ob;

	if (arg!="snake" && arg!="she") return 0;
	if (me->query("family/family_name") != "����ɽ") 
		return notify_fail("�㲻�ܻ���Ϊ�ȡ�\n");

	return notify_fail(this_object()->name()+"����̫���ִ��޷���Ϊ���ȡ�\n");
}

int do_struggle(string arg)
{
	object me, snake;
	int ap, jingli, jiali;

	me = this_player();
	snake = this_object();

	if( snake->query_temp("chaning") != me->query("id"))
		return 0;
	if( !me->query_temp("snake_chan") || !me->is_busy() )
		return 0;

	jingli = snake->query("jingli");
	jiali = me->query("jiali");
	ap = jingli + random(jingli);

	if(me->query_temp("struggle_snake") > 4) {
		message_vision(HIW"\n$N��������һ��������Ѳ�ס���ӵ�$n.....\n"NOR, me, snake);
		message_vision(HIR"\n����$N���Ӷ���̫��������ŭ�˲�ס��$P��$n��һ�ڱ�ҧס$P���ʺ�\n"NOR, me, snake);
		me->receive_wound("qi", random(ap/2), "��"+me->name()+"ҧ����");
		me->receive_damage("qi", ap/2, "��"+me->name()+"ҧ����");
		me->unconcious();
	}
	else {
		message_vision(HIW"\n$N��������һ��������Ѳ�ס���ӵ�$n.....\n"NOR, me, snake);
		me->add("neili", -jiali);
		snake->add("jingli", -jiali*2 );
		me->add_temp("struggle_snake", 1);
		remove_call_out("remove_effect");
		call_out("remove_effect", 1, me);
	}

	return 1;
}

void remove_effect(object me)
{
	me->delete_temp("struggle_snake");
}

#include "snake_perform.h"
