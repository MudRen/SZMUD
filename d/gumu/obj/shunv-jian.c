// /d/gumu/obj/shunv-jian.c ��Ů��
// by April 01.08.04
// update flower 01.08.24

#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;
inherit SWORD;

#include "/clone/unique/special_weapon.h"

void create()
{
	set_name(HIG"��Ů��"NOR, ({ "shunv jian", "shunv", "jian" }) );
	set_weight(3000);
		if( clonep() )
			set_default_object(__FILE__);
        else {
			set("unit", "��");
			set("long", "��������޼�ͷ�����޽��棬Բͷ�۱ߡ������ںڣ�û�����󣬵���Щ��һ��������ľ��\n");
			set("value", 12000);
			set("material", "steel");
			set("rigidity", 2000);
			set("wield_msg",HIG"$N�ν����ʣ���ŮӢ�ˣ��������죬��ؼ��ʱ�����ʢ��\n"NOR);
			set("unwield_msg", HIG"$N�����е�$n��������Ľ��ʡ�\n"NOR);
			set("unequip_msg", HIG"$N�����е�$n��������Ľ��ʡ�\n"NOR);
		}

        init_sword(120);
        setup();
        ::create();

}
