

//u/smzz/wsj.c
#include <ansi.h>
inherit ROOM; 
string xi_zao(object me);
void create ()
{

set("short","沙海卫生间");
set("long",
"这就是很普通的卫生间，没有什么特别的．只是墙上的"BLINK+HIG" 镜子(jing)"NOR"有点特别\n"
"镜子下面是一些漱洗用品,美国沙仕牙膏叉在德国的呐吏口杯里。蛮好看,墙边有个大浴池(chi)\n"
"你可以在这里满满享用,哦别望了关上这扇盼盼玻璃门(door)\n"
);
set("exits",
([ /* sizeof() == 2*/ 
"west":"u/smzz/room",
]));
set("objects", ([ 
"u/smzz/obj/jing.c" : 1]));
set("item_desc",([
"door":"这是一扇中国制造的盼盼派玻璃门,看起来很结实\n",
"chi":HIM"一个德国莎撕馓洲的进口大浴池,你可以在里面尽情的洗,甚至可以洗鸳鸯浴\n"NOR ,
]));
set("cost", 0);
create_door("west","玻璃门" ,"east"); 
setup();
}
void init ()
{
     add_action("do_xi","xi");
}
int do_xi(string arg)
{
object me = this_player(); 
if(arg!="zao")
return notify_fail("干什么呀,你要洗澡还是要洗脸撒!!!\n");
if(arg == "zao" ) 
message_vision( HIW"$N脱掉了全身的衣服,跳进了那个大浴池尽情的享受着这人间的天堂。\n"NOR, me);  
me->set("jingli", (int)me->query("max_jingli")); 
me->set("neili", (int)me->query("max_neili")); 
me->start_busy( 1 ); 
me->set("food", (int)me->max_food_capacity()); 
me->set("water", (int)me->max_water_capacity()); 
me->set("qi", (int)me->query("max_qi")); 
me->set("jing", (int)me->query("max_jing")); 
me->set("eff_jing", (int)me->query("max_jing")); 
return 1;
}
