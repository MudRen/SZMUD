//room: /newjob/builder/snssping.c 杉树坪
//Lara 2001/12/03
inherit ROOM;
#include <ansi.h>
void create()
{        
        set("short", "杉树坪");
        set("long", @LONG
这里长满了各种巨大无朋的杉树，树龄大都已有数百年，树干上皆遍
布青苔，十米以下绝少旁枝侧叶。因雪压雷霹自然倒伏的大树随处可见，
这些大树有的依然活着，生命力之强令人叹服。地上铺着一层厚厚的落叶
和由落叶形成的叶泥，轻轻一踩，往往可掩至脚脖。
LONG
        );

        set("exits", ([   
        "north" : __DIR__"snsbling",  
        "south" : __DIR__"sngsmiao",   
        "west" : __DIR__"snhongping",
        ]));
        set("no_clean_up", 0);       
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
