//Cracked by Roath
inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("�������", ({"jianbing", "guozi"}));
    set_weight(100);
    if (clonep())
	set_default_object(__FILE__);
    else {
	set("long", "����һ���Ⱥ����ļ�����ӣ�����ļ�����������ء�\n");
	set("unit", "��");
	set("food_remaining", 3);
	set("food_supply", 50);
	set("value", 100);
    }
}
