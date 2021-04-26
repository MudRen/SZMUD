//Cracked by Roath
// xiakedao/wanghait
// ssy

inherit __DIR__"no_pk_room";

int fishing(object me);
int halt_fishing(object me);

void create()
{
        set("short", "����ͤ");
        set("long", @LONG
һ�����Ź��ӵ�Сͤ�ӣ�ͤ����һ���(stream)����ˮ�ļ���
��ʯ������ϸ���ˮ���γ�һƬ����������ͤ���Ե�����������ͤ��
�Ĵ�ʯ(stone)�������ʲ�ᶫ����������Լ����¡¡��������
LONG );

      set("exits", ([
		     "south" : __DIR__"xiaolu2",
		     "northup" : __DIR__"pubu",
		     "east" : __DIR__"tulu",
      ]));

	set("item_desc",([
	    "stream" : "��ˮ�峺����ʱ�����(fish)Ծ��ˮ�档\n",
	    "fish" : "͸���峺�Ľ�ˮ�����Կ������������ˮ���������ڵ�������ȥ��\n",
	    "stone" : "����һ���ɽʯ��ʯͷ����������ʲ�ᡣ�뿴��������ʲ�ᣬ��
Ҫ�Ѵ�ʯ�ƿ�(move)��\n",
	]));

	set("outdoors", "xiakedao" );
	set("cost", 2);
	set("objects", ([ 
	    __DIR__ + "npc/baodating" : 1,
      ]));

	set("pole_count", 3);
	set("fish_count", 1);
	setup();
}

void init()
{
        ::init();

	if (  present("fishing pole", this_player()) )
		add_action("do_fish", "fishing");

	add_action("do_move", "move");
}

int do_move(string arg)
{	object pole, me = this_player();

	if ( !arg )
		return notify_fail( "��Ҫ��ʲô��\n");
	if ( arg != "stone" )
		return notify_fail( "ʲô��\n");

	if (query("pole_count") < 1)
	{	message_vision("$Nʹ���Ѵ�ʯ�ƿ���ȴû�з���ʲ�ᶫ����\n", me);
		return 1;
	}
	if (!(present("fishing pole", me)))
	{	message_vision("$Nʹ���Ѵ�ʯ�ƿ�������һ����ˣ�������������(fishing)��\n", me);
		pole = new(__DIR__+ "obj/pole.c");
		pole->move(me);
		add("pole_count", -1);
	}
	else
		message_vision("$Nʹ���Ѵ�ʯ�ƿ���ȴû�з���ʲ�ᶫ����\n", me);

	add_action("do_fish", "fishing");
	return 1;
}
int do_fish()
{	object me = this_player();
	if (  !(present("fishing pole", me)) )
		return notify_fail( "û��˵�ʲ���㣿\n");
	if (me->is_busy())
		return notify_fail( "����æ���ء�\n");

	message_vision("$N����ɽ���ߵ�һ���ʯ���ͳ���ˣ�����Щ�������ʼ����������\n", me);
	me->set_temp("fishing_time", 20);
	me->set_temp("learn_time", 0);
	me->set_temp("fish_caught", 0);
	me->start_busy((: fishing :), (: halt_fishing :));
	return 1;
}
int fishing(object me)
{	int check, level;
	int timeleft = (int) me->query_temp("fishing_time");
	int learned = (int) me->query_temp("learn_time");
	object fish;
	if (timeleft < 1)
	{	if (learned > 0)
		{	write("���������ˮ�������ζ������ӣ���ͻȻ�������мܷ���ļ������ѡ�\n");
			me->improve_skill("parry", me->query("int") * (int) learned);
			message_vision("$N������վ���������ϴ��ſ��ĵ�Ц�ݡ�\n", me);
		}
		else if ( (int)me->query_temp("fish_caught") > 0)
		{	message_vision("$N�������е�����������վ������\n", me);
		}
		else
		{	message_vision("$N���ĵ�վ���������૵�����������������������á�\n", me);
		}
		me->delete_temp("fishing_time");
		me->delete_temp("learn_time");
		me->delete_temp("fish_caught");
		return 0;
	}
	if ((int) me->query("kar") > random(500) )
	{	if ((int) me->query("kar") > random(1000) && (int)query("fish_count") == 1)
		{	set("fish_count", 0);
			fish = new(__DIR__ + "obj/fish1");
		}
		else
			fish = new(__DIR__ + "obj/fish");

		message_vision("$N���е����ͻȻ����������$N������һ�����㡣\n", me);
		fish->move(me);
		me->set_temp("fishing_time", 0);
		me->set_temp("fish_caught", 1);
	}
	if ((int) me->query("int") > random(40) )
	{	level = (int) me->query_skill("parry", 1);
		check = level * level * level;
		if ((int) me->query("combat_exp") > check && (int)me->query_skill("parry", 1) <30)
		{	learned = learned + 1;
			me->set_temp("learn_time", learned);
		}
	}
	me->set_temp("fishing_time", (int)(timeleft - 1));
	return 1;
}
int halt_fishing(object me)
{	message_vision("$N���ĵ�վ���������૵�������������������ã������ˡ�\n", me);
	return 1;
}
int valid_leave(object me, string dir)
{
	remove_action("do_fish", "fishing");
	return ::valid_leave(me, dir);
}
