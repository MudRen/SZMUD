// cloth.c �ټ���
// By jiuer
/*
ֻ��˵�����Ǹ�������ؤ������һ�ų����������΢�룬���ִ�ţ�
�����·���һ����һ��Ĵ����˲�����ȴϴ�øɸɾ�������������һ�������ȣ�
Ө�����񣬱��ϸ��Ÿ������Ĵ��«������һ���������ε�ģ��������Ｑ
*/
#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(WHT"�ټ���"NOR, ({"cloth"}) );
    set_weight(3000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "��");
		set("long", "һ�����Ʋ�Ƭ���Ƶ��·����·��϶�һ����һ��Ĵ����˲�����ȴϴ�øɸɾ�����\n");
        set("material", "cloth");
        set("armor_prop/armor", 2);
    }
    setup();
}
