// Code of ShenZhou
// huamao
// maco 2/18/2000

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name("������ñ", ({ "quman huamao", "mao", "cap" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����ά������г����Ļ�ñ����״��Բ�Ϸ����ڽ�˿��ñ�أ��̵װ׻����ؾ����š�\n");
		set("unit", "��");
		set("value", 300);
		set("material", "cloth");
		set("armor_prop/armor", 2);
		set("armor_prop/personality", 2);
	}
	setup();
}
