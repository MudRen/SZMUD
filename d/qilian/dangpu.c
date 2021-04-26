//广场 by remove 15/09/2001
#include <ansi.h>
inherit ROOM;
void create()
{
     set("short", "铁面当铺");
     set("long", @LONG
这是家远近闻名的当铺，三开间的门面，一块写着『铁面当铺』
四个金字的黑匾，足足七尺高的紫檀木的柜台(desk)被磨的光可照人。
柜台后面有五个柜子，分别陈列着各式武器(weapon)、护具穿戴(armor)、
药物(drug)、书籍(book)、和其它各式杂物(misc)。柜台后的老朝奉头
也不抬的只顾拨拉着算盘，柜台上方挂着一块牌子，上书∶「你情我愿，
概不赊欠」。
LONG);
     set("no_clean_up", 0);
     set("no_beg", 1);     
     set("exits", ([  /* sizeof() == 2 */
           "west" :  __DIR__"lanzhou",]));
     set("objects", ([
                __DIR__"npc/chaofeng" : 1,]));
     
     setup();
    replace_program(ROOM);
}
 /* 
   void init()
{
     add_action("do_knock", "knock");
}
int do_knock(string arg)
{
     object me;
     me = this_player();
     if ( arg == "desk" )
     {  message_vision("$N右手在柜台上轻扣几下，又对老朝奉轻声说了几句。老朝奉象变了个人似的，恭恭敬敬把$N请进了后堂。\n",me); 
     me->move(__DIR__"houtang");
     me->start_busy( 0 );return 1;}
     return notify_fail("你要敲什么？\n");              
}
*/





