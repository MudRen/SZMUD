//Cracked by Yujie
///d/forest/clhoutang.c
// by yujie 10 / 2001

inherit ROOM;

void create()
{
        set("short", "���ô���");
        set("long", @LONG
�����ǳ��ְ�ĺ��ã��������Ǹ���������˽���صء�һ�������ɷ
�����������￴�ţ������˵Ȳ��ý�����������ǵ��徻��
LONG );

        set("exits", ([
	       "north" : __DIR__"clhoulang1",
	       "south" : __DIR__"clhuayuan",
        ]));

	set("cost", 0);

        set("objects",([
               __DIR__"npc/cl_menwei" : 1,
        ]));
        
        set("no_fight",1);

        setup();

        // replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        object ob;

        if( dir != "north" )
                 return ::valid_leave(me, dir);

        if( !(ob = present("men wei", environment(me))) )
                 return ::valid_leave(me, dir);

        if( !living(ob) )
                 return ::valid_leave(me, dir);
                 
           if (stringp (me->query_temp("bangs/pos"))) 
        	 return ::valid_leave(me, dir);
        	 
        if (stringp (me->query_temp("invite")))
        	return ::valid_leave(me, dir);        	

        message_vision("$N����$n��ǰ��˵�����������Ұ������ǵ�˽���صأ������˵Ȳ������ڡ�\n", ob, me);
        return notify_fail("");
}

