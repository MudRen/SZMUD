// Code of ShenZhou
//donglang.c ��������
// by Sdong 07/98

inherit ROOM;

void create()
{
		  set("short", "��������");
		  set("long", @LONG
������һ�������ϣ������ǹ����������һ��������������һ����
(men)������ȴ�����š�
LONG
		  );

		  set("item_desc", ([
                "men" : "�����ź���ǵ�����\n",
        ]));

        set("exits", ([
					 "west" : __DIR__"disan",
                "north": __DIR__"c_dlang",
		  ]));

			set("objects", ([
				 __DIR__"npc/fang" : 1,
			 ]));

		  set("cost", 1);
        setup();
}

void init()
{
        add_action("do_unlock", "unlock");
        if (present("wang zhidan", environment(this_player())))
					 delete("exits/east");
}

int do_unlock(string arg)
{
		  object ob;
		  object room;

		  if (query("exits/east"))
					 return notify_fail("�������Ѿ��Ǵ򿪵ġ�\n");
		  if (!arg || (arg != "men" && arg != "west"))
					 return notify_fail("��Ҫ��ʲô��\n");
		  if (!(ob = present("danfang key", this_player())))
					 return notify_fail("�㲻��������\n");
		  set("exits/east", __DIR__"danfang2");
		  message_vision("$N��һ��Կ�״򿪷��š�\n", this_player());

		  if(!( room = find_object(__DIR__"danfang2")) )
					 room = load_object(__DIR__"danfang2");
		  if(objectp(room))
		  {
					 room->set("exits/west", __FILE__);
					 message("vision", "֨��һ�����������˰Ѵ��Ŵ��ˡ�\n", room);
					 remove_call_out("close_door");
					 call_out("close_door", 10);
		  }

		  return 1;
}

void close_door()
{
		  object room;

		  if(!( room = find_object(__DIR__"danfang2")) )
					 room = load_object(__DIR__"danfang2");
		  if(objectp(room))
		  {
					 delete("exits/east");
								message("vision", "�����������Զ������ˡ�\n", this_object());
					 room->delete("exits/west");
					 message("vision", "�����������Զ������ˡ�\n", room);
		  }
}



