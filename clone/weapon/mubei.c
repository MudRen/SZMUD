// Code of ShenZhou
// Jay 7/11/96

#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

void create()
{
    set_name(CYN"Ĺ��"NOR, ({"mubei", "bei", "hammer"}));
    set_weight(40000); 
    if( clonep() )
      set_default_object(__FILE__);
    else {
      set("long", "����д���ǡ��ȿ��Ƹ����ϱ�֮Ĺ����\n");
	set("unit","��");
	set("wield_msg","$N���ŵ���һ���ؿ��˸�ͷ��˵���Բ��𣬰���һ��Ĺ����\n");
	set("unwield_msg","$N��Ĺ��������һ�ţ���С���ҵ��Լ��Ľš�\n");
	set("material", "stone");
    }
    init_hammer(15);

    setup();
}
