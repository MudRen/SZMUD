// Code of Taiyang
// baojian.c

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
               set_name(HIY "̫����" NOR, ({ "taiyang jian", "jian", "sword", "baojian" })); 
        set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "steel");
                set("value", 22000);
		set("unit", "��");
                      set("long", HIY "����̫���������������񽣣������Ϸ��Ž�ɫ�Ĺ�ã�� \n"NOR); 
//***** ADDED BY SCATTER *****
                                      set("wposition", "/u/taiyang/baojian.c");
//***** END OF ADDING *****
                set("wield_msg", "$N��ৡ���һ�����һ����â�����$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
        init_sword(2000);
	setup();
}
