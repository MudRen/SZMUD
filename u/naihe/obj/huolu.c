//                ��׼��������ʾ��                                   |
// ��¯��ר���������ˣ� ���պ��ǣ�������  huolu.c
// by naihe �κ�  2002-06-06

#include <ansi.h>
inherit ITEM;

string temp_now;

void create()
{
	set_name(HIR"��¯"NOR, ({"huo lu"}));
	set_weight(20000);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "����һ����¯�����������ղˣ�cook!����\n");
	set("unit", "��");
	set("value", 1);
	}

	setup();
}

void init()
{
	add_action("do_cook","cook!");
}

int do_cook(string arg)
{
	object me,cook_use,cook_things,fire_things;
	me=this_player();

	cook_use=present("huo lu",me);
	cook_things=present("skeleton",me);
	fire_things=present("shuzhi",me);

	if(!arg) return notify_fail("������ʲô���ģ�\n");

	if(arg!="skeleton") return notify_fail("�����¯ֻ����һ���ˣ�skeleton����\n");

	if(!cook_things) return notify_fail("������û����ԭ�ϰɣ���ô���ˣ�\n");

        if((int)me->query("neili") < 1000)
	{
		if(!fire_things) return notify_fail("���������������������ʵʵ���Ҹ���֦����ʲô�����ջ�ա�\n");

		if(!cook_use) message_vision(HIR"$N��ȼ��"+fire_things->query("name")+""HIR"��¯���յ������ġ�\n"NOR,me);

		else
		{
		  message_vision(HIR"$N�ѻ�¯�ŵ����ϣ���ȼ��"+fire_things->query("name")+""HIR"��¯���յ������ġ�\n"NOR,me);
		  cook_use->move(environment(me));
		}

		destruct(fire_things);
		message_vision(HIR"$N��һ�ߺ��ǷŽ��˻�¯������������\n"NOR,me);
		destruct(cook_things);
		message_vision(HIY"$N������һ�� �����պ��ǡ� ��\n"NOR,me);
		new(__DIR__"hs_haigu")->move(me);
		return 1;
	}

	if(!cook_use) message_vision(HIR"$N����������¯�Ӻ���Ⱥ����ġ�\n"NOR,me);
	else
	{
	    message_vision(HIR"$N�ѻ�¯�ŵ����ϣ�����������¯�Ӻ���Ⱥ����ġ�\n"NOR,me);
	    cook_use->move(environment(me));
	}

        me->add("neili",-999);
	message_vision(HIR"$N��һ�ߺ��ǷŽ��˻�¯������������\n"NOR,me);
	destruct(cook_things);
	message_vision(HIY"$N������һ�� �����պ��ǡ� ��\n"NOR,me);
	new(__DIR__"hs_haigu")->move(me);
	return 1;
}

