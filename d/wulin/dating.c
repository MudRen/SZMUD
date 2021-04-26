//piao 2001/10/16
//room: /d/wulin/dating.c
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "英雄大厅");
        set("long", @LONG
英雄大厅是武林同盟最为宏伟的建筑，大厅四角由四根巨大的石柱支
撑，厅内点着三百六十支松枝做的火把，常年灯火通明，地上铺着整齐的
大理石，中间一条崭新的红地毯，地毯的尽头放着一张金壁辉煌的椅子，
椅子后面的墙上写着一个大大的“义”字。武林同盟的宗旨就是个“义”
字，锄恶扬善，舍生取义。大厅周围尽是汉白玉的浮雕，记录着前辈英侠
们赏善罚恶的英雄事迹，只要你努力，你的事迹也可能进入这些浮雕，为
后世英雄所景仰。
LONG
        ); 
       
        set("exits",([
                "north" : __DIR__"houyuan",                 
                "south" : __DIR__"zhengqiting",
                "west" : __DIR__"shishe",                 
                "east" : __DIR__"jiulu",
        ]));   

        set("objects",([
                __DIR__"npc/yishi1" : 1,
        ]));
                set("no_fight", "1");
                set("cost", 1);
                setup();
//              replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
       
        object *inv;
        int i;
        inv = all_inventory(me);//传回me身上所有的物品
        if( dir == "north"&&!wizardp(me)) { 
                if(!me->query_temp("houyuan") )
                return notify_fail(CYN"武林同盟义士拦住你，说道：阁下并没受到仙人的邀请, 不得进入后园, 还是请回吧。\n"NOR);
;
      }      
        for (i=0; i<sizeof(inv); i++) {  
                if (inv[i]->is_character())
                return notify_fail(CYN"你不能带着其他玩家进去。\n"NOR);
       
        }         

//      me->delete_temp("houyuan");
        return ::valid_leave(me, dir);
}             

