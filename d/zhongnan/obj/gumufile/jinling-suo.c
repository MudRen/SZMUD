// jinling-suo������

#include <ansi.h>
#include <weapon.h>
inherit WHIP;
void create()
{
	set_name(HIY "������" NOR, ({ "jinling suo", "suo" }));
       	set("long", "����һ�Խ��������ǽ�˿�������������\n");
	set("weight", 300);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "��");
		set("value", 50000);
                set("material", "gold");
                set("wield_msg", "$N���������$n�������У����ϵĽ����з����������졣\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
		set("female_only", 1);
	}
        init_whip(40);
	setup();
}	
