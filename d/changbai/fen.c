//chchong by fen.c
// Room: /d/changbai/fen.c
//chchong 2001/08/31

inherit ROOM;

void create()
{
        set("short", "��Ĺ");
        set("long", @LONG
    ������һ����Ĺ���������ó�ʱ��û�������������ϸ�����ܿ���
ԭ��Ĺ��������(cao) ��ס�ˡ���ʱ���������ݴ��д���˻˻ɳɳ����������
����ʲô��������������������
LONG
        );
	set("item_desc", ([
		"cao"   : "���Ӳݵĺ������������ʲô�������������ݿ���������(ba cao)��\n",
		]));
        set("exits", ([
  "northup" : __DIR__"yuzf",
]));
       set("objects", ([
                "/d/xingxiu/npc/jumang" : 1,
        ]) );
      set("no_clean_up", 0);
        set("outdoors", "changbai");
        set("cost", 1);
        setup();
}

void init()
{
        add_action("do_ba","ba");
}
 
int do_ba(string arg)
{
        object ob, me = this_player();
        if( !arg || arg=="" ) return 0;
        if( arg=="cao" ) 
        {
                ob = new("/clone/weapon/lengyue");
        if (!ob)
           return notify_fail("�㲦���Ӳݣ����������ƺ����������ˡ�\n");
           

//      ob->move("/d/changbai/fen");
        ob->move(me);

                write("�㲦���Ӳݣ�����������һ�ѱ�����\n");
           CHANNEL_D->do_channel(me, "rumor", sprintf("%sŪ����һ�����µ���", me->query("name")));

// command ("rumor "+me->query("name")+"Ū����һ�����µ���");
        return 1;        }
}
