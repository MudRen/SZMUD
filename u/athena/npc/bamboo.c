// ����ܰ(Athena)
// /u/athena/obj/bamboo.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIG "������" NOR, ({"fugui zhu","zhu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
        set("long","������������ˮ,�����ò���ïʢ��һ�붼�ɿ���,��һ��ȴ���ⰻȻ,���������˿�����!\n");  
                set_weight(30000);
                set("value", 5000000);
                set("unit", "��");
                set("no_get", 1);
                set("no_drop", 1);
        }
        setup();
}
