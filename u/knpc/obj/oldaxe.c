#include <ansi.h> 
#include <weapon.h>

inherit AXE;

void create()
{
        set_name(HIR"��ɽ��"NOR, ({ "kaishan fu", "fu","axe" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", BLU"���ǵ���Сӥ��ʹ�õ�һ��մ��Ѫ������Ĵ�師��\n"NOR);
                set("value", 100);
                set("material", "iron");
                set("wield_msg", "$N���һ��$n���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_axe(15);
        setup();
}
