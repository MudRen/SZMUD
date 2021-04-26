//room: /newjob/builder/snlslin.c 冷杉林
//Lara 2001/12/03
inherit ROOM;
#include <ansi.h>
void create()
{        
        set("short", "冷杉林");
        set("long", @LONG
高大茂密的冷杉林几乎遮住了天光，地上铺着厚厚的枯叶，青藤绕树
而上，犹如蟒蛇缠身，树干上印痕清晰可辨。树林中偶尔传来几声野兽的
吼叫，令人不觉有点胆战心惊。
LONG
        );

        set("exits", ([   
        "south" : __DIR__"snhongping",   
        "east" : __DIR__"snsbling",
        ]));
        set("no_clean_up", 0);       
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
