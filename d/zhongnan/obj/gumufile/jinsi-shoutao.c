// jinsi-shoutao.c ��˿����

#include <armor.h>
#include <ansi.h>

inherit WRISTS;

void create()
{
	set_name(HIY "��˿����" NOR, ({ "jinsi shoutao", "shoutao" }));
       	set("long", "����һ�Խ�˿���ף�Ө�����󣬹����覣�����ϡ�����С�\n");
	set("weight", 300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 50000);
		set("material", "gold");
		set("armor_prop/armor", 5);
		set("female_only", 1);
	}
	setup();
}	
