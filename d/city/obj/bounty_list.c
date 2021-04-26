// Code of ShenZhou
#include <ansi.h>;

inherit ITEM;
inherit F_SSERVER;

string wanted();
int do_arrest(string);

void create()
{
	set_name(RED"��������"NOR, ({ "haibu wenshu", "wenshu", }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set("material", "paper");
	}
	set("long", wanted());
	setup();
}

void init()
{
	add_action("do_arrest","arrest");
}

string wanted()
{
	int i;
	string msg;
	object *ob = users();

	msg = "";
	for (i = 0; i < sizeof(ob); i++)
		if ((int)ob[i]->query("PKS")>19 
		&& ob[i]->query("combat_exp")/ob[i]->query("PKS") < 10000
		&& environment(ob[i])->query("short") != "����") {
		msg += HIY"���"NOR+ob[i]->query("title") + " ";
		if (ob[i]->query("nickname"))
			msg += "��" + ob[i]->query("nickname") + "��" ;
		msg += ob[i]->name() + HIY"���\n"NOR;
		msg += (HIR"�÷�����"+chinese_number(ob[i]->query("PKS"))+"׮������\n"NOR);
		if (ob[i]->query("long"))
			msg += ("�÷���ò�������£�\n" + ob[i]->query("long"));
		else msg += ("�÷���ò���ꡣ\n");
		msg += ("��������������������������������������������\n");
	}
	if (msg == "")
		return "�����ΰ����á�\n";
	else
		return "���ڱ����������ͼ�������Ҫ����\n\n" + msg;
}

int do_arrest(string arg)
{
	object me=this_player(), victim, fighter;

	if (!me->query_temp("mark/Ѳ��"))
        return notify_fail("ʲô��\n");

	if (!arg)
        return notify_fail("��Ҫ�в�˭��\n");

	if (environment(me)->query("no_fight"))
		return notify_fail("���ﲻ׼ս����\n");

	victim = present(arg,environment(me));

	if (!victim)
        return notify_fail("���ﲢ�޴��ˣ�\n");

	if (victim == me) 
		return notify_fail("�αض��һ�٣�\n");

	if (!living(victim))
		return notify_fail("�ⲻ�ǻ��\n");

	if (!(userp(victim)
		&& victim->query("PKS")>19
		&& victim->query("combat_exp")/victim->query("PKS") < 10000))
		return notify_fail("���˲����׷���\n");

	message_vision(HIW"$N��$n�ߺ�һ����"+RANK_D->query_rude(victim)+"�����ˣ�������ܲ����ˣ��������־��ܣ���\n"NOR, me, victim);

	if (victim->is_fighting()) 
		victim->remove_all_killer();

	victim->kill_ob(me);
	me->fight_ob(victim);
	return 1;
}
