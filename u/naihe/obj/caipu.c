// 学做菜，看菜谱！  caipu.c
// by naihe  02-06-28

inherit ITEM;
#include <ansi.h>

string zzz,xxx,
zzz="的文件目录不对，变不出来。",
xxx="你身上已经有";


void create()
{
	set_name(HIW"秘传菜谱"NOR, ({"cai pu"}));
	set_weight(1000);
	set("long","一本神秘的菜谱，记载着数种美味菜式的做法，似乎出自一个女子之手。\n你可以看一下具体都写了些什么（shows）。\n");
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("value", 200);
	}
	setup();
}

void init()
{
	if(wizardp(this_player()))
	{
		add_action("do_cooks","cooks");
		add_action("do_gocook","gocook");
	}
	add_action("do_shows","shows");
}

int do_gocook()
{
	this_player()->move("/d/gaibang/zhulin3");
	write("你已经来到丐帮做菜的地方了。\n");
	return 1;
}

int do_shows(string arg)
{
	if(!arg) return notify_fail("你要看什么菜式的做法介绍？(cbc/zdf/hqt/nrt/jhj)\n");

	if(arg=="炒白菜" || arg=="cbc")
		write("
                          "HIW"炒白菜"NOR"

    越是平凡菜式，越见真功。需原料白菜、鸡油、鸭掌；取菜心而舍
叶梗，取鸭掌末添鸡油，混而炒之，香甜脆腻，滋味无穷。

    白菜，扬州城南果品摊小贩处可买得；鸡油，询问扬州醉仙楼小二
可得；鸭掌，切下(cut)烤鸭可得。\n");

	if(arg=="蒸豆腐" || arg=="zdf")
		write("
                          "HIW"蒸豆腐"NOR"

    此菜虽名“蒸豆腐”，实非心灵手巧之人不可做得。需原料豆腐，
火腿；先将火腿剖开，挖了二十四个圆孔，再将豆腐削成二十四个小球
分别放入孔内，扎住火腿再蒸，等到蒸熟，火腿的鲜味已全到了豆腐之
中，火腿却弃去不食。此菜味道鲜而不腻，其难难于将豆腐削成小球，
功力不亚于米粒刻字、雕核为舟。这菜另有名堂曰：“二十四桥明月夜”。

    豆腐，扬州城南街边酒馆可买得；火腿，醉仙楼二楼掌柜处可买得。\n");

	if(arg=="好逑汤" || arg=="hqt")
		write("
                          "HIW"好逑汤"NOR"

    此汤需原料荷叶，竹笋，樱桃，斑鸠肉，花；先剜出樱桃之核嵌入
斑鸠之肉，再配以其他各物，以荷叶清熬而成。成菜时碧绿清汤，红樱
漂于其上，绿笋映衬其下，数片花瓣散浮四周，各色晖映，鲜艳夺目之
极。兼之汤中荷叶清香、笋尖之鲜、樱桃之甜，斑鸠之肉味美无穷，各
般滋味，相映相成，正如诗句所说：“关关雉鸠，在河之洲，窈窕淑女，
君子好逑”，让人无限遐想。

    荷叶，于泉州王通治处可买得；竹笋，于扬州城郊青竹林可折(pick)
得；樱桃，扬州城南果品摊小贩处可买得；斑鸠肉，扬州城郊打斑鸠可
得；花，扬州城郊可拾得。\n");

	if(arg=="牛肉条" || arg=="nrt")
		write("
                          "HIW"牛肉条"NOR"

    此菜名为“玉笛谁家听落梅”，原料共需五种不同肉类，分别是：
小牛腰子，羊羔坐臀，小猪耳朵，獐肉，兔肉；其中獐肉兔肉相揉合为
一条小肉条，其余三肉又为三条小肉条，再将之搅合一起为一大条肉条，
此般一一做成，一同炙成一碟。碟中虽只五肉，但猪羊混咬是一般滋味，
獐牛同嚼又是一般滋味……次序的变化不计，此菜共有二十五变，合五
五梅花之数，又因肉条形如笛子，因此名为“玉笛谁家听落梅”。心思
之巧，味道之特，实非寻常牛肉可比！

    牛肉，三不管处打黄牛可得；羊肉，大草原处打绵羊可得；猪耳朵，
少室山下小土屋附近打小猪可得；獐肉，扬州城郊打獐子可得；兔肉，
扬州城郊打野兔可得。\n");

	if(arg=="叫化鸡" || arg=="jhj")
		write("
                          "HIW"叫化鸡"NOR"
    数菜之中，此菜原料最少，但做法却最为困难，其因在于火候若是
把握不当，或嫩或老，其味便大不相同。需原料公鸡，湿泥，并需配剑
作剖鸡洗脏之用。先剖开(cut)公鸡，洗去(xi)内脏，裹以(guo)湿泥，
再生火烤之(kao)。待至飘香之时，再烤十数秒即取出剥下(bo)干泥，鸡
毛随泥而落，将见鸡肉白嫩，浓香扑鼻。此菜方成。

    公鸡，华山村内老大娘身上携有；湿泥，似于杭州西湖边有取。\n");

	if(arg=="炒白菜" || arg=="cbc" || arg=="蒸豆腐" || arg=="zdf" || arg=="好逑汤" || arg=="hqt" || arg=="牛肉条" || arg=="nrt" || arg=="叫化鸡" || arg=="jhj")
	{
		write("
*******************************************************************
除了叫化鸡可随时烧烤之外，别的菜式要到：
竹林小道 -（这里是丐帮弟子为扬州城内的帮中长老们烧菜做饭的地方。）
那里，使用 cook 炒白菜/蒸豆腐/牛肉条/好逑汤 指令来做菜。要带fire。\n");
	if(wizardp(this_player())) write("巫师可以用 cooks 指令，直接获得做菜的原料。用gocook指令直接到达做菜处。\n");
		write("*******************************************************************\n");
		message_vision(CYN"$N拿起菜谱仔细地看着。\n"NOR,this_player());
	}
	else write("你要看什么菜式的做法介绍？(cbc/zdf/hqt/nrt/jhj)\n");
	return 1;
}

int do_cooks(string arg)
{
	object me,fire,cook_needs;

	me=this_player();

	if(!arg) return notify_fail("你要什么菜的原料？(cbc/zdf/hqt/nrt/jhj)\n");

	if(!present("huozhe",me))
	{
		fire=new("/d/xingxiu/npc/obj/fire");
		if(!fire) write("火折"+zzz+"\n");
		else fire->move(me);
	}

	if(arg=="炒白菜" || arg=="cbc")
	{
		write("炒白菜，需要  白菜，鸡油，鸭掌。\n");

/*****************************************
 白菜：/clone/food/baicai.c   "baicai"  
 鸡油：/clone/food/jiyou.c    "ji you"
 鸭掌：/clone/food/yazhang.c  "ya zhang"
******************************************/

		if(!present("baicai",me))  // 变白菜
		{
			cook_needs=new("/clone/food/baicai");
			if(!cook_needs) write("白菜"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"白菜了。\n");

		if(!present("ji you",me))  // 变鸡油
		{
			cook_needs=new("/clone/food/jiyou");
			if(!cook_needs) write("鸡油"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"鸡油了。\n");

		if(!present("ya zhang",me))  // 变鸭掌
		{
			cook_needs=new("/clone/food/yazhang");
			if(!cook_needs) write("鸭掌"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"鸭掌了。\n");

		write("ok.\n");
		return 1;
	}

	if(arg=="蒸豆腐" || arg=="zdf")
	{
		write("蒸豆腐，需要 豆腐，火腿。\n");

/**************************************
 豆腐：/clone/food/tofu.c   "doufu"
 火腿：/clone/food/ham.c    "huo tui"
**************************************/

		if(!present("doufu",me))  // 变豆腐
		{
			cook_needs=new("/clone/food/tofu");
			if(!cook_needs) write("豆腐"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"豆腐了。\n");

		if(!present("huo tui",me))  // 变火腿
		{
			cook_needs=new("/clone/food/ham");
			if(!cook_needs) write("火腿"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"火腿了。\n");

		write("ok.\n");
		return 1;
	}

	if(arg=="好逑汤" || arg=="hqt")
	{
		write("好逑汤，需要 荷叶，竹笋，樱桃，斑鸠肉，花。\n");

/*******************************************************
 荷叶：  /d/dongtinghu/obj/heye.c        "he ye"
 竹笋：  /d/gaibang/obj/zhusun.c         "zhu sun"
 樱桃：  /d/city/npc/obj/cherry.c        "ying tao"
 斑鸠肉：/clone/beast/obj/banjiu-rou.c   "banjiu rou"
 花：    /d/emei/obj/flower.c            "flower"
*******************************************************/

		if(!present("he ye",me))  // 变荷叶
		{
			cook_needs=new("/d/dongtinghu/obj/heye");
			if(!cook_needs) write("荷叶"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"荷叶了。\n");

		if(!present("zhu sun",me))  // 变竹笋
		{
			cook_needs=new("/d/gaibang/obj/zhusun");
			if(!cook_needs) write("竹笋"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"竹笋了。\n");

		if(!present("ying tao",me))  // 变樱桃
		{
			cook_needs=new("/d/city/npc/obj/cherry");
			if(!cook_needs) write("樱桃"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"樱桃了。\n");

		if(!present("banjiu rou",me))  // 变斑鸠肉
		{
			cook_needs=new("/clone/beast/obj/banjiu-rou");
			if(!cook_needs) write("斑鸠肉"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"斑鸠肉了。\n");

		if(!present("flower",me))  // 变花
		{
			cook_needs=new("/d/emei/obj/flower");
			if(!cook_needs) write("花"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"花了。\n");

		write("ok.\n");
		return 1;
	}

	if(arg=="牛肉条" || arg=="nrt")
	{
		write("牛肉条，需要 牛肉，羊肉，猪耳朵，獐肉，兔肉。\n");

/*************************************************
 牛肉：  /d/heimuya/obj/niurou.c      "niu rou"
 羊肉：  /clone/beast/obj/yangrou2.c  "yang rou"
 猪耳朵：/clone/beast/obj/pork.c      "zhu erduo"
 獐肉：  /d/gaibang/obj/zhangrou.c    "zhang rou"
 兔肉：  /d/wudang/npc/turou.c        "tu rou"
**************************************************/

		if(!present("niu rou",me))  // 变牛肉
		{
			cook_needs=new("/d/heimuya/obj/niurou");
			if(!cook_needs) write("牛肉"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"牛肉了。\n");

		if(!present("yang rou",me))  // 变羊肉
		{
			cook_needs=new("/clone/beast/obj/yangrou2");
			if(!cook_needs) write("羊肉"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"羊肉了。\n");

		if(!present("zhu erduo",me))  // 变猪耳朵
		{
			cook_needs=new("/clone/beast/obj/pork");
			if(!cook_needs) write("猪耳朵"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"猪耳朵了。\n");

		if(!present("zhang rou",me))  // 变獐肉
		{
			cook_needs=new("/d/gaibang/obj/zhangrou");
			if(!cook_needs) write("獐肉"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"獐肉了。\n");

		if(!present("tu rou",me))  // 变兔肉
		{
			cook_needs=new("/d/wudang/npc/turou");
			if(!cook_needs) write("兔肉"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"兔肉了。\n");

		write("ok.\n");
		return 1;
	}

	if(arg=="叫化鸡" || arg=="jhj")
	{
		write("叫化鸡，需要 公鸡，装备了剑剖公鸡，裹鸡的泥。具体做法，请看shows jhj.\n");

/********************************************
 公鸡： /d/gaibang/obj/gongji.c  "gong ji"
 湿泥： /d/gaibang/obj/mud.c     "mud"
********************************************/

		if(!present("gong ji",me))  // 变公鸡
		{
			cook_needs=new("/d/gaibang/obj/gongji");
			if(!cook_needs) write("公鸡"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"公鸡了。\n");

		if(!present("mud",me))  // 变湿泥
		{
			cook_needs=new("/d/gaibang/obj/mud");
			if(!cook_needs) write("湿泥"+zzz+"\n");
			else cook_needs->move(me);
		}
		else write(xxx+"湿泥了。\n");

		write("ok.\n");
		return 1;
	}

	write("没有这味菜可做！(cbc/zdf/hqt/nrt/jhj)\n");
	return 1;
}
