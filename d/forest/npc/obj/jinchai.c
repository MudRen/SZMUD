// Code of ShenZhou
inherit ITEM;

void create()
{
	set_name("����", ({ "jin chai", "chai" }));
	set("weight", 400);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","����һ�������ִ���Բ������ӨȻ����һ��ϣ��֮�䡣\n");
		set("unit", "֧");
		set("value", 3000);
		set("material", "gold");
		set("armor_prop/armor", 1);
	}
	setup();
}	
