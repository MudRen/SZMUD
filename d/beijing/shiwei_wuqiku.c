//Cracked by Roath

// Room: /d/beijing/shiwei_wuqiku

inherit ROOM;
#include "beijing_defs.h"

void create()
{
        set("short", "����Ӫ������");
        set("long", @LONG
�����Ǿ�������Ӫ�������⣬�����ǳ���������ȡ������
LONG
        );
        set("exits", ([ 
        "south" : __DIR__"shiweiying",
        ]));

        set("objects", ([
        __DIR__"npc/shiwei3":3,
        __DIR__"npc/ruidong":1,
        ]));
 
        set("no_clean_up", 0);
        set("cost", 2);
 
        setup();
}

