// Code of ShenZhou
// /d/changbai/renshen.c �˲�

inherit ITEM;
#include <ansi.h>

void create()
{
        set_name("����ɽ�˲�", ({"renshen", "shen"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��մ��ɽ��ĳ���ɽ�˲Ρ�\n");
                set("medicine", 1);
                set("no_sell",  1);
                set("value",  100);
                set("highprice",1000);
                set("lowprice",500);
        }
        setup();
}
