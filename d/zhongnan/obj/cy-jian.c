// Code of ShenZhou
// /clone/unique/cy-jian.c
// ������
// by sdong 08/01/98

#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit SWORD;
#include "/clone/unique/special_weapon.h"
void create()
{
	set_name(HIC"������"NOR, ({ "chongyang jian", "chongyang", "jian" }) );
	set_weight(4000);
		  if( clonep() )
					 set_default_object(__FILE__);
		  else {
		set("unit", "��");
					 set("long", "һ���������������ɭɭ��������������һ����ˮ���������ý�˿���������֣�����������\n");
		set("value", 10000);
		set("material", "steel");
		set("rigidity", 2000);
					 set("wield_msg",
			HIC"ֻ�����һ����$N�������Ѿ�����һ��"+"$n"+HIC"����������һ����ˮ��һ����֪�ǶϽ���������� !\n"NOR);
					 set("unwield_msg", HIG"$N�����е�$n��������Ľ��ʡ�\n"NOR);
					 set("unequip_msg", HIG"$N�����е�$n��������Ľ��ʡ�\n"NOR);
		  }

	init_sword(145);
		  setup();
	::create();
}


