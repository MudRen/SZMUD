// Code of ShenZhou

#include <armor.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit CLOTH;

void create()
{
	set_name("�ڲ���", ({ "wucan yi", "yi" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ���ɴ�ѩɽ�ϵ��ڲϲ�˿֯�ɵĺ��£������ޱȣ��������ɲã�����ֻ����ǰ���������Ͽ���һ��\n");
		set("material", "cloth");
		set("unit", "��");
		set("value", 50000);
		set("armor_prop/armor", 200);
	}
	setup();
	::create();
}
