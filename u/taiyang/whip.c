// Code of ShenZhou
// rouyun-bian.c ���Ʊ�

#include <weapon.h>
#include <ansi.h>
inherit WHIP;

void create()
{
        set_name(HIC "���Ʊ�", ({ "rouyun bian", "bian", "whip", "rouyun", "yunbian" }));
        set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
            set("long", HIC "�����ض��ɼ���֮��������.����Ʈ��,��������.�������Ʊ�.���ִ˱�,�����! \n");
                set("value", 1000000000);
		set("material", "leather");
                set("rigidity", 10);
		set("no_sell", 1);
                set("wield_msg", HIM "$N����һ���֣���Ͳ��Ʈ��һ�����,����һ��ȴ��Ϊ�Ʊޣ�\n" NOR);
                set("unwield_msg", HIM "$N����һ����,һ������û�����С�\n" NOR);
                set("shaolin", 1);
        }
        init_whip(1800);
        setup();
}
