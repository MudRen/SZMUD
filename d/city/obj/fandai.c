// Code of ShenZhou
// fandai.c ʳ��

inherit ITEM;

void create()
{
	set_name("ʳ��", ({ "shi he", "he", "box" }));
	set_weight(500);
	set_max_encumbrance(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һֻ��ϸ���֯�ɵ�ʳ�С�\n");
		set("value", 50);
	}
}

int is_container() { return 1; }

int reject(object ob)
{
        if (ob && ob->query("food_supply") ) return 0;
        notify_fail("��ֻ�ܰ�ʳ��Ž�ʳ�С�\n");
        return 1;
}
