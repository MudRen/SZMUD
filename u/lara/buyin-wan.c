// Code of ShenZhou
//wzfeng 99 11/29
#include <ansi.h>
inherit ITEM;

void setup()
{}
void init()
{
	add_action("do_eat", "eat");
}
void create()
{
        set_name(HIW"������"NOR, ({"buyin wan","wan"}));
        set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "��");
                set("long","����һ�������裬�̲�����֮������Ч���������˷�ʳ�����쳣 ��\n");
                set("value", 0);
		set("no_drop","�������������뿪�㡣\n");
                set("value", 2000);
		set("medicine", 1);

        }
        setup();
}
 
int do_eat(string arg)
{

	object me;
	int skill;
	me=this_player();
	skill=me->query_skill("pixie-jian", 1);

	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
	if(skill<200)
	{
	message_vision(HIR"$N����һ�������裬ֻ���û���һ�������һ������֮��֮���ﴮ��ȫ��ɲ�Ǽ�����ʧ�ף���������!\n"NOR, this_player());
	if(me->query("max_jingli")>50)
	{
	me->add("eff_jingli",-20);
	me->add("max_jingli",-20);
	}
	me->unconcious();
	}
	else
	{
		if(me->query("drug_list/1")==query("drug_list/1")
			&&me->query("drug_list/2")==query("drug_list/2")
			&&me->query("drug_list/3")==query("drug_list/3")
			&&me->query("drug_list/4")==query("drug_list/4")
			&&me->query("drug_list/5")==query("drug_list/5")
			)
		
		
		{

			if(me->query("pixie/buyin-wan/lvl")>=skill&&me->query("pixie/buyin-wan/lvl")>0)

			{
				message_vision(HIG"$N����һ�������裬ֻ���û���һ�������һ������֮��֮���ﴮ��ȫ��ɲ�Ǽ��������������������\n"NOR, this_player());
				message_vision(HIR"������ǰ��ҩ���ƺ���δ��ʧ����������Ч���ʵ��䷴��$Nɲ�Ǽ�����ʧ�ף���������\n"NOR, this_player());
	if(me->query("max_jingli")>50)
	{
	me->add("eff_jingli",-20);
	me->add("max_jingli",-20);
	}

			}
			else
			{
			
				message_vision(HIG"$N����һ�������裬ֻ���û���һ�������һ������֮��֮���ﴮ��ȫ��ɲ�Ǽ��������������������\n"NOR, this_player());
				me->add("eff_jingli",5+random(2));
				me->add("max_jingli",5+random(2));
				me->set("pixie/buyin-wan/lvl",skill);
			}
		
		}
		else
		{
		message_vision(HIG"$N����һ�������裬ֻ���û���һ�������һ������֮��֮���ﴮ��ȫ��ɲ�Ǽ��������������������\n"NOR, this_player());
		message_vision(HIR"���ϴ�ҩ�����������岻����ɲ�Ǽ�$N����ʧ�ף���������\n"NOR, this_player());
		me->add("max_jingli",-20);
		me->unconcious();
	
		}

	}
	
	
	destruct(this_object());
	return 1;
}

