//Code of ShenZhou
//神雕大侠令牌
//kissme 2202,2,12

inherit ITEM;

void create()
{
    set_name("神雕令牌",({"ling"}));
    set_weight(50);
    if(clonep())
        set_default_object(__FILE__);
    else {
        set("long","这是神雕大侠杨过的令牌！\n");
        set("unit","个");
        set("value",0);
        }
}


