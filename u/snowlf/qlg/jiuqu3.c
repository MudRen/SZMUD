// jiuqu2.c   沁涟宫/九曲回廊
// snowlf by 2001.12.18

#include <room.h>
#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
        set("short",HIW"九曲回廊"NOR);
        set("long","
    回廊沿池畔蜿蜒而建，但见廊腰缦回，檐牙高啄，内侧是花园，外临荷花
池。由此北行转西，至尽头处一观荷小亭。名【沁心】。南行转西可入书斋，
转东可至琴室，东向尽头为一水榭。
   
    "+HIM+"徐徐轻风拂面，空气中的清香让人心旷神怡！  
"NOR);

        set("valid_startroom",1);
        
        set("exits", ([
         	
		"west" : __DIR__"huayuan",
		"south" : __DIR__"jiuqu2",
		"northwest" : __DIR__"qingxinting",  
        ]));

        set("item_desc", ([
                        "lotus flower": "接天莲叶无穷碧，映日荷花别样红！\n",
			"荷塘佳色": "接天莲叶无穷碧，映日荷花别样红！\n",
                        ]));     
        set("valid_startroom",1);
        set("no_clean_up",0);
        set("no_fight",0);
        set("no_steal",1);

        setup();

}
