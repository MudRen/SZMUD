// Code of ShenZhou

#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit AXE;
#include "/clone/unique/special_weapon.h"

void create()
{
        set_name(HIY"�ƽ�"NOR, ({ "huangjin fu", "fu", "axe" }));
        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�ѳ��صĳ����𸫣��ǹ����򱩾�ɣ����ʹ�õı�������ȫ�ǻƽ����ġ�\n");
                set("value", 50000);
                set("material", "gold");
                set("wield_msg", "$N����˫�ۣ�������һ��$n��\n");
                set("unwield_msg", "$N���������е�$n��\n");
        }
        init_axe(140);
	setup();
	::create();
}
