// huayuan.c   沁涟宫/花园
// snowlf by 2001.12.19

#include <room.h>
#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
        set("short",HIG"花园"NOR);
        set("long","
    漫步园中，庭院清幽，异种花卉甚是不少。百花争放，山石古拙，杨
柳垂清，苍松翠竹，景致煞是宜人。清澈的溪流旁耸立着一座小亭子。
    憨˙堕い畑皘睲钵贺琌ぃぶκホ╁法
琱睲籥肞籄λ春璓焚琌﹜睲韩匪瑈羜ミ帝畒獸

    "+HIM+"徐徐轻风拂面，空气中的清香让人心旷神怡！
"NOR);

        set("valid_startroom",1);
        
        set("exits", ([
		"enter" : __DIR__"qingxinting",  
		"south" : __DIR__"study",
		"east" : __DIR__"jiuqu3",
		"west" : __DIR__"jiuqu4",
		"southwest" : __DIR__"jiuqu5",
		"northwest" : __DIR__"jiuqu2",		
        ]));

        set("item_desc", ([
                        "lotus flower": "接天莲叶无穷碧，映日荷花别样红！\n",
			"荷塘佳色": "接天莲叶无穷碧，映日荷花别样红！\n",
			"south": "
书斋 - /u/xrz/snowlf/study

    书斋门楹上题着一副对联：   
    
	     		灯火夜深书有味  
	     		墨花神湛字生光
    
    推门而入，但见正对门的方向有一张"+HIW+"书桌"+NOR+"(desk)，旁边靠墙两个大书
架上放满了书，桌上放著一盆"+HIR+"珊瑚"+NOR+"盆景，屋顶镶嵌一颗硕大的"+HIW+"夜明珠"+NOR+"(yemingzhu)。

    这里明显的出口是 west 和 out"
                        ]));     
        set("valid_startroom",1);
        set("no_clean_up",0);
        set("no_fight",0);
        set("no_steal",0);
        setup();

}
