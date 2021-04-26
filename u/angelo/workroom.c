#include <ansi.h>
  inherit ROOM;
void init();
int valid_leave();
void create()
{
          set("short", HIW"书房"NOR);
        set("long", @LONG
  这里是主人的书房. 靠墙的书柜里放满了四书五经. 在靠南的
墙上挂着一幅雨后荷花图. 书桌收拾的干干净净的.
LONG);
        set("exits", ([
                  "east" : "/u/angelo/livingroom",
                  "sl" : "/d/shaolin/guangchang1",
                "cy" : "/d/zhongnan/dadian",
                "sn" : "/d/shenlong/tingkou",
                "xi" : "/d/xixia/dawu",
                "hz" : "/d/hangzhou/kedian",
                "wud" : "/d/wudang/sanqingdian",
                "xk" : "/d/xiakedao/dadong",
                "xx" : "/d/xingxiu/xxh2",
                "gb" : "/d/gaibang/undertre",
                "gb2" : "/d/gaibang/gbxiaowu",
                "gy" : "/d/taihu/qianyuan",
                "kd" : "/d/city/kedian",
                "qz" : "/d/quanzhou/zhongxin",
                "hs" : "/d/huashan/pianting",
                "bt" : "/d/xingxiu/btyard",
                "dl" : "/d/dali/wangfu1", 
                "em" : "/d/emei/hz_guangchang",
                "xs" : "/d/xueshan/guangchang",
                "td" : "/d/taohua/jingshe",
               "hist" : "u/angelo/histroom",
]));
setup(); 
   call_other("/clone/board/angelo_b", "???");  
}
int valid_leave(object me, string dir)
{
          if ((string)me->query("id")!="angelo"){
   return notify_fail("不跟主人打声招呼就乱走不好吧! \n"); 
        }
  
        return ::valid_leave(me, dir);        return 1;
}
