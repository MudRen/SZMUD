//Cracked by ydh

//ydh's workroom :) 

inherit ROOM; 

#include <ansi.h>

void create() 
{ 

set("short",HIW"������תվ"NOR); 

set("long", @LONG 
�����ǲݶ������԰�������תվ����·������������ò����� :P
��Ҷ���ΪӪ��������������������ͨ���ݶ�����������ף�����
��Զ��������������鲻��......

------------------------------------------------------------ 
�͵�kd, ����sl1,sl2, �䵱wd, ؤ��gb, Ȫ��qz, ����bt, ����xx, 
ѩɽxs, ����xixia, �һ�thd, ȫ��zn, ��ɽfs, ���͵�xkd, 
̩ɽfc, ��üem,em1, ����dl, ����cb, ��ɽhs, ��ʦdown, ����enter
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

return notify_fail("�㻹û��������Խʱ�գ�����ʵʵ�߿͵�kd�ɣ�\n"); 


return ::valid_leave(me, dir); 
}
