//Cracked by Roath
inherit ITEM;
inherit F_LIQUID;

int check_value();

void create()
{
    set_name("�����", ({"cha", "tea"}));
    set_weight(500);
    if (clonep())
	set_default_object(__FILE__);
    else {
	set("long", "����һ��װ�����Ĵ��룬�Ѿ���Щ�����ˡ�\n");
	set("unit", "��");
	set("max_liquid", 3);
	set("value", 100);
	set("liquid", ([
		"type" : "tea",
		"name" : "�����ˮ",
		"remaining" : 3,
		"drunk_supply" : 5,
	]));
    }
}
