// /newjob/builder/pao.c ��ɫ����
// by jiuer 11/2001

#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("��ɫ����", ({"pao", "cloth", "chang pao"}) );
    set_weight(3000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "��");
		set("long", "һ������ͨͨ�ĺ�ɫ���ۡ�\n");
        set("material", "cloth");
        set("armor_prop/armor", 2);
    }
    setup();
}
