// Code of ShenZhou
// Jay 7/11/96

#include <weapon.h>
inherit HAMMER;

void create()
{
    set_name("����", ({"qiping"}));
    set_weight(3000); 
    if( clonep() )
      set_default_object(__FILE__);
    else {
      set("long", "���ǿ����������ң��������ʮ��·�����\n");
	set("unit","��");
	set("wield_msg","$N���һ�鷽�����ң�ץס����һ�ǡ�\n");
	set("unwield_msg","$N���������뻳�С�\n");
	set("material", "steel");
    }
    init_hammer(30);

    setup();
}
