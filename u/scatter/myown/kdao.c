 // Code of ShenZhou
// xuedao.c  Ѫ��

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit BLADE;
#include "/clone/unique/special_weapon.h"
void create()
{
        set_name(HIC"ѩ����"NOR, ({ "scatter blade", "dao", "blade" }));
        set_weight(7000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIC"һ�ۿ���ȥ��֪����ѵ�����һ������ʹ�á�\n" NOR);
                set("value", 7000000);
                set("material", "steel");
                set("rigidity", 1000);
                set("wield_msg", HIC "ֻ����ৡ���һ������ʱ����Χ��ǿ���£��ס�ˡ�\n" NOR);
                set("unwield_msg", HIC "��Χ��ʱ��ָ�ƽ����\n" NOR);
                set("clone_ob", "/u/scatter/myown/kdao");
        }
        ::create();
        init_blade(300);
        setup();
}
