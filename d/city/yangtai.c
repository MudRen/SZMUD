// workroom.c
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"天台"NOR);
        set("long", @LONG
  [1;33m这是一个宽大的阳台，是欣赏夜景的好地方

[1;34m    .   . ★  *   ☆   .    ★         .    *       ☆     . 
       .      .    [1;36m[5m☆[2;37;0m[1;34m     .    .  [1;36m[5m☆[2;37;0m[1;34m.    [1;36m[5m★[2;37;0m[1;34m        .    
 .   .  .   [1;36m[5m★[2;37;0m[1;34m       ☆   .     . .    .        .    [1;36m[5m☆[2;37;0m[1;34m  
    .           ☆          ★               ☆            .[2;37;0m






[1;34m        就向[1;36m[5m流星[2;37;0m[1;34m许个心愿 让[1;35m你[1;34m知道[33m我[1;31m[5m爱[2;37;0m[1;35m你[2;37;0m

LONG
        );
        set("no_clean_up", 0);
        set("no_fight", "1");
        set("exits", ([
                "out"  : "/d/city/guangchang",
        ]));

        setup();
}
