//Cracked by Roath
// Copy from  /d/shaolin/hanshui1.c
// Date: Long /8/1/97

inherit ROOM;

//void do_fisttime(object me);
int block_cmd();

void create()
{
    set("short", "ɳ̲");
    set("long", @LONG
��ĿԶ��������ֻ�����㵭���ķ�Ӱ���������ģ����µ�ϸɳ��
����ů�����˳������ֻ�����ȥ��˲��ϴˢ������㼣����Զ����ֻ
��Ÿ������ʳ���ƺ��������ˡ�
LONG
    );

	set("exits", ([
    	]));
    	set("no_fight", "1");
    	set("outdoors", "xiakedao");
    	if (random(10)> 5 )
    	{	set("objects", ([__DIR__"npc/li4.c" : 1, ]));
    	}
    	else
	{	set("objects", ([__DIR__"npc/zhang3.c" : 1, ]));
	}
	setup();
}

void init()
{   	object me = this_player();
	object greeter;
	object greeter2;

	if (!wizardp(me)) 
	{
		add_action("block_cmd","",1);
		me->set("block", 1);
	}
      if (interactive(this_player())) 
	{	write ("������������˹��������ܾ���ȴ����ô��İ���������������Ķ�����\n");
		greeter = present("li si", environment(me));
		greeter2 = present("zhang san", environment(me));
		if (!(greeter) && (!(greeter2)) )
		{	
			if (random(10) > 5)
			{	greeter = new(__DIR__"npc/zhang3.c");
			}
			else
			{	greeter = new(__DIR__"npc/li4.c");
    			}
			greeter->move(environment(me));	
		}
		else if ((!greeter2) && (greeter) && (greeter->query_temp("met") == 1) )
		{	greeter2 = new(__DIR__"npc/zhang3.c");
			greeter2->move(environment(me));	
		}
		else if ((!greeter) && (greeter2) && (greeter2->query_temp("met") == 1))
		{	greeter = new(__DIR__"npc/li4.c");
			greeter->move(environment(me));	
		}
		
	}
//	call_out("do_fisttime", 0, me);

}
//	write ("������������˹��������ܾ��������ᶼİ���������������ģ���\n");
//	write("�㲻֪������������£�ֻ�ø��������ˡ�\n");

int block_cmd()
{
        string cmd;
        cmd = query_verb();
        if ( cmd == "quit" || cmd == "goto" || cmd == "suicide" || cmd == "follow" || cmd == "tell" || cmd == "say" || cmd == "reply" || cmd == "look" )
                return 0;
        return 1;
}

