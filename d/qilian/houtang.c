//广场 by remove 15/09/2001
#include <ansi.h>
inherit ROOM;
void create()
{
     set("short", "当铺后堂");
     set("long", @LONG
这里是当铺的后堂，屋子里没有开窗户，只有桌上点着一盏小小的油灯。?
黑暗中你隐约看见桌后阴影里坐着一个人。
LONG);
     set("exits", ([
        "out" : __DIR__"dangpu",]));
     set("objects", ([
            __DIR__"npc/xixiashizhe" : 1]));
    set("no_clean_up", 1); 
    setup();
}


