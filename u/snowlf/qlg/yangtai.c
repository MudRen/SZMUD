// yangtai.c
// snowyu by 2001/12/18
// snowlf by 2001/12/19

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"��̨"NOR);
        set("long", @LONG
  [1;33m����һ���������̨��������ҹ���ĺõط�

[1;34m    .   . ��  *   ��   .    ��         .    *       ��     . 
       .      .    [1;36m[5m��[2;37;0m[1;34m     .    .  [1;36m[5m��[2;37;0m[1;34m.    [1;36m[5m��[2;37;0m[1;34m        .    
 .   .  .   [1;36m[5m��[2;37;0m[1;34m       ��   .     . .    .        .    [1;36m[5m��[2;37;0m[1;34m  
    .           ��          ��               ��            .[2;37;0m






[1;34m        ����[1;36m[5m����[2;37;0m[1;34m������Ը ��[1;35m��[1;34m֪��[33m��[1;31m[5m��[2;37;0m[1;35m��[2;37;0m

LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
                "down"  : __DIR__"meeting_room",
        ]));

        setup();
}