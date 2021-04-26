//map.c    密道图

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name( "密道图", ({ "tu", "map"}));
        set_weight(40);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long",
"\n"
"                        『密道图』\n\n"
"\n"
"              芝房    书房        厨房           男睡房\n"
"               |       |           |               |\n"
"      丹房≡≡长廊≡≡长廊≡后堂≡长廊≡≡长廊≡≡石室\n"
"      ≈≈ ←←　←←　← 　  |              |\n"
"       ↓                ↑   |           女睡房\n"
"                              |\n"
"               石室≡≡长廊≡大厅≡石室\n"
"                |             |\n"              
"               剑房       ↑ 长廊\n"
"                              |\n"
"                            大石屋\n"
"=========================================================\n\n"
"  　　　　　　　　　▲\n"
"　　　　　　　　　厉鬼峰\n"
" 　　　　　　　　　 ↑  \n"
"  　　　　　　　　　↑  \n"
" 　　　　　　　　　山崖            ≈≈≈≈≈≈\n"
"  　　　　　　　　　↑             ≈ 鳄鱼潭 ≈\n"
" 　　　　　　　　　 ↑           ／≈≈≈≈≈≈\n"
"　　　　　　　　　石窟←通道←大洞 ●≈≈≈≈≈\n"
"					    　　　　　　　　　\n\n");					
                set("value", 0);
                set("material", "skin");
              }
		setup();
}
