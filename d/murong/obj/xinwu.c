// Code of ShenZhou
inherit ITEM;
#include <ansi.h>

void create()
{
        set_name("����", ({"xinwu"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                
set("long","�������������ϵ����\n");
            
               set("no_get", "�ⶫ����͵������\n");
                set("material", "paper");
        }
}







