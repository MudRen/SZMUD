// final的小小房子

#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
	set("short",REF ""HIC"修罗仙境" NOR);
	set("long",	"
	"HIC"天"YEL"地"HIW"乾坤"NOR","HIM"唯我"HIG"修罗仙境。"NOR"

    "HIW"乾坤"HIG"仙境"U"正坛"NOR"，"CYN"想去便去，"YEL"正之道。

"HIC"------------------------------------------------------        
""			"HIW"乾坤
	"HIM"东海桃花(th)  "NOR"扬州丐帮(gb)  "HIG"云南大理(dl)"NOR"
		--------------------
			 "HIC"乾
  "YEL"   武当(wd)  全真(qz)  少林(sl)  华山(hs)  峨嵋(em)
	       "NOR" --------------------
			 "WHT"坤
	 "YEL"星宿(xx)  雪山(xs)  血刀(xd)  白陀(bt)
"HIC"------------------------------------------------------
			"HIW"OTHER
------------------------------------------------------
扬州(yz)  杭州(hz)  西夏(xi)  泉州(ql)  佛山(fs)
嘉兴(jx)  太湖(gy)  伊离(yl)  兰州(lz)  三不管(sbg)
北京(bj)  南洋(ny)  雪地(xd)  长白(cb)  黑木崖(hm)
大理(dl)  衡山(hx)  昆仑(kl)  慕容(mr)  神龙(so)

"NOR""	);
	set("no_fight", 1);
	set("objects", ([
		__DIR__"yumiko" : 1,
	]));
					      
	set("valid_startroom",1);
					      
	set("exits", ([
              //  "kl" : "/d/kunlun/wall5",
			  "zn" : "/d/zhongnan/dadian",
			    "f"	 :	"/d/final/pingyuan1",
				"kl" :  "//d/kunlun/damen",
                "sl" : "/d/shaolin/smdian",
                "sn" : "/d/shenlong/tingkou",
                "xi" : "/d/xixia/dawu",
                "hz" : "/d/hangzhou/kedian",
                "wd" : "/d/wudang/sanqingdian",
                "xx" : "/d/xingxiu/xxh2",
                "gb" : "/d/gaibang/undertre",
                "gy" : "/d/taihu/qianyuan",
                "hs" : "/d/huashan/buwei1",
                "bt" : "/d/xingxiu/btyard",
                "dl" : "/d/dali/wangfu1",
                "em" : "/d/emei/hz_guangchang",
                "xs" : "/d/xueshan/guangchang",
				"th" : "/d/taohua/shuilong",	
				"yz" : "/d/city/kedian",
                "qz" : "/d/quanzhou/zhongxin",
                "hs" : "/d/huashan/buwei1",
                "bt" : "/d/xingxiu/btyard",
                "dl" : "/d/dali/wangfu1",
                "em" : "/d/emei/hz_guangchang",
                "xs" : "/d/xueshan/guangchang",
                "wr": "/d/wizard/meeting_room",                                                             
	]));

	setup();
	//replace_program(ROOM);
}

void init()
{
	object me = this_player();

	if( wizardp(me) && getuid(me)!="final ")
		message("vision", me->name()+"走了过来。\n", environment(me), ({me}));

	add_action("do_leave", "leave");
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me))
		return notify_fail("温晓萌挡在你面前，恭身说道：“非常抱歉，您不能到那儿去。”\n");

	return ::valid_leave(me, dir);
}

int do_leave()
{
	object me = this_player();
	if(me)
		me->move("/d/city/wumiao");
	return 0;
}

