// guzheng.c ����

#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
	set_name(HIG"����"NOR, ({ "gu zheng", "zheng", "qin" }));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			HIG"����һ������ʮ�ֿ����Ĺ��ݣ������ɫ�����ʼ��á�\n"NOR);
		set("value", 5000);
                set("material", "wood");
                set("wield_msg", "$N����һ��$n�����С�\n");
                set("unwield_msg", "$N�����е�$n����������\n");
                set("shape", "zither");
      }
        init_staff(45);
        setup();
}

#include "/shenzhou/d/kunlun/obj/flute.h" 
