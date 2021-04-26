inherit ROOM;
#include <room.h>
#include <ansi.h>
void create () 
{ 
set ("short", HIG"银狐爱巢"NOR); 
  set ("long", @LONG 
无所不能为
LONG);
set("exits", ([
        "kd" : "/d/city/kedian",
        "kl" : "/d/kunlun/sanshengtang",
        "dl" : "/d/dali/wangfu1",
        "hs" : "/d/huashan/pianting",
        "wz" : "/d/wizard/wizard_room",
        "em" : "/d/emei/hz_guangchang",
        "xs" : "/d/xueshan/guangchang",
        "bt" : "/d/xingxiu/btyard",
        "xa" : "/d/xixia/dawu",
        "qz" : "/d/zhongnan/dadian",
        "sl" : "/d/shaolin/guangchang1",
        "xx" : "/d/xingxiu/xxh2",
        "gb" : "/d/gaibang/gbxiaowu",
        "mj" : "/d/mingjiao/damen",
        "gm" : "/d/zhongnan/gumu",
        "wg" : "/d/wudang/xiaoyuan",
        "th" : "/d/taohua/hyjuchu",
        "gy" : "/d/taihu/shufang",
            "down" : "/d/city/guangchang",
                        ]));
set("no_fight", "1");
        set("no_steal", "1");
        set("no_sleep_room", "1");
set("valid_startroom", 1);
setup(); 
}
int valid_leave(object me, string dir)
{
          if (this_player()->query("id") != "earl" && dir != "down")
                return notify_fail(RED"主人没叫你走呢！\n"NOR);
        return 1;
}
