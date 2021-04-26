// Code of ShenZhou
// 

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("��̳", ({"jiutan", "tan"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������װ�ƵĴ��̳��\n");
		set("unit", "��");
		set("value", 50);
		set("max_liquid", 500);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "�׾�",
		"remaining": 500,
		"drunk_apply": 1,
	]));
}
