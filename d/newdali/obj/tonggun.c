// Code of ShenZhou
#include <weapon.h>

inherit CLUB;

void create()
{
        set_name("��ͭ��", ({ "tong gun", "gun" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", 
"����һ���Ƴγε���ͭ��������û�м��ٽ����������ʹ���ġ�\n");
                set("value", 100);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_club(10);
        setup();
}

