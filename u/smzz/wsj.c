

//u/smzz/wsj.c
#include <ansi.h>
inherit ROOM; 
string xi_zao(object me);
void create ()
{

set("short","ɳ��������");
set("long",
"����Ǻ���ͨ�������䣬û��ʲô�ر�ģ�ֻ��ǽ�ϵ�"BLINK+HIG" ����(jing)"NOR"�е��ر�\n"
"����������һЩ��ϴ��Ʒ,����ɳ��������ڵ¹��������ڱ�����ÿ�,ǽ���и���ԡ��(chi)\n"
"�������������������,Ŷ�����˹����������β�����(door)\n"
);
set("exits",
([ /* sizeof() == 2*/ 
"west":"u/smzz/room",
]));
set("objects", ([ 
"u/smzz/obj/jing.c" : 1]));
set("item_desc",([
"door":"����һ���й�����������ɲ�����,�������ܽ�ʵ\n",
"chi":HIM"һ���¹�ɯ˺���޵Ľ��ڴ�ԡ��,����������澡���ϴ,��������ϴԧ��ԡ\n"NOR ,
]));
set("cost", 0);
create_door("west","������" ,"east"); 
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
return notify_fail("��ʲôѽ,��Ҫϴ�軹��Ҫϴ����!!!\n");
if(arg == "zao" ) 
message_vision( HIW"$N�ѵ���ȫ����·�,�������Ǹ���ԡ�ؾ�������������˼�����á�\n"NOR, me);  
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
