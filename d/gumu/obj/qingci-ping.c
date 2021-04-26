// qingci-ping.c ���ƿ������װ�����
// by april 01.08.27

#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(CYN"���ƿ"NOR, ({"qingci ping", "ping", "bottle" }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�����Сƿ����Ĺ������װ����ۡ�\n");
		set("unit", "��");
		set("max_liquid", 10);
	}

	set("liquid", ([
		"type": "mi",
		"name": "�����",
		"remaining": 0,
		"drunk_apply": 1,
	]));

}

void init()
{
	add_action("do_drink", "he");
	add_action("do_drink", "drink");
	add_action("do_fill", "fill");
	add_action("do_fill", "zhuang");
}

/*
int do_drink(string arg)
{
	object me = this_player();
	object ob = this_object();

	if (arg!="qingci ping" && arg!="ping" && arg!="bottle") return 0;

	if (me->is_busy())
		return notify_fail("����һ��������û����ɡ�\n");

	if ((int)me->query("water")
		>= (int)me->max_water_capacity() )
		return notify_fail("���Ѿ��ȵ�̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");

	if( !ob->query("liquid/remaining") )
		return notify_fail("���ƿ��ʲôҲû���ˡ�\n");

	me->add("jing", 30);

	if( me->is_fighting() ) me->start_busy(2);

	ob->add("liquid/remaining", -1 );
	me->add("water",5);

	if (ob->query("liquid/remaining")) {
		message_vision("$N����С��ƿ������һС������ۣ���ʱ��������ô���ˡ�\n",me);
	}
	else {
		message_vision("$N����С��ƿ���������һ������ۣ���ʱ��������ô���ˡ�\n",me);
	}

	return 1;
}
*/

int do_drink(string arg)
{
	object pl = this_player();

	if( !id(arg) ) return 0;
	if( !living(pl) ) return 0;
	if( pl->is_busy() )
		return notify_fail("����һ��������û����ɡ�\n");
	if( !query("liquid/remaining") )
		return notify_fail( name() + (query("liquid/name") ? "�Ѿ����ȵ�һ��Ҳ��ʣ�ˡ�\n":"�ǿյġ�\n"));
	if( (int)pl->query("water") >= (int)pl->max_water_capacity() )
		return notify_fail("���Ѿ���̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");

	add("liquid/remaining", -1);
	message_vision("$N����" + name() + "����һС��" + query("liquid/name") + "��\n",pl);
	pl->add("water", 5);
	pl->add("jingli", 5);

	if( query("liquid/name") == "�����" ) {
		pl->add("jing",30);
		if ((int)pl->query_condition("yufeng_poison")) {
		    pl->apply_condition("yufeng_poison", (int)pl->query_condition("yufeng_poison") - 5);
			tell_object(pl, HIW "��䶾������������һЩ��\n" NOR );
		}
	}
	if( query("liquid/name") == "�����ˮ" ) {
		pl->add("jingli",25);
		if ((int)pl->query_condition("yufeng_poison")) {
		    pl->apply_condition("yufeng_poison", (int)pl->query_condition("yufeng_poison") - 2);
			tell_object(pl, HIW "��䶾������ֻ������һ��㣡\n" NOR );
		}
	}
	
//	if( pl->query("jingli") > pl->query("max_jingli")) 
//	this_player()->set("jingli", this_player()->query("max_jingli"));

	if( pl->is_fighting() ) pl->start_busy(2);
	if( !query("liquid/remaining") ) {
		write("���Ѿ���" + name() + "���" + query("liquid/name")
			+ "�ȵ�һ��Ҳ��ʣ�ˡ�\n");
		if ( query("worthless") )  set("value", 0);
	}

	// This allows customization of drinking effect.
	if( query("liquid/drink_func") ) return 1;

	switch(query("liquid/type")) {
		case "alcohol":
			this_player()->apply_condition("drunk",
				(int)this_player()->query_condition("drunk") 
				+ (int)query("liquid/drunk_apply"));
			break;
	}
	
	return 1;
}

int do_fill(string arg)
{
	object pl = this_player();

	if( !id(arg) ) return 0;
	if( pl->is_busy() )
		return notify_fail("����һ��������û����ɡ�\n");
	if( !environment(pl)->query("resource/water") )
		return notify_fail("����û�еط�����װˮ��\n");

	if ( query("liquid/remaining")==query("max_liquid") 
		&& query("liquid/name")=="�����" ){
		
		message_vision("$N��ˮ����ע��" + name() + "�����ҡ�ȡ�\n", pl);
		set("liquid/type", "mi-water");
		set("liquid/name", "�����ˮ");
		set("liquid/remaining", query("max_liquid"));
		set("liquid/drink_func", 0);
	}
	else {
		if( query("liquid/remaining") ) 
			message_vision("$N��" + name() + "��ʣ�µ�" + query("liquid/name") + "������\n", pl);
		message_vision("$N��" + name() + "װ����ˮ��\n", pl);

		set("liquid/type", "water");
		set("liquid/name", "��ˮ");
		set("liquid/remaining", query("max_liquid"));
		set("liquid/drink_func", 0);
	}

	if( pl->is_fighting() ) pl->start_busy(2);

	return 1;
}
