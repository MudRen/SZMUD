// Code by Felix
// Room: /u/mafu/workroom.c

inherit ROOM;
#include <ansi.h>
#include <room.h>
void reset();
int valid_leave();

void create()
{
                  set("short", HIW"mafu 的工作室"NOR);
                  set("long", @LONG
这里就是神州里最懒的巫师 mafu 的工作室了。
----------------------------------------------------
  少林: sl  武当: wn  星宿: xx  丐帮: gb  白驼: bt
  华山: hs  侠客: xk  客店: kd  雪山: xs  峨嵋: em
  大理: dl  神龙: sn  西夏: xi  桃花: td  归云: gy
----------------------------------------------------
LONG
);





                  set("exits", ([
                "sl" : "/d/shaolin/guangchang1",
                "sn" : "/d/shenlong/tingkou",
                "xi" : "/d/xixia/dawu",
                "hz" : "/d/hangzhou/kedian",
                "wn" : "/d/wudang/sanqingdian",
                "xk" : "/d/xiakedao/dadong",
                "xx" : "/d/xingxiu/xxh2",
                "gb" : "/d/gaibang/undertre",
                "gb2" : "/d/gaibang/gbxiaowu",
                "gy" : "/d/taihu/qianyuan",
                "kd" : "/d/city/kedian",
                "qz" : "/d/quanzhou/zhongxin",
                "hs" : "/d/huashan/pianting",
                "bt" : "/d/xingxiu/btyard",
                "wr" : "/d/wizard/meeting_room",
                "dl" : "/d/dali/wangfu1", 
                "em" : "/d/emei/hz_guangchang",
                "xs" : "/d/xueshan/guangchang",
        ]));

	  //	set("objects", ([
	  //	   	"/clone/board/felix_b.c" : 1,
      //          __DIR__"obj/renshen-guo" : 1,
      //          __DIR__"obj/atm" : 1,
      //          __DIR__"npc/yahuan.c" : 1,
	  //		]));


set("valid_startroom",1);

        setup();

		call_other("/clone/board/mafu_b", "???");

}
