//gao.c ��Ҳ��"�����"
//of shenzhou
//snowlf by 201/11/09

#include <ansi.h>
#include <weapon.h>
//inherit ITEM;
inherit HAMMER;

void create()
{
	set_name( CYN "��" NOR , ({"gao","hezui chu ","chu"}) );
	set_weight(2000);
        set("unit", "��");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		
		set("long", "    ��Ҳ�Сi������j���������εĸ�ͷ�����пף�װ�����ҵ�̴ľ��ɣľ
�ѣ���ͷ���ô��մ���ģ�һͷ�Ǽ�׶�εģ���һͷ�����縫����ʵ����
�����ǿѻĺͲ�ʯ/��ز����ٵĹ��ߣ�
");
		set("value", 200);
		set("material", "iron");
		set("wield_msg", "$N����һ��$n���������С�\n");
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
