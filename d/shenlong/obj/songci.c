// Code of ShenZhou
inherit ITEM;

void create()
{
        set_name("�̴�", ({ "songci" }));
        set("weight", 1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long",
"����һƪ������̴ʡ�\n"
"Ϲ��������������������϶�ǧ��������̽�����ĳ�����������\n");
                set("unit", "��");
                set("value", 20);
        }
        setup();
}
