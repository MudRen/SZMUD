#include <ansi.h> 
inherit ROOM;

void create() 
{ 
set("short",HIB"��"HIC"���µ�һ¥"NOR+HIB"��"NOR); 
set ("long", 
"

         "HIY"��"NOR"    "HIC"һ"NOR"    "HIR"��"NOR"    "WHT"��"NOR"      
         "HIY"��"NOR"    "HIC"��"NOR"    "HIR"��"NOR"    "WHT"��"NOR"                   
         "HIY"�"NOR"    "HIC"��"NOR"    "HIR"��"NOR"    "WHT"��"NOR"                      
         "HIY"��"NOR"    "HIC"��"NOR"    "HIR"��"NOR"    "WHT"��"NOR"                        
         "HIY"��"NOR"    "HIC"��"NOR"    "HIR"��"NOR"    "WHT"ǳ"NOR"                                 
         "HIY"��"NOR"    "HIC"��"NOR"    "HIR"��"NOR"    "WHT"ˮ"NOR"                                           
         "HIY"��"NOR"    "HIC"��"NOR"    "HIR"��"NOR"    "WHT"��"NOR"                                                

                                          
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
return notify_fail("����ֻ����ʦ���ܽ�ȥ��\n");
        return ::valid_leave(me, dir); 
}