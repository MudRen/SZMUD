// by remove /16/09/2001
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "书房");
        set("long", @LONG
这里是武馆收藏各门各派武功密籍的地方。
LONG);
        set("exits", ([              
             "north" : __DIR__"guangchang"]));
        set("no_fight", 1);
        set("no_steal", 1);
        set("no_hit", 1);
        set("cost", 1);
        setup();
 
//replace_program(ROOM);
}void init()
{
        object *inv, me = this_player();
        int i, j=0;
        inv = all_inventory(me);
        for (i=0; i<sizeof(inv); i++)
         {
           if((string)inv[i]->me_query("id")=="book") j++;
           }
           me->set_temp("getbooks", j);
}
int valid_leave(object me,string dir)
{
        object *inv;
        int i, j=0;
        inv = all_inventory(me);
        for (i=0; i<sizeof(inv); i++)
         {
          if((string)inv[i]->me_query("id")=="book") j++;
           }
         if ( j == (int)me->query_temp("getbooks")+1 )                me->set_temp("wuguan/密籍", 1);
         if ( j == (int)me->query_temp("getbooks")+1 )
      return notify_fail("你不能那么黑心，一次拿走那么多书。\n");
         return ::valid_leave(me, dir);

}


