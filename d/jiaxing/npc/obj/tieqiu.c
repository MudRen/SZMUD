// Code of ShenZhou
inherit ITEM;

void create()
{
	set_name("����", ({ "tie qiu", "qiu" }));
	set("weight", 1500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","��Ȼ������ͨ��������޶��£������ܾ���������Щ���Ρ�\n");
		set("unit", "ֻ");
		set("material", "iron");
	}
	setup();
}	
