// Code of ShenZhou
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("����ʯ", ({ "xiaohuang shi", "shi" }) );
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ������ʯ����������ǹ�ͻ�ҩ�ı���Ʒ��\n");
                set("unit", "��");
//				set("no_drop",1);

        }

}
