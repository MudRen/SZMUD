// Room: /d/wulin/xiaowu.c
// Lara  2001/10/17
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIG"竹林小屋"NOR);
        set("long", @LONG
这是一间竹林外的小草屋，布置甚为简陋。一张竹床，上面铺着一床
竹席，另外还有一张石桌和几把竹椅(chair) 。墙上挂着一把竹剑，旁边
挂着一幅字(zi)。
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
        "chair" : HIY"一把泛黄的竹椅，你可以试着坐(sit)一下。\n"NOR,
  
                "zi" : HIG"你仔细一看居然是苏东坡的真迹。\n
                     
       复 久 虚 户 鸡 狗 依 暧 桃 榆 草 方 守 开 池 羁 一 误 性 少      
       得 在 室 庭 鸣 吠 依 暧 李 柳 屋 宅 拙 荒 鱼 鸟 去 入 本 无      
       返 樊 有 无 桑 深 墟 远 罗 荫 八 十 归 南 思 恋 三 尘 爱 适      
       自 笼 余 尘 树 巷 里 人 堂 后 九 余 园 野 故 旧 十 网 丘 俗      
       然 里 闲 杂 颠 中 烟 村 前 沿 间 母 田 际 渊 林 年 中 山 韵   
   
                                                      －陶渊明        
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
    if (!arg||arg!="chair") return notify_fail("你要往哪儿坐？\n");
    message_vision(HIR"$N小心翼翼的往竹椅上坐了下去。\n"NOR
    +YEL"竹椅发出嘎吱吱的响声。\n"NOR 
    +HIC"$N突然脚下一虚，差点摔了一交，原来是一把破竹椅。\n"NOR, me );
//     +HIC"原来这是武林中人梦寐以求的逍遥椅，据说坐在上面快乐胜似神仙。\n"NOR 
//     +HIG"$N但觉身子一轻，登时精力百倍，所有的疲劳伤痛一扫而光,感觉就像走在云端。\n"NOR, me );
  
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
