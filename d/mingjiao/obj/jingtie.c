// Code of ShenZhou
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"����"NOR, ({ "jing tie", "tie" }) );
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ�����ڽ��ʯ���������ľ���������������ĺò��ϡ�\n");
                set("unit", "��");
//		set("no_drop",1);

        }

}
