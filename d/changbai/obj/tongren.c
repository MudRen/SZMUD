// Code of ShenZhou
// /d/changbai/obj/tongren.c

#include <weapon.h>
inherit CLUB;

void create()
{
       set_name("����ͭ��", ({"tongren"}));
       set_weight(10000);
       if( clonep() )
              set_default_object(__FILE__);
       else {
              set("long", "��ͭ��ֻ�ж��㣬��ȴ��һ�ԣ�˫�ֹ�����£������һ�������ı�Ѩ�\n");
              set("unit", "��");
              set("value", 2000);
              set("material", "bonze"); 
              set("wield_msg","$N�ӱ���ж�¶���ͭ���������С�\n");
              set("unwield_msg","$N�Ѷ���ͭ�˷��ڱ��ϡ�\n");
       }

       init_club(50);

       setup();
}
