//  /d/gumu/liangongshi3.c
//   lgongf2.c
//   By Blacko,2001
//	update by April 01/08/19

 
#include <room.h>
#include <ansi.h>
#include <combat.h>

inherit FORCE;
inherit F_CLEAN_UP;
inherit ROOM;

#include "/kungfu/skill/force_list.h"

string check() { return "force"; }

int valid_enable(string usage) { return usage == "force"; }

void create()
{
        set("short", "男练功房");
        set("long", @LONG
这里是专给古墓男弟子设立的练功场所，屋子不大，但是倒也整洁，
屋内静悄悄的，声息全无。这个房间异常寒冷，一般人进来不禁要连打几
个喷嚏，但是这里却是练功(liangong)中男子们发散体内阳刚热气的极佳
的场所。东边有一扇小木门通往练功室。
LONG
        );        
        set("no_steal", "1");
        set("no_sleep_room", "1");

        set("exits", ([
   	         "east" : __DIR__"liangongshi1",
        ]));
 
		set("item_desc",([
		"door"		:	(: look_door :),
	      ]));
        create_door("east", "木门", "west", DOOR_CLOSED);

        set("cost", 0);
        setup();
}

string look_door()
{
	return "一道暗红色橡木小门。\n";
}

void init()
{
        add_action("do_liangong","liangong");
}

// practice.c

int do_liangong(string arg)
{
	object me=this_player();			//当前玩家
	object where = environment(me);		//所处环境
	string skillname;
	//int skill, skill_basic;
	int xj_lvl = me->query_skill("yunu-xinjing", 1);	//玉女心经等级
	int force_lvl = me->query_skill("force", 1);		//基本内功等级
	int v,i,j,k;		// 临时变量
	int cost;		// 练习时的耗费
	mapping skl;	// 所有skill
	string *sname;	// skill名字
	object *inv;	// 身上带的东西

	seteuid(getuid());

	// 男女有别
	if (me->query("gender") == "女性")
		return notify_fail("女儿家家的跑到大男人房间脱衣服练功？你羞不羞啊！\n");

	// 基本内功小于玉女心经不能练
	if( force_lvl < xj_lvl)
		return notify_fail("你的基本功火候未到，必须先打好基础才能继续提高。\n");

	// 忙时不练
	if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");

	// 战时不练
	if( me->is_fighting() )
		return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");

	// lvl小于30不能练
	if (xj_lvl<30)
		return notify_fail("你试着运了一下体内真气，显然玉女心经修为不够，真气无法运转。\n");

	// 必须空手
	if ( me->query_temp("weapon") )
        return notify_fail("练习玉女心经必须空手，静坐诚心方可。\n");

	// 必须裸体
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
		if( inv[i]->query("equipped") 
			&& inv[i]->query("armor_type")=="cloth")
			i = sizeof(inv)+1;
	if (i==sizeof(inv)+2)
        return notify_fail("练习玉女心经必须衣襟敞开方能及时散发热气。\n");

	// 内功要纯，否则大伤元气
	skl=this_player()->query_skills();
	sname=sort_array( keys(skl), (: strcmp :) );
    for(v=0; v<sizeof(skl); v++) {
		if (SKILL_D(sname[v])->check() == "force")
			k++;  
    }
    if ( k >=2 ) {
		// 这里加走火入魔伤害
        me->set("neili", 0);
        me->set("jingli", 50);
        me->set("qi", 50);
		i=(int)(me->query("max_jing")*65/100);
		me->set("eff_jing",i);
		return notify_fail("你体内不同内力互相冲撞，翻江倒海，难以克制。 \n"
			+"你猛一咬牙，狂喷一口热血，才不至于走火入魔。\n");
	}

	// 不能靠练习过关 ---- 30n-1时必须过关
	if ( (xj_lvl<270) && ((xj_lvl+1)/30*30 == xj_lvl+1 ) )
		return notify_fail("你继续练习着玉女心经，忽然体内真气一滞... \n"
			+"你似乎遇到了无法突破瓶颈，看来是时候过关了。 \n");

	// 计算练功消耗
	cost = to_int(sqrt(xj_lvl/to_float(150))*60);
	if ( (int)me->query("qi") < cost+10 )
		return notify_fail("你的体力不够练习玉女心经。\n");
	if ( (int)me->query("jingli") < cost+10 )
		return notify_fail("你的精力不够练习玉女心经。\n");
	if ( (int)me->query("neili") < cost+10 )
		return notify_fail("你的内力不够练习玉女心经。\n");

	// 消耗
	me->add("neili", -cost);
	me->receive_damage("jingli", cost, "精力透支过度死了");
	me->receive_damage("qi", cost, "体力透支过度死了");

	// 练功效果
	me->improve_skill("yunu-xinjing", force_lvl/4 +1, force_lvl > xj_lvl? 0: 1);
	write( HIY "你的" + to_chinese("yunu-xinjing") + "进步了！\n" NOR);
	return 1;

}

