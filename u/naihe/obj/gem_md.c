// 值钱的漂亮宝石，宝藏库里面用。gem_md.c
// by naihe 奈何  2002-05-16

#include <ansi.h>
inherit ITEM;

string clname;
int temp,tempa,tempb,
temp=(random(50000)+30000),
tempa=(temp*(random(5)+1)),
tempb=(temp/(random(5)+1));

int color=(random(5));
// 随机的负重、颜色、以及价值！

void create()
{
	if(color==0)
	{
		set_name(HIG"绿宝石"NOR, ({"gem","baoshi","green gem"}));
		clname="绿";
	}

	if(color==1)
	{
		set_name(HIR"红宝石"NOR, ({"gem","baoshi","red gem"}));
		clname="红";
	}

	if(color==2)
	{
		set_name(HIB"蓝宝石"NOR, ({"gem","baoshi","blue gem"}));
		clname="蓝";
	}

	if(color==3)
	{
		set_name(HIM"紫宝石"NOR, ({"gem","baoshi","violet gem"}));
		clname="紫";
	}

	if(color==4)
	{
		set_name(HIC"天蓝宝石"NOR, ({"gem","baoshi","sapphire gem"}));
		clname="天蓝";
	}

	switch(random(5))
	{
		case 0:set("long","一颗"+clname+"色的宝石，泛着迷人的光芒。\n");
		break;

		case 1:set("long","这颗宝石色泽纯正，它的"+clname+"是完全的"+clname+"，让人爱不释手。\n");
		break;

		case 2:set("long","宝石里幽幽地散发着"+clname+"色的光芒。\n");
		break;

		case 3:set("long","宝石里散发着"+clname+"色的光芒，映入你的眼帘，让你产生无限遐思。\n");
		break;

		case 4:set("long","宝石里淡淡地散发着"+clname+"色的光芒。\n");
		break;

	}

	set_weight(tempb);
	set("unit", "颗");
	set("value",tempa);

//	set("long","价值是："+tempa+", 重量是"+tempb+".\n"); 这句话做测试时用。
	setup();
}
