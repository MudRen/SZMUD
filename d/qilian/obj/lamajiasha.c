// Code of ShenZhou
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(YEL"��ɫ��������"NOR, ({"lama jiasha", "cloth", "jiasha"}) );
    set_weight(3000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "��");
		set("long", "һ�����������ճ����Ļ�ɫ���ġ�\n");
        set("material", "cloth");
        set("armor_prop/armor", 20);
    }
    setup();
}
