// Code of ShenZhou
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(HIY"ҩ��"NOR, ({"yaocai"}));
	set_weight(90);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��������ҩ���ҩ�ģ�������ɽ�Ρ�ѩ���ӡ�¹�ס����ߡ���ɰ�ȵȡ�\n");
                set("value", 10000);
		set("medicine", 1);
        }
        setup();
}
