// Code of ShenZhou
// Room: /d/murong/mantuo1
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "����ɽׯ");
	set("long", @LONG
    һ����ȥ�����Ǻ���ͷ׵Ĳ軨���������ݡ��Ų����ͣ�
ֻ�������г�ɽ������ޱ������ܣ��������ǣţ������
�º졢Ǿޱ֮��Ҳ��һ��ȫ�ޡ�
LONG
	);
	set("cost", 1);
	set("outdoors", "murong");
	set("exits", ([ 
        "south" : __DIR__"mantuo1",
                      ]));
	set("no_clean_up", 0);
        set("objects", ([
		"/d/murong/npc/ychao" : 1,
		]));

	setup();
}

void init()
{
        add_action("do_go", "back");
}

int do_go(string arg)
{
        object me;
        me = this_player () ;

       if ( !arg || ( arg != "zhuang" ) )
                return notify_fail("ʲô��\n");
        
       if ( (int)me->query_skill("dodge", 1) < 120)
           return notify_fail("\n�㹦������,������ľ׮\n");

     else if ( (int)me->query_skill("dodge", 1) >= 120)
       { me ->move("/d/murong/qing1");
       tell_object(me, "\n�㽡����ɣ���һ��ͻص�������...\n\n" ) ;
        return 1 ;
        }
    
     
}