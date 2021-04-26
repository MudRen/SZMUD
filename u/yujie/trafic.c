//Cracked by ydh

//ydh's workroom :) 

inherit ROOM; 

#include <ansi.h>

void create() 
{ 

set("short",HIW"草屋中转站"NOR); 

set("long", @LONG 
这里是草儿精神家园对外的中转站，各路神仙来往穿梭好不热闹 :P
大家都在为营造这个美丽的世界各显神通，草儿在这里衷心祝福大家
永远这样朝气蓬勃、激情不灭......

------------------------------------------------------------ 
客店kd, 少林sl1,sl2, 武当wd, 丐帮gb, 泉洲qz, 白驼bt, 星宿xx, 
雪山xs, 西夏xixia, 桃花thd, 全真zn, 佛山fs, 侠客岛xkd, 
泰山fc, 娥眉em,em1, 大理dl, 长白cb, 华山hs, 巫师down, 进屋enter
------------------------------------------------------------ 
LONG 
); 


set("exits", ([ 

"kd" :"/d/city/kedian", 

"down" :"/d/wizard/wizard_room", 

"sl1" :"/d/shaolin/guangchang1", 

"sl2" :"/d/shaolin/dmyuan2", 

"wd" :"/d/wudang/sanqingdian", 

"gb" :"/d/gaibang/gbxiaowu", 

"qz" :"/d/quanzhou/zhongxin", 

"hs" :"/d/huashan/buwei1", 

"xx" :"/d/xingxiu/xxh2", 

"dl" :"/d/dali/wangfu1", 

"em" :"/d/emei/baoguomen", 

"em1" :"/d/emei/hz_guangchang", 

"xs" :"/d/xueshan/guangchang", 

"bt" :"/d/baituo/changlang2", 

"thd" :"/d/taohua/jingshe", 

"gyz" :"/d/taihu/shufang", 

"zn" :"/d/zhongnan/dadian", 

"xixia" :"/d/xixia/dawu", 

"xkd" :"/d/xiakedao/shatan", 

"cb" :"/d/changbai/heifk", 

"fs" :"/d/foshan/yxhuiguan", 

"fc" :"/d/taishan/fengchan", 

"enter" :__DIR__"workroom",

])); 

set("objects", ([ 
__DIR__"npc/cao1":1,
])); 

set("no_fight",1); 

set("no_steal",1); 

set("valid_startroom",1); 



setup(); 

} 

int valid_leave(object me, string dir) 

{ 

if (!wizardp(me) && dir !="kd") 

return notify_fail("你还没有能力超越时空，老老实实走客店kd吧！\n"); 


return ::valid_leave(me, dir); 
}
