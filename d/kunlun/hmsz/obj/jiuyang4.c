// kunlun jiuyang2.c
inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>
 
void create()
{
        set_name("�������澭�����ľ�", ({ "jiuyang zhenjing4","jiuyang4","zhenjing4" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"����һ�������ľ��飬�������д�������������������֣���һ��Ҳ��ʶ�ã�������һ����
�ı����о�����Щ���ģ���ÿһ��֮�䣬ȴ��ӬͷС��д���˺��֡�\n",
        );
                set("value", 1000000);
                set("material", "paper");
                            }
                              ::create();
}
