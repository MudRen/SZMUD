// Code of ShenZhou
// visitcard.c ����
inherit ITEM;

void create()
{
        set_name("����", ({"bai tie", "tie"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"��������ͨ�İ�����\n");
                set("material", "paper");
        }
}