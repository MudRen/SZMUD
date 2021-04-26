// Code of ShenZhou
// d/emei/obj/fruit.c
// xbc 1997/02/03

inherit ITEM;
inherit F_FOOD;

string* titles = ({
        "��ľ��",
        "ʯ��",
        "����",
        "����",
	"����",
	"���޸�",
});

void create()
{
        set_name(titles[random(sizeof(titles))], ({ "fruit", "guo" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��Ұ��������ˮ�鼫�ˡ�\n");
                set("value", 10);
		set("food_remaining", 5);
		set("food_supply", 50);
	}
}
