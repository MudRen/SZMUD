// Code of ShenZhou
//iron.c

inherit ITEM;
void create()
{
        set_name("��ʯ", ({"iron stone", "tie shi", "stone", "iron"}));
        set_weight(random(300000));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
		set("material", "iron");
        }
	if (random(10) > 8){
                set("long", "һ�鷺��һ���Ϲ�ĺ�����\n");
                set("for_blade", 1);
                }
	setup();
}
