// Code of ShenZhou
// zhusun ����

inherit ITEM;

void create()
{
	set_name("����", ({"zhu sun", "bamboo shoot", "shoot"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���������̵�����\n");
		set("unit", "��");
		set("value", 0);
	}
}
