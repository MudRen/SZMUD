//datiechui.c ����
//of shenzhou
//snowlf by 201/11/09

#include <ansi.h>
#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("������", ({ "da tie chui", "chui" }) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ�Ѵ�������\n
");
		set("unit", "��");
		set("value", 100);
		set("material", "iron");
		set("wield_msg", "$N����һ��$n��\n");
		set("unwield_msg", "$N�������е�$n��\n");
            	set("no_sell",1);
              	set("no_steal",1);
//            	set("no_clean_up",1);
//            	set("no_drop",1);
//        	set("no_give",1);
/* �ⲻ������Ʒ�����no drop .no give �ǲ���Ҫ��Զ�������ϣ����װ�? 
   ----- �����ȹ��ˣ��������Ҫ�ٿ����ˡ�----snowlf      */
            	
	}
	init_hammer(25);  
//������������Ե���˼�������ȹص� --- snowlf

	setup();
}
