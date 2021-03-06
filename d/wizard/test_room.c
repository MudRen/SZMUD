// Room: /d/wizard/test_room.c
inherit ROOM;
#include <ansi.h>
void reset();
int valid_leave();
// changed by huaishi 8-15-2001

void create()
{
        set("short", HIW"测试组工作室"NOR);
        set("long", "
    这是测试组的休息室。房间的地板上放着各式各样的破烂和工具。不断地有
人在敲门，劳拉气急败坏地在房间里喊道：别催，我现在正忙着！有什么新活，
就在听到嘟一声后，开始在白板上留言！
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
                "west" : "/d/wizard/wizard_room",
                "tianan" : "/d/beijing/zijin/tiananmen",
        ]));    
     
        set("no_fight", "1");
        set("no_steal", 1);
        set("no_sleep_room", "1");           
        set("valid_startroom",1);            
        setup();
        call_other("/clone/board/test_b", "???");
        
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

