// Code by Felix
// Room: /u/smzz/workroom.c

inherit ROOM;
#include <ansi.h>
#include <room.h>
void reset();
int valid_leave();

void create()
{
set("short", HIC"沙漠之子办公室"NOR); 
set("long", 
""HIG"  大浪淘沙，物竞天择"NOR+HIM"  适者生存，弱者灭绝\n"NOR     
"               "HIY" ********************\n"NOR 
"                "HIY"*"NOR+BLINK+HIG" 非请勿入，敲们请进 "NOR+HIY"*\n"NOR
"               "HIY" ********************\n"NOR 
""MAG"                      侠 客 行\n"NOR 
""MAG"             ┌─┐               ┌─┐\n" 
"             │给│  ------------ │还│\n" 
"             │我│  |          | │你│\n" 
"             │一│  |          | │一│\n" 
"             │个│  |          | │腔│\n" 
"             │温│ --------------│燃│\n" 
"             │柔│_______________│烧│\n" 
"             │的│               │的│\n" 
"             │陷│               │爱│\n" 
"             │阱│               │情│\n" 
"             └─┘               └─┘\n"NOR
);
set("outdoors", "emei"); 





                  set("exits", ([
                "sl" : "/d/shaolin/guangchang1",
                "sn" : "/d/shenlong/tingkou",
                "xi" : "/d/xixia/dawu",
                "hz" : "/d/hangzhou/kedian",
                "wn" : "/d/wudang/sanqingdian",
                "xk" : "/d/xiakedao/dadong",
                "xx" : "/d/xingxiu/xxh2",
"athena":"u/athena/workroom",
"naihe":"u/naihe/workroom",
                "gy" : "/d/taihu/qianyuan",
                "kd" : "/d/city/kedian",
                "qz" : "/d/quanzhou/zhongxin",
"wm" : "d/city/wumiao",
                "hs" : "/d/huashan/pianting",
                "bt" : "/d/xingxiu/btyard",
"wz" : "/d/wizard/wizard_room",
"wr" : "/d/wizard/meeting_room",
                "wz" : "/d/wizard/wizard_room",
                "dl" : "/d/dali/wangfu1", 
                "em" : "/d/emei/hz_guangchang",
                "xs" : "/d/xueshan/guangchang",
"syj" : "/u/felix/syj",
  ])); 
set("item_desc", ([  
"diannao": HIW"这台19寸纯平电脑好像可以轻轻的抬(tai)起来。\n"NOR,  
"bian": HIW"这块匾表面是一块普通的匾，其实是天界里的超时空传送仪，
 ---------------------------------------------------- 
少林: sl  武当: wn  星宿: xx  丐帮: gb  白驼: bt
华山: hs  侠客: xk  客店: kd  雪山: xs  峨嵋: em
大理: dl  神龙: sn  西夏: xi  桃花: td  归云: gy
黄金大殿: wz 武庙：wm
----------------------------------------------------
你可以根据上面的按钮去你想去的地方！\n"NOR,
"duilian": HIM"一幅由江泽民书写的正楷字体的对联\n"NOR
]));  
call_other("/clone/board/smzz_b", "???");

set("valid_startroom",1);

        setup();
}
void init()
{
    add_action( "tai", "tai" );
}

int tai( string arg )
{
if ( !arg || arg != "diannao" )
     return notify_fail( "你要抬什么？抬轿子我座吗？\n" );
   add( "exits/enter", __DIR__"room" );
tell_room( this_object(), HIW"一道金光劈开电脑桌子下面漏出了一个黑洞，你可以enter\n"NOR ); 
    return 1;
}

int valid_leave(object me, string dir)
{
object zhitiao;
                  if ( !wizardp(me) && dir!="up" ){
zhitiao=new("u/smzz/obj/zhitiao"); 
zhitiao->move(me); 
zhitiao->set("sign",me->query("id")); 
message_vision(HIW"忽然"NOR+BLINK+YEL"本·拉登"NOR+HIW"跳了出来端着他的AK-47说：“#￥￥%··￥…………#！”\n"NOR+CYN"你一看这阵势吓得马上蹲在地\n"NOR, me); 
command("say 多看看这里的摆设，比如：对联那、电脑呀！");
return notify_fail("本·拉登觉得你不是坏人递给你一张很小的纸条，然后就不见了。\n"NOR);
        }
    else if ( dir == "enter" )
        call_out( "close_enter", 1 );
        return ::valid_leave(me, dir);
}

void close_enter()
{
    delete( "exits/enter" );
}
