//                ��׼��������ʾ��                                   |
// �ĳ�����ġ�ϴ�ּ䡱��������  ��dc_lav.c
// by naihe  2002-04-28  ��ï��
// �������Ը��ı��ļ�Դ�룬лл��

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ϴ�ּ�");
	set("long", "����һ����С�ķ��䣬���žͿ���ǰ���и�����ʯ�ѳɵ�С���ӣ���ߵ�ˮ
�ƺ���Ȫˮ�����ڻ��������ţ��峺���ס����ӱ������Ÿ�С���ӣ�paizi����\n");
	set("no_sleep_room", "1");
	set("invalid_startroom",1);
	set("item_desc",([
	    "paizi":"��ϴһϴ��(xishou)��תת�����ɣ���\n",
	    ]));

	set("exits", ([
	    "south": __DIR__"dc_tongdao",
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
	lucky=me->query_temp("duchang/lucky");
	add_lucky=(1+random(10));

	if (time()-query_temp("time")<5)
	return notify_fail("������ϴ�ء�\n");

	if(!arg)
	{
		if(!lucky)
		{
			message_vision("$N���ַŵ�������ϴ��ϴ���ƺ��о�ͦ�õģ�������͸���ϴϴ��תת�������ˡ�\n",me);
			me->set_temp("duchang/lucky",11);
		}

		else
		{
			switch(random(2))
			{
				case 0:
				if(lucky<50)
				{
					me->set_temp("duchang/lucky",(lucky+add_lucky));
					message_vision("$N���ַŵ�������ϴ��ϴ���о�Ȫˮ��������������ˣ��ƺ��ʹ˿�ʼʱ����ת��\n",me);
				}

				else message_vision("$N���ַŵ�������ϴ��ϴ�����޸о���\n",me);
				break;

				case 1:
				if(lucky<10)
				{
					me->delete_temp("duchang/lucky");
					message_vision("$Nϴ��ϴ�֣������Լ�����ʵ�ڵ�ù���ˣ�Ҳ��Ҫ��ı��䡣\n",me);
				}

				else
				{
					me->set_temp("duchang/lucky",(lucky-add_lucky));
					message_vision("$N���ַŵ�������ϴ��ϴ�����ؾ���һ˿������ȴ�ֲ�֪��Ϊʲô��\n",me);
				}
				break;
			}
		}
	lucky=me->query_temp("duchang/lucky");
	if(wizardp(me))  // ��ʦ�ܹ�������ǰ����ֵ�Լ�ϴ��ʱ���õȴ���
	{
		write("���ڵ�luckyֵ�� "+lucky+"\n");
		return 1;
	}

	set_temp("time",time());
	return 1;
	}

	else return 0;
}

int do_here(string arg)
{
	tell_object(this_player(),"������ϴ�ֵĵط�����������鲻�ðɡ�\n");
	return 1;
}
