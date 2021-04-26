// cloth.c 百家衣
// By jiuer
/*
只见说话的是个中年乞丐。这人一张长方脸，颏下微须，粗手大脚，
身上衣服东一块西一块的打满了补钉，却洗得干干净净，手里拿着一根绿竹杖，
莹碧如玉，背上负着个朱红漆的大葫芦，脸上一副馋涎欲滴的模样，神情猴急
*/
#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(WHT"百家衣"NOR, ({"cloth"}) );
    set_weight(3000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
		set("long", "一件用破布片缝制的衣服，衣服上东一块西一块的打满了补钉，却洗得干干净净。\n");
        set("material", "cloth");
        set("armor_prop/armor", 2);
    }
    setup();
}
