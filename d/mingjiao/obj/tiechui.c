// Code of ShenZhou
inherit ITEM;


void create()
{
        set_name("����", ({ "tie chui", "chui" }) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ�Ѵ������������������Ĺ��ߡ�\n"
);
                set("unit", "��");
		set("no_get", 1);
		set("no_drop", 1);


        }

}
