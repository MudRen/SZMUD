// Code by Felix
// Room: /u/felix/workroom.c

inherit ROOM;
#include <ansi.h>
#include <room.h>
void reset();
int valid_leave();

void create()
{
                  set("short", HIG"思远阁"NOR);
                  set("long", @LONG
这里有我童年的记忆，一扇大大而又明亮的玻璃窗，那是
每晚月亮偷窥我的必经之路。一盏昏黄得能给瞌睡虫催眠的台
灯。不知道是谁的眼泪把墙壁涂成了粉蓝色，让这颗坚强跳动
着的心的步伐更加凌乱。那窗前的风铃就像我的思念一样，只
要有一丝风便会叮叮当当的撕扯着我的心，牵动着它去寻找远
方的她。
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
                "wz" : "/d/wizard/wizard_room",
                "dl" : "/d/dali/wangfu1", 
                "em" : "/d/emei/hz_guangchang",
                "xs" : "/d/xueshan/guangchang",
				"syj" : "/u/felix/syj",
        ]));

	  //	set("objects", ([
	  //	   	"/clone/board/felix_b.c" : 1,
      //          __DIR__"obj/renshen-guo" : 1,
      //          __DIR__"obj/atm" : 1,
      //          __DIR__"npc/yahuan.c" : 1,
	  //		]));


set("valid_startroom",1);

        setup();

		call_other("/clone/board/felix_b", "???");

}
int valid_leave(object me, string dir)
{
                  if ( !wizardp(me) && dir!="up" ){
                                         return notify_fail("丫环一把揪住你的衣领说：“慢着，你脑袋没留下怎麽能走！”\n");
        }
        return ::valid_leave(me, dir);
}