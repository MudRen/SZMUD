// Code by Felix
// Room: /u/mafu/workroom.c

inherit ROOM;
#include <ansi.h>
#include <room.h>
void reset();
int valid_leave();

void create()
{
                  set("short", HIW"mafu �Ĺ�����"NOR);
                  set("long", @LONG
���������������������ʦ mafu �Ĺ������ˡ�
----------------------------------------------------
  ����: sl  �䵱: wn  ����: xx  ؤ��: gb  ����: bt
  ��ɽ: hs  ����: xk  �͵�: kd  ѩɽ: xs  ����: em
  ����: dl  ����: sn  ����: xi  �һ�: td  ����: gy
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
