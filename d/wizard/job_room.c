// Room: /d/wizard/job_room.c
inherit ROOM;
#include <ansi.h>
void reset();
int valid_leave();
// by hongh 7-30-2001

void create()
{
        set("short", HIW"游戏组工作室"NOR);
        set("long", "
    这里是【神州】的任务控制室，巫师正在测试各种任务,中间的桌子上
摆着一本进度报告(Board)，有几位巫师正在记录自己的工作进程.
"

        );

        set("exits", ([
                "sl" : "/d/shaolin/guangchang1",
                "sn" : "/d/shenlong/tingkou",
                "xi" : "/d/xixia/dawu",
                "wd" : "/d/wudang/sanqingdian",
                "xx" : "/d/xingxiu/xxh2",
                "gb" : "/d/gaibang/undertre",
                "gy" : "/d/taihu/qianyuan",
                "kd" : "/d/city/kedian",
                "qz" : "/d/quanzhou/zhongxin",
                "hs" : "/d/huashan/pianting",
                "bt" : "/d/xingxiu/btyard",
                "dl" : "/d/dali/wangfu1", 
                "em" : "/d/emei/hz_guangchang",
                "xs" : "/d/xueshan/guangchang",
                "td" : "/d/taohua/jingshe",
                "east" : "/d/wizard/wizard_room",
                "tianan" : "/d/beijing/zijin/tiananmen",
        ]));    
     
        set("no_fight", "1");
        set("no_steal", 1);
        set("no_sleep_room", "1");           
        set("valid_startroom",1);            
        setup();
        call_other("/clone/board/job_board", "???");
        
}

void init()
{
        add_action("do_exercise",  "exercise");
        add_action("do_exercise",  "lianqi");
        add_action("do_exercise",  "lianneili");
        add_action("do_exercise",  "dazuo");
        add_action("do_exercise",  "respirate");
        add_action("do_exercise",  "tuna");
        add_action("do_practice",  "practice");
        add_action("do_practice",  "lian");
        add_action("do_study",  "study");
        add_action("do_study",  "du");
}

int do_exercise(string arg)
{
        object me = this_player();
        tell_object(me, "你是来工作还是来练功啊？\n");
        return 1;
}

int do_practice(string arg)
{
        object me = this_player();
        tell_object(me, "在人家的地盘里也想练功，太放肆了吧？\n");
        return 1;
}

int do_study(string arg)
{
        object me = this_player();
        tell_object(me, "工作时还想练功，别这么认真好不好？\n");
        return 1;
}

