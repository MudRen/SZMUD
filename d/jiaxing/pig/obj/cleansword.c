// Code of ShenZhou
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("��ƽ��", ({ "cleansword", "sword", "jian" }));
        set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���峺�ľ��ֽ�����ƽ��\n");
                set("material", "steel");
                set("wield_msg", "$N�������Ĵָ��ʳָ����ָ������ָ����ס�˽��⣬����һ�ɣ�$nͻȻ���𣬽�����ǰ����ס�϶���$N˵���������аɣ�����\n");
                set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
        }
        init_sword(10);
        setup();
}

