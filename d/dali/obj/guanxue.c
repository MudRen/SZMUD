// Code of ShenZhou
// AceP
#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( CYN "��ѥ" NOR , ({ "guanxue", "xue" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("long", "һ˫�����Ա�ı�׼��ѥ��Ь�׺ܺ���Զ·ʱ�����Ժܺõر���˫�š�");
		set("value", 300);
		set("material", "boots");
		set("armor_prop/armor", 6);
	}
	setup();
}
