#include <ansi.h>
  inherit ROOM;
void init();
int valid_leave();
void create()
{
          set("short", HIW"�鷿"NOR);
        set("long", @LONG
  ���������˵��鷿. ��ǽ�����������������徭. �ڿ��ϵ�
ǽ�Ϲ���һ�����ɻ�ͼ. ������ʰ�ĸɸɾ�����.
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
   return notify_fail("�������˴����к������߲��ð�! \n"); 
        }
  
        return ::valid_leave(me, dir);        return 1;
}
