//Filename:  /d/jueqing/obj/gangzhang.c ��ͷ����
//jiuer--08/15/2001

#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("��ͷ����", ({ "longtou-gangzhang", "gangzhang", "staff" }));
	set_weight(30000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����Լһ��һ�ߵ���ͷ���ȣ�һ������������ͷ��\n");
		set("value", 2500);
		set("material", "steel");
		set("rigidity", 1200);

		set("wield_msg", "ֻ����ǰ���һ����$N���һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������\n");
	}
  	init_staff(35);
	setup();
}