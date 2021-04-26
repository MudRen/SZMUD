// ���պ��ǣ��������³����㣡���� hs_haigu.c
// by naihe  02-06-06

#include <ansi.h>
inherit ITEM;

int weight,remaining,
remaining=10+(random(6)),
weight=(remaining*3000+1000);

void create()
{
	set_name(RED"���պ���"NOR, ({"hongshao haigu"}));
	set_weight(weight);
	set("long", "����һ��������ͦ���˵Ĳˣ����պ��ǣ���ζ���ǳ��ĺá�\n");
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set("food_supply", 10);
	}
}

void init()
{
	add_action("do_food", "eat");
	add_action("do_food", "chi");
	add_action("do_puke","puke");
}

int do_food(string arg)
{
	object ob,me;

	me=this_player();
	ob=this_object();

	if(arg != ob->query("id"))
	return 0;

	if (me->is_busy())
	{
		write("����ô�죬С��Ǻ�����Լ�Ҳ�������˵�ԭ�ϡ�\n");
		return 1;
	}

	if ((int)me->query("food") >= (int)me->max_food_capacity())
	{
		write("��Ȼζ���ܺã�����ʵ�ڳԲ����ˡ�\n");
		return 1;
	}

	me->add("food", (int)query("food_supply"));

	if(me->is_fighting())
	me->start_busy(1);

	me->start_busy(2);
	remaining-=1;

	if (remaining>0)
		{
			message_vision("$N��������һ��"+this_object()->query("name")+"������ȥ����Ȼ��ζ���\n",me);
			message_vision("$N�ѿ�����ǿ��ͷ�е�û�κ�ζ���ˣ��Ų�������˳�����\n"NOR,me);
			new(__DIR__"hs_gutou")->move(environment(me));
			weight-=3000;
			this_object()->set_weight(weight);
// ����Խ�࣬ʳ����Ȼ��Խ������
		}

	else
		{
			message_vision("$Nҧ�����һ��"+this_object()->query("name")+"����Ȼ����ͷ���᲻���ӣ�Ҳ������������ȥ��\n",me);
			me->add("food", (int)query("food_supply"));
// ����ͷ���Ե��ˣ���ȻҪ����ӵ�ʳ�ﲹ����
			destruct(this_object());
		}
	return 1;
}

int do_puke(string arg)
{
	int temp_food;

	temp_food=this_player()->query("food");

	if(arg) return 0;

	if(temp_food<50)
	{
		write("�㻹�����أ�С�İѳ���θ��Ƣ��ʲô�Ķ��µ��ˡ�\n");
		return 1;
	}

	message_vision(CYN"$N"CYN"ͻȻ��ϡ��������Ż����һ��Ѷ��������ÿ�ʼ�е���ˡ�\n"NOR,this_player());
	this_player()->set("food",temp_food-50);
	return 1;
}

