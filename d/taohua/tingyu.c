// Code of ShenZhou
//Chaos, Ryu, 3/10/97

inherit ROOM;
int do_jump(string arg);

void create()
{
	set("short", "����ʯ");
	set("long", @LONG
�����ѽӽ��̲��ص����ģ�һ��������ʨ�Ĵ�ʯ����ˮ�ϣ�������������׭ --
�����㡱�������Ϊ��������ʹ�ã�ʯ���Ѿ�ʮ�ֹ⻬�����а���ʢ�ţ���������
��Ҷ�������ʯ������������һ��΢����������к�Ҷٿٿ���죬��β��ɫ����Ϸ
�ںɼ䡣�����������һ����������ͤ(ting)�������ƺ���·ͨ���ͤ��
LONG
	);

        set("item_desc", ([
        "ting" : 
		"ͤ��һ�ң���ϡ���Կ������С��Խ�ͤ�����֡�\n�㿴������
����̫Զ��Ӧ�ÿ������Ṧ����(fly)��ȥ��\n",
        ]));
/*        
	set("objects", ([
                __DIR__"obj/taoshu" : 1,
        ]));
*/
	set("exits", ([
                "west" : __DIR__"bibochi",
                "south" : __DIR__"zhulin3",
        ]));


	set("cost", 2);
	set("outdoors", "taohua");

	setup();

}

void init()
{
        add_action("do_jump", "fly");
}

int do_jump(string arg)
{
        object me = this_player();

        if ( !arg || arg != "ting" )
             return notify_fail( "ʲô��\n");

        message_vision("$N�������Խ�ͤ��ȥ��\n", me);
        if ( me->query_skill("dodge",1) <= 50 ) {
             message_vision("$Nһ�������񣬡����̡�һ������ˮ�����һ�����ࡣ\n", me);
             message_vision("$N�������ƵĴӳ������������������Ĩ��Ĩ�졣\n", me);
        }

        if ( me->query_skill("dodge",1) > 50 ) {
             me->move(__DIR__"shijian");
             message("vision", me->name() + 
"����������ʯ���˹�����\n",environment(me), ({me}) );
        }

        return 1;
}
