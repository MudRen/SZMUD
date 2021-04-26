// workroom.c
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"ÌìÌ¨"NOR);
        set("long", @LONG
  [1;33mÕâÊÇÒ»¸ö¿í´óµÄÑôÌ¨£¬ÊÇĞÀÉÍÒ¹¾°µÄºÃµØ·½

[1;34m    .   . ¡ï  *   ¡î   .    ¡ï         .    *       ¡î     . 
       .      .    [1;36m[5m¡î[2;37;0m[1;34m     .    .  [1;36m[5m¡î[2;37;0m[1;34m.    [1;36m[5m¡ï[2;37;0m[1;34m        .    
 .   .  .   [1;36m[5m¡ï[2;37;0m[1;34m       ¡î   .     . .    .        .    [1;36m[5m¡î[2;37;0m[1;34m  
    .           ¡î          ¡ï               ¡î            .[2;37;0m






[1;34m        ¾ÍÏò[1;36m[5mÁ÷ĞÇ[2;37;0m[1;34mĞí¸öĞÄÔ¸ ÈÃ[1;35mÄã[1;34mÖªµÀ[33mÎÒ[1;31m[5m°®[2;37;0m[1;35mÄã[2;37;0m

LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
                "down"  : "/u/snowyu/workroom",
        ]));

        setup();
}
    void init() 
{

              object me = this_player(); 
        if( wizardp(me) && getuid(me)!="snowyu ")
                message("vision", me->name()+"×ßÁË¹ıÀ´¡£\n", environment(me), ({me}));
}
