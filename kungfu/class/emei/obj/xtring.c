// Code of ShenZhou
// xtring.c ��ָ��

#include <armor.h>
#include <ansi.h>

inherit F_UNIQUE;
inherit FINGER;

void create()
{
        set_name("��ָ��", ({ "tie zhihuan", "ring" }) );
	set_color(HIW+BLK);
        set("weight", 400);
        if( clonep() )
		set_default_object(__FILE__);
        else
	{
		set("long", "���Ƕ������ŵ����������ʦ����Ů������֮����ָ����ָ���ڿ��š�������Ů���ĸ��֡�\n");
		set("unit", "��");
		set("value", 100000);
		set("rigidity", 10000);
		set("material", "alloy");
		set("armor_prop/armor", 1);
		set("no_get", 1);
		set("no_drop", 1);
	}
	setup();
}       
