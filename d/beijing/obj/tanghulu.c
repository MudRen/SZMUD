//Cracked by Roath
inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("���Ǻ�«", ({"hulu"}));
    set_weight(50);
    if (clonep())
	set_default_object(__FILE__);
    else {
	set("long", "����ɽ髣��������ı��ǣ���Ŀ�ˮ������ˡ�\n");
	set("unit", "��");
	set("food_remaining", 5);
	set("value", 150);
    }
}
