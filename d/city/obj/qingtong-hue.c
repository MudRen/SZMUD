// Code of ShenZhou
//��ͭ����
//kane

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name( "��ͭ����" , ({ "qingtong hue", "hue" }) );
	set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ����ͭ���ƵĻ��\n");
		set("value", 500);
		set("material", "bronze");
		set("armor_prop/armor", 8);
	}
	setup();
}
