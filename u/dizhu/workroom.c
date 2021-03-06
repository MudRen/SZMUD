// date 29/3/2001 by spirit

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "[1;32m小地主的农场[37;0m");
  set ("long", @LONG
[1;32m
杏花，烟雨，江南... ...
                     [1;36m《桃花庵歌》
[1;36m            桃花坞里桃花庵，桃花庵里桃花仙。 
            桃花仙人种桃树，又摘桃花换酒钱。 
            酒醒只在花前坐，酒醉还来花下眠。 
            半醒半醉日复日，花落花开年复年。 
            但愿老死花酒间，不愿鞠躬车马前。 
            车尘马足贵者趣，酒盏花枝贫者缘。 
            若将富贵比贫者，一在平地一在天。 
            若将贫贱比车马，他得驱驰我得闲。 
            别人笑我忒疯癫，我笑他人看不穿。 
            不见五陵豪杰墓，无花无酒锄作田。[37;0m
    baituo   白 驼 山      yuelao   月 老 亭       dali    大 理 国
    emei     峨 嵋 山      gaibang  丐    帮       beijing 北    京        
    huashan  华    山      kedian   扬州客店       xueshan 雪    山            
    leitai   擂    台      murong   姑苏慕容       shaolin 少 林 寺          
    shenlong 神 龙 岛      towiz    会 客 厅       wiz     巫    师            
    wudang   武 当 山      wuguan   泉州武馆       wumiao  武    庙            
    xingxiu  星 宿 海      xuanjie  玄 劫 教       taohua  桃    花
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/d/shaolin/npc/mu-ren" : 1,
]));
  set("exits", ([ /* sizeof() == 23 */
  "wudang" : "/d/wudang/sanqingdian",
  "xueshan" : "/d/xueshan/guangchang",
  "wumiao" : "/d/city/wumiao",
  "wuguan" : "/d/quanzhou/qianting",
  "wiz" : "/d/wizard/wizard_room",
  "towiz" : "/d/wizard/guest_room",
  "murong" : "/d/murong/qing4",
  "huashan" : "/d/huashan/pianting",
  "taohua" : "/d/taohua/jingshe",
  "shenlong" : "/d/shenlong/tingkou",
  "leitai" : "/u/xuy/bwdh/leitai",
  "xingxiu" : "/d/xingxiu/xxh2",
  "shaolin" : "/d/shaolin/guangchang1",
  "kedian" : "/d/city/kedian",
  "gaibang" : "/d/gaibang/undertre",
  "xuanjie" : "/d/qilian/datang",
  "yuelao" : "/d/city/yuelao",
  "emei" : "/d/emei/hz_guangchang",
  "guiyun" : "/d/taihu/qianyuan",
  "baituo" : "/d/xingxiu/btyard",
  "lingjiu" : "/d/lingjiu/main-22",
  "dali" : "/d/dali/wangfu1",
  "center" : "/d/wizard/center",
  "beijing" : "/d/beijing/kedian",
]));
  set("cost", 1);
  call_other("/clone/board/dizhu_b", "???"); 
  set("valid_startroom", 1);

  setup();
//  replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me))
		return notify_fail("玲玲挡在你面前，恭身说道：“非常抱歉，您不能到那儿去。”\n");

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
