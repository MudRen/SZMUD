//Lnere;
// qixiu-jian.c;

#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit SWORD;
#include "/clone/unique/special_weapon.h"
void create()
{
        set_name(HIB"���޽�"NOR, ({ "qixiu jian", "sword", "jian" }) );
	set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
                set("long", 
            "�˽�Ϊ��������ɽ֮�������ϹŽ�ħ��������ǧ�����ɴ���ɳɡ�\n"
            "��˵�˽������ܻó��������֮�⣬�⵽֮�����������ҡ�\n" );
		set("value", 10000);
		set("material", "steel");
		set("rigidity", 2000);
                set("wield_msg",
  HIY"ֻ����������ҫ����Ŀ��$N���ж���һ���Ϲ�����"+NOR+""+HIB+"���޽�"+NOR+"��"+HIW+"һ������ɫ����͸��������"+NOR+"���˲������� !\n"NOR);
            set("unwield_msg", HIW"$N�����е�"+HIB+"���޽�"+HIY+"���뱳�ϵĽ��ʡ�\n"NOR);
          set("unequip_msg", HIW"$N�����е�"+HIB+"���޽�"+HIY+"���뱳�ϵĽ��ʡ�\n"NOR);
        }

	init_sword(100);
        setup();
	::create();
}


