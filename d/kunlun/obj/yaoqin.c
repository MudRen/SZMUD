// Code of Shenzhou
#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
        set_name(HIY"��������"NOR, ({ "yao qin", "qin" }));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "��������ɫ���ɣ���������������ǧ��Ĺ��������š������ɡ�����С�֡�\n");
                set("value", 5000);
                set("material", "wood");
                set("wield_msg", "$N����һ��$n�����С�\n");
                set("unwield_msg", "$N�����е�$n����������\n");
                set("shape", "zither");
        }
        init_staff(45);
        setup();
}


#include "/d/kunlun/obj/zither.h"
#include "/d/kunlun/obj/music.h"


