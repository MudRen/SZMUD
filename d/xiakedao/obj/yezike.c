//Cracked by Roath
// yezike  Ҭ�ӿ�
// ssy

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("Ҭ�ӿ�", ({"yezi ke", "yezi", "ke"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ����Ҭ�ӿǣ���������װˮ��\n");
                set("unit", "��");
                set("value", 200);
                set("max_liquid", 10);
        }

        set("liquid", ([
			"type": "tea",
			"name": "Ҭ��֭",
			"remaining": 10,
			"drunk_apply": 0,
        ]));
}
