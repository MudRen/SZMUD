// obj /d/wulin/obj/qingjian
// Piao 2001/10/15
inherit ITEM;

void create()
{
        set_name("请柬", ({"qing jian", "jian"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                set("long","这是仙人所发的请柬。\n");
                set("material", "paper");
        }
}

