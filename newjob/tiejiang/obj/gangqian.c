//gangqing.c ��ǥ
//of shenzhou
//snowlf by 201/11/09

#include <ansi.h>
#include <weapon.h>
inherit STAFF;
//inherit ITEM;

void create()
{
	set_name( CYN "��ǥ" NOR , ({"qian","gang qian"}) );
	set_weight(2300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "
    ��ֻһ����ǥ��ͨ���ô��ִ��죬����ʯ����ʯ�Ĺ��ߣ���ʯ�Ĺ���
������Ƭ��ʯ��ʱ���ø����������Ϊ���ģ�����Ҫ��ǥ�ʹ����ƿ�����
�����ڲ�ʯʱ���Ч�����������߿��Ǳز����ٵ�Ŷ��
");
		set("value", 200);
		set("material", "iron");
		set("wield_msg", "$N����һ��$n��(����������ʲô�أ����뵱�����ðɣ�Ҳ���԰���xixi!)\n");
//
		set("unwield_msg", "$N�������е�$n��\n");
            	set("no_sell",1);
              	set("no_steal",1);
//            	set("no_clean_up",1);
//            	set("no_drop",1);
//        	set("no_give",1);
/* �ⲻ������Ʒ�����no drop .no give �ǲ���Ҫ��Զ�������ϣ����װ�? 
   ----- �����ȹ��ˣ��������Ҫ�ٿ����ˡ�----snowlf      */
            	
	}
	init_staff(25);  
//������������Ե���˼�������ȹص� --- snowlf

	setup();
}
