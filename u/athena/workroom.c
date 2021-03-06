// 苏梦馨(Athena)
// Room：/u/athena/workroom.c

#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
       set("short",MAG"夢馨小筑" NOR); 
       set("long", 
"这是一座富丽堂皇的大宅院，两头高大的石狮子镇住了大门
两侧，大门上的朱漆足足有三寸厚。门上一张匾，上书"CYN"“"NOR""NOR+BLINK+HIG"苏府"NOR""CYN"”"NOR" 
两个大字。
"HIY"-------------------------------------------------------"NOR"
华山"HIG":"NOR""HIC"hs"NOR" 全真"HIG":"NOR""HIC"qz"NOR" 杨州"HIG":"NOR""HIC"yz"NOR" 泰山"HIG":"NOR""HIC"ts"NOR" 少林"HIG":"NOR""HIC"sl"NOR" 武当"HIG":"NOR""HIC"wn"NOR" 神龙"HIG":"NOR""HIC"sn"NOR" 
丐帮"HIG":"NOR""HIC"gb"NOR" 星宿"HIG":"NOR""HIC"xx"NOR" 峨嵋"HIG":"NOR""HIC"em"NOR" 白驼"HIG":"NOR""HIC"bt"NOR" 雪山"HIG":"NOR""HIC"xs"NOR" 昆仑"HIG":"NOR""HIC"kl"NOR" 北京"HIG":"NOR""HIC"bj"NOR"  
西夏"HIG":"NOR""HIC"xi"NOR" 归云"HIG":"NOR""HIC"gy"NOR" 大理"HIG":"NOR""HIC"dl"NOR" 杭州"HIG":"NOR""HIC"hz"NOR" 古墓"HIG":"NOR""HIC"gm"NOR" 巫师"HIG":"NOR""HIC"wr"NOR" 桃花"HIG":"NOR""HIC"th"NOR":
"HIY"-------------------------------------------------------"NOR"\n");

        set("no_fight", 1);
        set("valid_startroom",1);
        set("exits", ([ /* sizeof() == 3 */
                  "hs"  : "/d/huashan/buwei1",
                  "qz"  : "/d/zhongnan/taijie2",
                  "yz"  : "d/city/kedian",
                  "ts"  : "/d/taishan/fengchan",
                  "north"  : "/u/athena/liuyuan",
                 "bt"  : "/d/baituo/btyard",
                  "sl"  : "/d/shaolin/guangchang1",
                  "wn"  : "/d/wudang/sanqingdian",
                  "sn"  : "/d/shenlong/tingkou",
                  "gb"  : "/d/gaibang/undertre",
                  "xx"  : "/d/xingxiu/xxh2",
                  "em"  : "/d/emei/hz_guangchang",
                  "xs"  : "/d/xueshan/guangchang",
                  "kl"  : "/d/kunlun/sanshengtang",                      
                  "bj"  : "/d/beijing/changanjie",
                  "xi"  : "/d/xixia/dawu",
                  "gy"  : "/d/taihu/qianyuan",
                  "dl"  : "/d/dali/wangfu1",
                  "hz"  : "/d/hangzhou/kedian",
                  "gm"  : "/d/gumu/dating",
                 "wr"  : "/d/wizard/wizard_room",
                  "th"  : "/d/taohua/jingshe",
]));
        set("objects", ([
                __DIR__"npc/meir" : 1,
                __DIR__"obj/bamboo" : 1,
]));
     call_other("/clone/board/athena_b", "???");


         setup();
        //replace_program(ROOM);
}

void init()
{
        object me = this_player();

        if( wizardp(me) && getuid(me)!="athena ")
                message("vision", me->name()+"走了过来。\n", environment(me), ({me}));

        add_action("do_leave", "leave");
        add_action("do_qu", "qu");
}

int valid_leave(object me, string dir)

{
        if (!wizardp(me))
                return notify_fail("枚儿揪住你的衣领说道：“慢着，想走没那么容易！”\n");

        return ::valid_leave(me, dir);
}

int do_leave()
{
        object me = this_player();
        if(me)
                me->move("/d/city/wumiao");
        return 1;
}

int do_qu(string arg) {
        object me;

        me=this_player();
        if( !arg )
                return notify_fail("去哪里？\n");
        
        if( file_size("/u/"+arg + "/workroom.c") <= 0 )
                return notify_fail("现在还没有那个地方。\n");
        message_vision(HIW"$N挥一挥衣袖，不带走一片泥土。\n"NOR,
                this_player());
        this_player()->move("/u/"+arg+"/workroom");             
        message_vision(HIC"$N突然出现在一阵烟雾中。\n"NOR,me);
        return 1;
}
