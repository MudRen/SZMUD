#include <ansi.h>
  inherit ROOM;
void init();
int valid_leave();
void create()
{
        set("short", HIG"观荷小筑"NOR);
        set("long", @LONG
只见门沿上挂着一串用竹子做的风铃,用力一摇会发出低沉的梆梆梆的声音。
左的门柱上订着一块牌子上面秀气的用楷书写着四个字--观荷小筑,透过篱笆往
里望去只见一大片密密麻麻的荷花围绕着那临水而建的楼阁。
LONG);
        set("exits", ([
                "enter" : "/u/angelo/livingroom",
                "east" : "/d//hangzhou/louwlou",
                "down" : "/d//yangzhou/kedian",
                      "west" : "/u/fanren/workroom", 
               "hist" : "u/angelo/histroom",
]));
setup(); 
   call_other("/clone/board/angelo_b", "???");  
  
}
