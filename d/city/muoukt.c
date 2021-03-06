// By FunBoo@sz
// 木偶看台

#include <ansi.h>
inherit ROOM;
int do_practice(string arg);
int do_study(string arg);

// Function declearation
string look_gaoshi();	// for user look gaoshi

void create()
{
        set("short", HIW"木偶戏棚子"NOR);
        set("long",
"这里是看木偶剧的的看台。你面前层层叠叠的搭起了一排排长凳，最前面是
一座表演木偶剧的台子。台上正有两个木偶在表演木偶剧，整个看台被挤得水泄
不通，彩声一阵高过一阵。木偶台边贴着一张告示(gaoshi)\n"
        );

        set("valid_startroom", 1);

        set("no_fight", 1);
        set("no_practice", 1);

        set("exits", ([
                "west": "/d/city/kantai",
        ]));

		set("item_desc", ([
		"gaoshi": (: look_gaoshi :),
		]));

        set("objects", ([
                "d/city/npc/yiren":1,
        ]));

        setup();
        call_other( "/clone/board/muoub", "???" );
}

void init()
{
                  add_action("do_practice",  "practice");
                  add_action("do_practice",  "lian");
                  add_action("do_study",  "study");
                  add_action("do_study",  "du");
}

int valid_leave(object me, string dir)
{
    if( dir=="west" )
	{
		if( wizardp(me) || (!me->query_temp("n_Muou_Cannot_Leave")))
		{
			return 1;
		}
        else
        {
			// Do not allow player leave
			if( me->query_temp("n_Muou_Cannot_Leave") )
			{
				return notify_fail("你给钱了，现在不能离开。\n");
			}
        }
	}
    return ::valid_leave(me, dir);
}

int do_practice(string arg)
{
	object me = this_player();
    tell_object(me, "这里不准练功!\n");
    return 1;
}

int do_study(string arg)
{
	object me = this_player();
	tell_object(me, "这里不准读书!\n");
	return 1;
}

string look_gaoshi()
{
	string msg;
	msg = "木偶戏使用规则：\n";
	msg+= "请先给一两黄金给艺人(give 1 gold to yiren)，然后就可以设计木偶了。\n";
	msg+= "如有人正在演木偶戏或者有人正在设计木偶，艺人不会收你所给的钱。\n";
	msg+= "\n";
	msg+= "艺人收了你的钱之后，请用setmuou的命令来设计木偶，具体要设计的项目如下：\n";
	msg+= "第一设计项目：\n";
	msg+= "年龄：		setmuou age 数目 (20 到 200)\n";
	msg+= "技能等级：	setmuou skill 数目 (1 到 800)\n";
	msg+= "心法等级：	setmuou xinfa 数目 (1 到 800)\n";
	msg+= "臂力：		setmuou str 数目 (12 到 30)\n";
	msg+= "智力：		setmuou int 数目 (12 到 30)\n";
	msg+= "根骨：		setmuou con 数目 (12 到 30)\n";
	msg+= "身法：		setmuou dex 数目 (12 到 30)\n";
	msg+= "门派：		setmuou menpai menpai (例如：shaolin, wudang, quanzhen...)\n";
	msg+= "\n";
	msg+= "全部天赋的总和不能超过九十，但可以是九十。\n";
	msg+= "当以上条件满足后，艺人就会记下来，然后在交易频道里面帮你找对手或开始木偶戏。\n";
	msg+= "如以上的任何一个条件没有满足，木偶戏都不会开始。\n";
	msg+= "也就是说，如果你的某个项目设计错了，可以用同样的命令来再设计一次。\n";
	msg+= "但是，如果条件满足了就不能再重新设计了。\n";
	msg+= "\n";
	msg+= "以下是可以设计或不设计的项目：\n";
	msg+= "第二设计项目：\n";
	msg+= "辟邪剑：        setmuou pxj 1 为木偶可以使用辟邪剑。\n";
	msg+= "正常死亡：	setmuou deathcount 数目 为木偶的正常死亡次数。\n";
	msg+= "如以上条件不设计的话，木偶会默认设计为不能使用辟邪剑和正常死亡一百次。\n";
	msg+= "第二设计项目必须要在第一设计项目完成前设定。\n";
	msg+= "\n";
	msg+= "如果你不想设计那么多的第一项目，可以用默认第一项目：\n";
	msg+= "命令：setmuou default 1\n";
	msg+= "如果是这样，系统就会设计木偶为：\n";
	msg+= "年龄：六十。技能和心法等级：四百。臂力，智力和身法二十。根骨三十。正常死亡一百。\n";
	msg+= "如果你不满意以上任何一项，可以在用setmuou menpai前重新设计。\n";
	msg+= "\n";
	msg+= "可以选择的兵器：jian, dao, zhang, zhen, bang, bian等等...\n";
	return msg;
}
