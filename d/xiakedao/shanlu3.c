//Cracked by Roath
// xiakedao/shanlu3.c
// modifiedy by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
С·�������۵�ͨ��ɽ�����Ų�������һȺ��������������ʧ
�ڿ��С�������ȴ��Щ������·�߲ݴ� (grass)�䲻ʱ����ɳɳ����
�죬�����Ƕ��ߣ����ǿ���뿪�ĺá�
LONG );

      set("exits", ([
		     "eastup" : __DIR__"shanding",
		     "westdown"  : __DIR__"xiaolu2",
      ]));
	set("item_desc",([
	    "grass" : "�Ҳݴ��г��ż��䲻���۵�С����\n",
	]));
	set("objects", ([ 
            "/d/city/npc/maque.c" : 3,
          "/d/city/obj/branch3" : 1,
          "/d/city/obj/branch4" : 1,
      ]));

	set("outdoors", "xiakedao" );
	set("cost", 2);
	setup();
}

void init()
{
        ::init();

	add_action("do_push", "push");
}

int do_push(string arg)
{
	object snake, me = this_player();

	if ( !arg )
		return notify_fail("��Ҫ��ʲô��\n");

	if ( arg != "grass" )
		return notify_fail("ʲ�᣿\n");

	if (present("snake",environment(me)))
                return notify_fail("����Ҫҧ�����ˣ��㻹�������棿���ܰɡ�\n");

        if( objectp(query("mysnake")) )
                return notify_fail( "���Ĵ���Ū��һ�£����ʲô��û���֡�\n");

	message_vision("$N�����Ӳݣ�������һֻ���ߡ����뿪�ɡ�\n", me);
	snake = new("/clone/beast/snake.c");
	snake->move(this_object());
        set("mysnake", snake);

        remove_call_out("do_destroy");
        call_out("do_destroy", 20, snake);
	return 1;
}

void do_destroy(object snake)
{
        if( !snake ) return;

        if( snake->is_fighting() || snake->is_busy() || !living(snake) ) {
                call_out("do_destroy", 20, snake);
                return;
        }

        message_vision("$N�ɿ�������ˡ�\n", snake);
        destruct(snake);
        delete("mysnake");
}
