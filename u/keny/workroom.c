#include <ansi.h> 
inherit ROOM;

void create() 
{ 
set("short",HIB"【"HIC"天下第一楼"NOR+HIB"】"NOR); 
set ("long", 
"

         "HIY"金"NOR"    "HIC"一"NOR"    "HIR"九"NOR"    "WHT"风"NOR"      
         "HIY"鳞"NOR"    "HIC"遇"NOR"    "HIR"霄"NOR"    "WHT"云"NOR"                   
         "HIY"蚩"NOR"    "HIC"风"NOR"    "HIR"龙"NOR"    "WHT"际"NOR"                      
         "HIY"是"NOR"    "HIC"云"NOR"    "HIR"吟"NOR"    "WHT"会"NOR"                        
         "HIY"池"NOR"    "HIC"便"NOR"    "HIR"惊"NOR"    "WHT"浅"NOR"                                 
         "HIY"中"NOR"    "HIC"化"NOR"    "HIR"天"NOR"    "WHT"水"NOR"                                           
         "HIY"物"NOR"    "HIC"龙"NOR"    "HIR"变"NOR"    "WHT"游"NOR"                                                

                                          
"
);

set("exits", ([
"down" : __DIR__ "misc", 
"east" : "/d/city/guangchang", 
"out" : "/d/wizard/wizard_room",
"kl" : "/d/kunlun/sanshengtang", 
]));
set("valid_startroom",1); 
set("no_clean_up",1); 
set("no_steal",1); 
setup();
}

int valid_leave(object me, string dir)
{
        if( dir!="down" && !wizardp(me) )
return notify_fail("那里只有巫师才能进去。\n");
        return ::valid_leave(me, dir); 
}
