// Code of ShenZhou
// shoutao.c

#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
	set_name( "��ָ��", ({ "zhitao", "zhi tao" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ�����������������ָ�ף�ǰ�˷������У��ȿɰ����������ˣ��ֿɱ���ָ�ؽڡ�\n");
		set("value", 250);
		set("material", "iron");
//***** ADDED BY SCATTER *****
                                set("wposition", "/clone/armor/zhitao.c");
//***** END OF ADDING *****
		set("armor_prop/armor", 5);
		set("shaolin",1);
	}
	setup();
}
