// /clone/unique/blackjian.c
// �ڽ�
// by jiuer 09/01/2001

#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit SWORD;

//#include "/clone/unique/special_weapon.h"
void create()
{
	set_name(HIB"�ڽ�"NOR, ({ "black jian", "heijian", "jian" }) );
	set_weight(3000);
		if( clonep() )
			 set_default_object(__FILE__);
		else {
		set("unit", "��");
		set("long", "һ����ϸ�ֳ��ĺڽ�����������ȴ�����쳣��\n");
		set("value", 10000);
		set("material", "steel");
		set("rigidity", 2000);
		set("wield_msg",
			HIB"ֻ������һ����$N������һ��"+"$n"+HIB"��������������пڷ������⣬��Ѻڽ����Ƿ����ޱȵ����С�!\n"NOR);
		set("unwield_msg", HIB"$N�����е�$n��������Ľ��ʡ�\n"NOR);
		set("unequip_msg", HIB"$N�����е�$n��������Ľ��ʡ�\n"NOR);
		}

	init_sword(100);
	setup();
	::create();
}


