// Code of ShenZhou
// Jay 7/11/96

#include <weapon.h>
inherit CLUB;

void create()
{
    set_name("���̹�", ({"han yanguan", "yanguan", "club"}));
    set_weight(500); 
    if( clonep() )
      set_default_object(__FILE__);
    else {
      set("long", "����һ֧ͭ�Ƶĺ��̹ܣ����滹ʣ����ĩ��\n");
	set("unit","֧");
	set("value",100);
	set("wield_msg","$N����һ֧���̹ܣ����ϻ𣬵�����ǣ������������\n");
	set("unwield_msg","$N�Ѻ��̹���Ь�����һྣ�С�ĵطŻػ��\n");
	set("material", "iron");
    }
    init_club(10);

    setup();
}
