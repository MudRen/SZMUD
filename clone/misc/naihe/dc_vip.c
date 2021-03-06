//                标准描述长度示例                                   |
// 赌场VIP贵宾房，这里是赌金子的，heihei  ★dc_vip.c
// naihe  2002-04-29 于茂名
// 2002-05-01完成！ by naihe
// 请勿擅自更改本文件源码，谢谢！

#include <ansi.h>
#include <room.h>
inherit ROOM;


void create()
{
	set("short", HIW"贵宾房"NOR);
	set("long", "这是一间不大的房间，但布置却尽显气派。墙壁上帖着的是从西洋出产的壁
纸，有着漂亮而不花俏的纹路；天花板上吊着一大串虽明亮却不耀眼的夜明珠，
整个房间充满了柔和之极的气氛。灯下的房间中央位置摆放着一张小巧的大理石
圆桌，桌旁有两张椅子，一个金发的美人正坐在对门的椅子上微微地对你笑着。
门边的墙角有着一个白玉砌成的小水池，里面还游着两尾煞是可爱的金鱼；池边
竖着一个镶边木纹小牌子(paizi) ；池子上方还帖有一张挺大的纸，上面写着几
个字：“赌局规则”(guize)。

你从嘈杂的大厅那边走了过来，顿时感到一种无以言喻的舒心。
\n");
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("invalid_startroom",1);

	set("item_desc",([
	    "paizi":""YEL"
#############
# "HIY"find here"NOR""YEL" #
#############
"NOR"\n",
	    "guize":""HIG"
┌┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┐
┆                              "HIR"★赌 局 规 则★"HIG"                               ┆
┆"HIR"【骰子】"HIG"                                                                    ┆
┆      格式：touzi <数目> <钱财>  例：touzi 1 gold. 意思是以1两黄金为底金。  ┆
┆      骰子，每人随意扔出3个骰子，相加点数大者即胜；赔率为1赔1。             ┆
┆      特殊情况：当3个骰子相同时，赔率上升为5倍；此时无论点数多少，皆为胜；  ┆
┆                但若庄、闲都是同骰，则看谁的点数大；赔率仍为5倍。           ┆
┆                                                                            ┆
┆"HIR"【斗牛】"HIG"                                                                    ┆
┆      格式：douniu <数目> <钱财>    例：douniu 1 gold.                      ┆
┆      斗牛，即每人五张牌（1-13），10-13亦为10，无花色，一次过翻开后计算。   ┆
┆      五张皆为10，称“五牛”，最大，赔率为5倍（同样，玩家亦要付出5倍价钱）。┆
┆      任意三张相加为10或20或30即为“有牛”；“有牛”者胜“无牛”者。        ┆
┆      “有牛”之后，剩余两张相加为点数；若两者皆有牛，按点数比大小。        ┆
┆      点数若超过十，则按零头算；若又是10则此盘称“牛牛”，赔率为3倍。       ┆
┆      点数为8或9时，赔率为2倍；其余的皆为1倍。若双方同样，则庄家为大。      ┆
┆                                                                            ┆
┆"HIR"【一张定输赢】"HIG"                                                              ┆
┆      格式：yizhang <数目> <钱财>    例：yizhang 1 gold.                    ┆
┆      一张定输赢，庄、闲各抽一张牌（1-13），1最大，其次是13、12、……2最小。┆
┆      若点数相同，则比花色：◇最小，※稍大，☆甚之，▲最大。游戏赔率为1赔1。┆
┆                                                                            ┆
┆      ----以上游戏都需要最少带着能够支付最大赔率的黄金在身才能开始，例如斗牛┆
┆          游戏，押注1 gold时，身上则需要至少带着5 gold。                    ┆
┆                                                     --by naihe 2002-05-06  ┆
└┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┘
"NOR"",
	]));

	set("objects", ([
	    __DIR__"npc/dc_boss" : 1,
	    ]));

	set("exits", ([
	    "out": __DIR__"dc_dating",
	    ]));

	create_door("out", "小门", "vip", DOOR_CLOSED);

	setup();
}

void init()
{
	add_action("do_skills",  "exercise");
	add_action("do_skills",  "dazuo");
	add_action("do_skills",  "respirate");
	add_action("do_skills",  "tuna");
	add_action("do_skills",  "practice");
	add_action("do_skills",  "lian");
	add_action("do_skills",  "study");
	add_action("do_skills",  "du");
	add_action("do_food", "eat");
	add_action("do_food", "chi");
	add_action("do_food", "drink");
	add_action("do_drop", "throw");
	add_action("do_drop", "drop");
	add_action("do_find","find");
        add_action("do_food", "he");
}

  void reset()
  {  
                ::reset();  
                set("no_clean_up",1);
  }
int do_skills(string arg)
{
	tell_object(this_player(),"要赌钱就专心赌，别存心添乱了。\n");
	return 1;
}

int do_food(string arg)
{
	tell_object(this_player(),"吃东西请到二楼茶座。\n");
	return 1;
}

int do_drop(string arg)
{
	if(arg=="gold") return 0;
	tell_object(this_player(),"不许乱扔东西。\n");
	return 1;
}

int do_find(string arg)
{
	object me,ob;
	int find;
	me = this_player();
	
	if(!arg)
	{
		if(me->query("jingli") < me->query("max_jingli")/2)
		return notify_fail("美人在前，你集中不起精神来寻找。\n");

		me->set("jingli",30);
		find=random(200);
		if(find<10 || find>190) ob=new("/clone/money/coin");
		if(find>9 && find <15) ob=new("/clone/money/silver");
		if(find>14 && find<30) ob=new("/clone/food/kaoya");
		if(find>29 && find<35) ob=new("/clone/money/gold");
		if(find>34 && find<40) ob=new("/clone/weapon/changjian");
		if(find==44 || find==88) ob=new("/clone/weapon/qinggang-jian");
		if(find==144 || find==188) ob=new("/clone/armor/tiejia");
		if(find>100 && find<110) ob=new("/clone/food/mitao");

		if(!ob)
		{
			message_vision("$N找了半天，什么也没找到，累得头昏眼花。\n",me);
			return 1;
		}

		else
		{
		ob->set_amount(1);
		message_vision("$N凝神找了半天，在墙角发现了一" + ob->query("unit") + ob->query("name") + "！\n",me);
		ob->move(me);
		return 1;
		}
	}

	return 0;
}
