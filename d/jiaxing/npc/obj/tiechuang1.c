// Code of ShenZhou
// Jay 8/9/96

inherit ITEM;

void create()
{
        set_name("����", ({"tie chuang","chuang","bed"}));
	set_weight(200000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long","һ��Ӳ����������\n");
                set("unit", "��");
                set("material", "steal");
        } 
	setup();
}

