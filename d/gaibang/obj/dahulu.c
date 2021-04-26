// Code of ShenZhou
// dahulu.c 

inherit F_UNIQUE;
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("���«", ({"da hulu", "hulu", "hu", "bottle"}));
	set_color("$HIR$");
	set_weight(800);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�������Ĵ��«������ĩ�������գ����кü����꣬\n����������ؤ��İ���ִ�ƣ��ͺ���ʵ۵����������ٵĽ�ӡһ�㡣\n");
		set("unit", "��");
		set("value", 350);
		set("max_liquid", 90);
	}

	// because a container can contain different liquid
	// we set it to contain water at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "�׾�",
		"remaining": 90,
		"drunk_apply": 3,
	]));
	setup();
	::create();

}
