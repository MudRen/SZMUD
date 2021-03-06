// base_room.c --- 房间样本

#include <room.h>    

inherit ROOM;        //一个房间必定继承了 ROOM , 这是在<mudlib.h>
                     //中被 #define 好的一个档案, 它表示一个特别的档案, 所
                    //有的房间都必须继承它. 才能拥有属於房间的一切特性　
string item2(object);

void create()     // 此函数是房间在一被创造出来时必定要呼叫的一个函数, 通常我
                            //们都在里面做一大堆设定初值的动作
{
         set("short", "房间样品");
         set("long", @LONG
这是房间描述第一行，系统会自动在开头插入四个空格，最长30个汉字，
这是第二行，最长32个汉字。
|<-------------------- 32 个汉字或 64 个英文 ------------------->|
通常我们在游戏中是以32个汉字作为标准长度，以便于使描述能够统一起来。
LONG);

         set("outdoors", "位置"); // 表示这里是室外，可以看到天色
         set("no_fight", 1); // 表示这里禁止一切引发战斗的行为
/*这两个是西游记里面有的，在神州中不会使用到。
     set("no_spells",1);  // 表示这里禁止使用法力。
     set("no_magic",1); // 表示这里禁止使用灵力。
*/
         set("no_get_from", 1); // 表示这里禁止 get from ....
         set("sleep_room", 1); // 表示这里任何人都可以 sleep
         set("valid_sleep",1); // 作用同上，专用于风云类LIB
         set("no_sleep_room", 1); // 表示这里任何人都不可以 sleep
         set("no_death", 1); // 表示在这里死的不算真死
         set("valid_startroom", 1); // 表示在这里save下次会从这里进来
     set("restrict_fly_room", 1); // 表示禁止对该房间使用灵力，专用于风云类LIB

         set("item_desc", ([
"item1": "item1 的描述\n",
"item2": (: item2 :),
         ]));
// 可以用 look item1, look item2 看

         set("objects", ([// refresh 呼叫的时机，是系统定时(约每半个小时一次)，呼叫主
                      // 要的用途在於房间中怪物，物品的再生。如果你改写了refresh()
                     // 函数,千万记得要串接 ::refresh(), 否则可能导致严重的后果(门
                     // 一打开就不会自动关上, 怪物打死後也不会再生...
                     // 这里我们采用set("objects", (["name1" : "file1", "name2" :
                     // "file2",... ]) );这种写法。(在 create() 里面这么写)，所
                     // 以 refresh() 被用到的机会不多了
// 文件名: 数量,              
]));
// 设置房间里的物品和 npc

set("exits", ([
// 出口: 文件名,
]));

setup(); //这个函数执行后房间才能按上面的设定来产生

// replace_program(ROOM);
// 注意！！！如果没有其他的函数才可以用这一句
}
void init()        //此函数被呼叫的时机在於有生物 (怪物及玩家)  进入这个房
                   //间的时候　这时有个常用的函数 this_player()  会传回走
                   //进房间的这个人, 或是怪物
{
      add_action("do_open", "open"); //赋予进入此房间的玩家一个新的指令：open
}
string item2(object me)
{
switch(random(3)) {
case 0: return "随机的显示0\n";
case 1: return "随机的显示1\n";
case 2: return "随机的显示2\n";
}
}  

