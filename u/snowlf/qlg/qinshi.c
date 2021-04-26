// qinshi.c   沁涟宫/水榭
// snowlf by 2001.12.18

#include <room.h>
#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
        set("short",HIM"琴室"NOR);
        set("long","沿池畔蜿蜒前行，至此已是最东，为一水榭。水面盈尺一小桥可达对岸"+HIC+"【仙
人掌之家】"+NOR+"，东北向入池，及池心，有桥拱如半月，下可行舟。凭栏相看，荷塘
佳色尽收眼底。西向可回正厅，转北复西向，即至花园。

    "+HIM+"徐徐轻风拂面，空气中的清香让人心旷神怡！
    
"NOR);

        set("valid_startroom",1);
        
        set("exits", ([

		"west" : __DIR__"jiuqu1",
		"northwest" : __DIR__"jiuqu2",
		"northeast" : "/u/xrz/workroom",
        ]));

        set("item_desc", ([
                        "lotus flower": "接天莲叶无穷碧，映日荷花别样红！\n",
			"荷塘佳色": "接天莲叶无穷碧，映日荷花别样红！\n",
                        ]));     
        set("valid_startroom",1);
        set("no_clean_up",0);
        set("no_fight",0);
        set("no_steal",1);
        set("objects",([ 
                __DIR__"npc/gongnu3":1,                
       
]));
        setup();

}
