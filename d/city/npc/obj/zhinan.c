// Code of ShenZhou
// ����ָ��.c
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("����ָ��", ({ "zhinan", "guide"}) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("no_drop", 1);
                set("long",
"       ��������������������������������\n"
"       |                               |\n"
"       |                               |\n"
"       |                      ����     |\n"
"       |                     | �� |    |\n"
"       |                     |    |    |\n"
"       |                     | �� |    |\n"
"       |                     |    |    |\n"
"       |  ��         ��      | ָ |    |\n"
"       |  ��         ��      |    |    |\n"
"       |  С         ��      | �� |    |\n"
"       |  ��         ��       ����     |\n"
"       |  ��      �� ׫                |\n"
"       |  ��      �� ��                |\n"
"       |  ��      �� ��                |\n"
"       |  ��      ��                   |\n"
"       |  ��                           |\n"
"       |  ��                           |\n"
"       |                               |\n"
"       |                               |\n"
"       ��������������������������������\n\n"

"����һ������ָ�ϣ���С�ײ˻������������еġ�\n"
"�Ȿ����˷������⣬ÿҳ���ǿյġ�\n\n" );
                set("value", 5);
                set("material", "paper");
        }
        setup();
}

