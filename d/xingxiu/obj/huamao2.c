// Code of ShenZhou
// huamao
// maco 2/18/2000

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name("�������ñ", ({ "maerjiang huamao", "mao", "cap" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����ά���СŮ���͹�������Ϊϲ����һ�ֻ�ñ��ñ���ø�ɫС���顢��Ƭ��׺�Ÿ��ָ����Ļ���ͼ����\n");
		set("unit", "��");
		set("value", 400);
		set("material", "cloth");
		set("armor_prop/armor", 4);
		set("armor_prop/personality", 5);
		set("wear_msg", "$N����һ���������ñ��ñ��С���ӹ�ʶ�Ŀ��������ž�Ө¶��ʢ�����ʻ���\n");
		set("female_only", 1);
	}
	setup();
}
