//By oytj 2002.08.05

#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIW"雨后彩虹"NOR);
  set ("long",HIW"

望能如雲 隨風而飛\n"HIC

"              
                      如果蓝色 \n
                   一段橙色的回忆
                   一次蓝色的洗礼
                   一回心灵的远航
                   在幸福中搁浅....
                   记得，那年那月，我曾遗失了很多东西
                   记得，那年那月，我还带走了一份牵挂
                   记得，那年那月，雨后出现了一道彩虹\n"NOR"


    "HIR"baituo"NOR"   "HIW"白 驼 山"NOR"      "HIR"yuelao"NOR"   "HIW"月 老 亭"NOR"       "HIR"dali"NOR"    "HIW"大 理 国"NOR"
    "HIR"emei"NOR"     "HIW"峨 嵋 山"NOR"      "HIR"gaibang"NOR"  "HIW"丐    帮"NOR"       "HIR"beijing"NOR" "HIW"北    京"NOR"        
    "HIR"huashan"NOR"  "HIW"华    山"NOR"      "HIR"kedian"NOR"   "HIW"扬州客店"NOR"       "HIR"xueshan"NOR" "HIW"雪    山"NOR"            
    "HIR"gumu"NOR"     "HIW"古    墓"NOR"      "HIR"kunlun"NOR"   "HIW"昆 仑 山"NOR"       "HIR"shaolin"NOR" "HIW"少 林 寺"NOR"          
    "HIR"shenlong"NOR" "HIW"神 龙 岛"NOR"      "HIR"towiz"NOR"    "HIW"会 客 厅"NOR"       "HIR"wiz"NOR"     "HIW"巫    师"NOR"            
    "HIR"wudang"NOR"   "HIW"武 当 山"NOR"      "HIR"wuguan"NOR"   "HIW"泉州武馆"NOR"       "HIR"wumiao"NOR"  "HIW"武    庙"NOR"            
    "HIR"xingxiu"NOR"  "HIW"星 宿 海"NOR"      "HIR"xuanjie"NOR"  "HIW"玄 劫 教"NOR"       "HIR"taohua"NOR"  "HIW"桃    花"NOR"\n"

 );

        set("objects", ([ /* sizeof() == 1 */ 
  "/u/oytj/npc/konglong.c" : 1,  
  "/u/oytj/obj/atm.c" : 1, 
  "/u/oytj/obj/zizhu.c" : 1,
  "/u/oytj/npc/peilian.c" : 2,
  "/u/oytj/npc/xx.c" : 1,
]));
  set("exits", ([ /* sizeof() == 23 */
  "wudang" : "/d/wudang/sanqingdian",
  "xueshan" : "/d/xueshan/guangchang",
  "wumiao" : "/d/city/wumiao",
  "wuguan" : "/d/wuguan/zhengting",
  "wiz" : "/d/wizard/wizard_room",
  "towiz" : "/d/wizard/guest_room",
  "kunlun" : "/d/kunlun/sanshengtang",
  "huashan" : "/d/huashan/pianting",
  "taohua" : "/d/taohua/jingshe",
  "shenlong" : "/d/shenlong/tingkou",
  "xingxiu" : "/d/xingxiu/xxh2",
  "shaolin" : "/d/shaolin/guangchang1",
  "kedian" : "/d/city/kedian",
  "gaibang" : "/d/gaibang/undertre",
  "xuanjie" : "/d/qilian/datang",
  "yuelao" : "/d/city/yuelao",
  "emei" : "/d/emei/hz_guangchang",
  "guiyun" : "/d/taihu/qianyuan",
  "baituo" : "/d/baituo/lingshege",
  "dali" : "/d/dali/wangfu1",
  "gumu" : "/d/gumu/dating",
  "beijing" : "/d/beijing/yiyantang",
]));
  set("cost", 1);
  set("valid_startroom", 1);

       call_other("/clone/board/oytj_b", "???"); 

  setup();
//  replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me))
		return notify_fail("小天使挡在你面前，恭身说道：“非常抱歉，您不能到那儿去。”\n");

	return ::valid_leave(me, dir);
}

int init()
{
        add_action("do_leave", "leave");
}

int do_leave()
{
	object me = this_player();
        tell_room(environment(me),
        "天空突然发出雷鸣，"+(string)me->query("name")+"掉落到了凡间。\n",
        ({this_player(), me}));
        me->move("/d/city/wumiao");
       message("vision", me->name() + "突然从空中掉了下来，结结实实摔了个屁墩。\n",
                environment(me), ({me}) );
	return 1;
}
