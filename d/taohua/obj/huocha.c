// Code of ShenZhou
// 

#include <weapon.h>

inherit PIKE;

void create()
{
        set_name("���", ({ "huo cha", "cha" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����棬����ȥ�۶۵ġ�\n");
                set("value", 300);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n������һ����ɵЦ�˼�����\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }
        init_pike(50);
        setup();
}

