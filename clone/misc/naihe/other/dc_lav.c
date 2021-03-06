//                标准描述长度示例                                   |
// 赌场里面的“洗手间”，哈哈哈  ★dc_lav.c
// by naihe  2002-04-28  于茂名
// 请勿擅自更改本文件源码，谢谢！

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "洗手间");
	set("long", "这是一个很小的房间，进门就看到前面有个鹅卵石堆成的小池子，里边的水
似乎是泉水，正在缓缓流动着，清澈见底。池子边上竖着个小牌子（paizi）。\n");
	set("no_sleep_room", "1");
	set("invalid_startroom",1);
	set("item_desc",([
	    "paizi":"“洗一洗手(xishou)，转转运气吧！”\n",
	    ]));

	set("exits", ([
	    "northeast": __DIR__"dc_dating",
	    ]));

	setup();
}

void init()
{
	add_action("do_xishou","xishou");
	add_action("do_here",  "exercise");
	add_action("do_here",  "dazuo");
	add_action("do_here",  "respirate");
	add_action("do_here",  "tuna");
	add_action("do_here",  "practice");
	add_action("do_here",  "lian");
	add_action("do_here",  "study");
	add_action("do_here",  "du");
	add_action("do_here", "eat");
	add_action("do_here", "chi");
	add_action("do_here", "drink");
	add_action("do_here", "he");
}

int do_xishou(string arg)
{
	object me=this_player();
	int lucky,add_lucky;
	lucky=me->query_temp("lucky/duchang");
	add_lucky=(random(10));

        if (time()-query_temp("time")<5)
	return notify_fail("有人在洗呢。\n");

	if(!arg)
	{
		if(!lucky)
		{
			write("你觉得自己今天实在倒霉极了，也许要逢赌必输。\n");
			me->set_temp("lucky/duchang",5);
		}

		else
		{
			switch(random(2))
			{
				case 0:
				if(lucky<50)
				{
					me->set_temp("lucky/duchang",(lucky+add_lucky));
					message_vision("$N把手放到池子里洗了洗，感觉泉水冰凉凉的舒服极了，似乎就此开始时来运转。\n",me);
				}

				else message_vision("$N把手放到池子里洗了洗，毫无感觉。\n",me);
				break;

				case 1:
				if(lucky<5)
				{
					me->delete_temp("lucky/duchang");
					write("你觉得自己今天实在倒霉极了，也许要逢赌必输。\n");
				}

				else
				{
					me->set_temp("lucky/duchang",(lucky-add_lucky));
					message_vision("$N把手放到池子里洗了洗，忽地觉得一丝不安，却又不知道为什么。\n",me);
				}
				break;
			}
		}
	set_temp("time",time());
	return 1;
	}

	else return 0;
}

int do_here(string arg)
{
	tell_object(this_player(),"这里是洗手的地方，做别的事情不好吧。\n");
	return 1;
}
