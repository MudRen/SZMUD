// July 31,2000
// Code by April
// d/gumu/shishi5.c

inherit ROOM;

void create()
{
        set("short","ͨ��");

        set("long",@LONG
�������һ�ţ�ͨ��ϸխ����������������ͷ���������ã�ʼ�ղ�
����ͷ������ȴԽ��Խƽ�����������״���һ���Ц֮����
LONG);

	 set("exits",([ 
	//	"east" : __DIR__"shandong",
		"west" : __DIR__"shiku",
		 ]));
	  
	 set("cost",1);
     setup();
}

void init()
{
	add_action("do_pa","pa");
}

int do_pa(string arg)
{
	object me = this_player();
	
	if ( !arg && arg != "east")
		return notify_fail("��Ҫ��ʲô��\n");

	if ( arg == "east") {	
		message_vision("$N��ϥ��������ȥ��\n", me);	
		me->move(__DIR__"shandong");
	//	me->delete_temp("marks/ok");
		message_vision("$N������һ�󣬽�������ɽ����\n", me);
		return 1;
	}
    return 0;
}
