// Code of ShenZhou
// yanting.c
// Jay 7/12/96

inherit ROOM;

void create()
{
    int i;
        set("short", "����");
        set("long", @LONG
�����ǽ�����������ͼҵĴ���������������͵���ʮ�ٵ���
�����кؿ�ӯ�ţ�ȺӢ�üá�������ڴ����ϽӴ����صĸ�·
Ӣ�ۡ�
LONG
        );

        set("objects", ([
	    __DIR__"npc/banhe" : 1,
	]));

        set("exits", ([
                "west" : __DIR__"yanting",
		"out" : __DIR__"gate",
		"north" : __DIR__"huayuan",
        ]));

	set("cost", 0);
        setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{     
    if ( (dir=="out") && present("xiao banhe",environment(me)) &&
                (present("yuan dao", me) || present("yang dao", me))) {
       message_vision("�����һ�Ѿ�ס$N����ɱ�Ҷ�Ů�ݵ������\n",
                me);
       return notify_fail("\n");
    }
    else
        return :: valid_leave(me,dir);
}

