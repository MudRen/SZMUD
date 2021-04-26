//Cracked by Roath
// xiakedao/xiaolu.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "С·");
        set("long", @LONG
����һ����ͨ��ʯ��·��·����ʯ���������ţ��Գ�������ͼ
����·�Գ���Щ������С��(bush)����ʱС��������һ����������
���������ɽ���С�ޡ�һ�󺣷紵���������������ʲ�ᶫ������
�����⡣
LONG );

      set("exits", ([
      	"south" : __DIR__"shatan",
		"north" : __DIR__"ybting",
      ]));

	set("item_desc",([
	    "bush" : 
"����Щ��֪����С������Ϊ���ں��ߣ����Զ��ܰ����������Ҫ����
������ʲ�ᣬ����Ҫ��������(push bush)��\n",
	]));

	set("outdoors", "xiakedao" );
	set("cost", 0);
	set("objects", ([ 
          "/d/city/obj/branch1" : 1,
      ]));
	setup();
}
void init()
{
        ::init();

	add_action("do_push", "push");
}

int do_push(string arg)
{	object jian, me = this_player();

	if ( !arg )
		return notify_fail( "��Ҫ��ʲô��\n");
	if ( arg != "bush" )
		return notify_fail( "Ҫ�� push bush���� push " + arg + " ���\n");
	
	if ((present("duanjian",environment(me)))||
	    (present("duanjian",me)))
	{	message_vision("$N�������з�����ȥ���˰��죬ȴʲ��Ҳû���ҵ���\n", me);
		return 1;	
	}
	else
	{	message_vision("$N�������з�����һ�Ѷ̽���\n", me);
		jian = new("/clone/weapon/duanjian.c");
		jian->set("value", 0);
		jian->move(environment(me));
		return 1;
	}
}
