// Code of ShenZhou
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
	set_name("������׹", ({ "yueya erzhui", "erzhui", "zhui", "earring" }));
	set("weight", 100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 5000);
		set("long", "һ�Ծ��µĶ�׹��������Ȧ���м�����һ�Ű���͸����Բ��ʯ����\n");
		set("material", "jade");
		set("armor_prop/armor", 2);
		set("female_only", 1);
	}
	setup();
}
