// kuayuan.c 沁涟宫、跨院
// snowlf by 2001.09.17
// snowlf change of 2001.9.30 (add board)  
#include <room.h>
#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
        set("short",HIG"跨院"NOR);
        set("long","西出正厅，穿过月亮门到跨院，迎门一道翠玉屏风，遮住院内的景物。不时
有嘻闹和欢笑声从院中传出。上面立著两只可爱的白色鸽子。从两侧饶过屏风可
进到院内。
    
"NOR);

        set("valid_startroom",1);
        
        set("exits", ([
         	"left" : __DIR__"neiyuan",
		"right" : __DIR__"neiyuan",
		"east" : "/u/snowlf/workroom",

		
        ]));


        set("valid_startroom",1);
        set("no_clean_up",0);
        set("no_fight",1);
        set("no_steal",1);
        set("objects",([ 
                __DIR__"npc/gezi":2,                
       
	])); 
        setup();

}
