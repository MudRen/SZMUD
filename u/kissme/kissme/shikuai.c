//kissme
//2002,2,7
//石块:stone.c
inherit ITEM;

void create()
{
    if(clonep())
          set_default_object(__FILE__);
    else {
    set_name("石块",({"shikuai"}));
    set("long","这是一块沉甸甸的石块。\n");
    set_weight(1300);
    set("unit","块");
    set("meterial","stone");
    }
    setup();
}
