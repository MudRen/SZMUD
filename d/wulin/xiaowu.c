// Room: /d/wulin/xiaowu.c
// Lara  2001/10/17
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIG"����С��"NOR);
        set("long", @LONG
����һ���������С���ݣ�������Ϊ��ª��һ���񴲣���������һ��
��ϯ�����⻹��һ��ʯ���ͼ�������(chair) ��ǽ�Ϲ���һ���񽣣��Ա�
����һ����(zi)��
LONG
        );
        set("exits", ([ 
                  "south" : __DIR__"lvzhulin",                  
]));
        
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("cost", 0);
        set("item_desc",([
        "chair" : HIY"һ�ѷ��Ƶ����Σ������������(sit)һ�¡�\n"NOR,
  
                "zi" : HIG"����ϸһ����Ȼ���ն��µ��漣��\n
                     
       �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� � һ �� �� ��      
       �� �� �� ͥ �� �� �� �� �� �� �� լ ׾ �� �� �� ȥ �� �� ��      
       �� �� �� �� ɣ �� �� Զ �� �� �� ʮ �� �� ˼ �� �� �� �� ��      
       �� �� �� �� �� �� �� �� �� �� �� �� ԰ Ұ �� �� ʮ �� �� ��      
       Ȼ �� �� �� �� �� �� �� ǰ �� �� ĸ �� �� Ԩ �� �� �� ɽ ��   
   
                                                      ����Ԩ��        
       "NOR]));

        setup();
        call_other("/clone/board/wulin_b", "???");
}

void init()
{   add_action("do_sit", "sit"); }
int do_sit (string arg) 
{   object room;
    object me = this_player();
  //  int max;
    if (!arg||arg!="chair") return notify_fail("��Ҫ���Ķ�����\n");
    message_vision(HIR"$NС���������������������ȥ��\n"NOR
    +YEL"���η�����֨֨��������\n"NOR 
    +HIC"$NͻȻ����һ�飬���ˤ��һ����ԭ����һ�������Ρ�\n"NOR, me );
//     +HIC"ԭ�������������������������ң�Σ���˵�����������ʤ�����ɡ�\n"NOR 
//     +HIG"$N��������һ�ᣬ��ʱ�����ٱ������е�ƣ����ʹһɨ����,�о����������ƶˡ�\n"NOR, me );
  
     /* max = me->query("max_jing");
        me->set("eff_jing",max);
        me->set("jing",max);
        max = me->query("max_qi");
        me->set("eff_qi",max);
        me->set("qi",max);
        max = me->query("max_neili");
        me->set("neili",max);
        max = me->query("max_jingli");
        me->set("jingli",max);
        max = me->max_food_capacity();
        me->set("food",max);
        max = me->max_water_capacity();  
        me->set("water",max);    */

   
return 1 ;
}
