// Code of Shenzhou
#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
        set_name(HIY"昆仑瑶琴"NOR, ({ "yao qin", "qin" }));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", "这张琴颜色暗旧，是数百年乃至上千年的古物，背面刻着“昆仑派”三个小字。\n");
                set("value", 5000);
                set("material", "wood");
                set("wield_msg", "$N捧起一张$n在手中。\n");
                set("unwield_msg", "$N将手中的$n放了下来。\n");
                set("shape", "zither");
        }
        init_staff(45);
        setup();
}


#include "/d/kunlun/obj/zither.h"
#include "/d/kunlun/obj/music.h"


