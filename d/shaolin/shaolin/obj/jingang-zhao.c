// Code of ShenZhou
// jingang-zhao.c

#include <armor.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit CLOTH;

void create()
{
	set_name("�����", ({ "jingang zhao", "zhao" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ��������������ģ�ͨ������ɽѩ��˿֯�ɣ������ޱ�
���������ˡ�������������ǰ�ɴ�Ħ����Я����ԭ��аħ��֮���ף�
���Ƿ�����Ͻ�ħ������\n");
		set("material", "cloth");
		set("unit", "��");
		set("value", 50000);
		set("wear_msg", HIY "ֻ����������һ����$Nչ��һ����������������������ϡ�
˲ʱ������Ϊ֮ʧɫ������ǧ�������ƶ�䣬һ��ׯ������\n" NOR);
		set("unequip_msg", HIY "$N������ִ����������������۵���СС��һ�š�\n" NOR);
		set("armor_prop/armor", 270);
		set("shaolin", 1);
	}
	setup();
	::create();
}
