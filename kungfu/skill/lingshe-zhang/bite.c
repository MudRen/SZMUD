// Code of ShenZhou
// bite (����ҧ��)

#include <ansi.h>
#define SNAKE_STAFF this_player()->query_temp("weapon")

inherit F_SSERVER;
inherit F_DBASE;

//void remove_bite(object);

int perform(object me, object target)
{
	string type, snake_path;
	object weapon, snake;
	int t, lv, poison, poi_amount, train_lv, snake_lv;
	
	t = (int)me->query_temp("baituo/bite");
	lv = (int)me->query_skill("lingshe-zhang", 1);
	poison = (int)me->query_skill("poison", 1);
	train_lv = (int)me->query_skill("training", 1);

	poi_amount = lv + poison;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��ֻ������͵Ϯս���еĶ��֡�\n");
		
	if (lv < 200 )
		return notify_fail("��������ȷ�������죬�޷���ʹ�ȹ���֮���������ˡ�\n");

	if (poison < 200 )
		return notify_fail("���ʹ���ķ�����֪���ޡ�\n");

	if (!objectp(weapon = me->query_temp("weapon")))
		 return notify_fail("������û�����ߵı�����\n");

	type = weapon->query("snake_type");

	if ( !type && weapon->query("id") != "shezhang")
		return notify_fail("���"+weapon->name()+"�ϲ�û���ߡ�\n");

	if( t && (time() - t) < 10 )
		return notify_fail("��ո��Ѿ��������ˣ������͹ʼ���ʩ������������Ч��\n");

	if( me->query_skill("training",1) < 100 )
	       return notify_fail("���Ԧ�����޷�˳����ʹ�������ˡ�\n");

	if( me->query("neili") < poi_amount)
		return notify_fail("�����������������������Ϯ��ʱ�ȿ�"+weapon->name()+"��\n");

	if( me->query("jingli") < 300)
		return notify_fail("��ľ�������������������Ϯ��ʱ�ȿ�"+weapon->name()+"��\n");

	if( me->query_skill_mapped("force") != "hamagong")
		return notify_fail("�����õ��ڹ��롸�����ȷ�����·��㣣�\n");

	me->add("neili", -(poi_amount/2 +50));
	me->add("jingli", -200);

	switch (type) {
	case "����" :
        snake_path = "/d/baituo/npc/guaishe";
	break;
	case "����" :
        snake_path = "/d/baituo/npc/lingshe";
	break;
	default:
        snake_path = "/d/baituo/npc/snake";
	type = "����";
	}
	
	seteuid(getuid());

	snake = new(snake_path);

	snake_lv = (train_lv + lv)*2/3;

	snake->set("bite_busy",1);
	snake->set("env/invisibility", 10);
	snake->set("owner",me);
	snake->move(environment(me));
	snake->set("default_actions", (: call_other, __FILE__, "query_action" :));
	snake->set("combat_exp",me->query("combat_exp"));

	snake->add_temp("apply/speed", 2);
	snake->add_temp("apply/attack", snake_lv);
	snake->add_temp("apply/damage", snake_lv/4 );
	snake->set("neili",me->query("neili"));
	snake->set("jingli",me->query("max_jingli")*2);
	snake->set("mex_jingli",me->query("mex_jingli"));
	snake->set("snake_poison", poi_amount*3 );
	snake->kill_ob(target);

	message_vision(HIB"\n$N��"+weapon->name()+HIB"һ�������Ͻ𻷵���һ�����죬һ��"+type+HIB"���ȵ�ֱ��������\n"NOR,me);

	me->start_busy(1);

	COMBAT_D->do_attack(snake, target, snake->query_temp("weapon"));

	if(weapon->query("snake") == 2) {
	snake->set("second_attack",1);
	COMBAT_D->do_attack(snake, target, snake->query_temp("weapon"));
	}

	destruct(snake);

	target->kill_ob(me);
	me->set_temp("baituo/bite",time());

	call_out("remove_bite", 10, me, type);

	return 1;
}

void remove_bite(object me, string type)
{
	me->delete_temp("baituo/bite");
	tell_object(me, type+"������ͷ��˻��һ����ͷ��\n");
}

mapping query_action(object me)
{
	string msg1, msg2;
	msg1 = HIR"���"+SNAKE_STAFF->name()+HIR"��$n��ǰ�ӹ�������������һ��$N������������Ȼ�ſ�ҧ��$n$l����������֮����"NOR;
	msg2 = HIW BLK"һ��$N�Ÿմܳ����䲻��"+SNAKE_STAFF->name()+HIW BLK"����һ��$NҲ����û��Ϣ�ذ��׶���һ����$n$lҧȥ��"NOR;
	return ([
	"action": me->query("second_attack") ? msg2 : msg1,
	"force" : 400,
	"dodge" : 0,
	"parry" : 0,
	"damage" : 400,
	"weapon" :"����",
	"damage_type":"ҧ��"]);
}
