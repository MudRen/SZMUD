// rany's workroom

#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
        set("short",GRN "战场" NOR);
        set("long", @LONG
        
面对拜索斯的挑衅，这次伊斯毫不留情地给了他们一个教训。人们
似乎还没有从惨烈的战场上清醒过来，你正为没有加入这场轰轰烈
烈的战役而遗憾，一个土豆砸到了你的头上。“烂的，不要了！”
一个少女这样自言自语道。当你想开口正想和她说话时，她冲着你
吼道：“有什么可奇怪的？！我们国家打仗就是用土豆的！！你这
个老不死的烂茄子！”你这才发现，整个战场满地都是茄子、柿子
和土豆。


LONG
        );
        set("no_fight", 1);
        set("objects", ([
                __DIR__"yumiko" : 1,
        ]));
                                              
        set("valid_startroom",1);
        
        set("objects", ([
        		__DIR__"qiushui" : 1,

        ]));
                                              
        set("exits", ([
                "yz" : "/d/city/kedian",
                "wr" : "/d/wizard/meeting_room",                                                             
                "gm" : "/d/gumu/dating",                                                             
        ]));

        setup();
        setup();
        //replace_program(ROOM);
}