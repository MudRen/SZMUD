// Code of ShenZhou
// greenrobe.c ��ɫ����
// By Marz

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("��ɫ����", ({"pao", "cloth", "dao pao"}) );
    set_color("GRN");
    set_weight(1500);
    if( clonep() )
       set_default_object(__FILE__);
    else {
	    set("female_only", 1);
        set("unit", "��");
//***** ADDED BY SCATTER *****
                                set("wposition", "/clone/armor/greenrobe.c");
//***** END OF ADDING *****
		set("long", "���Ǽ��ʵ��������ɫ���ۣ����ϻ����Ż��ء�\n");
        set("material", "cloth");
        set("armor_prop/armor", 1);
    }
    setup();
}
