// Code of ShenZhou
// dealer.c

#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("������", ({ "amite", "seller", "man" }) );
	set_max_encumbrance(100000000);
	set_color("$YEL$");
	set("title", "��������");
	set("gender", "����" );
	set("age", 30);
	set("long", "һλʱ���ڰ������׻�����������ˣ��������������������Ʒ��\n�������ǻ�����õ��������֡�\n");
	set("shen_type", 1);
	set("combat_exp", 10000);
	set("no_get_from", 1);
	set("no_get", 1);
	set("str", 22);
	set("dex", 20);
	set("con", 20);
	set("int", 20);
	set("dealer", 1);
	set("attitude", "friendly");
	setup();
}

void init()
{
	::init();
	add_action("do_list", "list");
	add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
}

void unconcious()
{
	message_vision("\n�����ز̵ֻ������������Ⱥ�У��ܿ�����˳��в����ˡ�\n", this_object());
	destruct(this_object());
}

void die()
{
	message_vision("\n�����ز̵ֻ������������Ⱥ�У��ܿ�����˳��в����ˡ�\n", this_object());
	destruct(this_object());
}