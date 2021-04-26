// С���˶�  :)  eat_naihe.c
// by naihe  2002-05-19    for spark.

inherit ITEM;
#include <ansi.h>

void yeah();
int last=5;
string where,l_hand,r_hand,l_leg,r_leg,head,soma,now,
l_hand="yes",
r_hand="yes",
l_leg="yes",
r_leg="yes",
head="yes";

void create()
{
	set_name(WHT"С���˶�"NOR, ({"tang ren","ren"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "����һ��С���˶���Ц������ģ��ɷ�ǿɰ�����ϡ�����κε����ӡ�\n");
		set("unit", "��");
		set("value", 0);
		set("food_supply", 10);
	}
	setup();
}

void init()
{
	add_action("do_food", "eat");
	add_action("do_food", "yao");
}

void yeah()
{
	object gem,me;
	me=this_player();
	gem=new("/u/naihe/obj/gem");

	gem->move(me);
	message_vision("$Nҧ��"WHT"С���˶�"NOR"�����������������ƺ���Щ������\n",this_player());
        destruct(this_object());
}

// ͷ��head �֣�hand �ţ�leg ���ӣ�soma

int do_food(string arg)
{
	object me=this_player();

	string temp,can_eat;
	can_eat="no";

	if(this_object()->query("off")==1) return 0;


	if (me->is_busy())
	return notify_fail("�����ԣ���ѽ��\n");

	if(!arg) return notify_fail("��Ҫ�����¿�ѽ��<hand/leg/head/soma>\n");

	if(arg == "left hand") where="���С��";
	if(arg == "right hand") where="�ұ�С��";
	if(arg == "left leg") where="����ȶ�";
	if(arg == "right leg") where="�ұ��ȶ�";
	if(arg == "head") where="С�Դ���";
	if(arg == "soma") where="����";

	if(arg!="left hand" && arg!="right hand" && arg!="left leg" && arg!="right leg" && arg!="head" && arg!="soma")
	return notify_fail("��������ҧ��ѽ����\n");

	if ((int)me->query("food") >= (int)me->max_food_capacity())
		return notify_fail("���Ѿ��Ա������Բ�������\n");

	if(arg=="left hand")
	{
		if(l_hand!="yes") return notify_fail(where+"�Ѿ����Ե�����\n");
		l_hand="no";
		can_eat="yes";
	}

	if(arg=="right hand")
	{
		if(r_hand!="yes") return notify_fail(where+"�Ѿ����Ե�����\n");
		r_hand="no";
		can_eat="yes";
	}

	if(arg=="left leg")
	{
		if(l_leg!="yes") return notify_fail(where+"�Ѿ����Ե�����\n");
		l_leg="no";
		can_eat="yes";
	}

	if(arg=="right leg")
	{
		if(r_leg!="yes") return notify_fail(where+"�Ѿ����Ե�����\n");
		r_leg="no";
		can_eat="yes";
	}

	if(arg=="head")
	{
		if(head!="yes") return notify_fail(where+"�Ѿ����Ե�����\n");
		head="no";
		can_eat="yes";
	}

	if(arg=="soma")
	{
		if(last!=0)
		    return notify_fail("�ȳ������Ǳ����ô��ѽ��\n");

		else
		{
			message_vision("$N����"WHT"С���˶�"NOR"������һ��ҧ����ȥ��\n",me);
			set("off",1);
			call_out("yeah",1);
			return 1;
		}
	}

	if(can_eat=="yes")
	{
		temp=now;
		if(last==5) now=where;
		else now=temp+"��"+where;


		if(head=="yes")
			set("long","���Ǹ���ҧ���˵�С���˶���Ц������С�Դ�ͦ���κε�ģ����\n���Ѿ����Ե���"+now+"�����˸о�����ϧ�ġ�\n");

		else set("long","����һ��С���˶���"+now+"���Ѿ����Ե��ˣ�\n��֪����������ԭ���Ǹ�ʲôģ�����أ�\n");
		last--;
	}

	switch(random(4))
	{
		case 0:
	message_vision("$N����"WHT"С���˶�"NOR"��һ�ڰ�����"+where+"ҧ��������\n",me);
		break;

		case 1:
	message_vision("$N����"WHT"С���˶�"NOR"��ѽ��ģ�һ��С�İ�����"+where+"���Ե��ˡ�\n",me);
		break;

		case 2:
	message_vision("$N����"WHT"С���˶�"NOR"�����س���ͻȻ������"+where+"��ҧ��������\n",me);
		break;

		case 3:
	message_vision("$N����"WHT"С���˶�"NOR"������ȥ�ģ�һ��С�İ�����"+where+"���ε��ˣ�ȴǡ�õ��������\n",me);
		break;
	}

	if(last==0) set("long","����һ��Բ�����Ķ������ƺ�ԭ���Ǹ����˶���\n");

	me->start_busy(1);
	me->add("food", (int)query("food_supply"));
	return 1;
}

