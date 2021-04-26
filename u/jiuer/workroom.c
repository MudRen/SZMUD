 // WizRoom: workroom.c
 // Jiuer/8/01/2000
// new here

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"诗园"NOR);
	set("long", @LONG

※※※※※※※※※※※※※※※※※※※※※※※※※※※※※	
※　　　　　　　　　　　　　　　　　　　　　　　　　　　※　
※　这里曾是我默默劳作的地方  这里曾是我品尝成功的乐园  ※ 
※　　　　　　　　　　　　　　　　　　　　　　　　　　　※
※　这里我们的感慨撒落到穹宇  这里我们的欢笑回荡着四壁  ※
※　　　　　　　　　　　　　　　　　　　　　　　　　　　※
※※※※※※※※※※※※※※※※※※※※※※※※※※※※※

LONG);
        set("valid_startroom",1);	
	    set("quickquit", 1);       
	    set("exits", ([ 
			"hs"  : "/d/huashan/pianting",
			"qzhou"  : "/d/quanzhou/zhongxin",
			"yz"  : "/d/city/kedian",
			"qz" : "/d/zhongnan/taijie2",
			"ts"  : "/d/taishan/fengchan",
			"sl"  : "/d/shenlong/dating",
			"wud" : "/d/wudang/sanqingdian",
			"gb"  : "/d/gaibang/undertre",
			"xx"  : "/d/xingxiu/xxh2",
			"em"  : "/d/emei/hz_guangchang",
			"bt"  : "/d/baituo/btyard",
			"xs"  : "/d/xueshan/guangchang",
			"kl"  : "/d/kunlun/guangchang",
			"bj"  : "/d/beijing/changanjie",
			"xi"  : "/d/xixia/dawu",
			"gy"  : "/d/taihu/qianyuan",
			"dl"  : "/d/dali/wangfu1",
			"hz"  : "/d/hangzhou/kedian",
			"gm"  : "/d/gumu/dating",
			"wr"  : "/d/wizard/wizard_room",
]));
      setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && dir != "yz")
		return notify_fail("你没事乱跑什么? \n");
	return ::valid_leave(me, dir);
}

