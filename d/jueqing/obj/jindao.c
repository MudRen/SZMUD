// jindao.c ��

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit BLADE;
#include "/clone/unique/special_weapon.h"
void create()
{
	set_name(YEL"��"NOR, ({ "jin dao", "jindao", "dao" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѱ����п�ľ�ݵ���������������ǻƽ���졣\n");
		set("value", 10000);
		set("material", "gold");
		set("rigidity", 300);
		set("wield_msg", HIY "ֻ�������һ����һ����⻮����$n����$N�����С�\n" NOR);
		set("unwield_msg", HIY "$n��$N����һת���ڰ���л���һ����⣬��ৡ���Ծ�뵶�ʡ�\n" NOR);
	}
	init_blade(120);
	setup();
	::create();
}


