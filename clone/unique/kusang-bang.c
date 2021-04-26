// Code of ShenZhou
// kusang-bang.c

#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;

inherit STICK;

void create()
{
        set_name(HIW"��ɥ��"NOR, ({"kusang bang", "bang", "stick"}));
        set_weight(10000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIW"һ�����ִ�͵Ŀ�ɥ�������ϰ������ƣ���ͷ����һ���������Ʋ���˿���촦��\n"NOR);
                set("value", 4000000);
                set("material", "blacksteal");
                set("rigidity", 2000);
	        set("poison", 5);
                set("wield_msg", "$N��������һЦ�����һ����ɥ��ץ�����С�\n");
                set("unwield_msg", "$N�����еĿ�ɥ��������С�\n");
        }

        init_stick(100);
        setup();
        ::create();
}       
