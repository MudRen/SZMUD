// Code of ShenZhou
// /d/emei/obj/coffin.c ʯ��

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW"�����"NOR, ({ "coffin", "guan cai", "guan" }) );
	set_weight(3000);
	set_max_encumbrance(50000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ������������ɵ�ʯ�ף���Ө��࣬ʵ�ǿ�����Ѱ�����\n");
		set("value", 1000);
//		set("material", "stone");
		set("no_get",1);
//		set("no_drop",1);
		set("arrow_count", 3);
	}
	set("opened", 0);
	setup();
}

void init()
{
	add_action("do_open", "open");
	add_action("do_put", "put");
}

int is_container() { return query("opened"); };

int do_open(string arg)
{
	object me = this_player();
	object ob = this_object();
	object rwj, book1, book2;

	if ( !arg && ( arg != "coffin" ) && ( arg != "guan" ) )
		return notify_fail("ʲô��\n");

	me->set_temp("th_tomb_thief",1);
	
	if ( query("opened") )
		return notify_fail("����ʯ�׸��Ѿ��ǿ����ˡ�\n");

	message_vision("$N��������˫������ȥ�����ʯ�׸ǡ�\n", me);
	if (query("arrow_count") > 0) {
		remove_call_out("shoot_arrow");
		call_out("shoot_arrow", 1, me);	
		return 1;
	}

	me->add("jingli", -(20+random(20)));
	me->add("qi", -(20+random(20)));

	if ( (int)me->query_str() < 22 ) {
		return notify_fail("��û��ô�������ᶯ�׸ǡ�\n");
	}

	message_vision("$N�����Ὺ����ʯ�׸ǡ�\n", me);
	me->add("tomb_thief", 1);
	ob->set("opened", 1);
      	ob->set("long", "����һ������������ɵ�ʯ�ף���Ө��࣬ʵ�ǿ�����Ѱ�������������һ�ߺ��ǡ�\n");
	rwj = new(__DIR__"ruanwei-jia");
	if (rwj) rwj->move(ob); 
	book1 = new(__DIR__"hetu");
	book2 = new(__DIR__"luoshu");
	if (book1) book1->move(ob);
	if (book2) book2->move(ob);

	return 1;
}

int shoot_arrow(object me)
{
	if ((int)query("arrow_count") < 1 ) return 0;

	switch ((int)query("arrow_count")) {
	case 3:
		message_vision(HIY"��Ȼ�伸֧�̼��ӹ׺�һ���������������ֱ����$N�����ţ�\n"NOR, me);
		break;
	case 2:
		message_vision(HIY"��Ȼ�伸֧�̼��ӹ׺�һ���������������ֱ����$N���ʺ�\n"NOR, me);
		break;
	case 1:
		message_vision(HIY"��Ȼ�伸֧�̼��ӹ׺�һ���������������ֱ����$N��ǰ�أ�\n"NOR, me);
		break;
	default:
		message_vision(HIY"��Ȼ�伸֧�̼��ӹ׺�һ���������������ֱ����$N�����ţ�\n"NOR, me);
		break;
	}
	add("arrow_count", -1);

	if ( (int)me->query_dex() > (30+random(10))) {
		message_vision("$Nͷһ�ͣ��ܿ��̼�������һ�ԡ�\n", me);
		return 1;
	}

	else if ( (int)me->query_dex() > (25+random(10))) {
		message_vision("$N������ܿ���ȴ������һ֧�̼������Ҽ磬������ȥ��\n", me);
		me->add("qi", -50);
		me->unconcious();
		return 1;
	}

	else {
		message_vision("$N��ܲ��������̼�������ã����ڵ��ϡ�\n", me);
		me->receive_damage("qi", 50, "������������");
		me->die();
		return 1;
	}
	return 0;
}

int do_put()
{
	write("ʲô��\n");
	return 1;
}
