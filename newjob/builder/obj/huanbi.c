//by jiuer

inherit ITEM;

void create()
{
	set_name("ë��", ({"mao bi", "bi"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һֻ���Ϻ��ë�Ƴɵ�ë�ʣ�ë��ֱͦ���Ǳ�����Ʒ��\n");
		set("unit", "֧");
		set("value", 1000);
	}
}
