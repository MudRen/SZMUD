// Code of ShenZhou
// Write by Wzfeng 12-29

inherit ITEM;

void create()
{
	set_name("ë��", ({"mao bi", "bi"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һֻ���Ϻ���ë�Ƴɵ�ë�ʣ�����մ���˺�ī��\n");
		set("unit", "֧");
		set("value", 100);
	}
}
