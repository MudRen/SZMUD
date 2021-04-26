// mashroom1.c ��Ģ��

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("��Ģ��", ({"hua mogu", "mashroom"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һֻ�ʺ�ɫ���׵��ɡ״��Ģ����\n");
		set("unit", "ֻ");
		set("value", 0);
		set("food_remaining", 3);
		set("food_supply", 10);
	}
}

void init()
{
	add_action("do_eat", "eat");
}
int do_eat(string arg)
{
	object me = this_player();
	if(arg =="hua mogu" || arg =="mashroom")
	{
	   write("������Ģ��ҧ�˼��ڡ�\n");
       me->set_temp("poison", 1);
		call_out("poison", 20, me);
		return 1;
	}

}

int poison(object me)
{
        me->delete_temp("poison");
        tell_object(me, HIR"��ͻȻ�е�һ��������ԭ��������о綾�Ļ�Ģ����\n"NOR);
        message("vision", me->name()+"���¼������ģ��ֽű��������°�ĭ������ȥ��\n", environment(me), ({me}) );
        me->receive_wound("qi", me->query("max_qi")+100, "�о綾������");
        return 1;
}
