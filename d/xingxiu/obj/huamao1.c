// Code of ShenZhou
// huamao
// maco 2/18/2000

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name("��ͻ�ñ", ({ "duoba huamao", "mao", "cap" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���ڵװ׻��Ļ�ñ��ά������������ϵ����ӳ������ֻ�ñ�����Ӵ󷽣�ׯ�ص��š�\n");
		set("unit", "��");
		set("value", 500);
		set("material", "cloth");
		set("armor_prop/armor", 5);
		set("armor_prop/personality", 3);
	}
	setup();
}
