// by jiuer
// ouyang ke fan.c ����
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(HIC"����"NOR, ({"fan","zheshan", "shan"}) );

    set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long","һ�����ȣ��ȹ��Ǹ����ġ�\n");
		set("rigidity", 1000000);
		set_weight(1000);
		set("value", 20);
		set("ding", 10);
		set("material", "blacksteel");

		set("wield_msg",HIM"$N�������ͳ�һ�����ȣ�һ�ӣ����˿�����¶������һ�使�����ε�ĵ����\n"NOR);
		set("unwield_msg", "ž��һ����$N�����Ⱥ����������ս����С�\n");

		init_stick(30);
		set("actions", (: call_other, __FILE__, "query_action" :) );
		setup();
	}
}
