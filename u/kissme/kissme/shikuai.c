//kissme
//2002,2,7
//ʯ��:stone.c
inherit ITEM;

void create()
{
    if(clonep())
          set_default_object(__FILE__);
    else {
    set_name("ʯ��",({"shikuai"}));
    set("long","����һ�������ʯ�顣\n");
    set_weight(1300);
    set("unit","��");
    set("meterial","stone");
    }
    setup();
}
