// Code of ShenZhou
// gaodian.c
// xQin 6/00

inherit ITEM;
inherit F_FOOD;

void create()
{
     set_name("��ɫ����", ({ "gaodian" }));
    set_weight(1500);
    if( clonep() )
            set_default_object(__FILE__);
    else {
          set("long", "��ɫ������״����,�ƺ�����������һ��\n");
          set("unit", "��");
          set("value", 60);
          set("food_remaining", 4);
          set("food_supply", 20);
     }
}
