// Code of ShenZhou
// huyao.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name( "ͷ��" , ({ "tou kui", "kui" }) );
        set_color("$HIC$");
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ������ͷ�������Ա���ͷ����\n");
		set("value", 500);
		set("material", "iron");
//***** ADDED BY SCATTER *****
                                set("wposition", "/clone/armor/toukui.c");
//***** END OF ADDING *****
		set("armor_prop/armor", 10);
		set("shaolin",1);
	}
	setup();
}
