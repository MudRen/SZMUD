// Code of ShenZhou

#include <weapon.h>
#include <ansi.h>
inherit PIKE;
void create()
{
        set_name("��צ", ({ "gang zhua", "zhua" }) );
        set_weight(14000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����α��У��������ߣ������һ֧��ָ��צ��\n");
                set("value", 200);
                set("material", "iron");
//***** ADDED BY SCATTER *****
				set("wposition", "/clone/weapon/gangzhua.c");
//***** END OF ADDING *****
                set("wield_msg", "$N�ó�һ��$n���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }
        init_pike(50);
        setup();
}

