
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
void create()
{
	set_name("��ң��", ({ "xiaoyao jian", "xiaoyao", "jian" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 50000);
		set("material", "steel");
		set("long", HIC"��˵���������е�������Ϻ�������ʯ���ɣ��ƺ��зǷ�����;��\n"NOR);
		set("wield_msg", HIY"$N�����ش����߳��һ��"+HIR"��"+HIG"��"+HIC"��"+HIM"��"+HIY"�ĳ������ƺ��Ǵ�˵�е�$n��\n"NOR);
		set("unequip_msg", HIB"৵�һ����$N�����е�$n�ջء�\n"NOR);
	}
	init_sword(500);
	setup();
}


