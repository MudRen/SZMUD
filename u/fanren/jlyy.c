//code of fanren
// jlyy.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
set_name(HIR "��������"NOR, ({ "jinlv yuyi", "yuyi" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
set("long", HIY "����һ��������������£�ͨ���ý�˿����Ƭ֯�ɣ������ޱ�
���������ˡ�������������ǰ�ɷ��˱�֯���ɣ�аħ��֮���ף�
�������Ϸ�����\n");
		set("material", "cloth");
		set("unit", "��");
              set("value", 500);



set("wear_msg", HIY "ֻ����������һ����$Nչ��һ����������������������ϡ�
˲ʱ������Ϊ֮ʧɫ������ǧ�������ƶ�䣬һ��ׯ������\n" NOR);
 set("unequip_msg", HIY "$N�����´����������������۵���СС��һ�ţ�С�ĵ��պá�\n" NOR);
                  set("armor_prop/armor", 2700);


	}
	setup();
}
