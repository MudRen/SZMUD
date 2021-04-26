//Cracked by Roath
// xiakedao/shatan.c
// modified by aln  5 / 98

inherit __DIR__"no_pk_room";

void create()
{
        set("short", "С·");
        set("long", @LONG
����һ������ʯ�̳ɵ�С·��·���Գ���Щ������С��(bush)��
һ�󺣷紵���������������ʲ�ᶫ�����������⡣
LONG );

      set("exits", ([
      	"south" : __DIR__"shatan",
		"north" : __DIR__"guangchang",
      ]));

	set("item_desc",([
	    "bush" : "����Щ��֪����С������Ϊ���ں��ߣ����Զ��ܰ����������Ҫ����\n"
			 "������ʲ�ᣬ����Ҫ��������(push bush)��\n",
	]));

	set("outdoors", "xiakedao");
	set("cost", 0);

	setup();
}

void init()
{
        ::init();

	add_action("do_push", "push");
}

int do_push(string arg)
{
	object jian;

	if ( !arg )
		return notify_fail( "��Ҫ��ʲô��\n");
	if ( arg != "bush" )
		return notify_fail( "Ҫ�� push bush���� push " + arg + " ���\n");
		
	message_vision("$N�������з�����һ�Ѷ̽���\n", this_player());
	jian = new("/clone/weapon/duanjian.c");
	jian->move(this_object());

	return 1;
}
