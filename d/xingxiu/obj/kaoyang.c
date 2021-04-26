// Code of ShenZhou
// kaoyang.c ��ȫ��

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void init();
int do_cut(string);

void create()
{
	set_name(HIY"��ȫ��"NOR, ({"kaoyang", "yang", "sheep" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "�ؽ��ĳ�����ʳ��ȫ������ʽ��ɫ����ͷ���ú����˸����ᡣ\n");
		set("unit", "ֻ");
		set("value", 3000);
		set("food_remaining", 10);
		set("food_supply", 100);
	}

	setup();
}

void init()
{
	add_action("do_cut", "cut");
}

int do_cut(string arg)
{
	object ob1 = this_object(), me = this_player();
	object ob2;
	int i, num = query("food_remaining")/2;

	if ( !arg || arg == "") return 0;

	if ( arg == "kaoyang" || arg == "yang" || arg == "sheep" ) {

		ob2 = new("/clone/food/yangrou");
		ob2->move(environment(ob1));

	if (num > 4) num = 4;
	
	if (num > 1) {
		for( i=0; i < num; i++ )
		{
			ob2 = new("/d/xixia/obj/yangrou");
			ob2->move(environment(ob1));
		}
		message_vision("$N����ȫ���ϻ�û�����"+chinese_number(num)+"�����Ⱥ�������£�С�����⴦�������磬���˴��ѡ�\n", me);
	}
	else {
		message_vision("$N��ʣ�µĿ�ȫ��һ������£�С�����⴦�������磬���˴��ѡ�\n", me);

	}
		destruct(ob1);
		return 1;
	}
	return 0;
}
