// Code of ShenZhou
// Ryu 3/26/97

inherit ITEM;

void create()
{
        set_name("������", ({"venom", "xian"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", "һ̲�����³��Ķ��ѡ�\n");
                set("unit", "̲");
                set("value", 0);
		set("no_get", 1);
        }
}

