// Code of ShenZhou
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("��", ({"mr-letter"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                
set("long","����һ��������д��Ľ�ݹ��ӵ��š�\n");
                set("no_drop", "�������������뿪�㡣\n");
                set("material", "paper");
        }
}







