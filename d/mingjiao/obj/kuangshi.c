// Code of ShenZhou
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIB"�ڽ��ʯ"NOR, ({ "wujin kuangshi", "kuangshi" }) );
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ���������ڽ��ʯ�������Ʊ����ĺò��ϡ�\n");
                set("unit", "��");
//				set("no_drop",1);

        }

}
