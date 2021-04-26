// 为spark而写，儿童节礼物  :)  babi-wawa.c
// by naihe  02-05-31  for spark.


#include <ansi.h>
inherit ITEM;

string head_now,head,shipin,shipin_wear,color_shipin,color,dress,
color="普普通通的",
dress="小连衣裙",
head_now="乱乱",
shipin="none";

void now();

void create()
{
	set_name(HIM"芭比娃娃"NOR, ({"babi", "baby","babi wawa"}));
	set("long","这是一个漂亮的芭比娃娃，你可以给她换衣服，梳头发，或者戴饰品。 :)\n");
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 0);
	}
	setup();
}

void init()
{
	add_action("do_huan","huan");
	add_action("do_shu","shu");
	add_action("do_dai","dai");
}

int do_shu(string arg)
{
	object me=this_player();

	if(!arg) return notify_fail("你要给她梳什么捏？\n");
	if(arg!="tou" && arg!="head" && arg!="toufa" && arg!="hair") return notify_fail("你要给她梳什么捏？\n");

	if(head!="good")
	{
		message_vision(CYN"$N轻轻地捧起"HIM"芭比娃娃"NOR+CYN"，细心地把她的头发梳得整整齐齐的。\n"NOR,me);
		head="good";
		head_now="整整齐齐";
	}

	else
	{
		message_vision(CYN"$N捧起"HIM"芭比娃娃"NOR+CYN"，把她的头发梳啊梳的却越梳越乱了。\n"NOR,me);
		head="bad";
		head_now="乱乱";
	}

	now();
	return 1;
}

int do_dai(string arg)
{
	if(!arg) return notify_fail("你要给她戴什么捏？\n");

	if(arg!="ring" && arg!="earring" && arg!="necklace" && arg!="none") return notify_fail("可以给她戴上：戒指（ring）或项链（necklace）或耳环（earring），或取下（none）。\n");

	switch(random(5))
	{
		case 0:color_shipin=""HIY"";
		break;
		case 1:color_shipin=""HIG"";
		break;
		case 2:color_shipin=""HIW"";
		break;
		case 3:color_shipin=""HIM"";
		break;
		case 4:color_shipin=""HIC"";
		break;
	}

	if(arg=="ring")
	{
		if(shipin!="none") message_vision(CYN"$N把"HIM"芭比娃娃"NOR+CYN""+shipin_wear+"着的小戒指取了下来。\n"NOR,this_player());
		shipin_wear="戴";
		shipin="一个"+color_shipin+"小戒指"NOR"";
	}

	if(arg=="earring")
	{
		if(shipin!="none") message_vision(CYN"$N把"HIM"芭比娃娃"NOR+CYN""+shipin_wear+"着的小耳环取了下来。\n"NOR,this_player());
		shipin_wear="戴";
		shipin="一对"+color_shipin+"小耳环"NOR"";
	}

	if(arg=="necklace")
	{
		if(shipin!="none") message_vision(CYN"$N把"HIM"芭比娃娃"NOR+CYN""+shipin_wear+"着的小项链取了下来。\n"NOR,this_player());
		shipin_wear="挂";
		shipin="一串"+color_shipin+"小项链"NOR"";
	}

	if(arg=="none")
	{
		message_vision(CYN"$N轻轻地把"HIM"芭比娃娃"NOR+CYN""+shipin_wear+"着的"+shipin+""CYN"取了下来。\n"NOR,this_player());
		shipin="none";
	}

	else message_vision(CYN"$N轻轻地给"HIM"芭比娃娃"NOR+CYN""+shipin_wear+"上了"+shipin+"。\n"NOR,this_player());

	now();
	return 1;
}

int do_huan(string arg)
{
	string tempa,tempb;

        if (!arg || sscanf(arg, "%s %s", tempa, tempb) != 2)
	        return notify_fail("指令格式： huan <颜色> <服装> .\n");

	if(tempa!="HIR" && tempa!="HIG" && tempa!="HIY" && tempa!="HIB" && tempa!="HIM" && tempa!="HIC" && tempa!="HIW" && tempa!="RED" && tempa!="GRN" && tempa!="YEL" && tempa!="BLU" && tempa!="MAG" && tempa!="CYN" && tempa!="WHT") return notify_fail("你要给她换什么颜色的服装捏？（help color）\n");

	if(tempb!="xiaoqun" && tempb!="hunsha" && tempb!="changqun")
		return notify_fail("你要给她换什么服装捏？（xiaoqun--小连衣裙 hunsha--婚礼服 changqun--露背长裙） \n");

	if(tempb=="xiaoqun") dress="小连衣裙";
	if(tempb=="hunsha") dress="婚纱";
	if(tempb=="changqun") dress="露背长裙";

	if(tempa=="HIR") color=""HIR"红色"NOR"";
	if(tempa=="HIG") color=""HIG"绿色"NOR"";
	if(tempa=="HIY") color=""HIY"黄色"NOR"";
	if(tempa=="HIB") color=""HIB"深蓝色"NOR"";
	if(tempa=="HIM") color=""HIM"粉红色"NOR"";
	if(tempa=="HIC") color=""HIC"天蓝色"NOR"";
	if(tempa=="HIW") color=""HIW"白色"NOR"";

	if(tempa=="RED") color=""RED"暗红色"NOR"";
	if(tempa=="GRN") color=""GRN"浅绿色"NOR"";
	if(tempa=="YEL") color=""YEL"暗黄色"NOR"";
	if(tempa=="BLU") color=""BLU"暗蓝色"NOR"";
	if(tempa=="MAG") color=""MAG"浅紫色"NOR"";
	if(tempa=="CYN") color=""CYN"蓝灰色"NOR"";
	if(tempa=="WHT") color=""WHT"浅灰色"NOR"";

	message_vision(CYN"$N轻轻地给"HIM"芭比娃娃"NOR+CYN"换上了一条"NOR""+color+""CYN""+dress+""CYN"。\n"NOR,this_player());
	now();
	return 1;
}

void now()
{
	if(shipin!="none")
	{
		this_object()->set("long","这是一个穿着"+color+dress+"的"HIM"芭比娃娃"NOR"，头发"+head_now+"的，还"+shipin_wear+"着"+shipin+"，可爱极了。\n你可以给她换衣服，梳头发，或者戴饰品。 :)\n");
	}

	else this_object()->set("long","这是一个穿着"+color+dress+"的"HIM"芭比娃娃"NOR"，头发"+head_now+"的，可爱极了。\n你可以给她换衣服，梳头发，或者戴饰品。 :)\n");
}

