// Code of ShenZhou
//ˮͰ
//xiaojian May 25,2000
//Fix ppl useing other piao get more exp mantian may/17/2001

#include <ansi.h>
inherit ITEM;
string long_desc();
void create()
{
	int water_level;
	set_name("ˮͰ", ({"shui tong", "tong", "bucket"}));
	set_weight(1000);
	if(clonep())
		set_default_object(__FILE__);

	else {
		set("long", (: long_desc :));
		set("unit", "��");
		set("material", "wood");
		set("value", 5000);
		set("no_sell", 1);
		set("no_give",0);
		set("no_get",1);
	        set("no_refresh", 1);

	}
}
string long_desc()
{
	string descrp;
	object ob;
	ob = this_object();
	descrp = 
		HIW"�⸱ľͰ��Щ�ر�Ͱ�׼��ģ����������ȡ���ֻͰ��һ��ϸ��������������������Щ�ֵֹġ�\n"NOR;
	if (ob->query("water_level") == 0)
		descrp += HIC"Ͱ����һ��ˮ��û�С�\n"NOR;
	else if (ob->query("water_level") <= 1)
		descrp += HIC"������һ���ˮ��\n"NOR;
	else if (ob->query("water_level") <= 3)
		descrp += HIC"�����а�Ͱˮ��\n"NOR;
	else if (ob->query("water_level") <= 4)
		descrp += HIC"�����ˮ�����ˡ�\n"NOR;
	else
		descrp += HIC"ľͰ����ػ��˻Σ������ˮ���ˣ���Щ�����ȡ� \n"NOR;
	return descrp;
}

int init()
{
	add_action("do_tiao", "carry");
	add_action("do_tiao", "tiao");
	add_action("do_fang", "putdown");
	add_action("do_fang", "fang");
	add_action("do_dao", "dao");
}

int do_tiao(string arg)
{
	object me, ob, *inv;
	int i;
	me = this_player();
	if(!arg || (arg != "shui tong" && arg!= "tong" && arg != "bucket"))
		return notify_fail("��Ҫ��ʲô? \n");

	ob = present("shui tong", environment(me));
	if(!ob) return notify_fail("���︽��û������������\n");
	if (me->is_busy())
		return notify_fail("����æ���أ�\n");
	inv = all_inventory(environment(me));
	for(i=0; i<sizeof(inv); i++) {
		if( inv[i]->query("id") == "shui tong" ) ob = inv[i];
		if(ob->query("owner") == me->query("id") || (wizardp(me))){
			message_vision(HIR"$N���������ڼ��ϣ�Ȼ�����˸��������۵��˫��������ľͰ��ƽƽ����\n"NOR,me);
			me->receive_damage("jingli",5+random(5));
			//tong has been carried, so the position factor is not applied
			ob->delete("tong_pos");
			ob->move(me);
			me->start_busy(random(3));
			return 1;
		}
	}
	return notify_fail("����û�����ˮͰ��\n");
}

int do_fang(string arg)
{
	object me, ob;
	me = this_player();
	if(!arg || (arg != "shui tong" && arg != "tong" && arg != "bucket"))	
		return notify_fail("��Ҫ����ʲô? \n");
	ob = present("shui tong", me);
	if( !ob)
		return notify_fail("�㲢û�������κζ�����\n");
	if(me->is_busy())
		return notify_fail("����æ����! \n");
	message_vision(HIB"$N��ľͰ�Ӽ��Ϸ��£�һ�ַ�ס�������ڱۣ�Ȼ����������������ľͰ��Ե��\n"NOR,me);
	message_vision(HIC"$N������žž���������죬ľͰ���ȵز��ڵ��ϡ�\n"NOR,me);
	me->receive_damage("qi",(10+random(10)),"��ľͰ������");
	ob->move(environment(me));
	//tong has been putdown, so set tong to be good position,compared to drop tong,tong won't be ��ֱ��
	ob->set("tong_pos",1);
	me->start_busy(1);
	return 1;
}
int do_dao(string arg)
{
	int water_level,max;
	object me,ob1,ob2;
	string what, target;
	me = this_player();

	if( !arg
        ||      sscanf(arg, "%s to %s", what, target)!=2)
                return notify_fail("�����ʽ: dao <��Ʒ> to <��Ʒ>��\n");

	ob1 = present("shui piao", me);
	ob2 = present(target, environment(me));
	if(!ob1)
		return notify_fail("��Ҫ��ʲô��ˮ? \n");
	if(!ob1->query("water_filled"))
		return notify_fail("ˮư��û��ˮ��ô��? \n");
	if( !ob2 )
		return notify_fail("��Ҫ�����ﵹˮ? \n");
	if (what != "shui" && what != "water")
		return notify_fail("��Ҫ��ʲô? \n");
	if (me->is_busy())
		return notify_fail("����æ���أ�\n");
	if(ob2->query("full"))
		return notify_fail("ˮͰ�Ѿ����ˡ�\n");
	if(ob2->query("owner") != me->query("id") && (!wizardp(me)))
		return notify_fail("����������ˮͰ��\n");
	if(!ob2->query("tong_pos"))
		return notify_fail("������Ͱ����(putdown),Ͱ��������������\n");
	if(ob1->query("owner/id") != me->query("id"))
	{
		message_vision("$N����"+ob1->query("owner/name")+"��ˮư��һưˮ������ˮͰ��\n",me);
		if(me->query_condition("tiaoshui") >5)
			me->apply_condition("tiaoshui",me->query_condition("tiaoshui")-5);
	}
	else message_vision("$N��һưˮ������ˮͰ��\n",me);
	ob1->set("water_filled",0);
	ob2->add("water_level",1);
	ob2->set("long", (: long_desc :));
	if (ob2->query("water_level") ==5 )
	ob2->set("full",1);
	me->start_busy(2+ random(2));
	me->receive_damage("jingli", (10+ random(5)));
	return 1;
}
