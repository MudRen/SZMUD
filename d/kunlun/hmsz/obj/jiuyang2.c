// kunlun jiuyang2.c
inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>
 
void create()
{
         set_name("「九阳真经」第二卷", ({ "jiuyang zhenjing2","jiuyang2","zhenjing2" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
"这是一本薄薄的经书，书封面上写著几个弯弯曲曲的文字，你一个也不识得，翻开来一看，
四本书中尽是这些怪文，但每一行之间，却以蝇头小楷写满了汉字。\n",
        );
                set("value", 1000000);
                set("material", "paper");
                            }
                              ::create();
}
