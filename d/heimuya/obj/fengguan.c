// Code of ShenZhou
// fengguan.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name( "���" , ({ "feng guan", "headress", "fengguan", "guan" }) );
        set_color("$HIY$");
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ڣ����������������Ҳ����������ͷ�ڡ�\n");
                set("value", 10000);
                set("material", "cloth");
       		set("wear_msg", HIY "$N���ᴩ���Ϸ�ڣ���˵�����Ҽ޵�����˭�����ܰ���һ��һ����\n" NOR);
		set("unequip_msg", HIY "$N�����ժ�·�ڡ�\n" NOR);
                set("armor_prop/armor", 4);
		set("female_only", 1);
        }
        setup();
}
