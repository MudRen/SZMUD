#include <room.h>
#include <ansi.h>
//Cracked by smzz
// xiulianshi.c 沙家正厅
 // by Xiang 

inherit ROOM;

void create()
{
set("short", HIM"沙家大厅"NOR);
set("long",
"这里是沙家正厅，你的头顶是一个非常大的吊灯，把整个大厅照的通亮\n"
"东边是卫生间，可以去那里方便有什么秘密活动就去那里吧,要注意关门哦。\n"
"北边好像是沙漠之子的书房吧，里面好象有好多的书．不过你是不能带走的\n"
"外面就是沙漠之子的办公室．你一抬头就可以看见墙上的正中挂着一块匾东\n" 
"边一扇盼盼牌"HIW"玻璃门"NOR"(door)对着那块匾让人觉得格局很合理\n"
" "BLINK+MAG"------------------\n"NOR
""MAG"|"NOR+BLINK+HIW"沙漠浩瀚 友邦世交 "NOR+MAG"|\n"NOR
" "BLINK+MAG"------------------\n"NOR
);
set("exits", ([ "out":"/u/smzz/workroom",
"north":__DIR__"shufang",
"east":"u/smzz/wsj",
"up":__DIR__"louti1",
]));     set("objects", ([ 
          "u/smzz/coffee.c" : 1,
          "u/smzz/ojuice.c" : 1 ]));
set("cost", 1);
set("item_desc",
([
"door":"这是一扇中国制造的盼盼派玻璃门,看起来很结实你可以open打开它\n"
]));
set("invalid_startroom", 1); 
set("cost", 3);
create_door("east", "木门", "west", DOOR_CLOSED); 
          setup();
          replace_program(ROOM);
}
