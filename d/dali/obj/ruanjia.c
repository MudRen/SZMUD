// ��˿����
// by snowyu 

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIY"��˿���"NOR, ({ "ruanjia", "armor" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������˿�������ഩ���ɵĻ������,�ഫ�Ƕ���Զ��
�����ն�����������۴��Խ�˿������ǰ����Ĵ��˶���Ϸ��ͼ��\n");
		set("material", "wood");
		set("value", 10);
		set("wear_msg", HIY "$N����һ����˿���,�������б�������,����Ͷ���һ�ɵ���֮��!\n" NOR);
		set("unequip_msg", HIY "$N����˿��״���������������\n" NOR);
		set("armor_prop/armor", 90);
		set("ruanjia", 1);
	}
	setup();
}

