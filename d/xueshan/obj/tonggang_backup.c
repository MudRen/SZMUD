// Code of ShenZhou
// /d/xueshan/obj/tonggang.c
//tong gang


#include <ansi.h>

inherit ITEM;
inherit "/d/xueshan/inherit/liquid_container.c";

void create()
{
		object suyou;

        set_name(HIY "����ѩ��" NOR, ({"tong gang", "gang"}));
        set_max_encumbrance(600000);
        set_weight(300000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", 
                "һ��ͨ��ƽ��ͭ�ס����ϵ���š�����ѩ�������ഫ\n"
                "��������Ƿ����������������ͽ��ݡ���������Ƕ����\n"
                "�����ϵ��鱦�����ֵ��ϵ��鱦�������һ�ֲ�ͬ��ˮ��ʯ��\n"
                "�����Ǻ���ͽ�Ǿ�������Ͷ����������\n");
                set("value", 10000);
				set("material","bronze");
				set("no_get",1);
         		// make it doesn't refresh the butter
                set("no_refresh",1);
        }

		// mark it as a liquid container
		set("liquid/container",1);
		set_max_liquid(50000);
		set_current_liquid(0);
		set("liquid/unique",1);
	    set("liquid/uniqueid","su you"); 

		setup();

        carry_liquid("/d/xueshan/obj/suyou", 12000);

}
