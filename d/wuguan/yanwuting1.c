#include <ansi.h>
inherit ROOM;
void create()
{
       set("short", "练武场");
       set("long", @LONG
这里是武馆的练武场，武馆弟子每天卯时不到就早早起来，在教头的
带领下练武。场地四周的兵器架上摆放着刀、枪、剑、戟等十八般兵器。
LONG);
       set("exits", ([
//             "northup" : __DIR__"taijie2",
             "west" : __DIR__"yanwuting2",
                          ]));
       set("objects", ([
             __DIR__"npc/xuetu1" : 1,
             "/d/wuguan/npc/mu-ren" : 1,
             ]));
       set("outdoors", "wuguan");
       setup();
}
