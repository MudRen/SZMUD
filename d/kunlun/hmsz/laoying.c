// laoying.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
                  set("short", "灵獒营");
                  set("long",@long
你一踏进厅，便吃了一惊。但见三十余头雄健猛恶的大犬，分成三排，
蹲在地下，一个身穿纯白狐裘的女郎坐在一张虎皮椅上，手执皮鞭，
喝道：“前将军，咽喉！”一头猛犬急纵而起，向站在墙边的一个
人咽喉中咬去。
long);
                 set("exits",([
"out" : __DIR__"tingwai",
]));

set("objects",([
                __DIR__"npc/zjzhen" :  1,
]));
              setup();
              replace_program(ROOM);
}
