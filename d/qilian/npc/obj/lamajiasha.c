// Code of ShenZhou
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(WHT"��ɫ��������"NOR, ({"lama jiasha", "jiasha"}) );
    set_weight(3000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "��");
		set("long", "һ�����ظ�³�������ճ����Ļ�ɫ���ġ�\n");
        set("material", "cloth");
        set("armor_prop/armor", 2);
    }
    setup();
}
