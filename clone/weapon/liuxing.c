// Code of ShenZhou
// weapon: /d/xingxiu/npc/obj/liuxing.c
// Jay: 6/30/96

#include <weapon.h>
 
inherit HAMMER;
 
void create()
{
        set_name("���Ǵ�", ({ "liuxing chui","hammer","chui" }) );           
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");                                
                set("material", "wood");                             
                set("long", "����һ���ÿ�ή�ĺ�«�����ϸɳ�Ƴɵ����Ǵ���\n");
		set("wield_msg", "$N�ӵ�������һЩɳ�ӣ���ɳ�ӹ���$n�У��������\n");
		set("unequip_msg", "$N��$n�е�ɳ�ӵ��ڵ��ϣ��Ѻ�«��������\n");
        }
        init_hammer(15);
}
