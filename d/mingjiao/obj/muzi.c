// Code of ShenZhou
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("��ǹģ��", ({ "huoqiang muzi", "muzi" }) );
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ����ǹģ�ӣ��ú������ɡ�\n");
                set("unit", "��");
		set("no_get",1);
		set("value",1);
//				set("no_drop",1);

        }

}

