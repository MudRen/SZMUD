// 为spark而写，装礼品的盒子 :)  presents.c
// by naihe  02-05-31  for spark.

// 注： 本物品要与 babi-wawa.c 、 bx-jingang.c 配套使用。


#include <ansi.h>
inherit ITEM;

int now=10;
string color,color_name,obj;
void chai_obj();

void create()
{
	set_name(HIW"精美礼品盒"NOR, ({"box", "he","lipin he"}));
	set("long","这是一个用漂亮的包装纸包起来的礼品盒，你可以拆掉（chai）包装纸来打开它。\n");
	set_weight(200);
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
	add_action("do_chai","chai");
}

int do_chai(string arg)
{
	object new_ob,me;
	me=this_player();

	if(now==0)
	{
		message_vision("$N拿起空盒子拆啊拆的把它拆得粉碎了。\n",me);
		call_out("chai_obj",0);
		return 1;
	}

	if(time()-query_temp("chaitime")<3) return notify_fail("哎，你拆礼品拆那么快，好象是在搞破坏耶……还不如直接砸了它算了？\n");

	if(now!=10 && arg!=color_name) return notify_fail("哎，你要拆啥哩？\n");

	switch(random(5))
	{
		case 0:color_name="red";
		color=""HIR"红色"NOR"（red）";
		break;
		case 1:color_name="green";
		color=""HIG"绿色"NOR"（green）";
		break;
		case 2:color_name="purple";
		color=""MAG"紫色"NOR"（purple）";
		break;
		case 3:color_name="blue";
		color=""HIC"蓝色"NOR"（blue）";
		break;
		case 4:color_name="yellow";
		color=""HIY"黄色"NOR"（yellow）";
		break;
	}

	now--;
	if(now==0)
	{
		switch(random(2))
		{
		    case 0:new_ob=new(__DIR__"babi-wawa");
		    break;
		    case 1:new_ob=new(__DIR__"bx-jingang");
		    break;
		}

	message_vision("$N拆开了最后一层包装纸，从盒子里拿出了一"+new_ob->query("unit")+new_ob->query("name")+"！\n",me);
		new_ob->move(me);
		this_object()->set("long","这是一个礼品盒，里面空空的什么都没有。\n");
		return 1;
	}

	else
	{
		this_object()->set("long","这是一个用"+color+"包装纸包起来的礼品盒，你可以拆掉（chai）包装纸来打开它。\n");
		message_vision("$N小心翼翼地拆开包装纸，发现里面还有一层"+color+"的包装纸。\n",me);
	}

	set_temp("chaitime",time());
	return 1;
}

void chai_obj()
{
	destruct(this_object());
}

