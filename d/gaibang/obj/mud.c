// Code of ShenZhou
// ni.c ��

inherit ITEM;

void create()
{
	set_name("ʪ��", ({"shi ni", "mud"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�Ŵ�����������ʪ�ࡣ\n");
		set("unit", "��");
		set("value", 0);
	}

	setup();
}

