// Code of ShenZhou
// ��Ƭ

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("��Ƭ�豭", ({"xiangpian chabei", "bei", "cup"}));
        set_weight(70);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ����ͨ�Ĳ豭��\n");
                set("unit", "��");
                set("value", 30);
		set("max_liquid", 4);
		set("worthless", 1);
		set("liquid", ([
        		"type": "tea",
			"name": "��Ƭ",
			"remaining": 4,
			"drunk_supply": 0,
    		]));
        }
}
