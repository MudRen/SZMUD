// Room: /d/wizard/wizard_room.c
// huaishi Aug 14, 2001
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIY"黄金大殿"+NOR);
        set("long", @LONG
这里是一座黄金的殿堂，十分雄伟，黄琉璃瓦闪烁金光。前檐有七尺深，斗
拱、飞檐、彩绘承尘，四根一人抱不住的朱漆柱子。殿里正中间放着巨大的红木
圆桌，桌上凌乱地放着一叠叠的设计图纸与文稿，其中最引人注目的是一本缎子
面的小册子，上面书写着三个楷体「功勋册」(ce)。
LONG
        );
        set("exits", ([ 
                  "job" : "/d/wizard/job_room",
                  "up"  : "/d/wizard/meeting_room",
                  "gm"  : "/d/gumu/dating",
                  "mp"  : "/d/wizard/smiling_room",                  
                  "wg"  : "/u/zyu/workroom",                  
                  "cl"  : "/d/forest/clxiaoting",                  
                  "test"  : "/d/wizard/testroom",                  
                  "down"  : "/d/wizard/guest_room",                  

]));
        
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("cost", 0);
        setup();
        call_other("/clone/board/wiz_b", "???");
}

void init()
{
        object me = this_player();

        if (wizhood(me) == "(player)")
                me->move("/d/death/death.c");
}
