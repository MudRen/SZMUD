//Cracked by Roath
// yellowrobe.c 
// By long

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(YEL"��ɫ����" NOR, ({"pao", "cloth"}) );
    	set_weight(1500);
    	if( clonep() )
       	set_default_object(__FILE__);
    	else 
	{
	    	set("female_only", 1);
        	set("unit", "��");
		set("long", "���Ǽ��ʵ�����Ļ�ɫ���ۡ�\n");
        	set("material", "cloth");
        	set("armor_prop/armor", 1);
    	}
    setup();
}
