// jitui.c ����
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("����", ({ "jitui", "tui" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���Ե�ʣ��ߵĿ����ȡ�\n");
		set("unit", "��");
		set("value", 0);
		set("food_remaining", 2);
		set("food_supply", 10);
	}
	setup();
}

int finish_eat()
{
	set_name("�еþ���ļ��ȹ�ͷ", ({ "bone" }) );
	set_weight(150);
	set("long", "һ���еþ���ļ��ȹ�ͷ��\n");
	return 1;
}
