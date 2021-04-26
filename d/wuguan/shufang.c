// by remove /16/09/2001
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "大书房");
        set("long", @LONG
这是一个非常宽畅的大书房，靠墙一排又一排的书架上，整整齐齐地
摆满了书。书房中央摆放着一张大木桌和一些木条凳，桌上整齐地罗放着
几本经文诗书选集。
LONG);
        set("exits", ([              
             "north" : __DIR__"qianting"]));
        set("objects", ([
                    __DIR__"obj/sanzijing" : 2,                   
                    __DIR__"obj/qianziwen" : 2,]));
        set("no_steal", 1);
        set("no_hit", 1);
        set("cost", 0);
        setup();
 
//replace_program(ROOM);
}

int valid_leave(object me,string dir)
{
        object *inv;
        int i, aa, bb;      
        inv = all_inventory(me);
        for (i=0; i<sizeof(inv); i++)
         {
          if ((string)inv[i]->query("id")=="sanzi jing") aa++;
          if ((string)inv[i]->query("id")=="qianzi wen") bb++;       
         }          
         if ( (aa + bb) >1 )
                     return notify_fail("你太黑心了，不能带走那么多书。\n");
         return ::valid_leave(me, dir);

}




