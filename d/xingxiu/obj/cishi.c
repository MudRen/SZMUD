// Code of ShenZhou
// weapon: ���̲���¶���� (Xianglu dao)
// wsky 4/7/00

#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("��ʯ", ({ "cishi", "magnet", "shi" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�鲻���۵�ʯͷ���ƺ���������΢ϸ�Ľ������¡�\n"NOR);
                set("material", "stone");
        }
        setup();
}

