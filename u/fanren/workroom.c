#include <ansi.h>
inherit ROOM;
void create()
{
             set("short", "风之陋室");
        set("long", @LONG
这里是风满楼的工作室,里面黑忽忽的,只有一盏昏暗的小灯,桌上和
房子能不能承受的起一场大风雪,走近一看,墙上各个角落都布满了蜘蛛丝,
也不知道这里主人到底在忙什么。在那盏昏暗的灯光下竟摆放着一台连着
Motorola V70手机的IBM笔记本电脑,屏幕上显示着----神州。
LONG);
        set("exits", ([
                  "down" : "/d/city/guangchang",
         "west" : "/d/wizard/wizard_room",

]));
              set("objects",([
           "/u/fanren/npc/muren" : 1,
                 "/u/fanren/npc/singer" : 1,
 ]));
         call_other("/clone/board/fanren_b", "???"); 
                 set("no_sleep", 1);
setup(); 
}
