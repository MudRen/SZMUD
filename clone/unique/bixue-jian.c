//Alan.F
// bixue-jian.c

#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit SWORD;
#include "/clone/unique/special_weapon.h"
void create()
{
	set_name(HIR"��Ѫ��"NOR, ({ "bixue jian", "sword", "jian" }) );
	set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
                set("long", 
                "�����ĳ����磬�����Ͽ����Ա���ѪȾ���ĸ�����:�����ұ�������\n"
                "������һ����Ѫ�ۣ�������Ѫ�����������������͵İ��⡣������\n"
                "��Ѫ����������Ԭ���������Ѫ��Ӣ�۵�Ѫ���ҳ���Ѫ�����껯�̣�\n"
                "������Ѫ������������\n");
		set("value", 10000);
		set("material", "steel");
		set("rigidity", 2000);
                set("wield_msg",
			HIR"ֻ��Ѫ��һ������Ѫ˳��$N��������"+NOR+""+HIC+"��Ѫ��"+NOR+"��"+RED+"һ����Ѫ��Χ����"+HIR+"��Ѫ��"+RED+"������ !\n"NOR);
                set("unwield_msg", HIW"$N�����е�"+HIC+"��Ѫ��"+HIW+"���뱳�ϵĽ��ʡ�\n"NOR);
                set("unequip_msg", HIW"$N�����е�"+HIC+"��Ѫ��"+HIW+"���뱳�ϵĽ��ʡ�\n"NOR);
        }

	init_sword(100);
        setup();
	::create();
}


